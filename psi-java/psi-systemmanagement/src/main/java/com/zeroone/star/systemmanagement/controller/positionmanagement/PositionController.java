package com.zeroone.star.systemmanagement.controller.positionmanagement;

import com.zeroone.star.project.dto.systemmanagement.positionmanagement.PositionDTO;
import com.zeroone.star.project.query.systemmanagement.positionmanagement.PositionQuery;
import com.zeroone.star.project.systemmanagement.positionmanagement.PositionApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
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

    @ApiOperation("添加职务")
    @PostMapping("/addPosition")
    @Override
    public JsonVO<String> savePosition(PositionDTO positionDTO) {
        return null;
    }


    @ApiOperation(value = "修改职务")
    @PostMapping("updatePosition")
    @Override
    public JsonVO<String> updatePosition(PositionDTO positionDTO) {
        return null;
    }


    @ApiOperation(value = "删除职务")
    @DeleteMapping("/deletePosition")
    @Override
    public JsonVO<String> deletePosition(String positionId) {
        //service
        iPositionService.deletePositionById(positionId);
        return JsonVO.success("删除成功");
    }

    @ApiOperation(value = "查询职级")
    @DeleteMapping("/queryPostRank")
    @Override
    public JsonVO<List<String>> queryPostRank() {
        //service
        return null;
    }
}
