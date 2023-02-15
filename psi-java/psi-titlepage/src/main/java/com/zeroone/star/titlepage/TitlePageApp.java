package com.zeroone.star.titlepage;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;

/**
 * @Description
 * @Author 苏乞儿
 * @Date 2023/2/10
 */
@SpringBootApplication
@EnableDiscoveryClient
public class TitlePageApp {
    public static void main(String[] args) {
        SpringApplication.run(TitlePageApp.class,args);
    }
}
