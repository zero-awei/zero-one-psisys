package com.zeroone.star.prepayment.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.prepayment.entity.BasBankAccount;
import com.zeroone.star.prepayment.mapper.BasBankAccountMapper;
import com.zeroone.star.prepayment.service.IBasBankAccountService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.vo.prepayment.BasBankAccountVO;
import com.zeroone.star.project.vo.prepayment.SysDepartVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

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

    @Autowired
    BasBankAccountMapper bankAccountMapper;

    @Override
    public List<BasBankAccountVO> getBasBankAccountList() {
        QueryWrapper<BasBankAccount> queryWrapper = new QueryWrapper<>();
        List<BasBankAccount> basBankAccounts = bankAccountMapper.selectList(queryWrapper);

        //封装成vo
        ArrayList<BasBankAccountVO> basBankAccountVOS = new ArrayList<>();
        for (BasBankAccount bankAccount:basBankAccounts){
            BasBankAccountVO bankAccounttVO = new BasBankAccountVO(bankAccount.getId(),bankAccount.getAccountNo(),bankAccount.getAccountNo(),bankAccount.getAccountNo());
            basBankAccountVOS.add(bankAccounttVO);
        }

        return basBankAccountVOS;
    }
}
