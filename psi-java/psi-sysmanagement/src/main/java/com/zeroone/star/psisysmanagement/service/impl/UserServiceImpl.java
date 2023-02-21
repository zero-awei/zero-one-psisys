package com.zeroone.star.psisysmanagement.service.impl;

import cn.hutool.core.date.DateTime;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.dto.sysmanagement.usermanagement.EditUserDTO;
import com.zeroone.star.project.dto.sysmanagement.usermanagement.UserDTO;
import com.zeroone.star.project.query.sysmanagement.usermanagement.FindUserQuery;
import com.zeroone.star.project.query.sysmanagement.usermanagement.UserQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.sysmanagement.usermanagement.EditUserVO;
import com.zeroone.star.project.vo.sysmanagement.usermanagement.UserVO;
import com.zeroone.star.psisysmanagement.entity.User;
import com.zeroone.star.psisysmanagement.mapper.UserMapper;
import com.zeroone.star.psisysmanagement.service.IUserService;
import lombok.SneakyThrows;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.BeanUtils;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.nio.charset.StandardCharsets;
import java.util.List;

/**
 * <p>
 * 用户表 服务实现类
 * </p>
 *
 * @author  axin
 * @since 2023-02-12
 */
@Slf4j
@Service
public class UserServiceImpl extends ServiceImpl<UserMapper, User> implements IUserService {

    // dan
    @Resource
    EasyExcelComponent excel;

    // axin
    //    展示用户列表 finished tested（传id的情况下）
    @Override
    public PageVO<UserVO> listAllUsers(UserQuery query) {
        //        创建分页对象
        Page<User> userPage = new Page<>(query.getPageIndex(), query.getPageSize());
//        执行分页查询
        Page<User> result = baseMapper.selectPage(userPage,null);
        return PageVO.create(result, UserVO.class);
    }

    // axin
    //    模糊查询用户 finished tested
    @Override
    public PageVO<UserVO> listUser(FindUserQuery query) {
        //        创建分页对象
        Page<User> userPage = new Page<>(query.getPageIndex(), query.getPageSize());
//        创建查询条件
        QueryWrapper<User> userQueryWrapper = new QueryWrapper<>();
        userQueryWrapper.like("realname",query.getName());
        userQueryWrapper.like("username",query.getName());
//        执行分页查询
        Page<User> result = baseMapper.selectPage(userPage, userQueryWrapper);
        return PageVO.create(result, UserVO.class);
    }

    // axin
    @Override
    public JsonVO<EditUserVO> review(String id) {
        return null;
    }

    // dan
    @SneakyThrows
    @Override
    public ResponseEntity<byte[]> getExcel(List<User> users) {
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        excel.export("用户", out, User.class, users);
        HttpHeaders headers = new HttpHeaders();
        String fileName = "user-" + DateTime.now().toString("yyyyMMddHHmmssS") + ".xlsx";
        fileName = new String(fileName.getBytes(StandardCharsets.UTF_8), StandardCharsets.ISO_8859_1);
        headers.setContentDispositionFormData("attachment", fileName);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        ResponseEntity<byte[]> result = new ResponseEntity<>(out.toByteArray(), headers, HttpStatus.CREATED);
        out.close();
        return result;
    }

    // dan
    @Override
    public void updateStatus(String id, Integer status) {
        User user = new User();
        user.setStatus(status);
        user.setId(id);
        this.updateById(user);
    }

    // dan
    @Override
    public void updateUser(EditUserDTO dto) {
        User user = new User();
        BeanUtils.copyProperties(dto, user);
        log.info("user = {}", user);
        this.updateById(user);
    }

    // dan
    @Override
    public EditUserVO getUserInfo(String id) {
        User user = this.getById(id);
        EditUserVO editUserVO = new EditUserVO();
        BeanUtils.copyProperties(user, editUserVO);
        return editUserVO;
    }

}