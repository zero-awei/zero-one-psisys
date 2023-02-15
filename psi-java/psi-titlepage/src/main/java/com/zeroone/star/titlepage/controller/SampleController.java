package com.zeroone.star.titlepage.controller;


import com.zeroone.star.project.query.sample.SampleQuery;
import com.zeroone.star.project.sample.SampleApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.sample.SampleVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import javax.validation.constraints.Min;

/**
 * <p>
 * 前端控制器
 * </p>
 * @author awei
 * @since 2023-02-04
 */
@RestController
@RequestMapping("sample")
@Api(tags = "示例接口")
@Validated
public class SampleController implements SampleApis {

    @GetMapping("query-all")
    @ApiOperation(value = "示例分页查询")
    @Override
    public JsonVO<PageVO<SampleVO>> queryAll(@Validated SampleQuery condition) {
        return null;
    }

    @Override
    public JsonVO<SampleVO> queryById(int id) {
        return null;
    }

    @GetMapping("query-one")
    @ApiOperation(value = "示例编号查询")
    public JsonVO<SampleVO> queryByIdValidate(
            @Min(value = 1, message = "最小值必须为1")
            @RequestParam int id) {
        return queryById(id);
    }
}

