package com.zeroone.star.payablemanagement.utils;

import com.baomidou.mybatisplus.core.handlers.MetaObjectHandler;
import com.zeroone.star.project.components.user.UserHolder;
import lombok.extern.slf4j.Slf4j;
import org.apache.ibatis.reflection.MetaObject;
import org.springframework.stereotype.Component;

import javax.annotation.Resource;
import java.time.LocalDateTime;

/**
 * @author The end
 */
@Component
@Slf4j
public class MyBatisMetaObjectHandler implements MetaObjectHandler {

    @Resource
    UserHolder userHolder;

    /**
     * 执行数据库插入操作时自动充填字段
     */
    @Override
    public void insertFill(MetaObject metaObject) {
        log.info("开始执行插入语句自动填充字段...");
        metaObject.setValue("createTime", LocalDateTime.now());
        metaObject.setValue("updateTime", LocalDateTime.now());
        try {
            metaObject.setValue("createBy", userHolder.getCurrentUser().getUsername());
            metaObject.setValue("updateBy", userHolder.getCurrentUser().getUsername());
        } catch (Exception e) {
            metaObject.setValue("createBy", "");
            metaObject.setValue("updateBy", "");
            log.error("无法获取当前用户！", e);
        }
    }

    /**
     * 执行数据库更新操作时自动充填字段
     */
    @Override
    public void updateFill(MetaObject metaObject) {
        log.info("开始执行更新语句自动填充字段...");
        metaObject.setValue("updateTime", LocalDateTime.now());
        try {
            metaObject.setValue("updateBy", userHolder.getCurrentUser().getUsername());
        } catch (Exception e) {
            metaObject.setValue("updateBy", "");
            log.error("无法获取当前用户！", e);
        }
    }

}