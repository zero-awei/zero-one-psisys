package com.zeroone.star.systemmanagement.controller.addressbook;

import com.zeroone.star.project.query.systemmanagement.addressbook.AddressbookQuery;
import com.zeroone.star.project.systemmanagement.addressbook.AddressbookApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.addressbook.AddressbookVO;
import com.zeroone.star.systemmanagement.service.addressbook.ISysUserService;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

/**
 * <p>
 * 描述：查询通讯录列表不完全版
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 西柚珍珠蜜
 * @version 1.0.0
 */


// ======================================== 无效(第一版本) =====================================



@RestController
//@RequestMapping("/addressbook-fake")
//@Api(tags = "查询通讯录列表不完全版")
@Validated
public class SysUserController implements AddressbookApis {

    @Resource
    ISysUserService service;

    @GetMapping("query-all")
    @ApiOperation(value = "通讯录分页查询")
    @Override
    public JsonVO<PageVO<AddressbookVO>> queryAddressbook(@Validated AddressbookQuery condition) {
        return JsonVO.success(service.listAddressbook(condition));
    }

    @GetMapping("query-more")
    @ApiOperation(value = "根据姓名和工号查询通讯录")
    @Override
    public JsonVO<PageVO<AddressbookVO>> getByRealnameAndWorkNo(@Validated AddressbookQuery condition) {
        return JsonVO.success(service.getByRealnameAndWorkNo(condition, condition.getRealname(), condition.getWorkNo()));
    }

    @Override
    public JsonVO<PageVO<AddressbookVO>> getByRealname(AddressbookQuery condition) {
        return null;
    }

    @Override
    public JsonVO<PageVO<AddressbookVO>> getByWorkNo(AddressbookQuery condition) {
        return null;
    }


}

