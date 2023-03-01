//package com.zeroone.star.payablemanagement.mapper;
//
//
//import com.zeroone.star.payablemanagement.entity.FinPayable;
//import com.zeroone.star.project.dto.payablemanagement.PayableDTO;
//import com.zeroone.star.project.vo.payablemanagement.PayableVO;
//import org.mapstruct.Mapper;
//import org.mapstruct.factory.Mappers;
//
//
//@Mapper
//public interface PayableConverter {
//    PayableConverter INSTANCE = Mappers.getMapper(PayableConverter.class);
//
//    //将实体类转换为DTO
//    PayableDTO payableEntity2DTO(FinPayable entity);
//    //将DTO转换为实体类
//    FinPayable payableDTO2Entity(PayableDTO payableDTO);
//    //将实体类转换为VO
//    PayableVO payableEntity2VO(FinPayable entity);
//    //将VO转换为实体类
//    FinPayable payableVO2Entity(PayableVO payableVO);
//}
