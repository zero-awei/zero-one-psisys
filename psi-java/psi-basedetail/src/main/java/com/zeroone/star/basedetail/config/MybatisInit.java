package com.zeroone.star.basedetail.config;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

/**
 * @Description
 * @Author 苏乞儿
 * @Date 2023/2/10
 */
@Configuration
@ComponentScan({
        "com.zeroone.star.project.config.mybatis"
})
public class MybatisInit {
}
