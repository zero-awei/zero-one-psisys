package com.zeroone.star.payablemanagement.config;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

/**
 * 扫描自定义组件
 */
@Configuration
@ComponentScan({
//        "com.zeroone.star.project.components.fastdfs",
        "com.zeroone.star.project.components.easyexcel"
})
public class ComponentInit {
}
