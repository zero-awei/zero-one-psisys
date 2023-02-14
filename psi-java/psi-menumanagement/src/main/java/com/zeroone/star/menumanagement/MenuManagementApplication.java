package com.zeroone.star.menumanagement;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;


@SpringBootApplication
@EnableDiscoveryClient
public class MenuManagementApplication {
    public static void main(String[] args) {
        SpringApplication.run(MenuManagementApplication.class, args);

    }
}
