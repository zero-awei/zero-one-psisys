package com.zeroone.star.payment.config;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

/**
 * @Description
 * @Author forever爱
 * @Date 2023/2/10
 */
@Configuration
@ComponentScan({
        "com.zeroone.star.project.config.mybatis"
})
public class MyBatisInit {
}
