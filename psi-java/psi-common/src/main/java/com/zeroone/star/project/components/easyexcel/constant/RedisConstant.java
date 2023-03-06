package com.zeroone.star.project.components.easyexcel.constant;

/**
 * <p>
 * 描述：Redis相关常量
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
public interface RedisConstant {
    /**
     * 角色资源映射Map的key
     */
    String RESOURCE_ROLES_MAP = "AUTH:RESOURCE_ROLES";

    /**
     * 验证码前缀
     */
    String CAPTCHA = "CAPTCHA:LOGIN";

    String USER_TOKEN = "AUTH:USER_TOKEN";
}
