package com.zeroone.star.prepayment.service;

import com.zeroone.star.prepayment.entity.BasBankAccount;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.vo.prepayment.BasBankAccountVO;

import java.util.List;

/**
 * <p>
 * 银行账户 服务类
 * </p>
 *
 * @author Kong
 * @since 2023-02-17
 */
public interface IBasBankAccountService extends IService<BasBankAccount> {

    /**
     * 获取银行账户列表
     * @return BasBankAccountVO 银行账户显示对象
     * @author 空
     */
    public List<BasBankAccountVO> getBasBankAccountList();
}
