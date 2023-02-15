package com.zeroone.star.systemmanagement.controller.addressbook;

import com.zeroone.star.project.query.systemmanagement.addressbook.OrganizationQuery;
import com.zeroone.star.project.query.systemmanagement.addressbook.OrganizationTreeQuery;
import com.zeroone.star.project.systemmanagement.addressbook.OrganizationApis;
import com.zeroone.star.project.systemmanagement.addressbook.OrganizationTreeApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.addressbook.OrganizationTreeVO;
import com.zeroone.star.project.vo.systemmanagement.addressbook.OrganizationVO;
import com.zeroone.star.systemmanagement.service.addressbook.ISysDepartService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

/**
 * <p>
 * 描述：查询组织列表或指定组织树
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 西柚珍珠蜜
 * @version 1.0.0
 */

@RestController
@RequestMapping("/addressbook")
@Api(tags = "查询组织列表或指定组织树")
@Validated
public class SysDepartController implements OrganizationApis, OrganizationTreeApis {

    @Resource
    ISysDepartService service;

    @GetMapping("organization")
    @ApiOperation(value = "查询组织列表")
    @Override
    public JsonVO<PageVO<OrganizationVO>> queryOrganization(@Validated OrganizationQuery condition) {
        return JsonVO.success(service.listOrganization(condition));
    }

    @GetMapping("organization-tree")
    @ApiOperation(value = "查询指定组织树")
    @Override
    public JsonVO<PageVO<OrganizationTreeVO>> queryOrganizationTree(@Validated OrganizationTreeQuery condition) {
        return JsonVO.success(service.listOrganizationTree(condition));
    }
}

