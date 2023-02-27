<template>
  <div>
    <!-- 其他应付 -->
    <!-- 表格数据 -->
    <psi-table :items="tableItems" :tableData="tableData" :attributes="attributes" :pagination="pagination"
      @add="handleAdd">
    </psi-table>
  </div>
</template>

<script setup>
import { ref, reactive, toRefs, onMounted } from 'vue'
// 引入方法

// 引入日期格式化方法
import { format } from '@/apis/date/index.js'



// 表格相关数据
const tableState = reactive({
  // 查询表单每一项的配置
  tableItems: [
    {
      type: 'text',
      label: '单据日期',
      prop: 'billDate',
      width: '120'
    },
    {
      type: 'text',
      label: '供应商',
      prop: 'supplierIdDictText',
      width: '120'
    },
    {
      type: 'daterange',
      label: '单据阶段',
      prop: 'billStageDictText',
      width: '120'
    },
    {
      type: 'text',
      label: '已生效',
      prop: 'isEffectiveDictText',
      width: '120'
    },
    {
      type: 'text',
      label: '已关闭',
      prop: 'isClosedDictText',
      width: '120'
    },
    {
      type: 'text',
      label: '自动单据',
      prop: 'isAutoDictText',
      width: '120'
    },
    {
      type: 'text',
      label: '备注',
      prop: 'remark',
      width: '120'
    },
    {
      type: 'text',
      label: '核批人',
      prop: 'approverDictText',
      width: '120'
    },
    {
      type: 'text',
      label: '制单人',
      prop: 'createByDictText',
      width: '120'
    },
    {
      type: 'text',
      label: '修改时间',
      prop: 'updateTime',
      width: '120'
    }
  ],

  // 配置数据绑定的字段
  tableData: [],
  attributes: {
    selection: true, //是否多选框
    index: true, // 索引
    border: true,
    maxHeight: '400',
    height: '400',
    headOperation: ['add', 'importData', 'exportData', 'select']
  }
})
const { tableItems, tableData, attributes } = toRefs(tableState)

// 分页相关配置
const pagination = reactive({
  currentPage: 2, // 当前页
  pageSize: 100, // 每页数据量
  pageSizes: [100, 200, 300, 400], // 可选择的每页展示量
  total: 400, //数据总量
  layout: 'total, sizes, prev, pager, next, jumper'
})

// -----方法---

// 点击新增按钮触发方法
function handleAdd() {

}
</script>


<style scoped></style>