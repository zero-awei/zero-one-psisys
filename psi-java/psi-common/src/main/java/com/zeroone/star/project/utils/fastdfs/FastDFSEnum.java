package com.zeroone.star.project.utils.fastdfs;


/**
 * FastDFS枚举类，枚举调用结果
 *
 * @author iceberg-work
 */

public enum FastDFSEnum {
    MISSING_FILE_NAME("缺失文件名", -1),
    UPLOAD_FAILED("文件上传失败", -2),
    DELETE_FAILED("文件删除失败", -3),
    DOWNLOAD_FAILED("文件下载失败", -4),
    SUCCESSFUL("操作成功", 0);

    /**
     * 提示信息
     */
    private final String message;

    /**
     * 用于标识是否成功的编码
     */
    private final int code;

    /**
     * 成功时传递的数据
     */
    private Object data;

    FastDFSEnum(String message, int code) {
        this.message = message;
        this.code = code;
    }

    FastDFSEnum addData(Object data) {
        this.data = data;
        return this;
    }

    public boolean isFailed() {
        return this.code < 0;
    }

    public String getMessage() {
        return message;
    }
    public int getCode() {
        return code;
    }

    public Object getData() {
        return data;
    }

    @Override
    public String toString() {
        return this.message;
    }
}
