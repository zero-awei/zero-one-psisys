package com.zeroone.star.psisysmanagement.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.psisysmanagement.entity.User;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 * 用户表 Mapper 接口
 * </p>
 *
 * @author axin
 * @since 2023-02-12
 */
@Mapper
public interface UserMapper extends BaseMapper<User> {

}
