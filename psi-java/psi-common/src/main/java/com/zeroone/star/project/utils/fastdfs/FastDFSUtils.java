package com.zeroone.star.project.utils.fastdfs;

import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import lombok.SneakyThrows;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.web.multipart.MultipartFile;

/**
 * FastDFS工具类
 *
 * @author iceberg-work
 */
public class FastDFSUtils {
    
    private static final FastDfsClientComponent DFS_CLIENT;

    @Value("${fastdfs.nginx-servers}")
    private static String serverUrl;
    
    static {
        DFS_CLIENT = new FastDfsClientComponent();
    }

    private FastDFSUtils() {}

    /**
     * 上传文件
     *
     * @param file 文件
     * @return 是否成功，如果成功则附加下载链接
     */
    @SneakyThrows
    public static FastDFSEnum upload(MultipartFile file) {
        // 获取文件名
        String filename = file.getOriginalFilename();
        if (filename == null) {
            return FastDFSEnum.MISSING_FILE_NAME;
        }
        // 获取文件的后缀
        String suffix = filename.substring(filename.lastIndexOf(".") + 1);
        // 上传文件到FastDFS
        FastDfsFileInfo res = DFS_CLIENT.uploadFile(file.getBytes(), suffix);
        if (res == null) {
            return FastDFSEnum.UPLOAD_FAILED;
        }
        // 拼接文件下载链接
        String downloadUrl = getDownloadUrlByFastDfsFileInfo(res, serverUrl, true);
        return FastDFSEnum.SUCCESSFUL.addData(downloadUrl);
    }

    /**
     * 上传文件
     *
     * @param bytes 二进制流
     * @param suffix 文件后缀
     * @return 是否成功，如果成功则附加下载链接
     */
    @SneakyThrows
    public static FastDFSEnum upload(byte[] bytes, String suffix) {
        FastDfsFileInfo res = DFS_CLIENT.uploadFile(bytes, suffix);
        if (res == null) {
            return FastDFSEnum.UPLOAD_FAILED;
        }
        // 拼接文件下载链接
        String downloadUrl = getDownloadUrlByFastDfsFileInfo(res, serverUrl, true);
        return FastDFSEnum.SUCCESSFUL.addData(downloadUrl);
    }

    public static String getDownloadUrlByFastDfsFileInfo(FastDfsFileInfo info,
                                                         String serverUrl,
                                                         boolean isToken) {
        return DFS_CLIENT.fetchUrl(info, serverUrl, isToken);
    }

    /**
     * 下载文件
     *
     * @param group 桶
     * @param storageId 标识
     * @return 下载链接
     */

    public static FastDFSEnum download(String group, String storageId) {
        // 进行下载
        byte[] bytes;
        try {
            bytes = DFS_CLIENT.downloadFile(FastDfsFileInfo.builder().storageId(storageId).group(group).build());
        } catch (Exception e) {
            return FastDFSEnum.DOWNLOAD_FAILED;
        }
        return FastDFSEnum.SUCCESSFUL.addData(bytes);
    }

    /**
     * 删除文件
     *
     * @param group 桶
     * @param storageId 标识
     * @return 是否成功
     */
    @SneakyThrows
    public static FastDFSEnum deleteFile(String group, String storageId) {
        int res = DFS_CLIENT.deleteFile(FastDfsFileInfo.builder().group(group).storageId(storageId).build());
        if (res == 0) {
            return FastDFSEnum.SUCCESSFUL.addData(res);
        }
        return FastDFSEnum.DELETE_FAILED;
    }
}
