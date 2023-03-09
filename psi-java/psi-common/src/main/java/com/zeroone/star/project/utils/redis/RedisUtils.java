package com.zeroone.star.project.utils.redis;

import lombok.extern.slf4j.Slf4j;
import org.springframework.data.redis.core.RedisCallback;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Component;

import javax.annotation.Resource;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.concurrent.TimeUnit;

@Component
@Slf4j
public class RedisUtils {

    @Resource
    private RedisTemplate<String, Object> redisTemplate;

    /**
     * @author Gerins
     * @param key
     * @return
     */
    public Object get(String key) {
        Object value = null;
        try {
            value = redisTemplate.opsForValue().get(key);
        } catch (Exception e) {
            log.error("RedisUtils#get fail! e:{" + e.getStackTrace().toString() + "}");
        }
        return value;
    }

    /**
     * @author Gerins
     * @param key
     * @return
     */
    public boolean isExist(String key) {
        if (get(key) != null) {
            return true;
        }
        return false;
    }


    /**
     * @author Gerins
     * @desc 添加元素，并设置过期时间
     * @param key
     * @param value
     * @param timeout
     * @param timeUnit
     * @return
     */
    public int add(String key, Object value, Long timeout, TimeUnit timeUnit) {
        try {
            if (Boolean.FALSE.equals(redisTemplate.opsForValue().setIfAbsent(key, value, timeout, timeUnit))) {
                // 添加失败
                return -1;
            }

        } catch (Exception e) {
            log.error("RedisUtils#add fail! e:{" + e.getStackTrace().toString() + "}");
            return -1;
        }
        return 0;
    }


    /**
     * @author Gerins
     * @desc 添加key-value
     * @param key
     * @param value
     * @return
     */
    public int add(String key, Object value) {
        try {
            if (Boolean.FALSE.equals(redisTemplate.opsForValue().setIfAbsent(key, value))) {
                // 添加失败
                log.error("RedisUtils#add fail");
                return -1;
            }

        } catch (Exception e) {
            log.error("RedisUtils#add fail! e:{" + e.getStackTrace().toString() + "}");
            return -1;
        }
        return 0;
    }


    /**
     * @author Gerins
     * @param key
     * @return
     */
    public int del(String key) {
        try {
            if (Boolean.FALSE.equals(redisTemplate.delete(key))) {
                return -1;
            }
        } catch (Exception e) {
            log.error("RedisUtils#del fail! e:{" + e.getStackTrace().toString() + "}");
            return -1;
        }

        return 0;
    }


    /**
     * @author Gerins
     * @param key
     * @return
     */
    public Long ttl(String key) {
        Long expiredTime;
        try {
            expiredTime = redisTemplate.getExpire(key);
        } catch (Exception e) {
            log.error("RedisUtils#setEx fail! e:{" + e.getStackTrace().toString() + "}");
            return -1L;
        }

        return expiredTime;
    }


    /**
     * @author Gerins
     * @param key
     * @param value
     * @return
     */
    public Long sAdd(String key, String value) {
        Long add;
        try {
            add = redisTemplate.opsForSet().add(key, value);
            if (add < 0) {
                log.error("RedisUtils#sAdd fail! e: add to Set failed");
                return -1L;
            }
        } catch (Exception e) {
            log.error("RedisUtils#sAdd fail! e:{" + e.getStackTrace().toString() + "}");
            return -1L;
        }

        return add;
    }

    /**
     * @author Gerins
     * @param key
     * @param value
     * @return
     */
    public Long sRemove(String key, String value) {
        Long remove;
        try {
            remove = redisTemplate.opsForSet().remove(key, value);
            if (remove < 0L) return -1L;
        } catch (Exception e) {
            log.error("RedisUtils#sRemove fail! e:{" + e.getStackTrace().toString() + "}");
            return -1L;
        }

        return remove;
    }


    /**
     * @author Gerins
     * @param key
     * @param value
     * @return
     */
    public boolean sIsMember(String key, String value) {
        boolean exist;
        try {
            exist = Boolean.TRUE.equals(redisTemplate.opsForSet().isMember(key, value));
        } catch (Exception e) {
            log.error("RedisUtils#sIsMember fail! e:{" + e.getStackTrace().toString() + "}");
            return false;
        }

        return exist;
    }


    /**
     * @author Gerins
     * @param key
     * @return
     */
    public Set<Object> sMembers(String key) {
        Set<Object> members;
        try {
            members = redisTemplate.opsForSet().members(key);
        } catch (Exception e) {
            log.error("RedisUtils#sMembers fail! e:{" + e.getStackTrace().toString() + "}");
            return null;
        }

        return members;
    }

    /**
     * @author Gerins
     * @param key
     * @param values
     * @return
     */
    public int hMSET(String key, Map<String, List<String>> values) {
        try {
            redisTemplate.opsForHash().putAll(key, values);
        } catch (Exception e) {
            log.error("RedisUtils#hMSET fail! e:{" + e.getStackTrace().toString() + "}");
            return -1;
        }
        return 0;
    }


    /**
     * @author Gerins
     * @desc pipeline 设置 key-value 并设置过期时间
     * @param keyValues
     * @param seconds
     */
    public void pipelineSetEx(Map<String, String> keyValues, Long seconds) {
        try {
            redisTemplate.executePipelined((RedisCallback<String>) connection -> {
                for (Map.Entry<String, String> entry : keyValues.entrySet()) {
                    connection.setEx(entry.getKey().getBytes(), seconds,
                            entry.getValue().getBytes());
                }
                return null;
            });
        } catch (Exception e) {
            log.error("RedisUtils#pipelineSetEx fail! e:{" + e.getStackTrace().toString() + "}");
        }
    }


    /**
     * pipeline 设置 key-value 并设置过期时间
     * @author Gerins
     * @param keyValues
     * @param seconds
     * @param delta
     */
    public void pipelineHashIncrByEx(Map<String, String> keyValues, Long seconds, Long delta) {
        try {
            redisTemplate.executePipelined((RedisCallback<String>) connection -> {
                for (Map.Entry<String, String> entry : keyValues.entrySet()) {
                    connection.hIncrBy(entry.getKey().getBytes(), entry.getValue().getBytes(), delta);
                    connection.expire(entry.getKey().getBytes(), seconds);
                }
                return null;
            });
        } catch (Exception e) {
            log.error("redis pipelineSetEX fail! e:{" + e.getStackTrace().toString() + "}");
        }
    }
}