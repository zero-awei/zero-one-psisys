package com.zeroone.star.systemmanagement.controller.organizationmanagement;


import com.zeroone.star.project.dto.systemmanagement.organizationmanagement.OrganizationManagementDTO;
import com.zeroone.star.project.query.systemmanagement.organizationmanagement.OrganizationListQuery;
import com.zeroone.star.project.systemmanagement.organizationmanagement.OrganizationManagementApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.organizationmanagement.OrganizationListVO;
import com.zeroone.star.project.vo.systemmanagement.organizationmanagement.OrganizationTreeVO;
import com.zeroone.star.systemmanagement.service.organizationmanagement.OrganizationmanagementService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 组织机构表 前端控制器
 * </p>
 *
 * @author Morrangee
 * @since 2023-02-13
 */
@RestController
@RequestMapping("/systemmanagement/sys-depart")
@Api(tags = "组织机构")
public class OrganizationmanagementController implements OrganizationManagementApis {

    @Resource
    private OrganizationmanagementService service;
    /**
     * 查询组织列表
     * @param condition 查询条件
     * @return
     */
    @ApiOperation("查询组织列表")
    @GetMapping("/query-all")
    @Override
    public JsonVO<PageVO<OrganizationListVO>> queryList(OrganizationListQuery condition) {
        PageVO<OrganizationListVO> pageVO = service.queryList(condition);
        return JsonVO.success(pageVO);
    }

    /**
     * 查询指定结构树
     *
     * @param departName 部门名称
     * @return
     */
    @ApiOperation("查询指定结构树")
    @GetMapping("query-tree")
    @Override
    public JsonVO<List<OrganizationTreeVO>> queryTree(String departName) {
        List<OrganizationTreeVO> list = service.queryTree(departName);
        return JsonVO.success(list);
    }

    /**
     * 新增组织结构
     * @param data 数据
     * @return
     */

    @ApiOperation("新增组织结构")
    @PostMapping("add") // add
    @Override
    public JsonVO<String> add(OrganizationManagementDTO data) {
        String s = service.add(data);
        if (s.equals("新增成功")) {
            return JsonVO.success(s);
        }
        else return JsonVO.fail(s);
    }

    /**
     * 修改组织结构
     * @param data 数据
     * @return
     */
    @ApiOperation("修改组织结构")
    @PutMapping("modify")
    @Override
    public JsonVO<String> modify(OrganizationManagementDTO data) {
        String s = service.modify(data);
        if (s.equals("更新成功")) {
            return JsonVO.success(s);
        }
        else return JsonVO.fail(s);
    }

    /**
     * 删除组织结构
     * @param id 部门id
     * @return
     */
    @ApiOperation("删除组织结构")
    @DeleteMapping("remove")
    @Override
    public JsonVO<String> remove(String id) {
        String s = service.remove(id);
        if (s.equals("删除成功")) {
            return JsonVO.success(s);
        }
        else return JsonVO.fail(s);
    }
}

