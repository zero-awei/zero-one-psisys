package com.zeroone.star.systemmanagement.controller.addressbook;

import cn.hutool.core.date.DateTime;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.query.systemmanagement.addressbook.AddressbookQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.addressbook.AddressbookVO;
import com.zeroone.star.systemmanagement.entity.addressbook.User;
import com.zeroone.star.systemmanagement.service.addressbook.IAddressbookService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import javax.annotation.PostConstruct;
import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 描述：excel
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 西柚珍珠蜜
 * @version 1.0.0
 */
@Controller
@RequestMapping("/systemmanagement/excel-addressbook")
@Api(tags = "通讯录数据导出")
public class ExcelController {
    @Resource
    EasyExcelComponent excel;
    private List<User> users = new ArrayList<>();

    @Resource
    IAddressbookService service;

    @PostConstruct
    public void initData() {

    }

    @SneakyThrows
    @ApiOperation(value = "获取导出文件")
    @GetMapping(value = "get-file", produces = "application/octet-stream")
    public ResponseEntity<byte[]> download(AddressbookQuery condition) {
        // 清理数据
        users.clear();
        // 初始化数据
        PageVO<AddressbookVO> vo = service.listAddressbook(condition);
        List<AddressbookVO> rows = vo.getRows();
        for (AddressbookVO row : rows) {
            User u = new User();
            u.setRealname(row.getRealname());
            u.setPhone(row.getPhone());
            u.setEmail(row.getEmail());
            u.setDepartName(row.getDepartName());
            u.setPost(row.getPost());
            u.setWorkNo(row.getWorkNo());
            users.add(u);
        }
        // 导出Excel
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        excel.export("测试", out, User.class, users);
        // 创建响应头
        HttpHeaders headers = new HttpHeaders();
        // 构建一个下载的文件名称
        String fileName = "test-" + DateTime.now().toString("yyyyMMddHHmmssS") + ".xlsx";
        fileName = new String(fileName.getBytes(StandardCharsets.UTF_8), StandardCharsets.ISO_8859_1);
        headers.setContentDispositionFormData("attachment", fileName);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        ResponseEntity<byte[]> result = new ResponseEntity<>(out.toByteArray(), headers, HttpStatus.CREATED);
        out.close();
        return result;
    }

    @Resource
    FastDfsClientComponent dfsClient;

    @Value("${fastdfs.nginx-servers}")
    private String serverUrl;

    @SneakyThrows
    @ApiOperation(value = "获取导出链接")
    @ResponseBody
    @GetMapping("get-url")
    public JsonVO<String> downloadUrl(AddressbookQuery condition) {
        // 清理数据
        users.clear();
        // 初始化数据
        PageVO<AddressbookVO> vo = service.listAddressbook(condition);
        List<AddressbookVO> rows = vo.getRows();
        for (AddressbookVO row : rows) {
            User u = new User();
            u.setRealname(row.getRealname());
            u.setPhone(row.getPhone());
            u.setEmail(row.getEmail());
            u.setDepartName(row.getDepartName());
            u.setPost(row.getPost());
            u.setWorkNo(row.getWorkNo());
            users.add(u);
        }
        // 导出Excel
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        excel.export("测试", out, User.class, users);
        // 上传到fastdfs
        String suffix = "xlsx";
        FastDfsFileInfo result = dfsClient.uploadFile(out.toByteArray(), suffix);
        // 关闭输出流
        out.close();
        // 处理传递结果
        if (result == null) {
            return JsonVO.fail("文件上传失败");
        }
        // 拼接文件下载地址
        String downloadUrl = dfsClient.fetchUrl(result, serverUrl, true);
        return JsonVO.success(downloadUrl);
    }
}
