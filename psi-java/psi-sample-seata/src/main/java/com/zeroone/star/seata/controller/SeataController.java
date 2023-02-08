package com.zeroone.star.seata.controller;

import com.zeroone.star.seata.service.TransService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

/**
 * <p>
 * 描述：测试修改数据
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@RestController
@RequestMapping("seata")
@Api(tags = "测试Seata")
public class SeataController {
    @Resource
    TransService service;

    @ApiOperation(value = "测试保存")
    @GetMapping("test-save")
    public Integer testSave(){
        return service.saveData();
    }
}
