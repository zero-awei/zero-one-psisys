package com.zeroone.star.login.config;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

/**
 * @author Gerins
 * Login模块 Redis配置类
 * 将Common模块的Redis Bean进行注入
 */
@Configuration
@ComponentScan({"com.zeroone.star.project.config.redis", "com.zeroone.star.project.utils.redis"})
public class RedisInit {
}
