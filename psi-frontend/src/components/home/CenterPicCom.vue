<template>
  <div>
    <el-card class="box-card">
      <template #header>
        <div class="card-header">
          <span>销售金额</span>
          <el-icon style="color:blue; top:-15px;">
            <Refresh />
          </el-icon>
        </div>
      </template>
      <div id="div1" style="width:230px;height:195px;float: left;"></div>
    </el-card>

 <!--    <el-card class="box-card">
      <template #header>
        <div class="card-header">
          <span>销售金额</span>
          <el-icon style="color:blue; top:-15px;">
            <Refresh />
          </el-icon>
        </div>
      </template>
      <div id="div1" style="width:273px;height:176px;float: left;"></div>
    </el-card>

    <el-card class="box-card">
      <template #header>
        <div class="card-header">
          <span>销售金额</span>
          <el-icon style="color:blue; top:-15px;">
            <Refresh />
          </el-icon>
        </div>
      </template>
      <div id="div1" style="width:273px;height:176px;float: left;"></div>
    </el-card>

    <el-card class="box-card">
      <template #header>
        <div class="card-header">
          <span>销售金额</span>
          <el-icon style="color:blue; top:-15px;">
            <Refresh />
          </el-icon>
        </div>
      </template>
      <div id="div1" style="width:273px;height:176px;float: left;"></div>
    </el-card> -->
    <!-- <div id="div2" style="width: 700px;height:300px;float: left;margin:20px"></div>
    <div id="div3" style="width: 700px;height:300px;float: left;margin:20px"></div>
    <div id="div4" style="width: 700px;height:300px;float: left;margin:20px"></div> -->
  </div>
</template>

<script setup>
import {  reactive,onMounted,onUpdated  } from 'vue'
import * as echarts from "echarts"
// import echarts from 'echarts'
import { getSalmList} from './api/CenterCom.js'
import { Refresh } from '@element-plus/icons-vue'


// import option1 from "@/static/option.js"
// import option2 from  "@/static/option.js"
// import option3 from  "@/static/option.js"
// import option4 from  "@/static/option.js"
//销售数据
const SalmList =reactive({
  month:[],
  money:[]
}) 

//请求数据
function doGetSalmList() {
  getSalmList(
    {},
    (data) => {
    data.forEach((item, index) => {
    let obj = item
    SalmList.month.push(obj.month)
    SalmList.money.push(obj.money)
  })
      console.log(data)
    },
    console.log(SalmList),
    // 失败回调函数
    (msg) => {
      ElMessage.warning(msg)
    }
  )
}



onMounted(()=>{
  getOption1();
  doGetSalmList();
   // this.getOption2();
    // this.getOption3();
    // this.getOption4();
})
console.log(SalmList.month)



 
function getOption1() {
  var myEcharts = echarts.init(document.getElementById("div1"));
      console.log(SalmList.month)
      //option1 柱状图
        var option1 = {
                yAxis: {
                  type:'value'
                },
                xAxis: {
                  type:'category',
                  data: SalmList.month,   // []将数据保存到json中，使用axios读取数据。axios.get("json路径").then(res=>{})  
                },
                tooltip: {
                  trigger: "axis"
                },
                grid: {
                  top: '4%',
                  left: '3%',
                  right: '4%',
                  bottom: '10%',
                  containLabel: true,
                },
                series: [{
                    type: 'bar',
                    itemStyle: {
                    color: '#1890ff'
                  },
                    markPoint: {
                      data: [
                        {
                          type: 'max', name: '最大值'
                        },{
                          type: 'min', name: '最小值'
                        }
                      ]
                    },
                    markLine: {
                      data: [
                        {
                          type: 'average', name: '平均值'
                        }
                      ]
                    },
                    label: {
                      show: true,
                      rotate: 30,
                      position: 'inside'
                    },
                    barWidth: '50%',
                    data: SalmList.money
                }]
              }

      myEcharts.setOption(option1);
                }


    //axios请求数据   
    // getOption1(){
    //   var myEcharts = echarts.init(document.getElementById("div1"));
    //   myEcharts.setOption(option1);
    //   axios.get("/js/testData.json").then(res => {
    //     // // console.log(res.data)
    //     myEcharts.setOption(
    //       {
    //         xAxis: {
    //           data: res.data.month
    //         },
    //         series: {
    //           data: res.data.data,
    //           label: {
    //               show: true
    //           }
    //         }
    //       }
    //     )
    //   })
    // },
    // // getOption2(){
    //   var myEcharts = echarts.init(document.getElementById("div2"));
    //   myEcharts.setOption(option2);
    //   axios.get("../../static/div2/data.json").then(res => {
    //     myEcharts.setOption(
    //       {
    //         xAxis: {
    //           data: res.data.data1
    //         },
    //         series: {
    //           data: res.data.data2,
    //           label: {
    //               show: true
    //           }
    //           }
    //       }
    //     )
    //   })
    // },
    // getOption3(){
    //   var myEcahrts = echarts.init(document.getElementById("div3"));
    //   myEcahrts.setOption(option3);
    //   axios.get("../../static/div3/data.json").then(res => {
    //     myEcahrts.setOption({
    //       series: {
    //         data: res.data.data1,
    //         label: {
    //             show: true
    //         }
    //       }
    //     })
    //   })
    // },
    // getOption4(){
    //   var myEcharts = echarts.init(document.getElementById("div4"));
    //   myEcharts.setOption(option4);
    //   axios.get("../../static/div4/data.json").then(res => {
    //     myEcharts.setOption({
    //       radar: {indicator: res.data.indicator},
    //       series: {
    //         data: res.data.data,
    //         label: {
    //             show: true
    //         },
    //         tooltip: {
    //           trigger: 'item'
    //         }
    //       }

    //     })
    //   })
    // }

</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
* {
  margin: 0;
}

div {
  top: 3px;
  left: -4px;
  width: 290px;
}

.card-header {
  display: flex;
  justify-content: space-between;
  align-items: center;
}

.card-header span {
  top: -15px;
  display: inline-block;
  flex: 1;
  white-space: nowrap;
  text-overflow: ellipsis;
  color: black;
  font-size: 16px;
}
</style>