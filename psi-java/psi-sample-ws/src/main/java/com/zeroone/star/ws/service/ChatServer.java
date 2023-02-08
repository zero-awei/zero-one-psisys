package com.zeroone.star.ws.service;

import cn.hutool.json.JSONUtil;
import lombok.SneakyThrows;
import org.springframework.stereotype.Component;

import javax.websocket.*;
import javax.websocket.server.ServerEndpoint;
import java.util.concurrent.ConcurrentHashMap;

/**
 * <p>
 * 描述：聊天室服务
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Component
@ServerEndpoint("/chat")
public class ChatServer {
    /**
     * 客户端连接对象池
     */
    private final static ConcurrentHashMap<String, Session> SESSION_POOL = new ConcurrentHashMap<>();

    @SneakyThrows
    @OnOpen
    public void onOpen(Session session) {
        // 判断编号是否重复
        if (SESSION_POOL.containsKey(session.getQueryString())) {
            //定义一个关闭理由
            CloseReason reason = new CloseReason(CloseReason.CloseCodes.CANNOT_ACCEPT, "ID冲突连接拒绝");
            session.getUserProperties().put("reason", reason);
            session.close();
            return;
        }
        // 将客户端对象记录对象池中
        SESSION_POOL.put(session.getQueryString(), session);
        System.out.println("用户（" + session.getQueryString() + "）：开启了连接");
    }

    @SneakyThrows
    @OnMessage
    public String onMessage(String msg, Session session) {
        // 消息格式 =>  ID::消息内容
        String[] msgArr = msg.split("::", 2);
        // 群发消息
        if ("all".equalsIgnoreCase(msgArr[0])) {
            for (Session one : SESSION_POOL.values()) {
                // 排除自己
                if (session == one) {
                    continue;
                }
                // 发送消息
                one.getBasicRemote().sendText(msgArr[1]);
            }
        }
        // 私聊
        else {
            // 获取接受者
            Session target = SESSION_POOL.get(msgArr[0]);
            if (target != null) {
                target.getBasicRemote().sendText(msgArr[1]);
            }
        }
        return "消息发送成功";
    }

    @OnClose
    public void onClose(Session session) {
        // 处理拒绝连接的连接对象（不从连接池中移除）
        Object reason = session.getUserProperties().get("reason");
        if (reason instanceof CloseReason) {
            CloseReason cr = (CloseReason) reason;
            if (cr.getCloseCode() == CloseReason.CloseCodes.CANNOT_ACCEPT) {
                System.out.println("拒绝客户端（" + session.getQueryString() + "）：连接关闭");
                return;
            }
        }
        // 将连接对象移除对象池
        SESSION_POOL.remove(session.getQueryString());
        System.out.println("客户端（" + session.getQueryString() + "）：连接关闭");
    }

    @OnError
    public void onError(Session session, Throwable err) {
        System.out.println("客户端（" + session.getQueryString() + "）：连接错误，" + err.getMessage());
    }

    @SneakyThrows
    public void sendMessage(String id, Object message) {
        // 群发消息
        if ("all".equalsIgnoreCase(id)) {
            for (Session one : SESSION_POOL.values()) {
                // 发送消息
                one.getBasicRemote().sendText(JSONUtil.toJsonStr(message));
            }
        }
        // 私聊
        else {
            // 获取接受者
            Session target = SESSION_POOL.get(id);
            if (target != null) {
                target.getBasicRemote().sendText(JSONUtil.toJsonStr(message));
            }
        }
    }
}
