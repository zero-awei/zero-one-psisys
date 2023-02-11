package com.zeroone.star.payment.controller;

import com.zeroone.star.project.dto.payment.ModifyDTO;
import com.zeroone.star.project.payment.ModifyApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("modify")
@Api(tags = "测试")
public class ModifyController implements ModifyApis {

    @PutMapping("submit")
    @ApiOperation(value = "修改功能（有申请）")
    @Override
    public JsonVO<String> modifyById(ModifyDTO modifyDTO) {
        return JsonVO.success("1111");
    }
}
