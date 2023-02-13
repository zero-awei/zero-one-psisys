package com.zeroone.star.payablemanagement.controller;

import com.alibaba.excel.annotation.ExcelProperty;
import com.alibaba.excel.util.MapUtils;
import com.baomidou.mybatisplus.annotation.TableField;
import com.fasterxml.jackson.annotation.JsonProperty;
import com.zeroone.star.payablemanagement.service.base.FinPayableService;
import com.zeroone.star.project.utils.easyexcel.EasyExcelUtils;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.payablemanagement.OthersPayableVO;
import entity.FinPayable;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.Data;
import lombok.SneakyThrows;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

/**
 * 用例
 *
 * @author iceberg-work
 */
@Controller
@RequestMapping("sample")
@Api(tags = "用例")
@RestController
public class SampleController {

    @Resource
    FinPayableService finPayableService;

    @Value("${customization.name.OthersPayable}")
    String name;

    Logger logger = LoggerFactory.getLogger(SampleController.class);

    @SneakyThrows
    @ApiOperation("模板导出Excel")
    @PostMapping(value = "importExcelAsTemplate", produces = "application/octet-stream")
    public ResponseEntity<byte[]> importExcelAsTemplate() {

        List<OthersPayableVO> list = new ArrayList<>(2);
        OthersPayableVO vo1 = new OthersPayableVO();
        OthersPayableVO vo2 = new OthersPayableVO();
        vo1.setApprovalResultType("11");
        vo2.setAmt("222");
        list.add(vo1);
        list.add(vo2);
        Map<String, Object> map = MapUtils.newHashMap();
        map.put("approver_dictText", "管理员");

        return EasyExcelUtils.downloadsAsTemplate(name, list, map);
    }

    @ApiOperation("上传Excel")
    @PostMapping("importExcel")
    public JsonVO<List<FinPayable>> uploadWithEasyExcel(MultipartFile file) {
        return JsonVO.success(EasyExcelUtils.imports(file, FinPayable.class));
    }

    @ApiOperation(value = "下载Excel")
    @GetMapping(value = "toExcel", produces = "application/octet-stream")
    public ResponseEntity<byte[]> toExcelByGet() {
        String sheetName = "fin";
        return EasyExcelUtils.downloads(sheetName, FinPayable.class, finPayableService.list());
    }

    @ApiOperation(value = "获取列表")
    @GetMapping(value = "list")
    public JsonVO<List<FinPayable>> list() {
        return JsonVO.success(finPayableService.list());
    }

    @ApiOperation(value = "传入实体并返回")
    @PostMapping(value = "entity2entity")
    public JsonVO<FinPayable> entity2entity(@RequestBody FinPayable finPayable) {
        return JsonVO.success(finPayable);
    }

    @ApiOperation(value = "获取用例1")
    @GetMapping(value = "get-sample1")
    public JsonVO<User> getSample1(User user) {
        logger.debug("user: {}", user);
        logger.debug("vo: {}", JsonVO.success(user));
        return JsonVO.success(user);
    }

    /**
     * 加了@RequestBody后要传json格式数据
     */
    @ApiOperation(value = "获取用例2")
    @PostMapping(value = "get-sample2")
    public JsonVO<User> getSample2(@RequestBody User user) {
        logger.debug("user: {}", user);
        logger.debug("vo: {}", JsonVO.success(user));
        return JsonVO.success(user);
    }
}

@Data
class User implements Serializable {
    @TableField(exist = false)
    private static final long serialVersionUID = 1L;
    /** value表示该属性对应的表头名称， index表示该属性所处的列的位置 */
    @ExcelProperty(value = "编号", index = 0)
    @JsonProperty(value = "id")
    private Integer id;
    @ExcelProperty(value = "姓名", index = 1)
    @JsonProperty(value = "name")
    private String name;
    @ExcelProperty(value = "电话", index = 2)
    @JsonProperty(value = "phone")
    private String phone;
}
