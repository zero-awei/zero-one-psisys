package com.zeroone.star.prepayment.config;

import com.zeroone.star.project.config.swagger.SwaggerCore;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import springfox.documentation.spring.web.plugins.Docket;
import springfox.documentation.swagger2.annotations.EnableSwagger2WebMvc;

/**
 * @Description
 * @Author forever爱
 * @Date 2023/2/10
 */
@Configuration
@EnableSwagger2WebMvc
public class SwaggerConfig {
    @Bean
    Docket modifyApi() {
        return SwaggerCore.defaultDocketBuilder("采购预付", "com.zeroone.star.prepayment.controller", "prepayment");
    }
}
