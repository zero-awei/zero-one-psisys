package com.zeroone.star.payablemanagement.config;

import com.zeroone.star.project.config.swagger.SwaggerCore;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import springfox.documentation.spring.web.plugins.Docket;
import springfox.documentation.swagger2.annotations.EnableSwagger2WebMvc;

/**
 * 描述：APi文档配置
 */
@Configuration
@EnableSwagger2WebMvc
public class SwaggerConfig {
    @Bean
    Docket sampleApi() {
        return SwaggerCore.defaultDocketBuilder("应付管理模块",
                "com.zeroone.star.payablemanagement.controller",
                "应付管理模块");
    }
}
