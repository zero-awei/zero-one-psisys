<template>
  <div>
    <el-card class="box-card">
      <template #header>
        <div class="card-header">
          <span :class="{ 'dark-span': isDarkThem }">销售金额</span>
          <el-icon style="color:#409eff; ">
            <Refresh />
          </el-icon>
        </div>
      </template>
      <div id="div1" style="width:365px;height:210px;float: left;padding:0;"></div>
    </el-card>
    <el-card class="box-card" style="margin-top:10px">
      <template #header>
        <div class="card-header">
          <span :class="{ 'dark-span': isDarkThem }">毛利润</span>
          <el-icon style="color:#409eff; ">
            <Refresh />
          </el-icon>
        </div>
      </template>
      <div id="div2" style="width:365px;height:210px;float: left;padding:0;"></div>
    </el-card>
    <el-card class="box-card" style="margin-top:10px">
      <template #header>
        <div class="card-header">
          <span :class="{ 'dark-span': isDarkThem }">采购金额</span>
          <el-icon style="color:#409eff;">
            <Refresh />
          </el-icon>
        </div>
      </template>
      <div id="div3" style="width:365px;height:210px;float: left;padding:0;"></div>
    </el-card>
    <el-card class="box-card" style="margin-top:10px">
      <template #header>
        <div class="card-header">
          <span :class="{ 'dark-span': isDarkThem }">库存结存金额</span>
          <el-icon style="color:#409eff; ">
            <Refresh />
          </el-icon>
        </div>
      </template>
      <div id="div4" style="width:365px;height:210px;float: left;padding:0;"></div>
    </el-card>

  </div>
</template>

<script setup>
import { reactive, onMounted, ref, watch } from 'vue'
import { storeToRefs } from 'pinia'
import * as echarts from "echarts"
// import echarts from 'echarts'
import { getSalmList } from './api/CenterCom.js'
import { getSaloList, getPuroList, getQussList } from './api/datalist.js'
import { Refresh } from '@element-plus/icons-vue'
import { themeStore } from '@/stores/theme'

// 切换主题相关
const themStore = themeStore()
const isDarkThem = ref(false)
const { isDarkTheme } = storeToRefs(themStore)
const subscribe = themStore.$subscribe((mutation, state) => {
  console.log('77777777', state.isDarkTheme)
  isDarkThem.value = state.isDarkTheme

})

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
      getOption1(flag, isDarkThem.value);
      console.log(data)
    },
    // 失败回调函数
    (msg) => {
      let flag = false
      getOption1(flag, isDarkThem.value);
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
      getOption2(flag1, isDarkThem.value);
      console.log(data)
    },
    // 失败回调函数
    (msg) => {
      let flag1 = false
      getOption2(flag1, isDarkThem.value);
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
      getOption3(flag2, isDarkThem.value);
      console.log(data)
    },
    // 失败回调函数
    (msg) => {
      let flag2 = false
      getOption3(flag2, isDarkThem.value);
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
      getOption4(flag3, isDarkThem.value);
      console.log(data)
    },
    // 失败回调函数
    (msg) => {
      let flag3 = false
      getOption4(flag3, isDarkThem.value);
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
    axisLabel: {
      interval: 0,//显示所有x轴标签
      rotate: 45
    }
  },
  tooltip: {
    trigger: "axis"
  },
  grid: {
    top: '24%',
    left: '8%',
    right: '0%',
    bottom: '0%',
    containLabel: true,
  },
  series: [{
    type: 'bar',
    itemStyle: {
      color: '#1890ff'
    },
    barCategoryGap: "20%",
    markPoint: {
      data: [
        {
          type: 'min', name: '最小值'
        }, {
          type: 'max', name: '最大值'
        },
      ]
    },
    label: {
      show: true,
      rotate: 30,
      position: 'top',
      textStyle: {
        color: 'black',
        fontSize: 8
      }
    },
    barWidth: '50%',
    data: []
  }]
}

function getOption1(flag, isDark, changeTheme) {
  let myEcharts = null;

  if (changeTheme) {
    myEcharts = echarts.init(document.getElementById("div1"));
    myEcharts.dispose()
  }
  if (isDark) {
    myEcharts = echarts.init(document.getElementById("div1"), 'dark');
  } else {
    myEcharts = echarts.init(document.getElementById("div1"));
  }

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
function getOption2(flag1, isDark, changeTheme) {
  let myEcharts = null;

  if (changeTheme) {
    myEcharts = echarts.init(document.getElementById("div2"));
    myEcharts.dispose()
  }
  if (isDark) {
    myEcharts = echarts.init(document.getElementById("div2"), 'dark');
  } else {
    myEcharts = echarts.init(document.getElementById("div2"));
  }

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
function getOption3(flag2, isDark, changeTheme) {
  let myEcharts = null;

  if (changeTheme) {
    myEcharts = echarts.init(document.getElementById("div3"));
    myEcharts.dispose()
  }
  if (isDark) {
    myEcharts = echarts.init(document.getElementById("div3"), 'dark');
  } else {
    myEcharts = echarts.init(document.getElementById("div3"));
  }

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
function getOption4(flag3, isDark, changeTheme) {
  let myEcharts = null;

  if (changeTheme) {
    myEcharts = echarts.init(document.getElementById("div4"));
    myEcharts.dispose()
  }
  if (isDark) {
    myEcharts = echarts.init(document.getElementById("div4"), 'dark');
  } else {
    myEcharts = echarts.init(document.getElementById("div4"));
  }

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
// echarts主题切换
// myChart.dispose();
// myChart = echarts.init(document.getElementById('main'), 'light');
// myChart.setOption(option);


watch(isDarkThem, (newValue, oldValue) => {
  // console.log('watch 已触发', newValue)
  getOption1(true, newValue, true)
  getOption2(true, newValue, true)
  getOption3(true, newValue, true)
  getOption4(true, newValue, true)
})

</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
* {
  margin: 0;
  padding: 0;
}

div {
  /* top: 3px;
  left: -4px; */
}

.card-header {
  display: flex;
  justify-content: space-between;
  align-items: center;
}

.card-header span {
  /* top: -15px; */
  display: inline-block;
  flex: 1;
  white-space: nowrap;
  text-overflow: ellipsis;
  color: black;
  font-size: 16px;
}

.dark-span {
  color: white !important;
}
</style>