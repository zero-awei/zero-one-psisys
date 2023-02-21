package com.zeroone.star.payablemanagement;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;

/**
 * 〈功能概述〉<br>
 *
 * @author:Administrator
 * @date: 2023/2/21 10:33
 */
@SpringBootApplication
@EnableDiscoveryClient
public class PayableManagementApplication {
    public static void main(String[] args) {
        SpringApplication.run(PayableManagementApplication.class, args);
    }
}
