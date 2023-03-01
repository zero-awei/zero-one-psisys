package com.zeroone.star.payablemanagement.service;

import com.zeroone.star.payablemanagement.entity.FinPayableCheck;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.payablemanagement.CheckPayableDTO;
import com.zeroone.star.project.query.payablemanagement.CheckPayableQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payablemanagement.CheckPayableVO;
import com.zeroone.star.payablemanagement.entity.FinPayableCheck;
import com.zeroone.star.project.dto.payablemanagement.CheckPayableDTO;

import java.util.List;
import com.zeroone.star.project.query.payablemanagement.CheckPayableQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payablemanagement.CheckPayableVO;

/**
 * <p>
 * 应付核销单 服务类
 * </p>
 *
 * @author j3
 * @since 2023-02-14
 */
public interface IFinPayableCheckService extends IService<FinPayableCheck> {

    void submitAdd(CheckPayableDTO dto);

    void saveAdd(CheckPayableDTO dto);

    void submitModify(CheckPayableDTO dto);

    void saveModify(CheckPayableDTO dto);

    void removeWithEntry(List<String> ids);

    boolean isCheckPass(String id, String approvalResultType, String approvalRemark);
    /**
     * 查询单据列表
     * @param condition 查询条件
     * @return 查询结果
     * @author spk
     */
    public PageVO<CheckPayableVO> getAll(CheckPayableQuery condition);


}
