package com.zeroone.star.project.utils.easyexcel;


import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.utils.fastdfs.FastDFSEnum;
import com.zeroone.star.project.utils.fastdfs.FastDFSUtils;
import lombok.SneakyThrows;
import org.apache.poi.ss.formula.functions.T;
import org.springframework.beans.factory.annotation.Value;

import java.io.ByteArrayOutputStream;
import java.util.List;

/**
 * EasyExcel工具类
 *
 * @author iceberg-work
 */
public class EasyExcelUtils {

    private static final EasyExcelComponent EXCEL;

    @Value("${fastdfs.nginx-servers}")
    private static String serverUrl;

    static {
        EXCEL = new EasyExcelComponent();
    }

    private EasyExcelUtils() {}

    /**
     * 下载Excel
     *
     * @param sheetName 工作表名
     * @param tClass 用于数据导出的类
     * @param list 用于数据导出的列表
     * @return 二进制流
     */
    @SneakyThrows
    public byte[] download(String sheetName, Class<T> tClass, List<T> list) {
        // 导出Excel
        try (ByteArrayOutputStream out = new ByteArrayOutputStream()) {
            EXCEL.export(sheetName, out, tClass, list);
            return out.toByteArray();
        }
    }

    /**
     * 下载Excel
     *
     * @param sheetName 工作表名
     * @param list 用于数据导出的列表
     * @return 二进制流
     */
    @SneakyThrows
    public byte[] download(String sheetName, List<T> list) {
        return download(sheetName,T.class, list);
    }

    /**
     * 下载Excel
     *
     * @param sheetName 工作表名
     * @param tClass 用于数据导出的类
     * @param list 用于数据导出的列表
     * @return 下载链接
     */
    @SneakyThrows
    public String downloadUrl(String sheetName, Class<T> tClass, List<T> list) {
        // 导出Excel
        byte[] out = download(sheetName, tClass, list);
        // 上传到fastdfs
        String suffix = "xlsx";
        FastDFSEnum res = FastDFSUtils.upload(out, suffix);
        // 处理传递结果
        if (res.isFailed()) {
            return null;
        }
        return (String) res.getData();
    }

    /**
     * 下载Excel
     *
     * @param sheetName 工作表名
     * @param list 用于数据导出的列表
     * @return 下载链接
     */
    @SneakyThrows
    public String downloadUrl(String sheetName, List<T> list) {
        return downloadUrl(sheetName, T.class, list);
    }
}
