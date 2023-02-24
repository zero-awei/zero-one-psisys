package com.zeroone.star.paymentmanagement.exception;

import com.zeroone.star.project.vo.JsonVO;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.RestControllerAdvice;

import javax.servlet.http.HttpServletRequest;

@RestControllerAdvice
public class GlobalExceptionHandler {
    private static final Logger log = LoggerFactory.getLogger(GlobalExceptionHandler.class);

    @ExceptionHandler(BaseException.class)
    public JsonVO baseException(BaseException e, HttpServletRequest request) {
        String requestURI = request.getRequestURI();
        log.error("请求地址'{}',参数为：'{}'，发生异常为：'{}',异常码为：'{}'", requestURI, e.getArgs(), e.getDefaultMessage(), e.getCode());
        return JsonVO.create(null, Integer.valueOf(e.getCode()), e.getDefaultMessage());

    }

    @ExceptionHandler(RuntimeException.class)
    public JsonVO handleRuntimeException(RuntimeException e, HttpServletRequest request) {
        String requestURI = request.getRequestURI();
        log.error("请求地址'{}',发生未知异常.", requestURI, e);
        return JsonVO.fail(e.getMessage());
    }

    /**
     * 系统异常
     */
    @ExceptionHandler(Exception.class)
    public JsonVO handleException(Exception e, HttpServletRequest request) {
        String requestURI = request.getRequestURI();
        log.error("请求地址'{}',发生系统异常.", requestURI, e);
        return JsonVO.fail(e.getMessage());
    }


}
