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
import org.apache.poi.ss.formula.functions.T;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.math.BigDecimal;
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
    //匹配查询条件的列名
    private static Map<String,String> advanceQuery ;
    static {
        advanceQuery = new HashMap<>();
        advanceQuery.put("编码","code");
        advanceQuery.put("名称","name");
        advanceQuery.put("简称","short_name");
        advanceQuery.put("辅助名称","aux_name");
        advanceQuery.put("客户分类","customer_category");
        advanceQuery.put("客户等级","customer_category");
        advanceQuery.put("纳税规模","tax_scale");
        advanceQuery.put("欠款额度","credit_quota");
        advanceQuery.put("所属总公司","headquarters");
        advanceQuery.put("所属地区","area");
        advanceQuery.put("业务区域","biz_area");
        advanceQuery.put("客户地址","address");
        advanceQuery.put("客户网址","website");
        advanceQuery.put("法人代表","legal_person");
        advanceQuery.put("法人电话","legal_person_phone");
        advanceQuery.put("财务信息联系人","financial_contacts");
        advanceQuery.put("财务信息联系电话","financial_phone");
        advanceQuery.put("开票信息单位名称","invoice_company");
        advanceQuery.put("开票信息税号","invoice_tax_code");
        advanceQuery.put("开票信息开户行","invoice_bank_name");
        advanceQuery.put("开票信息行号","invoice_bank_code");
        advanceQuery.put("开票信息账号","invoice_account");
        advanceQuery.put("开票信息联系电话","invoice_phone");
        advanceQuery.put("开票地址","invoice_address");
        advanceQuery.put("办款资料单位名称","payment_company");
        advanceQuery.put("办款资料开户行","payment_bank_name");
        advanceQuery.put("办款资料行号","payment_bank_code");
        advanceQuery.put("办款资料账号","payment_account");
        advanceQuery.put("收件信息收件人","recv_name");
        advanceQuery.put("收件信息联系电话","recv_phone");
        advanceQuery.put("收件信息传真","recv_fax");
        advanceQuery.put("收件信息Email","recv_email");
        advanceQuery.put("收件信息地址","recv_address");
        advanceQuery.put("收件信息邮编","recv_postcode");
        advanceQuery.put("启用","is_enabled");
        advanceQuery.put("备注","remark");

    }

    @Override
    /**
    查询指定的客户
     @parm
     @return CustomerVO
    */
    public CustomerShowVO getByCode(String code) {
        QueryWrapper<Customer> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("code",code);
        Customer customer = customerMapper.selectOne(queryWrapper);
        //Customer customer = customerMapper.selectById(id);
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
     * 根据条件进行分页查询客户
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

        //构造page<Customer>对象
        Page<Customer> customerVOPage = new Page<>(query.getPageIndex(), query.getPageSize());
        //构造条件查询对象
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
        //处理客户等级和客户
        codeToname(customerListnew);
        //返回PageVO对象
        return PageVO.create(customerList,CustomerShowVO.class);

    }
    /**
     * 根据高级条件进行分页查村客户
     * @param customerCdvancedQuery 高级查询条件对象
     * @return PageVO<CustomerShowVO> 分页对象
     * */
    @Override
    public PageVO<CustomerShowVO> getByAdvancedCondition(CustomerCdvancedQuery customerCdvancedQuery) {
        //生成一个条件查询
        QueryWrapper<Customer> wrapper = new QueryWrapper<>();
        //解析前端传过来的是否是规范输入
        boolean issql = isVaildSQL(customerCdvancedQuery.getAdvencedQuery(),wrapper);
        //规范数据，进行分页查询
        if(issql){
            //构造page<Customer>对象
            Page<Customer> customerVOPage = new Page<>(customerCdvancedQuery.getPageIndex(), customerCdvancedQuery.getPageSize());
            Page<Customer> customerList = customerMapper.selectPage(customerVOPage,wrapper);
            List<Customer> customerListnew =  customerList.getRecords();
            //处理客户等级和客户
            codeToname(customerListnew);
            //返回PageVO对象
            return PageVO.create(customerList,CustomerShowVO.class);
        }
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
    /**
     * 处理高级查询条件的字符串，判断是否能生合法的条件查询的QueryWrapper
     * @param s 高级查询条件的字符串
     * @param wrapper 条件查询对象
     * @return boolean 是否能生成
    **/
    public static boolean isVaildSQL(String s, QueryWrapper<Customer> wrapper){
        //处理字符串,找到每一个条件
        int slow = 0;
        int quick = 0;
        s = s.trim();
        //分析字符串
        while (quick<s.length()){
            //找到一个条件
            //条件名：[]
            if(s.charAt(quick) == ']'&&s.charAt(slow) == '['){
                String name = s.substring(slow+1,quick).trim();
                //非法name
                if(!advanceQuery.containsKey(name)){
                    return false;
                }
                else{
                    //要转换成值
                    name = advanceQuery.get(name);
                    slow = quick;//s[slow] = s[quick] =']'
                    //获取条件,s[slow] = ']',s[quick] = '['
                    while(quick<s.length()&&s.charAt(quick)!='['){
                        quick++;
                    }
                    //条件也要匹配
                    String condition = s.substring(slow+1,quick).trim();
                    //获取条件值s[slow] = '[',s[quick] = '['
                    slow = quick;
                    while (quick<s.length()&&s.charAt(quick)!=']'){
                        quick++;
                    }
                    String value = s.substring(slow+1,quick).trim();
                    //构造查询
                    if(name!=null&&condition!=null&&value!=null){
                        boolean flag = toWrapper(name,condition,value,wrapper);
                        slow = quick;

                        //连接逻辑运算
                        if(flag){
                            //最后一个子查询了，可以返回了(只有这个是合法返回值)
                            if(quick == s.length()-1){
                                return  true;
                            }
                            while (quick<s.length()&&s.charAt(quick)!='['){
                                quick++;
                            }
                            String and_or = s.substring(slow+1,quick);
                            if(and_or.equals("or")){
                                wrapper.or();
                            }
                            //非法查询
                            if(!and_or.equals("or")&&!and_or.equals("and")){
                                return false;
                            }
                        }
                        //非法查询
                        else {
                            return false;
                        }
                    }

                    slow = quick;//s[slow] = '[',s[quick] = '['
                }

            }
            //完成一个条件找下一个条件或者是在找第一个条件
            quick++;
        }
        //如果一个都匹配不上，非法输入
        return false;




    }
    /**
     * 进行查询条件的生成
     * @param name 进行条件查询的名字
     * @param condition 进行怎样的条件查询
     * @param value 进行条件查询的条件值
     * @param wrapper QueryWrapper对象
     * */
    public static boolean toWrapper(String name, String condition, String value, QueryWrapper<Customer> wrapper){
        //等于查询
        if(condition.equals("等于")){
            wrapper.eq(name,value);
            return true;
        }

        //大于查询
        if (condition.equals("大于")){
            wrapper.gt(name,value);
            return true;
        }
        //大于等于查询
        if (condition.equals("大于等于")){
            wrapper.ge(name,value);
            return true;
        }
        //小于查询
        if(condition.equals("小于")){
            wrapper.lt(name,value);
            return true;
        }
        //小于等于的查询
        if(condition.equals("小于等于")){
            wrapper.le(name,value);
            return true;
        }
        //不等于的查询
        if(condition.equals("不等于")){
            wrapper.ne(name,value);
            return true;
        }
        //以开头
        if(condition.equals("以开头")){
            wrapper.likeLeft(name,value);
            return true;
        }
        //以结尾
        if(condition.equals("以结尾")){
            wrapper.likeRight(name,value);
            return true;
        }
        //包含
        if(condition.equals("包含")){
            wrapper.like(name,value);
            return true;
        }
        //在...之中查询
        if(condition.equals("在之中")){
            //要处理value先，先检查是不是以逗号的形式分隔（如果不存在，就是非法查询）
            StringBuilder s = new StringBuilder();
            int count = 0;
            int start = 0;
            int end = 0;
            //构造查询得条件[value1,value2,value3.....]
            while (end<value.length()){
                if(value.charAt(end)==','){
                    //逗号之间是空字符，直接跳过
                    if(end-start<=1){
                        end++;
                        continue;
                    }
                    s.append("'");
                    s.append(value.substring(start,end));
                    s.append("'");
                    s.append(",");
                    count+=1;
                    start = end+1;
                }
               end++;
                //最后一个条件值,就不用加逗号了
                if(end == value.length()-1){
                    s.append("'");
                    //左闭右开
                    s.append(value.substring(start,end+1));
                    s.append("'");
                }
            }
            wrapper.inSql(name,value);
            return true;

        }
        //非法condition，一个都匹配不上
        return false;
    }
    /**
     * 把客户对象中的等级和分类的编码转换成名称
     * @param  customerListnew 客户对象数组
     * */
    private  void codeToname(List<Customer> customerListnew){
        //使用List来接受查询level和cate对象
        List<CusCategory> cusCategoryList = cusCategoryMapper.selectList(null);
        List<CusLevel> cusLevelList = cusLevelMapper.selectList(null);
        //map<CusCategory.getId,CusCategory.getName>
        Map<String,String> cusCategorymap= cusCategoryList.stream().collect(Collectors.toMap(CusCategory::getId,CusCategory::getName));
        Map<String,String> cuslevelmap = cusLevelList.stream().collect(Collectors.toMap(CusLevel::getId,CusLevel::getName));
        //对每一个customer进行客户种类和客户等级的赋值
        for(Customer c:customerListnew){
            if(c.getCustomerCategory()!=null){
                c.setCustomerCategory(cusCategorymap.get(c.getCustomerCategory()));
            }
            if(c.getCustomerLevel()!=null){
                c.setCustomerLevel(cuslevelmap.get(c.getCustomerLevel()));
            }
        }

    }
}
