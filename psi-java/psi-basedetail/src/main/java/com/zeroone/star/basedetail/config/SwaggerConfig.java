package com.zeroone.star.basedetail.config;

import com.zeroone.star.project.config.swagger.SwaggerCore;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.stereotype.Component;
import springfox.documentation.spring.web.plugins.Docket;
import springfox.documentation.swagger2.annotations.EnableSwagger2WebMvc;

/**
 * @Description
 * @Author 苏乞儿
 * @Date 2023/2/10
 */
@Configuration
@EnableSwagger2WebMvc
public class SwaggerConfig {

    @Bean
    Docket sampleApi() {
        return SwaggerCore.defaultDocketBuilder("基础信息模块", "com.zeroone.star.basedetail.controller", "basedetail");
    }
}
