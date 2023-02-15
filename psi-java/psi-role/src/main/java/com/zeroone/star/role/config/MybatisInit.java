package com.zeroone.star.role.config;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

/**
 * 初始化mp插件
 * 包括了分页插件
 */
@Configuration
@ComponentScan("com.zeroone.star.project.config.mybatis") // 扫描组件
public class MybatisInit {

}
