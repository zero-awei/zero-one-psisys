package com.zeroone.star.titlepage;

import com.alibaba.nacos.api.exception.NacosException;
import com.alibaba.nacos.api.naming.NamingFactory;
import com.alibaba.nacos.api.naming.NamingService;
import com.alibaba.nacos.api.naming.pojo.Instance;
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
public class TitlePageApp {
    public static void main(String[] args) throws NacosException, UnknownHostException {
       /* Properties properties = new Properties();
        properties.setProperty("namespace", "7fc50d88-3410-44a3-acff-9108d2bfe2b2");
        properties.setProperty("serverAddr","43.138.51.248:8848");
        NamingService namingService = NamingFactory.createNamingService(properties);
        // 创建服务实例
        Instance instance = new Instance();
        instance.setIp(InetAddress.getLocalHost().getHostAddress());
        instance.setPort(10102);
        instance.setServiceName("homepage-j2");
        // 注册服务实例到 Nacos 服务注册中心
        namingService.registerInstance(instance.getServiceName(), instance.getIp(), instance.getPort());*/
        SpringApplication.run(TitlePageApp.class,args);
    }
}
