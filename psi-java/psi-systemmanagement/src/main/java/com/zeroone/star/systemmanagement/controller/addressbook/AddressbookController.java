package com.zeroone.star.systemmanagement.controller.addressbook;

import com.zeroone.star.project.query.systemmanagement.addressbook.AddressbookQuery;
import com.zeroone.star.project.query.systemmanagement.addressbook.OrganizationQuery;
import com.zeroone.star.project.query.systemmanagement.addressbook.OrganizationTreeQuery;
import com.zeroone.star.project.systemmanagement.addressbook.AddressbookApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.addressbook.AddressbookVO;
import com.zeroone.star.systemmanagement.service.addressbook.IAddressbookService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

/**
 * <p>
 * 描述：查询通讯录列表
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 西柚珍珠蜜
 * @version 1.0.0
 */

@RestController
@RequestMapping("/systemmanagement/addressbook")
@Api(tags = "查询通讯录列表")
@Validated
public class AddressbookController implements AddressbookApis {

    @Resource
    IAddressbookService service;

    @GetMapping("query-all")
    @ApiOperation(value = "通讯录分页查询")
    @Override
    public JsonVO<PageVO<AddressbookVO>> queryAddressbook(@Validated AddressbookQuery condition) {
        return JsonVO.success(service.listAddressbook(condition));
    }

    @GetMapping("query-realname-and-workno")
    @ApiOperation(value = "根据姓名和工号查询通讯录")
    @Override
    public JsonVO<PageVO<AddressbookVO>> getByRealnameAndWorkNo(@Validated AddressbookQuery condition) {
        return JsonVO.success(service.getByRealnameAndWorkNo(condition));
    }

    @GetMapping("query-realname")
    @ApiOperation(value = "根据姓名查询通讯录")
    @Override
    public JsonVO<PageVO<AddressbookVO>> getByRealname(@Validated AddressbookQuery condition) {
        return JsonVO.success(service.getByRealname(condition));
    }

    @GetMapping("query-workno")
    @ApiOperation(value = "根据工号查询通讯录")
    @Override
    public JsonVO<PageVO<AddressbookVO>> getByWorkNo(@Validated AddressbookQuery condition) {
        return JsonVO.success(service.getByWorkNo(condition));
    }

    @GetMapping("query-depart-name")
    @ApiOperation(value = "查询指定组织树")
    @Override
    public JsonVO<PageVO<AddressbookVO>> getByDepartName(@Validated OrganizationTreeQuery condition) {
        return JsonVO.success(service.getByDepartName(condition));
    }

    @GetMapping("query-all-depart")
    @ApiOperation(value = "查询组织树")
    @Override
    public JsonVO<PageVO<AddressbookVO>> queryDepart(@Validated OrganizationQuery condition) {
        return JsonVO.success(service.listDepart(condition));
    }

}
