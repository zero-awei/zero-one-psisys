<template>
  <el-card style="width:304px;height:100%">
    <template #header>
      <div class="card-header">
        <span>处理中主要单据</span>
        <!-- 更新图标 加事件 -->
        <el-icon style="color:#409eff; left:-30px" @click="doReset()">
          <Refresh />
        </el-icon>
      </div>
    </template>
    <div class="card-bottom">
      <el-table :data="TableList.data" style="width:280px;height:955px">
        <!-- prop {类别 第一个空白}编制中 待核批 执行中-->
        <el-table-column prop="name" label="" width="63" />
        <el-table-column prop="edit" label="编制中" width="63" />
        <el-table-column prop="appr" label="待核批" width="63" />
        <el-table-column prop="exec" label="执行中" width="63" />
      </el-table>
    </div>
    <!-- </template> -->
    <!-- <div class="card-bottom">
      <el-table :data="tableData" style="width:436"> -->
    <!-- prop {类别 第一个空白}编制中 待核批 执行中-->
    <!-- <el-table-column prop="name" label="" width="103" />
        <el-table-column prop="edit" label="编制中" width="127" />
        <el-table-column prop="appr" label="待核批" width="103" />
        <el-table-column prop="exec" label="执行中" width="103" />
      </el-table> -->
    <!-- </div> -->
  </el-card>
</template>

<script setup>
/* //引入表单数据
import tableData from "@/assets/.json"
import { defineProps} from "vue"
//定义props属性
const props = defineProps({

}) */
import { getTableList } from './api/datalist.js'
import { reactive, onMounted, ref } from 'vue'
import { Refresh } from '@element-plus/icons-vue'


//数据
const TableList = reactive({
  data: []
})
//请求数据
onMounted(() => {
  doGetTableList()
})

//方法
function doGetTableList() {
  getTableList(
    {},
    (data) => {
      data.forEach((item, index) => {
        let obj = item
        TableList.data.push(obj)
      })
      console.log(data)
    },
    // 失败回调函数
    (msg) => {
      ElMessage.warning(msg)
    }
  )
}
console.log(TableList.data)

function doReset() {
  doGetTableList()
}

</script>


<style lang="scss" scoped>
.el-table {
  font-size: 14px;
}

.el-card {
  // top:7px;
  // left:-13px;
  width: 295px;

  // --el-card-padding: 20px;
  .card-header {
    display: flex;
    justify-content: space-between;
    align-items: center;

    span {
      color: black;
      font-size: 16px;
      white-space: nowrap;
      text-overflow: ellipsis;
    }
  }
}
</style>
