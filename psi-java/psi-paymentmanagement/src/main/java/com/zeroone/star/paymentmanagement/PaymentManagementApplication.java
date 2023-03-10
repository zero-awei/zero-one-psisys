package com.zeroone.star.paymentmanagement;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;

//@MapperScan("com.zeroone.star.payment.mapper")
@SpringBootApplication
@EnableDiscoveryClient
public class PaymentManagementApplication {
    public static void main(String[] args) {
        SpringApplication.run(PaymentManagementApplication.class, args);
    }
}
