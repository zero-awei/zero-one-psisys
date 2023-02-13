package com.zeroone.star.role.config;

import com.zeroone.star.project.config.swagger.SwaggerCore;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import springfox.documentation.spring.web.plugins.Docket;
import springfox.documentation.swagger2.annotations.EnableSwagger2WebMvc;

/**
 * 生成api文档
 * api文档配置
 */
@Configuration
@EnableSwagger2WebMvc
public class SwaggerConfig {
    @Bean
    Docket sampleApi(){
        return SwaggerCore.defaultDocketBuilder("示例模块","com.zeroone.star.role.controller","sample");
    }
}
