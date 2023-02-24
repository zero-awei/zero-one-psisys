package com.zeroone.star.basedetail.entity;


import cn.hutool.core.util.StrUtil;
import com.alibaba.excel.converters.Converter;
import com.alibaba.excel.converters.ReadConverterContext;
import com.alibaba.excel.converters.WriteConverterContext;
import com.alibaba.excel.enums.CellDataTypeEnum;
import com.alibaba.excel.metadata.data.WriteCellData;

/**
 * @author Third uncle
 * @date 2023/2/16 - 17:52
 */
public class IsEnabledConverter implements Converter<String> {
//    private static final String YES = "是";
//    private static final String NO = "否";
//
//    // Java数据类型 integer
//    @Override
//    public Class supportJavaTypeKey() {
//        return Integer.class;
//    }
//
//    // Excel文件中单元格的数据类型  string
//    @Override
//    public CellDataTypeEnum supportExcelTypeKey() {
//        return CellDataTypeEnum.STRING;
//    }

    @Override
    public Class<?> supportJavaTypeKey() {
        return String.class;
    }

    @Override
    public CellDataTypeEnum supportExcelTypeKey() {
        return CellDataTypeEnum.STRING;
    }

    /**
     * 这里是读的时候会调用
     * @return
     */
    @Override
    public String convertToJavaData(ReadConverterContext<?> context) {
//        return context.getReadCellData().getStringValue();
        String readCellValue = context.getReadCellData().getStringValue();
        if(StrUtil.isNotEmpty(readCellValue)){
            readCellValue = ("是").equals(readCellValue) ? "1":"0";
        }
        return readCellValue;
    }

    /**
     * 这里是写的时候会调用
     */
    @Override
    public WriteCellData<?> convertToExcelData(WriteConverterContext<String> context) {
        String cellValue = context.getValue();
        if(StrUtil.isNotEmpty(cellValue)){
            cellValue = ("1").equals(context.getValue()) ? "是":"否";
        }
        return new WriteCellData<>(cellValue);
    }

}
