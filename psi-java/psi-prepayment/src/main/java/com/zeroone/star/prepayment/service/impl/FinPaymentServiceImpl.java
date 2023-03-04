package com.zeroone.star.prepayment.service.impl;
import cn.hutool.core.bean.BeanUtil;
import cn.hutool.core.util.IdUtil;
import com.alibaba.excel.EasyExcel;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.prepayment.entity.FinPayment;
import com.zeroone.star.prepayment.mapper.FinPaymentMapper;
import com.zeroone.star.prepayment.service.IFinPaymentService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.prepayment.AuditDTO;
import com.zeroone.star.project.dto.prepayment.ModifyDTO;
import com.zeroone.star.project.query.prepayment.DocListQuery;
import com.zeroone.star.project.utils.easyExcel.EasyExcelUtils;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.prepayment.DocListVO;
import org.springframework.stereotype.Service;
import javax.annotation.Resource;
import java.time.LocalDateTime;
import com.zeroone.star.project.dto.prepayment.PrepaymentDTO;
import org.springframework.beans.BeanUtils;
import org.springframework.web.multipart.MultipartFile;
import java.util.List;
import java.util.function.Consumer;
import cn.hutool.core.bean.BeanUtil;
import cn.hutool.core.date.DateTime;
import cn.hutool.core.util.IdUtil;
import com.alibaba.excel.EasyExcel;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.prepayment.entity.FinPayment;
import com.zeroone.star.prepayment.entity.FinPaymentEntry;

import com.zeroone.star.prepayment.mapper.FinPaymentEntryMapper;
import com.zeroone.star.prepayment.mapper.FinPaymentMapper;
import com.zeroone.star.prepayment.mapper.FinPaymentReqEntryMapper;
import com.zeroone.star.prepayment.mapper.FinPaymentReqMapper;
import com.zeroone.star.prepayment.service.IFinPaymentService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.prepayment.AuditDTO;
import com.zeroone.star.project.dto.prepayment.ModifyDTO;
import com.zeroone.star.project.query.prepayment.DocListQuery;
import com.zeroone.star.project.query.prepayment.FinPaymentExportQuery;
import com.zeroone.star.project.utils.easyExcel.EasyExcelUtils;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.prepayment.DocListVO;
import lombok.SneakyThrows;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

import java.io.ByteArrayOutputStream;
import java.nio.charset.StandardCharsets;
import java.time.LocalDateTime;

import com.zeroone.star.project.dto.prepayment.PrepaymentDTO;
import org.springframework.beans.BeanUtils;
import org.springframework.web.multipart.MultipartFile;

import java.util.ArrayList;
import java.util.List;
import java.util.function.Consumer;

/**
 * <p>
 * 付款单 服务实现类
 * </p>
 *
 * @author zhd
 * @since 2023-02-18
 */
@Service
public class FinPaymentServiceImpl extends ServiceImpl<FinPaymentMapper, FinPayment> implements IFinPaymentService {

    @Resource
    FinPaymentMapper finPaymentMapper;

    /**
     * 修改付款单
     * author forever爱
     */
    @Override
    public boolean updateById(ModifyDTO modifyDTO, UserDTO userDTO) {
        FinPayment finPayment = new FinPayment();
        BeanUtil.copyProperties(modifyDTO, finPayment);
        //时间
//        finPayment.setUpdateTime(LocalDateTime.now());
        //用户信息
        finPayment.setUpdateBy(userDTO.getUsername());
        return updateById(finPayment);
    }

    /**
     * 审核采购预付单功能
     * param auditDTO 审核DTO
     * return 查询结果
     * author forever爱
     */
    @Override
    public JsonVO<String> auditById(AuditDTO auditDTO, UserDTO userDTO) {
        FinPayment finPayment = new FinPayment();
        BeanUtil.copyProperties(auditDTO, finPayment);
        //审核生效时间、修改时间
//        finPayment.setUpdateTime(LocalDateTime.now());
//        finPayment.setEffectiveTime(LocalDateTime.now());
        //审核人、修改人信息
        finPayment.setApprover(userDTO.getUsername());
        finPayment.setUpdateBy(userDTO.getUsername());
        boolean flag = updateById(finPayment);
        if (flag) {
            return JsonVO.success("修改成功");
        }
        return JsonVO.fail("修改失败");
    }

    /**
     * 添加采购预付单
     * Author: Kong
     */
    @Override
    public int insert(PrepaymentDTO prepaymentDTO, UserDTO userDTO){
        FinPayment finPayment = new FinPayment();
        BeanUtils.copyProperties(prepaymentDTO,finPayment);
        //时间
//        finPayment.setCreateTime(LocalDateTime.now());
        //用户信息
        finPayment.setCreateBy(userDTO.getUsername());
        return finPaymentMapper.insert(finPayment);
    }

    @Override
    public PageVO<DocListVO> listAll(DocListQuery condition) {
        //构建分页对象
        Page<FinPayment> finPaymentPage = new Page<>(condition.getPageIndex(),condition.getPageSize());
        //创建查询条件
        QueryWrapper<FinPayment> finPaymentQueryWrapper = new QueryWrapper<>();
        //根据单据编号查询
        if (condition.getBillNo()!=null)finPaymentQueryWrapper.eq("bill_no",condition.getBillNo());
        //根据单据日期查询
        if(condition.getBillDateStart()!=null && condition.getBillDateEnd()!=null)
            finPaymentQueryWrapper.between("bill_date",condition.getBillDateStart(),condition.getBillDateEnd());
        else if (condition.getBillDateStart()!=null)
            finPaymentQueryWrapper.ge("bill_date",condition.getBillDateStart());
        else if(condition.getBillDateEnd()!=null)
            finPaymentQueryWrapper.le("bill_date",condition.getBillDateEnd());
        //根据单据主题查询
        if (condition.getSubject()!=null)finPaymentQueryWrapper.like("subject",condition.getSubject());
        //根据供应商查询
        if (condition.getSupplierId()!=null)finPaymentQueryWrapper.eq("supplier_id",condition.getSupplierId());
        //根据处理状态查询
        if (condition.getBillStage()!=null)finPaymentQueryWrapper.eq("bill_stage",condition.getBillStage());
        //根据是否生效查询
        if (condition.getIsEffective()!=null)finPaymentQueryWrapper.eq("is_effective",condition.getIsEffective());
        //根据是否关闭查询
        if (condition.getIsClosed()!=null)finPaymentQueryWrapper.eq("is_closed",condition.getIsClosed());
        //根据是否作废查询
        if (condition.getIsVoided()!=null)finPaymentQueryWrapper.eq("is_voided",condition.getIsVoided());
        //根据付款类型查询（即2011是有申请，2010是无申请）
        if (condition.getPaymentType()!=null)finPaymentQueryWrapper.eq("payment_type",condition.getPaymentType());
        //执行SQL
        Page<FinPayment> result = baseMapper.selectPage(finPaymentPage, finPaymentQueryWrapper);
        return PageVO.create(result,DocListVO.class);
    }

    /**
     * ClassName FinPaymentServiceImpl
     * Description IFinPaymentService服务类的实现
     * Author HZP
     * Date 2023/2/18 21:48
     * Version 1.0
     **/
    @Override
    public FinPayment getByBillNo(String billNo) {
        QueryWrapper<FinPayment> FinQueryWrapper = new QueryWrapper<>();
        FinQueryWrapper.eq("bill_no", billNo);
        return baseMapper.selectOne(FinQueryWrapper);
    }

    /**
     * 根据id查询付款单
     * author yuhang
     */
    @Override
    public FinPayment selectById(String id) {
        QueryWrapper<FinPayment> FinQueryWrapper = new QueryWrapper<>();
        FinQueryWrapper.eq("id", id);
        return baseMapper.selectOne(FinQueryWrapper);
    }

    @Override
    public JsonVO<String> closeById(String id,UserDTO userDTO) {
        FinPayment finPayment = selectById(id);
        // 查询要关闭的单据信息
        if (finPayment == null) {
            return JsonVO.fail("此单据不存在!");
        }
        //单据阶段为执行中，才可以关闭
        if ("32".equals(finPayment.getBillStage())) {
            finPayment.setId(id);
            finPayment.setBillStage("33");
            finPayment.setIsClosed(1);
            finPayment.setUpdateTime(LocalDateTime.now());
            finPayment.setUpdateBy(userDTO.getUsername());
            boolean flag = updateById(finPayment);
            if (flag) {
                return JsonVO.success("修改成功");
            }
            return JsonVO.fail("修改失败");
        }
        return JsonVO.fail("单据阶段错误!");
    }

    @Override
    public JsonVO<String> uncloseById(String id,UserDTO userDTO) {
        FinPayment finPayment = selectById(id);
        // 查询要关闭的单据信息
        if (finPayment == null) {
            return JsonVO.fail("此单据不存在!");
        }
        //单据阶段为执行止或者执行完，才可以关闭
        String billStage = finPayment.getBillStage();
        if ("33".equals(billStage) || "34".equals(billStage)) {
            finPayment.setId(id);
            finPayment.setBillStage("32");
            finPayment.setIsClosed(0);
            finPayment.setUpdateTime(LocalDateTime.now());
            finPayment.setUpdateBy(userDTO.getUsername());
            boolean flag = updateById(finPayment);
            if (flag) {
                return JsonVO.success("修改成功");
            }
            return JsonVO.fail("修改失败");
        }
        return JsonVO.fail("单据阶段错误!");
    }

    @Override
    public JsonVO<String> voidById(String id,UserDTO userDTO) {
        FinPayment finPayment = selectById(id);
        // 查询要关闭的单据信息
        if (finPayment == null) {
            return JsonVO.fail("此单据不存在!");
        }
        //单据阶段为执行止或者执行完，才可以关闭
        String billStage = finPayment.getBillStage();
        if ("33".equals(billStage) || "34".equals(billStage)) {
            return JsonVO.fail("单据阶段错误!");
        }
        finPayment.setId(id);
        finPayment.setIsVoided(true);
        finPayment.setUpdateTime(LocalDateTime.now());
        finPayment.setUpdateBy(userDTO.getUsername());
        boolean flag = updateById(finPayment);
        if (flag) {
            return JsonVO.success("修改成功");
        }
        return JsonVO.fail("修改失败");
    }

    @Resource
    FinPaymentMapper paymentMapper;

    @Override
    public void importExcelOfPayment(MultipartFile file) throws Exception {
        EasyExcel.read(file.getInputStream(), FinPayment.class, EasyExcelUtils.getListener(this.process(), 2)).sheet().doRead();
    }

    // 用于获取当前登录的用户信息
    @Resource
    UserHolder userHolder;
    /**
     * 返回一个接口实现
     */
    public Consumer<List<FinPayment>> process() {
        return payments -> {
            for (FinPayment payment : payments) {
                payment.setId(IdUtil.getSnowflake().nextIdStr());
                payment.setCreateTime(LocalDateTime.now());
                try {
                    UserDTO currentUser = userHolder.getCurrentUser();
                    payment.setCreateBy(currentUser.getUsername());
                } catch (Exception e) {
                    throw new RuntimeException(e);
                }
            }
            paymentMapper.addBatch(payments);
        };
    }

    @Resource
    EasyExcelComponent excel;
    @Resource
    FastDfsClientComponent dfsClient;
    @Value("${fastdfs.nginx-servers}")
    private String serverUrl;
    @Resource
    FinPaymentMapper paymentMapper;
    @Resource
    FinPaymentEntryMapper paymentEntryMapper;

    @Override
    public void importExcelOfPayment(MultipartFile file) throws Exception {
        EasyExcel.read(file.getInputStream(), FinPayment.class, EasyExcelUtils.getListener(this.process(), 2)).sheet().doRead();
    }


    /**
     * 导出获取无申请采购预付表
     *
     * @return 无申请带有明细信息的采购预付信息列表
     */
    private List<FinPaymentExportQuery> fetchExportFinPayment(boolean isRequested) {

        // 获取主表数据
        List<FinPayment> allFinPayments;
        QueryWrapper<FinPayment> finPaymentQueryWrapper = new QueryWrapper<>();
        if (isRequested) {
            finPaymentQueryWrapper.eq("payment_type", 2011);
        } else {
            finPaymentQueryWrapper.eq("payment_type", 2010);
        }
        allFinPayments = finPaymentMapper.selectList(finPaymentQueryWrapper);

        // 初始化最终结果列表及明细查询条件
        List<FinPaymentExportQuery> results = new ArrayList<>();
        QueryWrapper<FinPaymentEntry> finPaymentEntryQueryWrapper = new QueryWrapper<>();

        // 装填最终结果数据
        for (FinPayment nowFinPayment : allFinPayments) {

            // 创建一个导出对象准备存储一行数据
            FinPaymentExportQuery temp = new FinPaymentExportQuery();
            // 将查询获取到的主表属性对应拷贝到导出实体类的属性
            BeanUtils.copyProperties(nowFinPayment, temp);
            // 对应原始数据修改显示信息
            if (isRequested) {
                temp.setIsRequested("采购预付(有申请)");
            } else {
                temp.setIsRequested("采购预付(无申请)");
            }
            temp.setIsEffective(nowFinPayment.getIsEffective() == 1 ? "是" : "否");
            temp.setIsAuto(nowFinPayment.getIsAuto() == 1 ? "是" : "否");
            temp.setIsVoided(nowFinPayment.getIsVoided() ? "是" : "否");
            temp.setIsRubric(nowFinPayment.getIsRubric() == 1 ? "是" : "否");
            temp.setIsClosed(nowFinPayment.getIsClosed() == 1 ? "是" : "否");


            // 构造明细表查询条件
            finPaymentEntryQueryWrapper.eq("mid", nowFinPayment.getId());
            // 查询明细表数据
            List<FinPaymentEntry> finPaymentEntryList = paymentEntryMapper.selectList(finPaymentEntryQueryWrapper);

            // 清空查询条件避免重复添加多个条件
            finPaymentEntryQueryWrapper.clear();

            // 将查询到的明细表属性对应拷贝到导出实体类（多条）并将其添加到最终结果列表中
            for (FinPaymentEntry entryTemp : finPaymentEntryList) {
                BeanUtils.copyProperties(entryTemp, temp);
                temp.setEid(entryTemp.getId());
                temp.setMid(entryTemp.getMid());
                temp.setEBillNo(entryTemp.getBillNo());
                temp.setESrcBillType(entryTemp.getSrcBillType());
                temp.setESrcNo(entryTemp.getSrcNo());
                temp.setEAmt(entryTemp.getAmt());
                temp.setERemark(entryTemp.getRemark());
                temp.setEVersion(entryTemp.getVersion());
                results.add(temp);
            }
        }

        return results;
    }

    /**
     * 获取导出文件
     *
     * @param isRequested 获取需要导出的信息类别(有申请/无申请?)
     * @return 导出报表文件
     */
    @SneakyThrows
    @Override
    public ResponseEntity<byte[]> download(boolean isRequested) {

        // 获取数据，参数控制是否有申请
        List<FinPaymentExportQuery> results = fetchExportFinPayment(isRequested);

        // 导出Excel
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        excel.export("采购预付单信息", out, FinPaymentExportQuery.class, results);
        // 创建响应头
        HttpHeaders headers = new HttpHeaders();
        // 构建下载文件名称
        String fileName = "fin_payment_" + DateTime.now().toString("yyyyMMddHHmmssS") + ".xlsx";
        fileName = new String(fileName.getBytes(StandardCharsets.UTF_8), StandardCharsets.ISO_8859_1);
        headers.setContentDispositionFormData("attachment", fileName);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        ResponseEntity<byte[]> result = new ResponseEntity<>(out.toByteArray(), headers, HttpStatus.CREATED);
        out.close();
        return result;

    }

    @SneakyThrows
    @Override
    public JsonVO<String> downloadUrl(boolean isRequested) {

        // 获取数据，参数控制是否有申请
        List<FinPaymentExportQuery> results = fetchExportFinPayment(isRequested);

        // 导出Excel
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        excel.export("PaymentNoRequest", out, FinPaymentExportQuery.class, results);
        // 上传到fastdfs
        String suffix = "xlsx";
        FastDfsFileInfo result = dfsClient.uploadFile(out.toByteArray(), suffix);
        //关闭输出流
        out.close();
        // 处理传递结果
        if (result == null) {
            return JsonVO.fail("文件上传失败");
        }
        // 拼接上下文地址
        String downloadUrl = dfsClient.fetchUrl(result, serverUrl, true);

        return JsonVO.success(downloadUrl);
    }

    // 用于获取当前登录的用户信息
    @Resource
    UserHolder userHolder;

    /**
     * 返回一个接口实现
     */
    public Consumer<List<FinPayment>> process() {
        return payments -> {
            for (FinPayment payment : payments) {
                payment.setId(IdUtil.getSnowflake().nextIdStr());
                payment.setCreateTime(LocalDateTime.now());
                try {
                    UserDTO currentUser = userHolder.getCurrentUser();
                    payment.setCreateBy(currentUser.getUsername());
                } catch (Exception e) {
                    throw new RuntimeException(e);
                }
            }
            paymentMapper.addBatch(payments);
        };
    }
}
