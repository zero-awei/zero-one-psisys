package com.zeroone.star.payablemanagement;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;

@EnableDiscoveryClient
@SpringBootApplication
public class PayablemanagementApplication {

    public static void main(String[] args) {
        SpringApplication.run(PayablemanagementApplication.class, args);
    }

}
