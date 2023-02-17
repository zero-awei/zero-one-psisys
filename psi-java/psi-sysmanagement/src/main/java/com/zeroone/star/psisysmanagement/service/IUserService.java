package com.zeroone.star.psisysmanagement.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.psisysmanagement.entity.User;
import org.springframework.http.ResponseEntity;

import java.util.List;

/**
 * <p>
 * 用户表 服务类
 * </p>
 *
 * @author axin
 * @since 2023-02-12
 */
public interface IUserService extends IService<User> {
    ResponseEntity<byte[]> getExcel(List<User> users);
}
