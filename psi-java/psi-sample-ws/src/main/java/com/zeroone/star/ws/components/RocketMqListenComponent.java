package com.zeroone.star.ws.components;

import com.zeroone.star.project.dto.notify.SampleNotifyDTO;
import com.zeroone.star.ws.service.ChatServer;
import lombok.extern.slf4j.Slf4j;
import org.springframework.cloud.stream.annotation.StreamListener;
import org.springframework.cloud.stream.messaging.Sink;
import org.springframework.stereotype.Component;

import javax.annotation.Resource;

/**
 * <p>
 * 描述：消息订阅组件
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Slf4j
@Component
public class RocketMqListenComponent {
    @Resource
    ChatServer chat;

    @StreamListener(Sink.INPUT)
    public void listenNotify(SampleNotifyDTO notify) {
        log.info(notify.toString());
        chat.sendMessage(notify.getClientId(), notify.getMessage());
    }
}
