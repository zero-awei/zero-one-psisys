package com.zeroone.star.basedetail.service.customermanagement.impl;

import cn.hutool.core.bean.BeanUtil;
import cn.hutool.core.bean.copier.CopyOptions;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.metadata.IPage;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.basedetail.entity.customermanagement.CusCategory;
import com.zeroone.star.basedetail.entity.customermanagement.CusLevel;
import com.zeroone.star.basedetail.entity.customermanagement.Customer;
import com.zeroone.star.basedetail.mapper.customermanagement.CusCategoryMapper;
import com.zeroone.star.basedetail.mapper.customermanagement.CusLevelMapper;
import com.zeroone.star.basedetail.mapper.customermanagement.CustomerMapper;
import com.zeroone.star.basedetail.service.customermanagement.ICustomerService;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.query.basedetail.customermanagement.CustomerCdvancedQuery;
import com.zeroone.star.project.query.basedetail.customermanagement.CustomerQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.basedetail.customermanagement.CustomerShowVO;
import com.zeroone.star.project.vo.basedetail.customermanagement.CustomerVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * <p>
 * 客户 服务实现类
 * </p>
 *
 * @author yizhiyang
 * @since 2023-02-13
 */
@Service

public class CustomerServiceImpl extends ServiceImpl<CustomerMapper,Customer> implements ICustomerService {
    @Autowired
    private CustomerMapper customerMapper;
    @Autowired
    private CusCategoryMapper cusCategoryMapper;
    @Autowired
    private CusLevelMapper cusLevelMapper;
    //用于匹配大写字母
    private static Pattern humpPattern = Pattern.compile("[A-Z]");
    @Override
    /**
    查询指定的客户
     @parm id
     @return CustomerVO
    */
    public CustomerShowVO getById(String id) {
        /*多表查询的方法*/
        /*Customer customer = customerMapper.getCustomerById(id);
        if(customer!=null){
            System.out.println(customer.toString());
            //CustomerVO customervo = BeanUtil.copyProperties(customer, CustomerVO.class);
            CustomerVO customervo = copyCustomerToCutomerVO(customer);
            System.out.println(customervo.toString());
            return customervo;
        }*/
        Customer customer = customerMapper.selectById(id);
        //要判断是否为空，虽然正常不可能传输错误（因为是点击，用户没有办法乱输入），但是怕前端传输数据失败（错误），防止程序崩溃
        if(customer!=null){
            String cate_id = customer.getCustomerCategory();
            String level_id = customer.getCustomerLevel();
            CustomerShowVO customerShowVO = copyCustomerToCutomerVO(customer);
            //这里查不到，为什么呢？因为没有导入数据库，该死
            CusCategory cusCategory = cusCategoryMapper.selectById(cate_id);
            CusLevel cusLevel  = cusLevelMapper.selectById(level_id);
            //判断非空
            if(cusCategory!=null){
                customerShowVO.setCustomerCategory(cusCategoryMapper.selectById(cate_id).getName());
            }
            if(cusLevel!=null){
                customerShowVO.setCustomerLevel(cusLevelMapper.selectById(level_id).getName());
            }
            return customerShowVO;
        }

        return null;
    }
    /**
     * 根据条件进行查询客户
     * @param query 查询条件对象
     * @return PageVO<CustomerVO> 分页对象
     */

    public PageVO<CustomerShowVO> getByCondition(CustomerQuery query){
        //直接bean转map?Map<String,String>,要过滤掉空值
        Map<String,Object> cusmap = BeanUtil.beanToMap(query,new HashMap<>(),
                CopyOptions.create().
                        setIgnoreNullValue(true));
        //接受新的map
        Map<String,Object> cusmapw = new HashMap<>();
        cusmap.remove("pageIndex");
        cusmap.remove("pageSize");
        if(cusmap.size()==0){
            return null;
        }
        //使用List来接受查询level和cate对象
        List<CusCategory> cusCategoryList = cusCategoryMapper.selectList(null);
        List<CusLevel> cusLevelList = cusLevelMapper.selectList(null);
        Map<String,String> cusCategorymap= cusCategoryList.stream().collect(Collectors.toMap(CusCategory::getId,CusCategory::getName));
        Map<String,String> cuslevelmap = cusLevelList.stream().collect(Collectors.toMap(CusLevel::getId,CusLevel::getName));
        //构造page<Customer>对象
        Page<Customer> customerVOPage = new Page<>(query.getPageIndex(), query.getPageSize());
        //构造条件查询对象,直接查？
        QueryWrapper<Customer> customerQueryWrapper = new QueryWrapper<>();
        for(String s:cusmap.keySet()){
            //实体类转成驼峰命名（为什么数据库就命名就不能也是用驼峰呢
            String new_key = humpToLine2(s);
            cusmapw.put(new_key,cusmap.get(s));
            //放入新的东西
        }
        //条件查询构造器
        customerQueryWrapper.allEq(cusmapw);
        //空的话就会报错
        Page<Customer> customerList = customerMapper.selectPage(customerVOPage,customerQueryWrapper);
        List<Customer> customerListnew =  customerList.getRecords();
        for(Customer c:customerListnew){
                if(c.getCustomerCategory()!=null){
                    c.setCustomerCategory(cusCategorymap.get(c.getCustomerCategory()));
                }
                if(c.getCustomerLevel()!=null){
                    c.setCustomerLevel(cuslevelmap.get(c.getCustomerLevel()));
                }
        }
        //customerList.setRecords(customerListnew);
        PageVO<CustomerShowVO> customerVOPageVO = PageVO.create(customerList,CustomerShowVO.class);
        return customerVOPageVO;

    }

    @Override
    public PageVO<CustomerShowVO> getByAdvancedCondition(CustomerCdvancedQuery customerCdvancedQuery) {
        return null;
    }

    /**
     * 把customer对象的属性赋值给 CustomerVO对象，方便list的转
     * @param customer cutomer对象
     * @return CustomerVO对象
     */
    private static CustomerShowVO copyCustomerToCutomerVO(Customer customer){
        CustomerShowVO customervo = new CustomerShowVO();
         BeanUtil.copyProperties(customer, customervo,
                CopyOptions.create().setIgnoreNullValue(true).setIgnoreError(true));
        return customervo;
    }
    /**
     * 把Query的属性字段驼峰名转成数据库的下划线命名
     * @param str cutomer对象
     * @return String
     */
    public static String humpToLine2(String str) {
        Matcher matcher = humpPattern.matcher(str);
        StringBuffer sb = new StringBuffer();
        while (matcher.find()) {
            matcher.appendReplacement(sb, "_" + matcher.group(0).toLowerCase());
        }
        matcher.appendTail(sb);
        return sb.toString();
    }
}
