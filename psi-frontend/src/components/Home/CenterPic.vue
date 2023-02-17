<template>
<div ref="echart1" style=" width=500px;height=280px">
</div>    
</template>
<script>
//定义数组接受传入数据
import { getData } from "@/assets/testData.json"
import * as echarts from "echarts"
export default {
    data() {
        return {

        }
    },
    mounted() {
        getData().then(({ data }) => {
            const { tableData } = data.data
            this.tableData = tableData
            //基于准备好的dom，初始化echarts实例
            const echarts1 = echarts.init(this.$refs.echarts1)
            //指定图表的配置项和数据
            var echarts1Option = {}
            //处理xAxis 解构数据
            const {orderData} = data.data
            //返回对象枚举
            const xAxis = Object.keys(orderData.data[0])
            const xAxisData = {
                data:xAxis
            }
            echarts1Option.xAxis =xAxisData
            echarts1Option.yAxis ={}
            echarts1Option.legend =xAxisData
            echarts1Option.series = []
            xAxis.forEach(key => {
                echarts1Option.series.push({
                    name: key,
                    data: orderData.data.map(item => item[key]),
                    //折线图
                    type:"line"
                })
            })
            //使用指定的配置项和数据显示图表
            echarts1.setOption(echarts1Option)
       })
    }
    
}
</script>