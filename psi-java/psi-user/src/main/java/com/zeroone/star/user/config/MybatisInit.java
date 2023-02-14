package com.zeroone.star.user.config;


//初始化MybatisPlus插件，包括分页插件

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

@Configuration
@ComponentScan("com.zeroone.star.project.config.mybatis")
public class MybatisInit {

}
