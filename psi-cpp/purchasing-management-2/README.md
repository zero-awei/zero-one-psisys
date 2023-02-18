# 演示示例模块

## 简介
架构使用演示示例项目。

## 目录结构说明
> `psi-sample`
>
> > `api` -- 模拟`MVC`中Controller实现，用于接收用户请求
> >
> > `service` -- 业务逻辑服务层
> >
> > `dao` -- 数据库访问层
> >
> > `domain`  -- 领域模型实体
> >
> > `public` -- 测试访问网页案例
> >
> > `Macros.h` -- 通用宏定义
> >
> > `uselib` -- 静态库测试案例
> >
> > `stdafx.h` -- 预编译标头文件
> >
> > `main.cpp` -- 程序入口

## 各层命名规范

- `Controller/Service/DAO` 层方法命名规约
  - 获取单个对象的方法用 `query/get/select` 做前缀。
  - 获取多个对象的方法用 `query/list/select` 做前缀。
  - 获取统计值的方法用 `count/count/count` 做前缀。
  - 插入的方法用 `add/save/insert` 做前缀。
  - 删除的方法用 `remove/remove/delete` 做前缀。
  - 修改的方法用 `modify/update/update` 做前缀。
  - `Controller`数据执行方法使用exec作前缀。
    - 如接口方法名称为`queryByName`，对应的执行方法名则为`execQueryByName`。
  - `API`请求路径命名，多个单词使用-连接，如`/query-by-name`。
- 领域模型命名规约
  - 数据对象：`xxxDO`，`xxx` 即为数据表名。
  - 数据传输对象：`xxxDTO`，`xxx` 为业务领域相关的名称。
  - 查询对象：`xxxQuery`，`xxx`为业务领域相关的名称。
  - 展示对象：`xxxVO`，`xxx` 一般为网页名称。
  - `POJO` 是 `DO/DTO/BO/VO/Query` 的统称，禁止命名成 `xxxPOJO`。

