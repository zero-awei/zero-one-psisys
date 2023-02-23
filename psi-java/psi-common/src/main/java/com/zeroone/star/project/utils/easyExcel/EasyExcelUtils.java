package com.zeroone.star.project.utils.easyExcel;

import com.alibaba.excel.context.AnalysisContext;
import com.alibaba.excel.event.AnalysisEventListener;
import lombok.extern.slf4j.Slf4j;

import java.util.ArrayList;
import java.util.List;
import java.util.function.Consumer;
@Slf4j
public class EasyExcelUtils {
    /**
     * @param consumer   传入一个消费者接口对象，作用：业务逻辑处理
     * @param thresshold 批处理阈值，作用：减轻数据库的压力
     * @param <T>        实体类
     */
    public static <T> AnalysisEventListener<T> getListener(Consumer<List<T>> consumer, int thresshold) {
        return new AnalysisEventListener<T>() {
            /**
             * 存储对象
             */
            List<T> list = new ArrayList<>(thresshold);

            //easyExcel每次从Excel中读取一行数据就会调用一次invoke方法
            @Override
            public void invoke(T t, AnalysisContext analysisContext) {
                log.info("read item: {}", t.toString());
                list.add(t);
                if (list.size() >= thresshold) {
                    consumer.accept(list);
                    list.clear();
                }
            }

            //easyExcel在将Excel表中数据读取完毕后，最终执行此方法
            @Override
            public void doAfterAllAnalysed(AnalysisContext analysisContext) {
                //最后,如果size<thresshold就在这里进行数据的处理
                if (list.size() > 0) {
                    consumer.accept(list);
                }
            }
        };
    }

}
