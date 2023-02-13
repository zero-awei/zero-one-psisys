package com.zeroone.star.payablemanagement.controller;

import cn.hutool.core.date.DateTime;
import com.alibaba.excel.annotation.ExcelProperty;
import com.baomidou.mybatisplus.annotation.TableField;
import com.fasterxml.jackson.annotation.JsonProperty;
import com.zeroone.star.payablemanagement.service.base.FinPayableService;
import com.zeroone.star.project.utils.easyexcel.EasyExcelUtils;
import com.zeroone.star.project.utils.response.ResponseUtils;
import com.zeroone.star.project.vo.JsonVO;
import entity.FinPayable;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.Data;
import lombok.SneakyThrows;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.io.Serializable;
import java.nio.charset.StandardCharsets;
import java.util.List;

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

    @ApiOperation(value = "导出ExcelByPost", produces = "application/octet-stream")
    @PostMapping(value = "toExcelByPost")
    public ResponseEntity<byte[]> toExcelByPost() {
        String sheetName = "fin";
        byte[] bytes = EasyExcelUtils.download(sheetName, FinPayable.class, finPayableService.list());
        return ResponseUtils.bytes2Xlsx(bytes, sheetName);
    }

    @ApiOperation(value = "导出ExcelByGet", produces = "application/octet-stream")
    @GetMapping(value = "toExcel2ByPost")
    public ResponseEntity<byte[]> toExcelByGet() {
        String sheetName = "fin";
        byte[] bytes = EasyExcelUtils.download(sheetName, FinPayable.class, finPayableService.list());
        return ResponseUtils.bytes2Xlsx(bytes, sheetName);
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
        System.out.println(user);
        System.out.println(JsonVO.success(user));
        return JsonVO.success(user);
    }

    /**
     * 加了@RequestBody后要传json格式数据
     */
    @ApiOperation(value = "获取用例2")
    @PostMapping(value = "get-sample2")
    public JsonVO<User> getSample2(@RequestBody User user) {
        System.out.println(user);
        System.out.println(JsonVO.success(user));
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
