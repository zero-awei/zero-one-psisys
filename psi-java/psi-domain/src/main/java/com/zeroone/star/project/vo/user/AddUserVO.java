package com.zeroone.star.project.vo.user;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.util.Date;
import java.util.List;

@Data
@ApiModel("用户管理中下拉框部门显示对象")
public class AddUserVO {
    /**
     * 主键id
     */
    @ApiModelProperty(value = "id", example = "")
    private String id;

    /**
     * 部门列表
     */
    @ApiModelProperty(value = "选择您负责的部门", example = "")
    private String departName;

}