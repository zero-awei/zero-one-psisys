package com.zeroone.star.psisysmanagement;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;

@SpringBootApplication
@EnableDiscoveryClient
public class PsiSysManagementApplication {

    public static void main(String[] args) {
        SpringApplication.run(PsiSysManagementApplication.class, args);
    }

}
