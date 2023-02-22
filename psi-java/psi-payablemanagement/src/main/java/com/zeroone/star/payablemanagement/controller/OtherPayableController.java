package com.zeroone.star.payablemanagement.controller;

import com.zeroone.star.payablemanagement.service.IFinPayableService;
import com.zeroone.star.project.dto.payablemanagement.PayableDTO;
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

    @Resource
    IFinPayableService finPayableService;

    @PostMapping(value = "addOtherPayable")
    @ApiOperation(value = "添加其他应付单")
    @Override
    public JsonVO<PayableVO> addOtherPayable(PayableDTO PayableDTO) {
        return null;
    }

    @PutMapping(value = "updateOtherPayable")
    @ApiOperation(value = "修改其他应付单")
    @Override
    public JsonVO<PayableVO> updateOtherPayable(PayableDTO PayableDTO) {
        return null;
    }

    @DeleteMapping("/{otherPayableId}")
    @ApiOperation(value = "删除其他应付单")
    @Override
    public JsonVO<PayableVO> deleteOtherPayable(Integer otherPayableId) {
        return null;
    }

    @PutMapping(value = "updateOtherPayableStatus")
    @ApiOperation(value = "更新其他应付单状态")
    @Override
    public JsonVO<PayableVO> updateOtherPayableStatus(Integer otherPayableId, String status) {
        return null;
    }


}
