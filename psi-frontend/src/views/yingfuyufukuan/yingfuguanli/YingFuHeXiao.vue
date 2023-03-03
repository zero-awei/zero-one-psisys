<template>
  <!-- 应付核销界面 -->
  <div>
    <!-- 查询 -->
    <psi-form :items="items" :formData="formData" :toggleItems="toggleItems" @query="handleQuery"
      @reset="handleReset"></psi-form>
  </div>
    <div style="margin-top:10px">
    <!-- 表格数据 -->
    <!-- 导入导出 应付核销新增？？？？？？ -->
    <psi-table :items="tableItems" :tableData="tableData" :attributes="attributes" :pagination="pagination"
      @add="handleAdd">
    </psi-table>
  </div>

    <!-- 弹出框 -->
    <!-- <psi-dialog ref="editDialog" v-model="editDialogVisible" :attrs="editDialogVisible">
    </psi-dialog>
    <psi-dialog ref="editDialog" v-model="examineDialogVisible" :attrs="examineDialogVisible">
    </psi-dialog> -->
</template>

<script setup>
import { ref, reactive, toRefs, onMounted } from 'vue'
// import { getTableList, query } from './api/yingfuhexiao.js'
import { format } from '@/apis/date/index.js'

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
  // 查询表单折叠项的配置
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
          label: '否',
          value: 1
        },
        {
          label: '是',
          value: 0
        }
      ]
    }
  ],

  // 配置数据绑定的字段
  formData: {
    billNo: '',
    billStage: '',
    daterange: [],
    isClosed: 0,
    isEffective: 0,
    isVoided: 1,
    subject: '',
    supplierId: ''
  }
})
const { items, toggleItems, formData } = toRefs(formState)

const tableStatus = reactive({
  // table列配置
  tableItems: [
    {
      label: '单据编号',
      prop: 'name',
      width: '160',
      align: 'center',
      type: 'function',
      fixed: true,
      // ES6 的 Template Strings 模版字符串
      callback: (data) => {
        return `<span style="color:#409eff"> ${data.name}</span>`
      }
    },
    {
      type: 'text',
      label: '单据日期',
      prop: 'date',
      width: '100'
    },
    {
      type: 'text',
      label: '单据主题',
      prop: 'city',
      width: '184'
    },
    {
      type: 'text',
      label: '源单号',
      prop: 'address',
      width: '160'
    },
    {
      type: 'text',
      label: '供应商',
      prop: 'zip',
      width: '184'
    },
    // tag?????????????????? 操作怎么写
    {
      type: 'text',
      label: '操作',
      prop: 'tag',
      width: '120'
    }
    // {
    //   type: 'slot',
    //   label: '操作',
    //   prop: 'operation',
    //   slotName: 'operation'
    // }
  ],
  // table 数据
  tableData: [
    {
      date: '2016-05-03',
      name: 'Tom1',
      state: 'California',
      city: 'Los Angeles',
      address: 'No. 189, Grove St, Los Angeles',
      zip: 'CA 90036',
      tag: 'Home'
    },
    {
      date: '2016-05-02',
      name: 'Tom2',
      state: 'California',
      city: 'Los Angeles',
      address: 'No. 189, Grove St, Los Angeles',
      zip: 'CA 90036',
      tag: 'Office'
    },
    {
      date: '2016-05-04',
      name: 'Tom3',
      state: 'California',
      city: 'Los Angeles',
      address: 'No. 189, Grove St, Los Angeles',
      zip: 'CA 90036',
      tag: 'Home'
    },
    {
      date: '2016-05-01',
      name: 'Tom4',
      state: 'California',
      city: 'Los Angeles',
      address: 'No. 189, Grove St, Los Angeles',
      zip: 'CA 90036',
      tag: 'Office'
    }
  ],
  // table 总体配置
  attributes: {
    selection: true, //是否多选框
    index: true, // 索引
    border: true, //表格边框
    maxHeight: '400', // 表格最大高度
    height: '400',    //表格高度
    headOperation: ['add', 'importData', 'exportData', 'select']
  }
})

const { tableItems, tableData, attributes } = toRefs(tableStatus)
// 分页相关配置
const pagination = reactive({
  currentPage: 2, // 当前页
  pageSize: 100, // 每页数据量
  pageSizes: [100, 200, 300, 400], // 可选择的每页展示量
  total: 400, //数据总量
  layout: 'total, sizes, prev, pager, next, jumper'
})


/* // 7.2 列出所有单据
//TODO 前后联调
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
 */

/* // editDialog配置

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
const { examineDialogAttrs } = toRefs(editdialogState) */
// function edit(data){
//   editDialogVisible=true
//   // 弹出框内的表格数据和data配置


// }
// ------方法 ----
// 表单重置
function handleReset() {
  //查询表单重置，表格也要刷新
  doGetTableList()
}
// 7.5 普通查询
function handleQuery(data) {
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
  /* // 后端调用接口
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
  ) */
}
// 点击新增按钮触发方法
function handleAdd() {

}
// 在钩子函数时查询所有单据
onMounted(() => {
  // doGetTableList()
})
</script>

<style scoped></style>
