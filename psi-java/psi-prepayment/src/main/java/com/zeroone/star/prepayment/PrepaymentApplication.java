package com.zeroone.star.prepayment;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;

/**
 * @Description
 * @Author forever爱
 * @Date 2023/2/10
 */
@SpringBootApplication
@EnableDiscoveryClient
public class PrepaymentApplication {
    public static void main(String[] args) {
        SpringApplication.run(PrepaymentApplication.class,args);
    }
}
