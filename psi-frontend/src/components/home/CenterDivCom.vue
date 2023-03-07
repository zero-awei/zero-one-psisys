<template>
  <!-- <div>{{ Data.chuku.todayCount}}</div> -->
      <el-card>
        <template #header>
          <div class="card-header">
            <span>销售</span>
            <el-icon style="color:blue;"><Refresh @click="handleReSal()"/></el-icon>
          </div>
        </template>

        <div>
            <!-- div1订单 出库两个div -->
         <div class="div1">
             <el-row :gutter="20">
           <!-- 订单部分 -->
              <el-col :span="12">
                <el-card class="cardBody" shadow="hover">
                   <div class="Div">
                        <h1>订单</h1>
                             <!--订单左  -->
                            <div class="body">
                                <div class="name">
                                  <span>今日笔数</span>
                                  <!-- {{ Data.dingdan.todayAmt}} -->
                                  <p>{{ SalList.dingdan.todayCount}}</p>
                                </div>
                                
                               <div class="data">
                                    <p style="font-size:14px; display:block;"> 本周:{{ SalList.dingdan.weekCount}}</p>
                                    <p style="font-size:14px;display:block;">本月:{{ SalList.dingdan.monthCount}}</p>
                               </div >
                            </div >
                        
                        <!-- 订单右 -->
                        
                             <div class="body">
                                <div class="name">
                                  <span>今日金额</span>
                                  <p>{{ SalList.dingdan.todayAmt}}</p>
                                </div>
                                
                               <div class="data">
                                    <p style="font-size:14px; display:block;"> 本周:{{ SalList.dingdan.weekAmt}}</p>
                                    <p style="font-size:14px;display:block;">本月:{{ SalList.dingdan.monthCount}}</p>
                               </div >
                            </div >
                    </div>

                </el-card>
            </el-col>

                <!-- 出库部分 -->
              <el-col :span="12">
                <el-card class="cardBody" shadow="hover">
                    <div class="Div">
                     <h1>出库</h1>
                <!--出库左  -->
                   <div class="body">
                                <div class="name">
                                  <span>今日笔数</span>
                                  <p>{{ SalList.chuku.todayCount}}</p>
                                </div>
                                
                               <div class="data">
                                    <p style="font-size:14px; display:block;"> 本周:{{ SalList.chuku.weekCount}}</p>
                                    <p style="font-size:14px;display:block;">本月:{{ SalList.chuku.monthCount}}</p>
                               </div >
                            </div >
                    <!-- 出库右 -->
                    <div class="body">
                                <div class="name">
                                  <span>今日金额</span>
                                  <p>{{ SalList.chuku.todayAmt}}</p>
                                </div>
                                
                               <div class="data">
                                    <p style="font-size:14px; display:block;"> 本周:{{ SalList.chuku.weekAmt}}</p>
                                    <p style="font-size:14px;display:block;">本月:{{ SalList.chuku.monthAmt}}</p>
                               </div >
                            </div >
                    </div>

                </el-card>
            </el-col>

            </el-row>
         </div>

            <div class="div2">
             <el-row :gutter="20">
           <!-- 应收部分 -->
              <el-col :span="12">
                <el-card class="cardBody" shadow="hover">
                   <div class="Div">
                        <h1>应收</h1>
                             <!--应收左  -->
                            <div class="body">
                                <div class="name">
                                  <span>今日笔数</span>
                                  <p>{{ SalList.yingshou.todayCount}}</p>
                                </div>
                                
                               <div class="data">
                                    <p style="font-size:14px; display:block;"> 本周:{{ SalList.yingshou.weekCount}}</p>
                                    <p style="font-size:14px;display:block;">本月:{{ SalList.yingshou.monthCount}}</p>
                               </div >
                            </div >
                        
                        <!-- 应收右 -->
                        
                             <div class="body">
                                <div class="name">
                                  <span>今日金额</span>
                                  <p>{{ SalList.yingshou.todayAmt}}</p>
                                </div>
                                
                               <div class="data">
                                    <p style="font-size:14px; display:block;"> 本周:{{ SalList.yingshou.weekAmt}}</p>
                                    <p style="font-size:14px;display:block;">本月:{{ SalList.yingshou.monthAmt}}</p>
                               </div >
                            </div >
                    </div>

                </el-card>
            </el-col>

                <!-- 收款部分 -->
              <el-col :span="12">
                <el-card class="cardBody" shadow="hover">
                    <div class="Div">
                     <h1>收款</h1>
                <!--收款左  -->
                   <div class="body">
                                <div class="name">
                                  <span>今日笔数</span>
                                  <p>{{ SalList.shoukuan.todayCount}}</p>
                                </div>
                                
                               <div class="data">
                                    <p style="font-size:14px; display:block;"> 本周:{{ SalList.shoukuan.weekCount}}</p>
                                    <p style="font-size:14px;display:block;">本月:{{ SalList.shoukuan.monthCount}}</p>
                               </div >
                            </div >
                    <!-- 收款右 -->
                    <div class="body">
                                <div class="name">
                                  <span>今日金额</span>
                                  <p>{{ SalList.shoukuan.todayAmt}}</p>
                                </div>
                                
                               <div class="data">
                                    <p style="font-size:14px; display:block;"> 本周:{{ SalList.shoukuan.weekAmt}}</p>
                                    <p style="font-size:14px;display:block;">本月:{{ SalList.shoukuan.monthAmt}}</p>
                               </div >
                            </div >
                    </div>

                </el-card>
            </el-col>

            </el-row>
         </div>

        </div>
    </el-card>


    <!-- 第二个 -->
    <el-card class="card2">
        <template #header>
          <div class="card-header">
            <span>销售</span>
            <el-icon style="color:blue;"><Refresh @click="handleRePur()"/></el-icon>
          </div>
        </template>

        <div>
            <!-- div1订单 出库两个div -->
         <div class="div1">
             <el-row :gutter="20">
           <!-- 订单部分 -->
              <el-col :span="12">
                <el-card class="cardBody" shadow="hover">
                   <div class="Div">
                        <h1>订单</h1>
                             <!--订单左  -->
                            <div class="body">
                                <div class="name">
                                  <span>今日笔数</span>
                                  <!-- {{ Data.dingdan.todayAmt}} -->
                                  <p>{{ PurList.dingdan.todayCount}}</p>
                                </div>
                                
                               <div class="data">
                                    <p style="font-size:14px; display:block;"> 本周:{{ PurList.dingdan.weekCount}}</p>
                                    <p style="font-size:14px;display:block;">本月:{{ PurList.dingdan.monthCount}}</p>
                               </div >
                            </div >
                        
                        <!-- 订单右 -->
                        
                             <div class="body">
                                <div class="name">
                                  <span>今日金额</span>
                                  <p>{{ PurList.dingdan.todayAmt}}</p>
                                </div>
                                
                               <div class="data">
                                    <p style="font-size:14px; display:block;"> 本周:{{ PurList.dingdan.weekAmt}}</p>
                                    <p style="font-size:14px;display:block;">本月:{{ PurList.dingdan.monthCount}}</p>
                               </div >
                            </div >
                    </div>

                </el-card>
            </el-col>

                <!-- 出库部分 -->
              <el-col :span="12">
                <el-card class="cardBody" shadow="hover">
                    <div class="Div">
                     <h1>出库</h1>
                <!--出库左  -->
                   <div class="body">
                                <div class="name">
                                  <span>今日笔数</span>
                                  <p>{{ PurList.chuku.todayCount}}</p>
                                </div>
                                
                               <div class="data">
                                    <p style="font-size:14px; display:block;"> 本周:{{ PurList.chuku.weekCount}}</p>
                                    <p style="font-size:14px;display:block;">本月:{{ PurList.chuku.monthCount}}</p>
                               </div >
                            </div >
                    <!-- 出库右 -->
                    <div class="body">
                                <div class="name">
                                  <span>今日金额</span>
                                  <p>{{ PurList.chuku.todayAmt}}</p>
                                </div>
                                
                               <div class="data">
                                    <p style="font-size:14px; display:block;"> 本周:{{ PurList.chuku.weekAmt}}</p>
                                    <p style="font-size:14px;display:block;">本月:{{ PurList.chuku.monthAmt}}</p>
                               </div >
                            </div >
                    </div>

                </el-card>
            </el-col>

            </el-row>
         </div>

            <div class="div2">
             <el-row :gutter="20">
           <!-- 应收部分 -->
              <el-col :span="12">
                <el-card class="cardBody" shadow="hover">
                   <div class="Div">
                        <h1>应收</h1>
                             <!--应收左  -->
                            <div class="body">
                                <div class="name">
                                  <span>今日笔数</span>
                                  <p>{{ PurList.yingshou.todayCount}}</p>
                                </div>
                                
                               <div class="data">
                                    <p style="font-size:14px; display:block;"> 本周:{{ PurList.yingshou.weekCount}}</p>
                                    <p style="font-size:14px;display:block;">本月:{{ PurList.yingshou.monthCount}}</p>
                               </div >
                            </div >
                        
                        <!-- 应收右 -->
                        
                             <div class="body">
                                <div class="name">
                                  <span>今日金额</span>
                                  <p>{{ PurList.yingshou.todayAmt}}</p>
                                </div>
                                
                               <div class="data">
                                    <p style="font-size:14px; display:block;"> 本周:{{ PurList.yingshou.weekAmt}}</p>
                                    <p style="font-size:14px;display:block;">本月:{{ PurList.yingshou.monthAmt}}</p>
                               </div >
                            </div >
                    </div>

                </el-card>
            </el-col>

                <!-- 收款部分 -->
              <el-col :span="12">
                <el-card class="cardBody" shadow="hover">
                    <div class="Div">
                     <h1>收款</h1>
                <!--收款左  -->
                   <div class="body">
                                <div class="name">
                                  <span>今日笔数</span>
                                  <p>{{ PurList.shoukuan.todayCount}}</p>
                                </div>
                                
                               <div class="data">
                                    <p style="font-size:14px; display:block;"> 本周:{{ PurList.shoukuan.weekCount}}</p>
                                    <p style="font-size:14px;display:block;">本月:{{ PurList.shoukuan.monthCount}}</p>
                               </div >
                            </div >
                    <!-- 收款右 -->
                    <div class="body">
                                <div class="name">
                                  <span>今日金额</span>
                                  <p>{{ PurList.shoukuan.todayAmt}}</p>
                                </div>
                                
                               <div class="data">
                                    <p style="font-size:14px; display:block;"> 本周:{{ PurList.shoukuan.weekAmt}}</p>
                                    <p style="font-size:14px;display:block;">本月:{{ PurList.shoukuan.monthAmt}}</p>
                               </div >
                            </div >
                    </div>

                </el-card>
            </el-col>

            </el-row>
         </div>

        </div>
    </el-card>


    <div style="height:300px;"></div>



</template>


<script setup>
import {  reactive, onMounted ,toRaw} from 'vue'
import { getSalList, getPurList} from './api/CenterCom.js'
import { Refresh } from '@element-plus/icons-vue'

/*        数据         */
//销售数据
const SalList = reactive({
  dingdan:{},
  chuku:{},
  yingshou:{},
  shoukuan:{}
})
//采购数据
const PurList = reactive({
  dingdan:{},
  chuku:{},
  yingshou:{},
  shoukuan:{}
})



/*     挂载数据              */
//请求数据
onMounted(() => {
  doGetSalList()
  doGetPurList()
  // console.log(data)
})

/*      方法       */
//请求销售概况
function doGetSalList() {
  getSalList(
    {},
    (data) => {
      // let arr =data
      // SalList=JSON.parse(JSON.stringify(arr))
      SalList.dingdan = data[0]
      SalList.chuku = data[1]
      SalList.yingshou = data[2]
      SalList.shoukuan = data[3]
      // SalList = data
      console.log(data)
      // console.log(SalList.dingdan)//正常数据
    },
    console.log(SalList),//proxy
    // 失败回调函数
    (msg) => {
      ElMessage.warning(msg)
    }
  )
}
//请求采购概况
function doGetPurList() {
  getPurList(
    {},
    (data) => {
      // let arr =data
      // SalList=JSON.parse(JSON.stringify(arr))
      PurList.dingdan = data[0]
      PurList.chuku = data[1]
      PurList.yingshou = data[2]
      PurList.shoukuan = data[3]
      // SalList = data
      console.log(data)
      // console.log(SalList.dingdan)//正常数据
    },
    console.log(PurList),//proxy
    // 失败回调函数
    (msg) => {
      ElMessage.warning(msg)
    }
  )
}
//刷新
function handleReSal(){
  doGetSalList()
}
function handleRePur(){
  doGetPurList()
}

/* const Data = toRaw(SalList)
console.log(Data) */
// let arr=JSON.parse(JSON.stringify(SalList))
/* console.log(SalList.value)
console.log(SalList.value.chuku) */


</script>

<style scoped>
.el-card{
    top:5px;
    left:3px;
}
.el-row{
    height:213px;
}
.box-card{
    top:40px;
    height:500px;
}

.card-header {
  display: flex;
  justify-content: space-between;
  align-items: center;
}
.card2{
  top:15px;
}
.div1{
    bottom:25px;
}
.div2{
    bottom:25px;
}
.div1 .div2{
    width:587px;
    height:192px;
}

.cardBody{
    /* display:flex; */
    width:290px;
    height:210px;
    margin-left:-20px;
}
.Div{
    width:245px;
    height:165px;
    padding:15px;
}
.Div h1{
    font-size:14px;
    color: rgba(0,0,0,.85);
    font-weight: 500;
    margin-bottom:10px;
}
.Div span{
    color: rgba(0,0,0,.45);
    display: inline-block;
    font-size: 15px;
    line-height: 22px;
    margin-bottom: 4px;
}
.body .name{
    margin-right:37px;
}
.name p{
    color: rgba(0,0,0,.85);
    font-size: 24px;
    line-height: 32px;
    margin: 0;
}
.data{
    padding:0px 30px;
}
.head{
    font-size:18px;
}

.text {
  font-size: 14px;
}

.item {
  margin-bottom: 18px;
}

.box-card {
  width: 574px;
  height:480px;
  padding:4px;

}
.body{
    display: flex;
}
</style>