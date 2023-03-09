package com.zeroone.star.project.sysmanagement;

import com.zeroone.star.project.dto.sysmanagement.usermanagement.AddUserDTO;
import com.zeroone.star.project.dto.sysmanagement.usermanagement.EditUserDTO;
import com.zeroone.star.project.dto.sysmanagement.usermanagement.UserDTO;
import com.zeroone.star.project.query.sysmanagement.usermanagement.FindUserQuery;
import com.zeroone.star.project.query.sysmanagement.usermanagement.UserQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.sysmanagement.usermanagement.AddUserVO;
import com.zeroone.star.project.vo.sysmanagement.usermanagement.DepartVO;
import com.zeroone.star.project.vo.sysmanagement.usermanagement.EditUserVO;
import com.zeroone.star.project.vo.sysmanagement.usermanagement.UserVO;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.multipart.MultipartFile;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotEmpty;
import javax.validation.constraints.NotNull;
import java.util.List;

/*
* 2023.2.24
* */
public interface UserApis {
    /**
     * 用户列表
     * @param query 查询条件
     * @return 查询结果
     */
    JsonVO<PageVO<UserVO>> listAllUsers(UserQuery query);

    /**
     * 查询用户
     * @param query 查询条件
     * @return 查询结果
     */
    JsonVO<PageVO<UserVO>> listUser(FindUserQuery query);

    /**
     * 数据回显
     * @param id 用户id
     * @return 用户信息
     */
    JsonVO<EditUserVO> review(@NotBlank(message = "id 不能为空") String id);

    /**
     * 新增用户
     * @param dto 数据对象
     * @return 新增用户的编号
     */
    JsonVO<String> addUser(AddUserDTO dto);

    /**
     * 删除用户
     * @param id 用户id
     * @return 删除用户的编号
     */
    JsonVO<String> deleteUser(@NotBlank(message = "id 不能为空") String id);

    /**
     * 用户导入
     * @return
     */
    JsonVO<String> upload(MultipartFile file);

    /**
     * 导出选定用户
     * @param id 用户id
     * @return 导出文件
     */
    ResponseEntity<byte[]> download(@NotEmpty(message = "导出用户必须大于0") List<String> id);

    /**
     * 导出全部用户
     * @return 导出文件
     */
    ResponseEntity<byte[]> downloadAllUsers();

    /**
     * 下拉框获取部门列表
     * @return
     */
    JsonVO<List<DepartVO>> listDepartment();

     /**
     * 修改用户
     * @param dto 数据数据内容
     * @return 修改成功提示
     */
    JsonVO<String> modifyUser(@Validated EditUserDTO dto);

    /**
     * 冻结/解冻用户
     * @param id 用户id
     * @return 修改成功提示
     */
    JsonVO<String> modifyStatus(@NotBlank(message = "id不能为空") String id, @NotNull(message = "状态不能为空") @RequestParam Integer status);

}