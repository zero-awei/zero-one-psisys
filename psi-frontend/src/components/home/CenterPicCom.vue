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
      <div id="div1" style="width:250px;height:180px;float: left;padding:0;"></div>
    </el-card>

       <el-card class="box-card">
      <template #header>
        <div class="card-header">
          <span>毛利润</span>
          <el-icon style="color:blue; top:-15px;">
            <Refresh />
          </el-icon>
        </div>
      </template>
      <div id="div2" style="width:250px;height:180px;float: left;padding:0;"></div>
    </el-card>

    <el-card class="box-card">
      <template #header>
        <div class="card-header">
          <span>采购金额</span>
          <el-icon style="color:blue; top:-15px;">
            <Refresh />
          </el-icon>
        </div>
      </template>
      <div id="div3" style="width:250px;height:180px;float: left;padding:0;"></div>
    </el-card>

    <el-card class="box-card">
      <template #header>
        <div class="card-header">
          <span>库存结存金额</span>
          <el-icon style="color:blue; top:-15px;">
            <Refresh />
          </el-icon>
        </div>
      </template>
      <div id="div4" style="width:250px;height:180px;float: left;padding:0;"></div>
    </el-card> 

  </div>
</template>

<script setup>
import { reactive, onMounted, onUpdated, nextTick } from 'vue'
import * as echarts from "echarts"
// import echarts from 'echarts'
import { getSalmList } from './api/CenterCom.js'
import { getSaloList,getPuroList,getQussList} from './api/datalist.js'
import { Refresh } from '@element-plus/icons-vue'
// import option1 from "@/static/option.js"
// import option2 from  "@/static/option.js"
// import option3 from  "@/static/option.js"
// import option4 from  "@/static/option.js"
//销售数据
const SalmList = reactive({
  month: [],
  money: []
})
//毛利润
const SaloList = reactive({
  x: [],
  y: []
})
//采购金额
const PuroList = reactive({
  x: [],
  y: []
})
//库存结存金额
const QussList = reactive({
  x: [],
  y: []
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
      let flag = true
      getOption1(flag);
      console.log(data)
    },
    console.log(SalmList),
    // 失败回调函数
    (msg) => {
      let flag = false
      getOption1(flag);
      ElMessage.warning(msg)
    }
  )
}
//毛利润
function doGetSaloList() {
  getSaloList(
    {},
    (data) => {
      data.forEach((item, index) => {
        let obj = item
        SaloList.x.push(obj.x)
        SaloList.y.push(obj.y)
      })
      let flag1 = true
      getOption2(flag1);
      console.log(data)
    },
    console.log(SaloList),
    // 失败回调函数
    (msg) => {
      let flag1 = false
      getOption2(flag1);
      ElMessage.warning(msg)
    }
  )
}
//采购金额
function doGetPuroList() {
  getPuroList(
    {},
    (data) => {
      data.forEach((item, index) => {
        let obj = item
        PuroList.x.push(obj.x)
        PuroList.y.push(obj.y)
      })
      let flag2 = true
      getOption3(flag2);
      console.log(data)
    },
    console.log(PuroList),
    // 失败回调函数
    (msg) => {
      let flag2 = false
      getOption3(flag2);
      ElMessage.warning(msg)
    }
  )
}
//库存结存金额
function doGetQussList() {
  getQussList(
    {},
    (data) => {
      data.forEach((item, index) => {
        let obj = item
        QussList.x.push(obj.x)
        QussList.y.push(obj.y)
      })
      let flag3 = true
      getOption4(flag3);
      console.log(data)
    },
    console.log(QussList),
    // 失败回调函数
    (msg) => {
      let flag3 = false
      getOption3(flag3);
      ElMessage.warning(msg)
    }
  )
}



onMounted(() => {
  doGetSalmList();
  doGetSaloList();
  doGetPuroList();
  doGetQussList();
  // getOption1();
  // this.getOption2();
  // this.getOption3();
  // this.getOption4();
})
// onUpdated(() => {
//   doGetSalmList();
//   getOption1();
// })
// console.log(SalmList.month)

  //option1 柱状图
var option1 = {
    yAxis: {
      type: 'value',
    },
    xAxis: {
      data: [],   // 将数据保存到json中，使用axios读取数据。axios.get("json路径").then(res=>{})  
      axisLabel:{
        interval:0,//显示所有x轴标签
        rotate:45
      }
    },
    tooltip: {
      trigger: "axis"
    },
    grid: {
      top: '5%',
      left: '0%',
      right: '4%',
      bottom: '10%',
      containLabel: true,
    },
    series: [{
      type: 'bar',
      itemStyle: {
        color: '#1890ff'
      },
      barCategoryGap:"20%",
      markPoint: {
        data: [
           {
            type: 'min', name: '最小值'
          },{
            type: 'max', name: '最大值'
          },
        ]
      },
      label: {
        show: true,
        rotate: 30,
        position: 'top',
        textStyle:{
          color:'black',
          fontSize:8
        }
      },
      barWidth: '50%',
      data: []
    }]
  }

function getOption1(flag) {
  var myEcharts = echarts.init(document.getElementById("div1"));
  console.log(SalmList.month)
  // 如果没有数据，渲染空页面
  myEcharts.setOption(option1);
  if (flag) { // 如果有数据渲染
    myEcharts.setOption(
      {
        xAxis: {
          data: SalmList.month
        },
        series: {
          data: SalmList.money,
          label: {
            show: true
          }
        }
      }
    )
  }
}
function getOption2(flag1) {
  var myEcharts = echarts.init(document.getElementById("div2"));
  // console.log(SalmList.month)
  // 如果没有数据，渲染空页面
  myEcharts.setOption(option1);
  if (flag1) { // 如果有数据渲染
    myEcharts.setOption(
      {
        xAxis: {
          data: SaloList.x
        },
        series: {
          data: SaloList.y,
          label: {
            show: true
          }
        }
      }
    )
  }
}
function getOption3(flag2) {
  var myEcharts = echarts.init(document.getElementById("div3"));
  // console.log(SalmList.month)
  // 如果没有数据，渲染空页面
  myEcharts.setOption(option1);
  if (flag2) { // 如果有数据渲染
    myEcharts.setOption(
      {
        xAxis: {
          data: PuroList.x
        },
        series: {
          data: PuroList.y,
          label: {
            show: true
          }
        }
      }
    )
  }
}
function getOption4(flag3) {
  var myEcharts = echarts.init(document.getElementById("div4"));
  // console.log(SalmList.month)
  // 如果没有数据，渲染空页面
  myEcharts.setOption(option1);
  if (flag3) { // 如果有数据渲染
    myEcharts.setOption(
      {
        xAxis: {
          data: QussList.x
        },
        series: {
          data: QussList.y,
          label: {
            show: true
          }
        }
      }
    )
  }
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
  padding:0;
}
div {
  top: 3px;
  left: -4px;
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