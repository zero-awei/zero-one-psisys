package com.zeroone.star.prepayment.service;
import com.zeroone.star.prepayment.entity.FinPayment;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.dto.prepayment.AuditDTO;
import com.zeroone.star.project.dto.prepayment.ModifyDTO;
import com.zeroone.star.project.dto.prepayment.PrepaymentDTO;
import com.zeroone.star.project.query.prepayment.DocListQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.prepayment.DocListVO;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.stereotype.Component;

import javax.jws.soap.SOAPBinding;

/**
 * <p>
 * 付款单 服务类
 * </p>
 *
 * @author zhd
 * @since 2023-02-18
 */
@Component
public interface IFinPaymentService extends IService<FinPayment> {


    /**
     * 修改付款单
     * author forever爱
     */
    public boolean updateById(ModifyDTO modifyDTO, UserDTO userDTO);
    /**
     * 审核采购预付单功能
     * param auditDTO 审核DTO
     * return 查询结果
     * author forever爱
     */
    JsonVO<String> auditById(AuditDTO auditDTO, UserDTO userDTO);

    /**
     * 添加付款单
     * param prepaymentDTO
     * return
     * author KONG
     */
    public int insert(PrepaymentDTO prepaymentDTO, UserDTO userDTO);

    PageVO<DocListVO> listAll(DocListQuery condition);

    /**
     * 根据单据编号查询指定付款单
     * param billNo 单据编号
     * return 查询结果
     * author hzp
     */
    FinPayment getByBillNo(String billNo);


    /**
     * 根据id查询付款单
     * author yuhang
     */
    public FinPayment selectById(String id);

    /**
     * 关闭功能
     * author yuhang
     */
    public JsonVO<String> closeById(String id,UserDTO userDTO);

    /**
     * 反关闭功能
     * author yuhang
     */
    public JsonVO<String> uncloseById(String id,UserDTO userDTO);

    /**
     * 作废功能
     * author yuhang
     */
    public JsonVO<String> voidById(String id,UserDTO userDTO);

}
