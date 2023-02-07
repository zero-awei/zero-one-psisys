package com.zeroone.star.cpp.callback;

import com.zeroone.star.cpp.service.impl.CppServiceImpl;
import feign.hystrix.FallbackFactory;
import org.springframework.stereotype.Component;

/**
 * <p>
 * 描述：服务异常工厂
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Component
public class CppServiceFallBack implements FallbackFactory<CppServiceImpl> {
    @Override
    public CppServiceImpl create(Throwable cause) {
        return new CppServiceImpl(cause);
    }
}
