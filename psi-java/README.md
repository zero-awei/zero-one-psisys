# 工程简介
项目架构父模块，用于管理第三方依赖和项目模块

创建spring boot项目的时候如果比较慢可以使用：http://start.aliyun.com/ 替代原来的 https://start.spring.io


# 延伸阅读

## `nacos`服务器配置参考

***注意：上传到  `Nacos`  配置中心的配置不要带中文注释，不然会出想编码问题。***

### `system.yaml`

系统配置，后续配置网关或新增服务器都在这里配置，方便在线扩展

```yaml
spring:
  cloud:
    inetutils:
      #优先网络IP选择
      preferred-networks: 
        - 192.168
        - 39.99
      #忽略一些虚拟网卡
      ignored-interfaces:
        - docker0
        - veth.*
        - VM.*
        - br-.*
```

### `data-source.yaml`

数据源配置

```yaml
#References
#https://github.com/alibaba/druid/tree/master/druid-spring-boot-starter
#https://github.com/alibaba/druid/wiki/DruidDataSource%E9%85%8D%E7%BD%AE
#https://github.com/alibaba/druid/wiki/DruidDataSource%E9%85%8D%E7%BD%AE%E5%B1%9E%E6%80%A7%E5%88%97%E8%A1%A8
spring:
  #配置MySQL数据库
  datasource:
    url: jdbc:mysql://192.168.220.128:3306/test?useUnicode=true&useSSL=false&characterEncoding=utf-8&serverTimezone=Asia/Shanghai&allowPublicKeyRetrieval=true
    username: root
    password: 123456
    driver-class-name: com.mysql.cj.jdbc.Driver
    type: com.alibaba.druid.pool.DruidDataSource
    druid:
      name: DruidDataSource
      initial-size: 1
      min-idle: 1
      max-active: 20
      async-init: true
      max-wait: 6000
      time-between-eviction-runs-millis: 60000
      min-evictable-idle-time-millis: 300000
      max-evictable-idle-time-millis: 900000
      validation-query: SELECT 1
      test-while-idle: true
      test-on-borrow: false
      test-on-return: false
      pool-prepared-statements: true
      max-pool-prepared-statement-per-connection-size: 20
      connection-init-sqls: SET NAMES utf8mb4 COLLATE utf8mb4_0900_ai_ci;
      filters: stat
  #配置Redis数据库
  redis:
    host: 192.168.220.128
    port: 6379
    password: 01star
  data:
    #mongodb配置
    mongodb:
      #格式: mongodb://账号:密码@主机地址:端口/数据库名称
      uri: mongodb://awei:123456@192.168.220.128:27017/firstDb
```

### `third-services.yaml` 

第三方服务配置

```yaml
#C++提供服务器
cpp:
  sample:
    url: http://localhost:8090
    name: feign-cpp-sample
#sentinel提供服务
sentinel:
    dashboard: 192.168.220.128:8718
#rocketmq配置
rocket-mq:
    name-server: 192.168.220.128:9876
#seata配置
seata:
  default: 192.168.220.128:8091
#logstash配置
logstash:
  host: 192.168.220.128
#FASTDFS配置
#References
#https://i4t.com/4758.html
#https://github.com/happyfish100/fastdfs/tree/master/docker/dockerfile_network/conf
fastdfs:
  charset: UTF-8
  connect-timeout: 5
  network-timeout: 30
  http-secret-key: FastDFS1234567890
  http-anti-steal-token: true
  connection-pool-max-idle: 20
  connection-pool-max-total: 20
  connection-pool-min-idle: 2
  nginx-servers: 192.168.220.128:8888
  tracker-servers: 192.168.220.128:22122
#Easy ES
easy-es:
  address: 192.168.220.128:9200
  username: elastic #es用户名,若无则删去此行配置
  password: WG7WVmuNMtM4GwNYkyWH #es密码,若无则删去此行配置
```

