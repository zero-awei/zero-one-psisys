package com.zeroone.star.homepage.config;

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
