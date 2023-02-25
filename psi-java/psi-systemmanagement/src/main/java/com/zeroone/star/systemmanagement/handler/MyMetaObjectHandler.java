package com.zeroone.star.systemmanagement.handler;

import com.baomidou.mybatisplus.core.handlers.MetaObjectHandler;
import org.apache.ibatis.reflection.MetaObject;
import org.springframework.stereotype.Component;

import java.util.Date;

/**
 * @author mumu
 * @since 2023-02-23
 */
@Component
public class MyMetaObjectHandler implements MetaObjectHandler {

    //使用MP 执行insert 操作时 ，此方法执行
    @Override
    public void insertFill(MetaObject metaObject) {
        this.setFieldValByName("createTime", new Date(), metaObject);
        this.setFieldValByName("updateTime", new Date(), metaObject);
    }
    //使用MP 执行update 操作时 ，此方法执行
    @Override
    public void updateFill(MetaObject metaObject) {
        this.setFieldValByName("updateTime", new Date(), metaObject);
    }
}
