package com.zeroone.star.project.vo.prepayment;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;


/**
 * @Author: Kong
 * @License: (C) Copyright 2005-2019, xxx Corporation Limited.
 * @Contact: xxx@xxx.com
 * @Date: 2023-02-11 21:20
 * @Version: 1.0
 * @Description:
 */
@Data
@ApiModel("供应商显示对象")
public class SupplierVO {
    /**
     * id
     */
    @ApiModelProperty(value = "id",example = "1623600860981665793")
    private String id;

    /**
     * 助记名
     */
    @ApiModelProperty(value = "助记名",example = "00001 公交卡")
    private String aux_name;




}