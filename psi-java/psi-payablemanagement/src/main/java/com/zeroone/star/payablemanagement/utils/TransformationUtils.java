package com.zeroone.star.payablemanagement.utils;


import org.apache.commons.lang3.StringUtils;

import java.lang.reflect.Field;
import java.lang.reflect.Method;


/**
 * 实体类与DTO，VO相互转换的工具类
 *
 */
public class TransformationUtils {
    public static void toDto(Class pc, Object po, Class dc, Object dto) throws Exception {
        //获取实体类的全部属性
        Field[] dcFields = dc.getDeclaredFields();
        Field[] pcFields = pc.getDeclaredFields();

        for (Field dcField : dcFields) {
            //AccessibleTest 类中的成员变量为private
            //取消属性的访问权限控制，即使private属性也可以进行访问
            dcField.setAccessible(true);
            String dcName = dcField.getName();
            //屏蔽序列化的字段
            if ("serialVersionUID".equals(dcName)) {
                continue;
            }
            //遍历entity
            for (Field pcField : pcFields) {
                pcField.setAccessible(true);
                String pcName = pcField.getName();
                if (dcName.equals(pcName)) {
                    String pcMethodName = "get" + StringUtils.capitalize(pcName);
                    Method pcMethod = pc.getDeclaredMethod(pcMethodName);
                    dcField.set(dto, pcMethod.invoke(po));
                }
            }

        }
    }

    public static <IN,OUT> OUT toAllDto(IN in,Class<OUT> clazz) {
        OUT out = null;
        try {
            out= clazz.newInstance();
            TransformationUtils.toDto(in.getClass(), in, out.getClass(), out);

        } catch (Exception e) {
            e.printStackTrace();
        }
        return out;
    }


    public static <E,T> T convert(E e,Class<T> clazz) throws IllegalAccessException {
        T t = null;
        try {
            t = clazz.newInstance();
            Field[] declaredFields = t.getClass().getDeclaredFields();
            Field[] fields = e.getClass().getDeclaredFields();
            /*遍历数据传输类*/
            for (Field field : fields) {
                field.setAccessible(true);
                String name = field.getName();
                Object value = field.get(e);
                /*遍历实体类寻找和该字段一样的字段*/
                for (Field field1 : declaredFields) {
                    /*判断是否为一样的字段*/
                    if (name.equals(field1.getName())) {
                        /*是的话设置值并跳出本层循环*/
                        field1.setAccessible(true);
                        field1.set(t,value);
                        break;
                    }
                }
            }
        } catch (Exception ex) {
            throw new RuntimeException(ex);
        }

        return t;
    }



//    public static FinPayable transmissionCreateDTO(PayableDTO createDTO) throws IllegalAccessException {
//        FinPayable payable = new FinPayable();
//        Field[] declaredFields = payable.getClass().getDeclaredFields();
//        Field[] fields = createDTO.getClass().getDeclaredFields();
//        /*遍历数据传输类*/
//        for (Field field : fields) {
//            field.setAccessible(true);
//            String name = field.getName();
//            Object value = field.get(createDTO);
//            /*遍历实体类寻找和该字段一样的字段*/
//            for (Field field1 : declaredFields) {
//                /*判断是否为一样的字段*/
//                if (name.equals(field1.getName())) {
//                    /*是的话设置值并跳出本层循环*/
//                    field1.setAccessible(true);
//                    field1.set(payable,value);
//                    break;
//                }
//            }
//        }
//        return payable;
//    }

}
