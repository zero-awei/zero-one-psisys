package com.zeroone.star.psisysmanagement.service.impl;

import cn.hutool.core.date.DateTime;
import com.alibaba.excel.EasyExcel;
import com.alibaba.excel.read.listener.PageReadListener;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.dto.sysmanagement.usermanagement.AddUserDTO;
import com.zeroone.star.project.dto.sysmanagement.usermanagement.EditUserDTO;
import com.zeroone.star.project.query.sysmanagement.usermanagement.FindUserQuery;
import com.zeroone.star.project.query.sysmanagement.usermanagement.UserQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.sysmanagement.usermanagement.EditUserVO;
import com.zeroone.star.project.vo.sysmanagement.usermanagement.UserVO;
import com.zeroone.star.psisysmanagement.entity.Depart;
import com.zeroone.star.psisysmanagement.entity.User;
import com.zeroone.star.psisysmanagement.mapper.UserMapper;
import com.zeroone.star.psisysmanagement.service.DepartService;
import com.zeroone.star.psisysmanagement.service.IUserService;
import lombok.SneakyThrows;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.BeanUtils;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.multipart.MultipartFile;

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

    @Resource
    DepartService departService;

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

    //    axin
//       新增用户
    @Override
    public void saveUser(AddUserDTO dto) {
        User user = new User();
        BeanUtils.copyProperties(dto, user);
        log.info("user = {}", user);
        this.save(user);
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
    public boolean updateStatus(String id, Integer status) {
        User user = new User();
        user.setStatus(status);
        user.setId(id);
        return this.updateById(user);
    }

    // dan
    @Override
    public boolean updateUser(EditUserDTO dto) {
        User user = new User();
        BeanUtils.copyProperties(dto, user);
        log.info("user = {}", user);
        return this.updateById(user);
    }

    // dan
    @Transactional
    @Override
    public EditUserVO getUserInfo(String id) {
        User user = this.getById(id);
        EditUserVO editUserVO = new EditUserVO();
        BeanUtils.copyProperties(user, editUserVO);
        QueryWrapper<Depart> queryWrapper = new QueryWrapper<>();
        queryWrapper.select("depart_name").eq("id", user.getDepartIds());
        List<Depart> departs = departService.getBaseMapper().selectList(queryWrapper);
        log.info("departs :{}", departs);
        editUserVO.setDepartName(departs.get(0).getDepartName());
        return editUserVO;
    }

    // dan
    @Transactional
    @Override
    public void saveUsers(MultipartFile file) throws Exception {
        EasyExcel.read(file.getInputStream(), User.class, new PageReadListener<User>(this::saveBatch)).sheet().doRead();
    }

}