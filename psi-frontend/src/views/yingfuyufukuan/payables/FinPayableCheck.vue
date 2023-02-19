<template>
  <!-- 应付核销界面 -->
  <div>
    <psi-form
      :items="items"
      :formData="formData"
      :toggleItems="toggleItems"
      @query="doQuery"
      @reset="doReset"
    ></psi-form>
    <br />
    <psi-table
      :items="tableItems"
      :tableData="tableData"
      :attributes="attributes"
      :pagination="pagination"
    >
    </psi-table>

    <psi-dialog
      ref="editDialog"
      v-model="editDialogVisible"
      :attrs="editDialogVisible"
    >
    </psi-dialog>
    <psi-dialog
      ref="editDialog"
      v-model="examineDialogVisible"
      :attrs="examineDialogVisible"
    >
    </psi-dialog>
  </div>
</template>

<script setup>
import { ref, reactive, toRefs, onMounted } from 'vue'
import { getTableList, query } from './methods.js'
// 查询表单相关数据及方法
const formState = reactive({
  // 查询表单每一项的配置
  items: [
    {
      type: 'input',
      label: '单据编号',
      prop: 'billNo'
    },
    {
      type: 'daterange',
      label: '单据日期',
      prop: 'daterange',
      startPlaceholder: '开始日期',
      endPlaceholder: '结束日期'
    }
  ],
  toggleItems: [
    {
      type: 'input',
      label: '单据主题',
      prop: 'subject'
    },
    {
      type: 'select',
      label: '供应商',
      prop: 'supplierId',
      placeholder: '请选择性别',
      options: [
        {
          label: '供应商1',
          value: 0
        },
        {
          label: '供应商2',
          value: 1
        }
      ]
    },
    {
      type: 'select',
      label: '单据阶段',
      prop: 'billStage',
      placeholder: '请选择性别',
      options: [
        {
          label: '阶段1',
          value: 0
        },
        {
          label: '阶段2',
          value: 1
        }
      ]
    },
    {
      type: 'select',
      label: '已生效',
      prop: 'isEffective',
      options: [
        {
          label: '是',
          value: 0
        },
        {
          label: '否',
          value: 1
        }
      ]
    },
    {
      type: 'select',
      label: '已关闭',
      prop: 'isClosed',
      options: [
        {
          label: '是',
          value: 0
        },
        {
          label: '否',
          value: 1
        }
      ]
    },
    {
      type: 'select',
      label: '已作废',
      prop: 'isVoided',
      options: [
        {
          label: '是',
          value: 0
        },
        {
          label: '否',
          value: 1
        }
      ]
    }
  ],

  // 配置数据绑定的字段
  formData: {
    billNo: '',
    billStage: '',
    daterange: '',
    isClosed: 0,
    isEffective: 0,
    isVoided: 0,
    subject: '',
    supplierId: ''
  }
})
const { items, toggleItems, formData } = toRefs(formState)
// 表单重置
function doReset() {
  //查询表单重置，表格也要刷新
  doGetTableList()
}
// 7.5 普通查询
function doQuery(params) {
  // params是子组件返回的参数
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
    border: true
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
const { examineDialogAttrs } = toRefs(editdialogState)
// function edit(data){
//   editDialogVisible=true
//   // 弹出框内的表格数据和data配置

// }
</script>

<style></style>
