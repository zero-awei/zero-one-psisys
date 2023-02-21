package com.zeroone.star.payablemanagement.controller;


import com.zeroone.star.project.dto.payablemanagement.CheckPayableDTO;
import com.zeroone.star.project.payablemanagement.CheckPayableApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.springframework.web.bind.annotation.*;

import java.util.List;

/**
 * <p>
 * 应付核销单 前端控制器
 * </p>
 *
 * @author The end
 * @since 2023-02-14
 */
@RestController
@RequestMapping("/payable/check")
@Api(tags = "应付管理-应付核销")
public class CheckPayableController implements CheckPayableApis {

    @ApiOperation("新增应付核销单")
    @PostMapping("/save")
    @Override
    public JsonVO<Void> addPayableCheck(@RequestBody CheckPayableDTO dto) {
        return null;
    }

    @ApiOperation("修改应付核销单")
    @PutMapping("/modify")
    @Override
    public JsonVO<Void> modifyPayableCheck(@RequestBody CheckPayableDTO dto) {
        return null;
    }

    @ApiOperation("关闭应付核销单（批量）")
    @PutMapping("/close")
    @Override
    public JsonVO<Void> closePayableCheck(@ApiParam("单据id集合") @RequestParam List<String> ids) {
        return null;
    }

    @ApiOperation("反关闭应付核销单（批量）")
    @PutMapping("/unclose")
    @Override
    public JsonVO<Void> unclosePayableCheck(@ApiParam("单据id集合") @RequestParam List<String> ids) {
        return null;
    }

    @ApiOperation("删除应付核销单（批量）")
    @DeleteMapping("/delete")
    @Override
    public JsonVO<Void> deletePayableCheck(@ApiParam("单据id集合") @RequestParam List<String> ids) {
        return null;
    }

    @ApiOperation("审核应付核销单")
    @PutMapping("/check")
    @Override
    public JsonVO<Void> checkPayableCheck(@ApiParam("单据id") @RequestParam String id,
        @ApiParam("核批结果") String approvalResultType,
        @ApiParam(value = "核批意见", allowEmptyValue = true) @RequestParam(required = false) String approvalRemark) {
        return null;
    }

    @ApiOperation("作废应付核销单")
    @PutMapping("/void")
    @Override
    public JsonVO<Void> voidPayableCheck(@ApiParam("单据id") @RequestParam String id) {
        return null;
    }
}

