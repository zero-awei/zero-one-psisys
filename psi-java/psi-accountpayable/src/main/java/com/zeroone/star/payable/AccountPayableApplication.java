package com.zeroone.star.payable;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;

@EnableDiscoveryClient
@SpringBootApplication
public class AccountPayableApplication {

    public static void main(String[] args) {
        SpringApplication.run(com.zeroone.star.payable.AccountPayableApplication.class, args);
    }

}
