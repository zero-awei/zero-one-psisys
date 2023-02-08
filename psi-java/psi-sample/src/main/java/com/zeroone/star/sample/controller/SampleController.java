package com.zeroone.star.sample.controller;


import com.zeroone.star.project.query.sample.SampleQuery;
import com.zeroone.star.project.sample.SampleApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.sample.SampleVO;
import com.zeroone.star.sample.service.ISampleService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
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
    @Resource
    ISampleService service;

    @GetMapping("query-all")
    @ApiOperation(value = "示例分页查询")
    @Override
    public JsonVO<PageVO<SampleVO>> queryAll(@Validated SampleQuery condition) {
        return JsonVO.success(service.listAll(condition));
    }

    @Override
    public JsonVO<SampleVO> queryById(int id) {
        return JsonVO.success(service.getById(id));
    }

    @GetMapping("query-one")
    @ApiOperation(value = "示例编号查询")
    public JsonVO<SampleVO> queryByIdValidate(
            @Min(value = 1, message = "最小值必须为1")
            @RequestParam int id) {
        return queryById(id);
    }

    @GetMapping("test-seata")
    @ApiOperation(value = "测试seata")
    public JsonVO<String> testSeata() {
        try {
            service.testSeata();
            return JsonVO.success("数据保存成功");
        }catch (Exception e){
            return JsonVO.fail(e.getMessage());
        }
    }
}

