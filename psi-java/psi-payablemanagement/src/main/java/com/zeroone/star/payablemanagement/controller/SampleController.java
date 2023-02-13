package com.zeroone.star.payablemanagement.controller;

import com.alibaba.excel.annotation.ExcelProperty;
import com.baomidou.mybatisplus.annotation.TableField;
import com.fasterxml.jackson.annotation.JsonProperty;
import com.zeroone.star.payablemanagement.service.base.FinPayableService;
import com.zeroone.star.project.utils.easyexcel.EasyExcelUtils;
import com.zeroone.star.project.vo.JsonVO;
import entity.FinPayable;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.Data;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.io.Serializable;
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

    Logger logger = LoggerFactory.getLogger(SampleController.class);

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
