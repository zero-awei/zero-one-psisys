<template>
  <el-card style="width:436px;">
    <template #header>
        <div class="card-header">
             <span>处理中主要单据</span>
             <!-- 更新图标 加事件 -->
             <el-icon><Refresh /></el-icon>
        </div>
    </template> 
      <div class="card-bottom">
          <el-table :data="tableData" style="width:436">
            <!-- prop {类别 第一个空白}编制中 待核批 执行中-->
            <el-table-column 
                prop="date" label="Date" width="127" />
            <el-table-column 
                prop="date" label="Date" width="103" />
            <el-table-column 
                prop="name" label="Name" width="103" />
            <el-table-column 
                prop="address" label="Address" width="103"/>
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

const tableData = [
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
]
</script>


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
</style>
