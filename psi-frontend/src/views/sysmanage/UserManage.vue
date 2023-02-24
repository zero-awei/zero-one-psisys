<template>
  <div>
    <!-- 查询 -->
    <psi-form :items="items" :formData="formData" @query="doQuery" @reset="doReset"></psi-form>
    <!-- 表格数据 -->
    <div style="margin-top:10px">
      <psi-table :items="tableItems" :tableData="tableData" :attributes="attributes" :pagination="pagination">
        <!-- 批量操作 -->
        <template v-slot:batchOperation="slot">
          <el-button>批量操作</el-button>
        </template>
        <template v-slot:basicOperation="slot">


          <el-button link type="primary" @click="menuEditDialogVisible = true">编辑</el-button>
          |
          <el-button link type="primary" @click="deleteMenu(slot.data)">更多</el-button>
        </template>
      </psi-table>
    </div>
    <!-- 弹出框 -->
    <psi-dialog ref="editDialog" v-model="editDialogVisible" :attrs="editDialogAttrs">
    </psi-dialog>
    <psi-dialog ref="editDialog" v-model="examineDialogVisible" :attrs="examineDialogAttrs">
    </psi-dialog>
  </div>
</template>

<script setup>
import { ref, reactive, toRefs, onMounted } from 'vue'
import { getTableList } from './api/user.js'
import { format } from '@/apis/date/index.js'
// 查询表单相关数据及方法
const formState = reactive({
  // 查询表单每一项的配置
  items: [
    {
      type: 'input',
      label: '用户编号',
      prop: 'roleId',
      placeholder: '请输入',
    },
    {
      type: 'select',
      label: '状态',
      prop: 'status',
      placeholder: '请选择',
      options: [
        {
          label: '状态1',
          value: 0
        },
        {
          label: '状态2',
          value: 1
        },
        {
          label: '状态3',
          value: 2
        }
      ]
    }
  ],

  // 配置数据绑定的字段
  formData: {
    roleId: '',
    status: '',
  }
})
const { items, formData } = toRefs(formState)
// 表单重置
function doReset() {
  //查询表单重置，表格也要刷新
  doGetTableList()
}
// 7.5 普通查询
function doQuery(data) {
  // // // console.log('父组件接收')
  // // // console.log('params--', params.daterange)
  // // console.log('data.daterange[0]', data.daterange[0])
  // // console.log('data.daterange[1]', data.daterange[1])
  // // console.log('typeof', typeof data.daterange[1])
  // 处理表单数据 主要是开始日期和结束日期
  let params = {}
  params.billNo = data.billNo
  params.billStage = data.billStage
  params.billStage = data.billStage
  params.isClosed = data.isClosed
  params.isEffective = data.isEffective
  params.isVoided = data.isVoided
  params.subject = data.subject
  params.supplierId = data.supplierId
  params.billDateBegin = format(data.daterange[0], 'yyyy-MM-dd hh:mm:ss')
  params.billDateEnd = format(data.daterange[1], 'yyyy-MM-dd hh:mm:ss')
  // // console.log('params', params)
  query(
    {
      params
    },
    (data) => {
      tableData = data.rows
      pagination.currentPage = data.pageIndex
      pagination.pageSize = data.pageSize
      pagination.pages = data.pages
    }
  )
}
// 表格相关数据
const tableState = reactive({
  // 查询表单每一项的配置
  tableItems: [
    {
      type: 'text',
      label: '用户',
      prop: 'billDate',
      width: '120'
    },
    {
      type: 'text',
      label: '角色名称',
      prop: 'supplierIdDictText',
      width: '120'
    },
    {
      type: 'daterange',
      label: '状态',
      prop: 'billStageDictText',
      width: '120'
    },
    {
      type: 'text',
      label: '创建时间',
      prop: 'isEffectiveDictText',
      width: '120'
    },

    {
      type: 'slot',
      label: '操作',
      width: '400',
      slotName: 'basicOperation',
      fixed: 'right'
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
    headOperation: ['add', 'select']
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
// 7.2 列出所有单据
function doGetTableList() {
  getTableList(
    // 参数为空是这么写？
    {},
    // 请求成功
    (data) => {
      // 分页配置
      // 页面属性 配对 返回数据
      pagination.currentPage = data.pageIndex
      pagination.pageSize = data.pageSize
      pagination.pages = data.pages
      // 表格列表数据
      tableData = data.rows
    },
    () => {
      ElMessage.error('查询数据出现错误')
    }
  )
}
// 在钩子函数时查询所有单据
onMounted(() => {
  doGetTableList()
})

// editDialog配置

let editDialogVisible = ref(false)
const editdialogState = reactive({
  editDialogAttrs: {
    title: '应付核销 - 编辑',
    width: '80%'
  }
})
const { editDialogAttrs } = toRefs(editdialogState)
function edit(data) {
  editDialogVisible = true
  // 弹出框内的表格数据和data配置
}
// examineDialog配置

let examineDialogVisible = ref(false)
const examineDialogState = reactive({
  examineDialogAttrs: {
    title: '应付核销 - 审核',
    width: '80%'
  }
})
const { examineDialogAttrs } = toRefs(examineDialogState)
// function edit(data){
//   editDialogVisible=true
//   // 弹出框内的表格数据和data配置

// }
</script>

<style></style>
