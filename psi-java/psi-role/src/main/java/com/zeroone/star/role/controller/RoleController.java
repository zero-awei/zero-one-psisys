package com.zeroone.star.role.controller;

import com.baomidou.mybatisplus.extension.service.IService;
import org.springframework.beans.factory.annotation.Autowired;

import javax.annotation.Resource;

public class RoleController<T,S extends IService<T>> {

    @Autowired
    protected S service;

}
