package com.zeroone.star.project.utils.easyexcel;

import com.alibaba.excel.EasyExcelFactory;
import com.alibaba.excel.ExcelWriter;
import com.alibaba.excel.write.metadata.WriteSheet;
import com.alibaba.excel.write.metadata.fill.FillConfig;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.easyexcel.ExcelReadListener;
import com.zeroone.star.project.utils.fastdfs.FastDFSEnum;
import com.zeroone.star.project.utils.fastdfs.FastDFSUtils;
import com.zeroone.star.project.utils.response.ResponseUtils;
import lombok.SneakyThrows;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.ResponseEntity;
import org.springframework.web.multipart.MultipartFile;

import java.io.ByteArrayOutputStream;
import java.util.List;
import java.util.Map;
import java.util.Objects;

/**
 * EasyExcel工具类
 *
 * @author iceberg-work
 */
public class EasyExcelUtils {

    private static final EasyExcelComponent EXCEL;

    @Value("${fastdfs.nginx-servers}")
    private static String serverUrl;

    private static final String BASE_PATH;

    static {
        EXCEL = new EasyExcelComponent();
        BASE_PATH = "templates/";
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
     * 按照模板导出Excel;
     * 模板应保存在`BASE_PATH`.
     *
     * @param excelName 模板Excel文件名
     * @param list 填充物，模板表中{.xxx}的xxx对应Bean的成员属性
     * @param map 填充物，模板表中{xxx}的xxx对应key
     * @return 二进制文件流
     */
    @SneakyThrows
    public static <T> byte[] exportsAsTemplate(String excelName, List<T> list, Map<String, Object> map) {
        String templateFileName =
                Objects.requireNonNull(EXCEL.getClass().getClassLoader().getResource(BASE_PATH + excelName)).getPath();
        ByteArrayOutputStream out = new ByteArrayOutputStream();

        ExcelWriter excelWriter = null;
        try {
            excelWriter = EasyExcelFactory.write(out).withTemplate(templateFileName).build();
            WriteSheet writeSheet = EasyExcelFactory.writerSheet().build();
            // 这里注意 入参用了forceNewRow 代表在写入list的时候不管list下面有没有空行 都会创建一行，然后下面的数据往后移动。默认 是false，会直接使用下一行，如果没有则创建。
            // forceNewRow 如果设置了true,有个缺点 就是他会把所有的数据都放到内存了，所以慎用
            // 简单的说 如果你的模板有list,且list不是最后一行，下面还有数据需要填充 就必须设置 forceNewRow=true 但是这个就会把所有数据放到内存 会很耗内存
            // 如果数据量大 list不是最后一行 参照下一个
            FillConfig fillConfig = FillConfig.builder().forceNewRow(Boolean.FALSE).build();
            excelWriter.fill(list, fillConfig, writeSheet);
            excelWriter.fill(map, writeSheet);
        } finally {
            // 千万别忘记关闭流
            if (excelWriter != null) {
                excelWriter.finish();
            }
            out.close();
        }
        return out.toByteArray();
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
     * 按照模板下载Excel
     *
     * @param excelName 模板Excel文件名
     * @param list 填充物，模板表中{.xxx}的xxx对应Bean的成员属性
     * @param map 填充物，模板表中{xxx}的xxx对应key
     * @return
     */
    public static <T> ResponseEntity<byte[]> downloadsAsTemplate(String excelName, List<T> list, Map<String, Object> map) {
        byte[] bytes = EasyExcelUtils.exportsAsTemplate(excelName, list, map);
        return ResponseUtils.bytes2Xlsx(bytes, excelName);
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
