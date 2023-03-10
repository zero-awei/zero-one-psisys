package com.zeroone.star.systemmanagement;

import com.alibaba.nacos.api.exception.NacosException;
import com.alibaba.nacos.api.naming.NamingFactory;
import com.alibaba.nacos.api.naming.NamingService;
import com.alibaba.nacos.api.naming.pojo.Instance;
import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;

import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.Properties;

/**
 * @Description
 * @Author 苏乞儿
 * @Date 2023/2/10
 */
@SpringBootApplication
@EnableDiscoveryClient
@MapperScan(value = "com.zeroone.star.systemmanagement.mapper")
public class SystemManagementApp {

    public static void main(String[] args) throws NacosException, UnknownHostException {
        SpringApplication.run(SystemManagementApp.class,args);
    }
}
