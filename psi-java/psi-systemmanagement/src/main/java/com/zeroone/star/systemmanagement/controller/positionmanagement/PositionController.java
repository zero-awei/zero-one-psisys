package com.zeroone.star.systemmanagement.controller.positionmanagement;

import com.zeroone.star.project.dto.systemmanagement.positionmanagement.PositionDTO;
import com.zeroone.star.project.query.systemmanagement.positionmanagement.PositionQuery;
import com.zeroone.star.project.systemmanagement.positionmanagement.PositionApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.systemmanagement.positionmanagement.PositionVO;
import com.zeroone.star.systemmanagement.service.positionmanagement.IPositionService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import java.util.List;

/**
 * @Description
 * @Author j2 - mumu
 * @Data 2023-02-11 17:10
 */
@RestController
@RequestMapping("/systemmanagement/sys-position")
@Api(tags = "职务管理")
@Validated
public class PositionController implements PositionApis {

    @Autowired
    IPositionService iPositionService;

    @ApiOperation("查询所有职务")
    @GetMapping("/queryall")
    @Override
    public JsonVO<PageVO<PositionVO>> listPositionByPageAndCondition(PositionQuery positionQuery) {
        return null;
    }

    @ApiOperation("添加职务（返回值data值表示插入成功与否）")
    @PostMapping("/addPosition")
    @Override
    public JsonVO<String> savePosition(PositionDTO positionDTO) {
        return null;
    }


    @ApiOperation(value = "修改职务（返回值data值表示更新成功与否）")
    @PostMapping("updatePosition")
    @Override
    public JsonVO<String> updatePosition(PositionDTO positionDTO) {
        if (positionDTO == null){
            return JsonVO.fail("无法执行请求,请联系管理员！");
        }
        String result = iPositionService.update(positionDTO);
        if (result.equals("更新失败")){
            return JsonVO.fail(result);
        }
        return JsonVO.success(result);
    }


    @ApiOperation(value = "删除职务（返回值data值表示删除成功与否）")
    @DeleteMapping("/deletePosition")
    @Override
    public JsonVO<String> deletePosition(String positionId) {
        if(positionId == null){
            return JsonVO.fail("无法执行请求,请联系管理员！");
        }
        String result = iPositionService.deletePositionById(positionId);
        if (result.equals("删除失败")){
            return JsonVO.fail(result);
        }
        return JsonVO.success(result);
    }

    @ApiOperation(value = "查询职级")
    @DeleteMapping("/queryPostRank")
    @Override
    public JsonVO<List<String>> queryPostRank() {
        //service
        return null;
    }
}
