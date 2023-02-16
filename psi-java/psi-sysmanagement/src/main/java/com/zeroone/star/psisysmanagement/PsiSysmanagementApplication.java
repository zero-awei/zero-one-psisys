package com.zeroone.star.psisysmanagement;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;

@SpringBootApplication
@EnableDiscoveryClient
public class PsiSysmanagementApplication {

    public static void main(String[] args) {
        SpringApplication.run(PsiSysmanagementApplication.class, args);
    }

}
