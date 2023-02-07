package com.zeroone.star.sample.test.entity;

import lombok.Builder;
import lombok.Data;

/**
 * @Description 测试用户类
 * @Author 阿伟学长
 * @Copy &copy;01星球
 * @Address 01星球总部
 */
@Data
@Builder
public class TestUser {
    private Integer id;
    private String name;
    private String phone;
}
