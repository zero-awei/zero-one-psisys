package com.zeroone.star.systemmanagement.service.addressbook.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.query.systemmanagement.addressbook.AddressbookQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.addressbook.AddressbookVO;
import com.zeroone.star.systemmanagement.entity.addressbook.Addressbook;
import com.zeroone.star.systemmanagement.mapper.addressbook.AddressbookMapper;
import com.zeroone.star.systemmanagement.service.addressbook.IAddressbookService;
import org.apache.logging.log4j.util.Strings;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;

/**
 * <p>
 * 描述：通讯录业务层实现类
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 西柚珍珠蜜
 * @version 1.0.0
 */
@Service
@Transactional
public class AddressbookServiceImpl extends ServiceImpl<AddressbookMapper, Addressbook> implements IAddressbookService {

    @Resource
    private AddressbookMapper mapper;



    @Override
    public PageVO<AddressbookVO> listAddressbook(AddressbookQuery query) {
        // 构建分页对象
        Page<Addressbook> addressBookPage = new Page<>(query.getPageIndex(), query.getPageSize());
        // 执行查询
        Page<Addressbook> result = mapper.listAddressbook(addressBookPage,query);
        return PageVO.create(result, AddressbookVO.class);
    }

    @Override
    public PageVO<AddressbookVO> getByRealnameOrWorkNo(AddressbookQuery query) {
        // 执行查询
        Page<Addressbook> addressBookPage = new Page<>(query.getPageIndex(), query.getPageSize());
        // 构建查询条件
        Page<Addressbook> result = mapper.getByRealnameOrWorkNo(addressBookPage,query);
        return PageVO.create(result, AddressbookVO.class);
    }
}
