package com.zeroone.star.psisysmanagement.util;

import java.util.Random;

/**
 * @Description ID生成器
 * @Author Freasy
 * @Date 2023-02-23
 * @Version 1.0
 */
public class IDGenerator {
    private static final String[] alphabetArr = new String[]{"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

    public static String nextID() {
        StringBuilder stringBuffer = new StringBuilder();
        for (int i = 0; i < 15; i++) {
            Random random = new Random();
            stringBuffer.append(alphabetArr[random.nextInt(alphabetArr.length)]);
        }

        return stringBuffer.toString();
    }

}
