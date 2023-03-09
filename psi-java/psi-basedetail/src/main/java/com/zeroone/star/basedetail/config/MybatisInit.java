package com.zeroone.star.basedetail.config;

import com.baomidou.mybatisplus.extension.plugins.MybatisPlusInterceptor;
import com.baomidou.mybatisplus.extension.plugins.inner.OptimisticLockerInnerInterceptor;
import org.springframework.context.annotation.Bean;
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
