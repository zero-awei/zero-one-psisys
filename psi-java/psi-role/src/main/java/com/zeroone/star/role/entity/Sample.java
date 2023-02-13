package com.zeroone.star.role.entity;

import java.io.Serializable;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 
 * </p>
 *
 * @author ali
 * @since 2023-02-12
 */
@Getter
@Setter
public class Sample implements Serializable {

    private static final long serialVersionUID = 1L;

    private Integer id;

    private String name;

    private String sex;

    private Integer age;


}
