package com.zeroone.star.prepayment.service.impl;

import com.zeroone.star.prepayment.entity.BasBankAccount;
import com.zeroone.star.prepayment.mapper.BasBankAccountMapper;
import com.zeroone.star.prepayment.service.IBasBankAccountService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 银行账户 服务实现类
 * </p>
 *
 * @author Kong
 * @since 2023-02-17
 */
@Service
public class BasBankAccountServiceImpl extends ServiceImpl<BasBankAccountMapper, BasBankAccount> implements IBasBankAccountService {

}
