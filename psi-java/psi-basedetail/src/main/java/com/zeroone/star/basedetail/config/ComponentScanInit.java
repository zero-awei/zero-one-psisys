package com.zeroone.star.basedetail.config;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

/**
 * 扫描自定义组件
 * @author Third uncle
 * @date 2023/2/14 - 15:57
 */
@Configuration
@ComponentScan({
    "com.zeroone.star.project.components.fastdfs",
        "com.zeroone.star.project.components.easyexcel",
        "com.zeroone.star.project.components.user",
        "com.zeroone.star.project.components.jwt"
})
public class ComponentScanInit {

}
