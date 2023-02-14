package com.zeroone.star.project.payment;

import com.zeroone.star.project.dto.payment.ModifyDTO;
import com.zeroone.star.project.vo.JsonVO;

import com.zeroone.star.project.query.payment.DocListQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payment.DocListVO;


import com.zeroone.star.project.query.payment.PreDetQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.payment.DetHavVO;
import com.zeroone.star.project.vo.payment.DetNoVO;

import com.zeroone.star.project.vo.JsonVO;
import org.springframework.http.ResponseEntity;

/**
 * <p>
 * 描述：API接口定义
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author forever爱
 * @version 1.0.0
 */
public interface PaymentApis {
    /**
     * 修改采购预付单功能
     * param modifyDTO 带明细表的收款单DTO
     * return 查询结果
     * author forever爱
     */
    JsonVO<String> modifyById(ModifyDTO modifyDTO);

    /**
     * 单据列表查询
     * param condition 查询条件
     * return 查询结果
     * author husj
     * version 1.0.0
     */
    JsonVO<PageVO<DocListVO>> queryAll(DocListQuery condition);

    /**
     * 通过单据编号查询数据-采购预付有申请
     * param condition 单据编号-查询条件
     * return 查询结果
     * author hzp
     */
    JsonVO<DetHavVO> queryByBillHav(PreDetQuery condition);

    /**
     *通过单据编号查询数据-采购预付无申请
     * param condition 单据编号-查询条件
     * return 查询结果
     * author hzp
     */
    JsonVO<DetNoVO> queryByBillNo (PreDetQuery condition);

    /**
     * 获取导出文件
     * return 返回响应对象
     * author 明破
     */
    ResponseEntity<byte[]> download();

    /**
     * 获取导出链接
     * return 返回下载路径
     * author 明破
     */
    JsonVO<String> downloadUrl();
}
