package com.zeroone.star.sample.test.entity;

import lombok.Builder;
import lombok.Data;

/**
 * @Description 测试产品类
 * @Author 阿伟学长
 * @Copy &copy;01星球
 * @Address 01星球总部
 */
@Data
@Builder
public class Product {
    /**
     * 序号
     */
    private int id;
    /**
     * 全名称
     */
    private String name;
    /**
     * 规格
     */
    private String standers;
    /**
     * 单位
     */
    private String unit;
    /**
     * 数量
     */
    private int number;
    /**
     * 单价
     */
    private int price;
    /**
     * 金额
     */
    private int money;
    /**
     * 最小起订单位
     */
    private String minUnit;
    /**
     * 备注
     */
    private String marker;
}
