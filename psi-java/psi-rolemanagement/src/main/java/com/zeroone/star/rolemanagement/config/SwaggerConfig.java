package com.zeroone.star.rolemanagement.config;

import com.zeroone.star.project.config.swagger.SwaggerCore;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import springfox.documentation.spring.web.plugins.Docket;
import springfox.documentation.swagger2.annotations.EnableSwagger2WebMvc;

/**
 * <p>
 * 描述：APi文档配置
 * @author Gerins
 * @version 1.0.0
 */
@Configuration
@EnableSwagger2WebMvc
public class SwaggerConfig {
    @Bean
    Docket rolemanagementApi() {
        return SwaggerCore.defaultDocketBuilder("角色管理模块", "com.zeroone.star.rolemanagement.controller", "rolemanagement");
    }
}
