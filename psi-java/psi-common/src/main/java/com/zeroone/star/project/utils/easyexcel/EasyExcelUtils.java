package com.zeroone.star.project.utils.easyexcel;


import com.alibaba.excel.EasyExcel;
import com.alibaba.excel.EasyExcelFactory;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.easyexcel.ExcelReadListener;
import com.zeroone.star.project.utils.fastdfs.FastDFSEnum;
import com.zeroone.star.project.utils.fastdfs.FastDFSUtils;
import com.zeroone.star.project.utils.response.ResponseUtils;
import lombok.SneakyThrows;
import org.apache.poi.ss.formula.functions.T;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.ResponseEntity;
import org.springframework.web.multipart.MultipartFile;

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
     * 导出Excel
     *
     * @param sheetName 工作表名
     * @param tClass 用于数据导出的类
     * @param list 用于数据导出的列表
     * @return 二进制流
     */
    @SneakyThrows
    public static <T> byte[] exports(String sheetName, Class<T> tClass, List<T> list) {
        // 导出Excel
        try (ByteArrayOutputStream out = new ByteArrayOutputStream()) {
            EXCEL.export(sheetName, out, tClass, list);
            return out.toByteArray();
        }
    }

    /**
     * 导出Excel
     *
     * @param sheetName 工作表名
     * @param tClass 用于数据导出的类
     * @param list 用于数据导出的列表
     * @return 下载链接
     */
    @SneakyThrows
    public static <T> String exportsUrl(String sheetName, Class<T> tClass, List<T> list) {
        // 导出Excel
        byte[] out = exports(sheetName, tClass, list);
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
     * @param tClass 用于数据导出的类
     * @param list 列表数据
     * @return HTTP响应体
     */
    public static <T> ResponseEntity<byte[]> downloads(String sheetName, Class<T> tClass, List<T> list) {
        byte[] bytes = EasyExcelUtils.exports(sheetName, tClass, list);
        return ResponseUtils.bytes2Xlsx(bytes, sheetName);
    }

    /**
     * 导入Excel
     *
     * @param file 二进制文件流
     * @param tClass 用于数据导入的类
     * @return 列表数据
     */
    @SneakyThrows
    public static <T> List<T> imports(MultipartFile file, Class<T> tClass) {
        ExcelReadListener<T> excelReadListener = new ExcelReadListener<>();
        EasyExcelFactory.read(file.getInputStream(), tClass, excelReadListener).sheet().doRead();
        return excelReadListener.getDataList();
    }
}
