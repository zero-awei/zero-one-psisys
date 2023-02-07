package com.zeroone.star.cpp.service.impl;

import com.zeroone.star.cpp.service.SampleService;
import com.zeroone.star.project.dto.cpp.SampleDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.cpp.SampleVO;
import lombok.AllArgsConstructor;

import java.util.Map;

/**
 * <p>
 * 描述：服务熔断后提示信息
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@AllArgsConstructor
public class CppServiceImpl implements SampleService {
    private Throwable err;

    private void setMessage(JsonVO<?> vo) {
        if (err.getMessage() != null) {
            vo.setMessage(err.getMessage());
        } else {
            vo.setMessage(err.getClass().toGenericString());
        }
    }

    @Override
    public JsonVO<PageVO<SampleVO>> get(Map<String, Object> params) {
        JsonVO<PageVO<SampleVO>> vo = JsonVO.fail(null);
        setMessage(vo);
        return vo;
    }

    @Override
    public JsonVO<Long> post(Map<String, Object> params) {
        JsonVO<Long> vo = JsonVO.fail(null);
        setMessage(vo);
        return vo;
    }

    @Override
    public JsonVO<Long> put(Map<String, Object> params) {
        JsonVO<Long> vo = JsonVO.fail(null);
        setMessage(vo);
        return vo;
    }

    @Override
    public JsonVO<Long> delete(Map<String, Object> params) {
        JsonVO<Long> vo = JsonVO.fail(null);
        setMessage(vo);
        return vo;
    }

    @Override
    public JsonVO<SampleVO> json(SampleDTO dto) {
        JsonVO<SampleVO> vo = JsonVO.fail(null);
        setMessage(vo);
        return vo;
    }
}
