package com.zeroone.star.psisysmanagement.service.impl;

import cn.hutool.core.date.DateTime;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.dto.sysmanagement.usermanagement.EditUserDTO;
import com.zeroone.star.project.vo.sysmanagement.usermanagement.EditUserVO;
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
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.nio.charset.StandardCharsets;
import java.util.List;

/**
 * <p>
 * 用户表 服务实现类
 * </p>
 *
 * @author axin
 * @since 2023-02-12
 */
@Service
@Slf4j
public class UserServiceImpl extends ServiceImpl<UserMapper, User> implements IUserService {

    @Resource
    EasyExcelComponent excel;

    @SneakyThrows
    @Override
    public ResponseEntity<byte[]> getExcel(List<User> users) {
        // 导出Excel
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        excel.export("测试", out, User.class, users);
        // 创建响应头
        HttpHeaders headers = new HttpHeaders();
        // 构建一个下载的文件名称
        String fileName = "test-" + DateTime.now().toString("yyyyMMddHHmmssS") + ".xlsx";
        fileName = new String(fileName.getBytes(StandardCharsets.UTF_8), StandardCharsets.ISO_8859_1);
        headers.setContentDispositionFormData("attachment", fileName);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        ResponseEntity<byte[]> result = new ResponseEntity<>(out.toByteArray(), headers, HttpStatus.CREATED);
        out.close();
        return result;
    }

    @Override
    public void updateStatus(String id, Integer status) {
        User user = new User();
        user.setStatus(status);
        user.setId(id);
        this.updateById(user);
    }

    @Override
    public void modifyUser(EditUserDTO dto) {
        User user = new User();
        BeanUtils.copyProperties(dto, user);
        log.info("user = {}", user);
        this.updateById(user);
    }

    @Override
    public EditUserVO getUserInfo(String id) {
        User user = this.getById(id);
        EditUserVO editUserVO = new EditUserVO();
        BeanUtils.copyProperties(user, editUserVO);
        return editUserVO;
    }
}
