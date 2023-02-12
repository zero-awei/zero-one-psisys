package com.example.psisample;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;

@EnableDiscoveryClient
@SpringBootApplication
public class PsiSampleApplication {

    public static void main(String[] args) {
        SpringApplication.run(PsiSampleApplication.class, args);
    }

}
