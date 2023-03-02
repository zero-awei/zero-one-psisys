package com.zeroone.star.prepayment.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.prepayment.entity.FinPayment;
import com.zeroone.star.prepayment.entity.FinPaymentEntry;
import com.zeroone.star.prepayment.mapper.FinPaymentEntryMapper;
import com.zeroone.star.prepayment.mapper.FinPaymentMapper;
import com.zeroone.star.prepayment.service.IFinPaymentEntryService;
import com.zeroone.star.prepayment.service.IFinPaymentReqService;
import com.zeroone.star.prepayment.service.IFinPaymentService;
import com.zeroone.star.prepayment.service.IPrepaymentService;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.dto.prepayment.*;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.prepayment.*;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.util.List;
import java.util.Random;

import com.zeroone.star.prepayment.entity.FinPaymentReq;
import com.zeroone.star.prepayment.entity.PurOrder;
import com.zeroone.star.prepayment.service.*;
import com.zeroone.star.project.query.prepayment.DocListQuery;
import com.zeroone.star.project.query.prepayment.PreDetQuery;

import java.util.ArrayList;

/**
 * 付款单 服务类
 * author forever爱
 * since 2023-02-13
 */
@Service
public class PrepaymentServiceImpl extends ServiceImpl<FinPaymentEntryMapper, FinPaymentEntry> implements IPrepaymentService {

    @Resource
    IFinPaymentService finPaymentService;
    @Resource
    IFinPaymentEntryService finPaymentEntryService;
    @Resource
    IFinPaymentReqService finPaymentReqService;
    @Resource
    IPurOrderService purOrderService;
    @Resource
    FinPaymentMapper finPaymentMapper;
    @Resource
    FinPaymentEntryMapper finPaymentEntryMapper;

    /**
     * 修改采购预付单
     * 步骤：
     *  1、finPayment表   数据修改
     *  2、finPaymentEntry表 数据修改
     *  3、判断是
     *  3、finPaymentEntry表 插入数据列表
     *  4、判断是否成功，如果成功
     *  5、如果失败
     * param modifyDTO 修改DTO
     * return
     * author forever爱
     */
    @Override
    @Transactional
    public JsonVO<String> modifyById(ModifyDTO modifyDTO, UserDTO userDTO) {
        //1、finPayment表中数据修改
        finPaymentService.updateById(modifyDTO,userDTO);
        //2、finPaymentEntry表中数据修改
        boolean flag = finPaymentEntryService.updateById(modifyDTO);
        //3、判断成功还是失败
        if (flag){
            return JsonVO.success("修改成功");
        }
        return JsonVO.fail("修改失败");
    }

    /**
     * 审核采购预付单功能
     * author forever爱
     * since 2023-02-13
     */
    @Override
    public JsonVO<String> auditById(AuditDTO auditDTO, UserDTO userDTO) {
        return finPaymentService.auditById(auditDTO,userDTO);
    }

    /**
     * 单据分页查询
     * 采购预付（有申请）：payment_type 2011
     * 采购预付（无申请）：payment_type 2010
     * author husj
     * since 2023-02-13
     */
    @Override
    public PageVO<DocListVO> queryAll(DocListQuery condition) {
        return finPaymentService.listAll(condition);
    }


    /**
     * 根据单据编号查询信息
     * author hzp
     * since 2023-02-13
     */
    @Override
    public JsonVO<DetHavVO> queryByBillHav(PreDetQuery condition) {
        //根据查询条件里的单据编号去fin_payment查询对应付款单据
        FinPayment finPayment = finPaymentService.getByBillNo(condition.getBillNo());
        //根据fin_payment_entry表mid对应fin_payment中id查询对应明细,且对应fin_payment_req表
        List<FinPaymentEntry> finPaymentEntrys = finPaymentEntryService.listByMid(finPayment.getId(),"FinPaymentReq");
        //判空
        if(finPaymentEntrys==null){
            DetHavVO detHavVO = new DetHavVO();
            BeanUtil.copyProperties(finPayment,detHavVO);
            return JsonVO.success(detHavVO);
        }
        //明细单中的src_bill_id对应申请单中的id查询对应申请单
        FinPaymentReq finPaymentReq = finPaymentReqService.getBySrcBillId(finPaymentEntrys.get(0).getSrcBillId());
        //非空判断
        if(finPaymentReq==null){
            finPaymentReq=new FinPaymentReq();
        }
        //构建明细单列表VO
        List<FinPaymentEntryVO> finPaymentEntryVOList = new ArrayList<>();
        for (FinPaymentEntry finPaymentEntry : finPaymentEntrys) {
            FinPaymentEntryVO finPaymentEntryVO = new FinPaymentEntryVO();
            BeanUtil.copyProperties(finPaymentEntry,finPaymentEntryVO);
            finPaymentEntryVO.setSrcBillNo(finPaymentReq.getBillNo());
            finPaymentEntryVOList.add(finPaymentEntryVO);
        }
        FinPaymentReqVO finPaymentReqVO = new FinPaymentReqVO();
        BeanUtil.copyProperties(finPaymentReq,finPaymentReqVO);
        DetHavVO detHavVO = new DetHavVO();
        BeanUtil.copyProperties(finPayment,detHavVO);
        detHavVO.setReq(finPaymentReqVO);
        detHavVO.setListDetail(finPaymentEntryVOList);
        return JsonVO.success(detHavVO);
    }

    @Override
    public JsonVO<DetNoVO> queryByBillNo(PreDetQuery condition) {
        //根据查询条件里的单据编号去fin_payment查询对应付款单据
        FinPayment finPayment = finPaymentService.getByBillNo(condition.getBillNo());
        //根据fin_payment_entry表mid对应fin_payment中id查询对应明细，且对应Pur_Order
        List<FinPaymentEntry> finPaymentEntrys = finPaymentEntryService.listByMid(finPayment.getId(),"PurOrder");
        //判空
        if(finPaymentEntrys==null){
            DetNoVO detNoVO = new DetNoVO();
            BeanUtil.copyProperties(finPayment,detNoVO);
            return JsonVO.success(detNoVO);
        }
        //明细单中的src_bill_id对应申请单中的id查询对应采购单
        PurOrder purOrder = purOrderService.getBySrcBillId(finPaymentEntrys.get(0).getSrcBillId());
        //非空判断
        if(purOrder==null){
            purOrder = new PurOrder();
        }
        //构建明细单列表和返回VO
        List<FinPaymentEntryVO> finPaymentEntryVOList = new ArrayList<>();
        for (FinPaymentEntry finPaymentEntry : finPaymentEntrys) {
            FinPaymentEntryVO finPaymentEntryVO = new FinPaymentEntryVO();
            BeanUtil.copyProperties(finPaymentEntry,finPaymentEntryVO);
            finPaymentEntryVO.setSrcBillNo(purOrder.getBillNo());
            finPaymentEntryVOList.add(finPaymentEntryVO);
        }
        PurOrderVO purOrderVO = new PurOrderVO();
        BeanUtil.copyProperties(purOrder,purOrderVO);
        DetNoVO detNoVO = new DetNoVO();
        BeanUtil.copyProperties(finPayment,detNoVO);
        detNoVO.setListDetail(finPaymentEntryVOList);
        detNoVO.setPurOrder(purOrderVO);
        return JsonVO.success(detNoVO);
    }

    @Override
    public ResponseEntity<byte[]> download() {
        return null;
    }

    @Override
    public JsonVO<String> downloadUrl() {
        return null;
    }

    /**
     * 删除功能
     * author 出运费
     */
    @Override
    @Transactional
    public JsonVO<String> deleteById(DeleteDTO deleteDTO) {
//        //(不清楚具体数字代表什么处理状态 所以这一步先省略)
//        //获取处理状态
        String billStage = finPaymentMapper.selectById(deleteDTO.getId()).getBillStage();
        //只有编制中的可以删除
        if ("12".equals(billStage)){
            int i = finPaymentMapper.deleteById(deleteDTO.getId());
            int mid = finPaymentEntryMapper.delete(new QueryWrapper<FinPaymentEntry>().eq("mid", deleteDTO.getId()));
            if (i > 0&&mid > 0){
                return JsonVO.success("删除成功！");
            }else {
                return JsonVO.fail("删除失败！");
            }
        }
        return JsonVO.fail("删除失败！");
    }

    /**
     * 采购预付款操作
     * param prepaymentDTO
     * return
     * author 空
     */
    @Override
    @Transactional
    public JsonVO<String> prepay(PrepaymentDTO prepaymentDTO,UserDTO userDTO) {
        //生成19位id
        long timestamp1 = System.currentTimeMillis(); // 毫秒级时间戳
        int randNum1 = new Random().nextInt(1000000000); // 生成9位随机数
        String uniqueId1 = timestamp1 + String.format("%09d", randNum1); // 将时间戳和随机数拼接起来
        String id1 = uniqueId1.substring(0, 19);// 截取前19位作为最终的唯一ID
        prepaymentDTO.setId(id1);
        finPaymentService.insert(prepaymentDTO,userDTO);
        int res = finPaymentEntryService.insert(prepaymentDTO);
        if (res == 1){
            return JsonVO.success("修改成功");
        }
        return JsonVO.fail("修改失败");
    }


    @Override
    public JsonVO<List<SupplierVO>> querySupplierList() {
        return null;
    }

    @Override
    public JsonVO<PageVO<PaymentReqEntryVO>> queryAllByBillNo(String billNo) {
        return null;
    }

    @Override
    public JsonVO<String> excelImport(MultipartFile file) {
        return null;
    }

    /**
     * 关闭功能
     * author yuhang
     */
    @Override
    public JsonVO<String> closeById(String id,UserDTO userDTO) {
        return finPaymentService.closeById(id,userDTO);
    }

    /**
     * 反关闭功能
     * author yuhang
     */
    @Override
    public JsonVO<String> uncloseById(String id,UserDTO userDTO) {
        return finPaymentService.uncloseById(id, userDTO);
    }

    /**
     * 作废功能
     * author yuhang
     */
    @Override
    public JsonVO<String> voidById(String id,UserDTO userDTO) {
        return finPaymentService.voidById(id, userDTO);
    }
}
