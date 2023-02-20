package com.zeroone.star.paymentmanagement.config;

import com.zeroone.star.project.config.swagger.SwaggerCore;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import springfox.documentation.spring.web.plugins.Docket;
import springfox.documentation.swagger2.annotations.EnableSwagger2WebMvc;

/**
 * Swagger配置
 */
@Configuration
@EnableSwagger2WebMvc
public class SwaggerConfig {
    Docket paymentApi(){
        return SwaggerCore.defaultDocketBuilder("付款管理模块","com.zeroone.star.paymentmanagement.controller","paymentmanagement");
    }
}
