package com.zeroone.star.systemmanagement;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;

@SpringBootApplication
@EnableDiscoveryClient
public class SystemManagementApp {
    public static void main(String[] args) {
        SpringApplication.run(SystemManagementApp.class, args);
    }
}
