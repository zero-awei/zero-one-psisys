package com.zeroone.star.titlepage.config;

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
    Docket titlepageApi() {
        return SwaggerCore.defaultDocketBuilder("首页模块", "com.zeroone.star.titlepage.controller", "titlepage");
    }
}
