package com.zeroone.star.payablemanagement.controller;

import com.zeroone.star.payablemanagement.service.IFinPayableService;
import com.zeroone.star.project.dto.payablemanagement.PayableDTO;
import com.zeroone.star.project.dto.payablemanagement.PayableStatusDTO;
import com.zeroone.star.project.payablemanagement.OtherPayableApis;
import com.zeroone.star.project.query.payablemanagement.PayableQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payablemanagement.PayableVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;

@RestController
@RequestMapping("/payablemanagement/othermanagement")
@Api(tags = "应付管理-其他应付")
public class OtherPayableController implements OtherPayableApis {
    @Resource
    IFinPayableService service;

    @GetMapping("query-all")
    @ApiOperation(value = "根据条件分页查询")
    @Override
    public JsonVO<PageVO<PayableVO>> queryAll(PayableQuery condition) {
        return JsonVO.success(service.queryAll(condition));
    }


    @GetMapping("query-one")
    @ApiOperation(value = "示例单据编号查询")
    @Override
    public JsonVO<PayableVO> queryByBillNo(String bill_no) {
        return JsonVO.success(service.getByBillNo(bill_no));
    }

    @PostMapping("/export")
    @ApiOperation(value = "其他应付导出功能")
    public JsonVO<String> fileExport() {
        return null;
    }

    @PostMapping("/import")
    @ApiOperation(value = "其他应付导入功能")
    public JsonVO<String> fileImport(MultipartFile file) {
        return null;
    }


    @PostMapping(value = "addOtherPayable")
    @ApiOperation(value = "添加其他应付单")
    @Override
    public JsonVO<String> addOtherPayable(PayableDTO create) {

        return service.addOtherPayable(create) > 0 ? JsonVO.success("新增保存成功") : JsonVO.fail("新增保存失败");
    }

    @PutMapping(value = "updateOtherPayable")
    @ApiOperation(value = "修改其他应付单")
    @Override
    public JsonVO<String> updateOtherPayable(PayableDTO update) {

        return service.updateOtherPayable(update) > 0 ? JsonVO.success("编辑保存成功") : JsonVO.fail("编辑保存失败");
    }

    @DeleteMapping("deleteOtherPayable}")
    @ApiOperation(value = "删除其他应付单")
    @Override
    public JsonVO<String> deleteOtherPayable(PayableDTO delete) {

        return service.delOtherPayable(delete) > 0 ? JsonVO.success("删除成功") : JsonVO.fail("删除失败");
    }

    @PutMapping(value = "updateOtherPayableStatus")
    @ApiOperation(value = "更新其他应付单状态")
    @Override
    public JsonVO<String> updateOtherPayableStatus(PayableStatusDTO payableStatus) {

        return service.updateOtherPayableStatus(payableStatus) > 0 ? JsonVO.success("更新状态成功") : JsonVO.fail("更新状态失败");
    }


}
