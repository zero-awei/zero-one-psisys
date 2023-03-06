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
        Properties properties = new Properties();
        properties.setProperty("namespace", "7fc50d88-3410-44a3-acff-9108d2bfe2b2");
        properties.setProperty("server.ip","192.168.1.100");
        properties.setProperty("serverAddr","43.138.51.248:8848");
        NamingService namingService = NamingFactory.createNamingService(properties);
        // 创建服务实例
        Instance instance = new Instance();
        instance.setIp(InetAddress.getLocalHost().getHostAddress());
        instance.setPort(10101);
        instance.setServiceName("systemmanagement-j2");
        // 注册服务实例到 Nacos 服务注册中心
        namingService.registerInstance(instance.getServiceName(), instance.getIp(), instance.getPort());
        SpringApplication.run(SystemManagementApp.class,args);
    }
}
