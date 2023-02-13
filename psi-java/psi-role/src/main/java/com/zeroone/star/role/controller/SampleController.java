package com.zeroone.star.role.controller;


import com.zeroone.star.project.query.sample.SampleQuery;
import com.zeroone.star.project.sample.SampleApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.sample.SampleVO;
import com.zeroone.star.role.service.ISampleService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

/**
 * <p>
 *  前端控制器
 * </p>
 *
 * @author ali
 * @since 2023-02-12
 */
@RestController
@RequestMapping("sample")
@Api(tags = "实例接口")
public class SampleController implements SampleApis {

    @Resource
    ISampleService service;

    @GetMapping("query-all")
    @ApiOperation(value = "示例分页查询")
    @Override
    public JsonVO<PageVO<SampleVO>> queryAll(SampleQuery condition) {
        return JsonVO.success(service.listAll(condition));
    }

    @GetMapping("query-one")
    @ApiOperation(value = "示例编号查询")
    @Override
    public JsonVO<SampleVO> queryById(int id) {
        return JsonVO.success(service.getById(id));
    }
}

