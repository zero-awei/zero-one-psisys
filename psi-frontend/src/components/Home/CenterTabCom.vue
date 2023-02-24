<template>
  <el-card style="width:295px;">
    <template #header>
        <div class="card-header">
             <span>处理中主要单据</span>
             <!-- 更新图标 加事件 -->
             <el-icon style="color:blue;"
              @click="doReset()"><Refresh /></el-icon>
        </div>
    </template> 
      <div class="card-bottom">
          <el-table :data="tableData" style="width:436">
            <!-- prop {类别 第一个空白}编制中 待核批 执行中-->
             <el-table-column 
                prop="name" label="" width="103"/>
            <el-table-column 
                prop="edit" label="编制中" width="127" />
            <el-table-column 
                prop="appr" label="待核批" width="103" />
            <el-table-column 
                prop="exec" label="执行中" width="103" />
          </el-table>
      </div>
  </el-card>
</template>

<script setup>
/* //引入表单数据
import tableData from "@/assets/.json"
import { defineProps} from "vue"
//定义props属性
const props = defineProps({

}) */
import { getTableList} from './api/datalist.js'
import {onMounted } from 'vue'
// const {tableData} = toRefs(tableState)
/* function doGetTableList() {
  getTableList(
    // 参数为空是这么写？
    {},
    // 请求成功
    (data) => {
      // 表格列表数据
      console.log(data.data)
      tableData = data.data
      name = tableData.name
      appr = tableData.appr
      edit = tableData.edit
      exec = tableData.exec 
    },
    () => {
      ElMessage.error('查询数据出现错误')
    }
)
}

// 表单重置
function doReset() {
  //查询表单重置，表格也要刷新
  doGetTableList()
}
// 在钩子函数时查询所有单据
onMounted(() => {
  getTableList()
})
 */

/* const tableData = [
  {
    date: '2016-05-03',
    name: 'Tom',
    address: 'No. 189, Grove St, Los Angeles',
  },
  {
    date: '2016-05-02',
    name: 'Tom',
    address: 'No. 189, Grove St, Los Angeles',
  },
  {
    date: '2016-05-04',
    name: 'Tom',
    address: 'No. 189, Grove St, Los Angeles',
  },
  {
    date: '2016-05-01',
    name: 'Tom',
    address: 'No. 189, Grove St, Los Angeles',
  },
] */
</script>


<style lang="scss" scoped>
.el-card{
  top:25px;
  left:-10px;
  width:295px;
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
}
</style>
