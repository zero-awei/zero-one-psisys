package com.zeroone.star.seata.service.impl;

import com.zeroone.star.seata.service.TransService;
import io.seata.spring.annotation.GlobalTransactional;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.Random;

/**
 * <p>
 * 描述：实现测试事务服务
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Service
@GlobalTransactional
public class TransServiceImpl implements TransService {
    @Resource
    JdbcTemplate jdbcTemplate;
    private final Random random = new Random();

    @Override
    public int saveData() {
        // 随机测试执行保存结果
        if (random.nextBoolean()) {
            String sql = "UPDATE `sample` SET `name` = '赵云', `sex` = '女', `age` = 20 WHERE `id` = 9";
            return jdbcTemplate.update(sql);
        }
        return 0;
    }
}
