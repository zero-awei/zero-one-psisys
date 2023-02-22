<script setup>
import {getSysList,getCusList} from '@/data/home/CenterCom.js'
import {getSupList} from '@/data/home/datalist.js'
import {onMounted } from 'vue'

//1.概况
function doGetSysList() {
  getSysList(
    {},
    // 请求成功
    (data) => {
      //概况数据
      console.log(data.data)
      SyData = data.data
    },
    () => {
      ElMessage.error('查询数据出现错误')
    }
)
}
// 表单重置
function doResetSy() {
  //重置刷新
  doGetSysList()
}

//2.客户
function doGetCusList() {
 getCusList(
    {},
    // 请求成功
    (data) => {
      // 客户数据
      console.log(data.data)
      CusData = data.data
    },
    () => {
      ElMessage.error('查询数据出现错误')
    }
)
}
// 表单重置
function doResetCus() {
  //重置刷新
  doGetCusList()
}
//3.供应商
function doGetSupList() {
 getSupList(
    {},
    // 请求成功
    (data) => {
      // 客户数据
      console.log(data.data)
      SupData = data.data
    },
    () => {
      ElMessage.error('查询数据出现错误')
    }
)
}
// 表单重置
function doResetSup() {
  //重置刷新
  doGetSupList()
}

// 在钩子函数时查询所有单据
onMounted(() => {
 getSysList(),
 getCusList(),
 getSupList()
})
</script>

<template>
 <div class="top">
    <div class="head">
      <el-row>
        <el-col :span="12">
            <el-card class="box-card">
              <template #header>
                <div class="card-header">
                      <!-- {{Card name}} -->
                      <span>概况</span>
                      <!-- 更新图标 加事件 -->
                    <el-icon @click="doResetSy()"><Refresh /></el-icon>
                </div>
              </template>  
                  <div class="card-bottom1">
                    <el-row>
                        <el-col :span="8" v-for="item in SyData">
                          <span >{{item.label}}</span>
                          <p>{{item.value}}</p>
                        </el-col>
                      <!--   <el-col :span="8">
                          <span>客户欠款（元）</span>
                          <p>math</p>
                        </el-col>
                        <el-col :span="8">
                          <span>欠供应商（元）</span>
                          <p>math</p>
                        </el-col>    -->       
                     </el-row>
                  </div >  
            </el-card>
          </el-col>

          <el-col :span="5">
             <el-card class="box-card">
              <template #header>
                <div class="card-header">
                      <!-- {{Card name}} -->
                      <span>客户</span>
                      <!-- 更新图标 加事件 -->
                    <el-icon @click="doGetCusList()"><Refresh /></el-icon>
                </div>
              </template>  
                  <div class="card-bottom2">
                    <div class="body">
                      <div class="head-info.center" v-for="item in CusData ">
                        <span>{{item.label}}</span>
                        <p>{{item.value}}</p>
                      </div>
                     <!--  <div class="head-info.center">
                        <span>本周+</span>
                        <p>0</p>
                      </div>
                      <div class="head-info.center">
                        <span>本月+</span>
                        <p>0</p>
                      </div>
                      <div class="head-info.center">
                        <span>客户数</span>
                        <p>0</p>
                      </div> -->
                    </div>
                  </div >  
            </el-card>
          </el-col>

          <el-col :span="7">
            <el-card class="box-card">
              <template #header>
                <div class="card-header">
                      <!-- {{Card name}} -->
                      <span>供应商</span>
                      <!-- 更新图标 加事件 -->
                    <el-icon @click="doResetSup()"><Refresh /></el-icon>
                </div>
              </template>  
                  <div class="card-bottom2">
                    <div class="body">
                      <div class="head-info.center" v-for="item in SupData">
                        <span>{{item.label}}</span>
                        <p>{{item.value}}</p>
                      </div>
                     <!--  <div class="head-info.center">
                        <span>本周+</span>
                        <p>0</p>
                      </div>
                      <div class="head-info.center">
                        <span>本月+</span>
                        <p>0</p>
                      </div>
                      <div class="head-info.center">
                        <span>供应商数</span>
                        <p>0</p>
                      </div> -->
                    </div>
                  </div >  
            </el-card>
          </el-col>
        </el-row>
      </div>
    </div >
</template>

<style lang="scss" scoped>
.card-header {
  display: flex;
  justify-content: space-between;
  align-items: center;
span{
  color: black;
  font-size: 16px;
  white-space: nowrap;
  text-overflow: ellipsis;
}
}

.card-bottom1{ 
.head-info.center{
span{
    color: rgba(70, 67, 67, 0.45);
    display: inline-block;
    font-size: 14px;
    line-height: 22px;
    margin-bottom: 4px;
}
 p{
    color: rgba(0,0,0,.85);
    font-size: 24px;
    line-height: 32px;
    margin: 0;
}
} 
}

.card-bottom2{
 .body{
  display:flex;
  .head-info.center {
    text-align: center;
    padding: 0 40px;
    span{
    color: rgba(0,0,0,.45);
    display: inline-block;
    font-size: 14px;
    line-height: 22px;
    margin-bottom: 4px;
       }
     .head-info.center p {
    color: rgba(0,0,0,.85);
    font-size: 24px;
    line-height: 32px;
    margin: 0;
     }
   }
 }
}
</style>

 