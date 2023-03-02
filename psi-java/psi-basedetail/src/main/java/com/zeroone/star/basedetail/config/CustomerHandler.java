package com.zeroone.star.basedetail.config;

import com.baomidou.mybatisplus.core.handlers.MetaObjectHandler;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import org.apache.ibatis.reflection.MetaObject;
import org.springframework.stereotype.Component;
import javax.annotation.Resource;
import java.time.LocalDateTime;

/**
 * @Description 客户数据自动填充
 * @author YinXing
 * @date 2023年02月21日
 */
@Component
public class CustomerHandler implements MetaObjectHandler {

    @Resource
    UserHolder userHolder;

    UserDTO currentUser;

    /**
     * 插入时自动填充，针对插入时间类型
     * @param metaObject
     */
    @Override
    public void insertFill(MetaObject metaObject) {
        try {
            currentUser = userHolder.getCurrentUser();
        }catch (Exception e){
            currentUser = null;
        }
        this.setFieldValByName("createTime", LocalDateTime.now(), metaObject);
        this.setFieldValByName("updateTime", LocalDateTime.now(), metaObject);
        this.setFieldValByName("createBy", currentUser.getUsername(), metaObject);
        this.setFieldValByName("updateBy", currentUser.getUsername(), metaObject);
    }

    /**
     * 修改时更新
     * @param metaObject
     */
    @Override
    public void updateFill(MetaObject metaObject) {
        try {
            currentUser = userHolder.getCurrentUser();
        }catch (Exception e){
            currentUser = null;
        }
        this.setFieldValByName("updateTime", LocalDateTime.now(), metaObject);
        this.setFieldValByName("updateBy", currentUser.getUsername(), metaObject);
    }
}
