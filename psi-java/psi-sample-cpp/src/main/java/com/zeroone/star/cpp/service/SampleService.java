package com.zeroone.star.cpp.service;

import com.zeroone.star.cpp.callback.CppServiceFallBack;
import com.zeroone.star.cpp.config.FeignConfiguration;
import com.zeroone.star.project.dto.cpp.SampleDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.cpp.SampleVO;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.*;

import java.util.Map;

/**
 * <p>
 * 描述：示例声明式服务接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@FeignClient(
        name = "${cpp.sample.name}",
        url = "${cpp.sample.url}",
        fallbackFactory = CppServiceFallBack.class,
        configuration = FeignConfiguration.class
)
public interface SampleService {
    @GetMapping("get")
    JsonVO<PageVO<SampleVO>> get(@RequestParam Map<String, Object> params);

    @PostMapping("post")
    JsonVO<Long> post(@RequestParam Map<String, Object> params);

    @PutMapping("put")
    JsonVO<Long> put(@RequestParam Map<String, Object> params);

    @DeleteMapping("delete")
    JsonVO<Long> delete(@RequestParam Map<String, Object> params);

    @PostMapping("json")
    JsonVO<SampleVO> json(@RequestBody SampleDTO dto);
}
