package com.zeroone.star.systemmanagement.controller.organizationmanagement;


import com.zeroone.star.project.dto.systemmanagement.organizationmanagement.OrganizationManagementDTO;
import com.zeroone.star.project.query.systemmanagement.organizationmanagement.OrganizationListQuery;
import com.zeroone.star.project.systemmanagement.organizationmanagement.OrganizationManagementApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.organizationmanagement.OrganizationListVO;
import com.zeroone.star.project.vo.systemmanagement.organizationmanagement.OrganizationTreeVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

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

    /**
     * 查询组织列表
     * @param condition 查询条件
     * @return
     */
    @ApiOperation("查询组织列表")
    @GetMapping("/query-all") // query-list
    @Override
    public JsonVO<PageVO<OrganizationListVO>> queryList(OrganizationListQuery condition) {
        return null;
    }

    /**
     * 查询指定结构树
     * @param departName 部门名称
     * @return
     */
    @ApiOperation("查询指定结构树")
    @GetMapping("query-one") // query-tree
    @Override
    public JsonVO<OrganizationTreeVO> queryTree(String departName) {
        return null;
    }

    /**
     * 新增组织结构
     * @param data 数据
     * @return
     */

    @ApiOperation("新增组织结构（返回值data值表示插入成功与否）")
    @PostMapping("insert") // add
    @Override
    public JsonVO<String> add(OrganizationManagementDTO data) {
        return null;
    }

    /**
     * 修改组织结构
     * @param data 数据
     * @return
     */
    @ApiOperation("修改组织结构（返回值data值表示更新成功与否）")
    @PutMapping("update") //modify
    @Override
    public JsonVO<String> modify(OrganizationManagementDTO data) {
        return null;
    }

    /**
     * 删除组织结构
     * @param id 部门id
     * @return
     */
    @ApiOperation("删除组织结构（返回值data值表示删除成功与否）")
    @DeleteMapping("delete")
    @Override
    public JsonVO<String> delete(String id) {
        return null;
    }
}

