package com.zeroone.star.payable.controller;


import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.payable.service.IFinPayableService;
import com.zeroone.star.project.dto.payable.FinPayableDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.payable.FinPayableVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

/**
 * <p>
 * 应付单 前端控制器
 * </p>
 *
 * @author chosen1
 * @since 2023-02-13
 */
@RestController
@RequestMapping("/jeecg-boot/finance/finPayable")
@Api(tags = "采购应付")
public class FinPayableController {

    @Resource
    IFinPayableService payableService;

    @GetMapping("list/201")
    @ApiOperation("分页查询")
    public JsonVO<Page<FinPayableVO>> listAll(FinPayableDTO payableDTO) {
        return payableService.listAll(payableDTO);
    }

    @GetMapping("sigle/{id}")
    @ApiOperation("单据详情")
    public JsonVO<FinPayableVO> sigleById(@RequestParam("id") String id) {
        return payableService.getById(id);
    }

}

