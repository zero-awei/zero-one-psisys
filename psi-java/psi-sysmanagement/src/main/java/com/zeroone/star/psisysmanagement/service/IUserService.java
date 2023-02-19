package com.zeroone.star.psisysmanagement.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.sysmanagement.usermanagement.EditUserDTO;
import com.zeroone.star.project.vo.sysmanagement.usermanagement.EditUserVO;
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

    void updateStatus(String id, Integer status);

    void updateUser(EditUserDTO dto);

    EditUserVO getUserInfo(String id);
}
