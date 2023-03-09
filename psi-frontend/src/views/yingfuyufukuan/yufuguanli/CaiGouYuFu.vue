<template>
  <div>
    <!-- 采购预付（无申请） -->
     <div>
      <!-- 查询 -->
      <psi-form :items="items" :formData="formData" :toggleItems="toggleItems" @query="handleQuery"
        @reset="handleReset"></psi-form>
    </div>
      <div style="margin-top:10px">
      <!-- 表格数据 -->
      <!-- 导入导出 采购预付（无新增）新增？？？？？？ -->
      <psi-table :items="tableItems" :tableData="tableData" :attributes="attributes" :pagination="pagination"
        @add="handleAdd">
      </psi-table>
    </div>

      <!-- 弹出框 -->
      <!-- <psi-dialog ref="editDialog" v-model="editDialogVisible" :attrs="editDialogVisible">
    </psi-dialog>
    <psi-dialog ref="editDialog" v-model="examineDialogVisible" :attrs="examineDialogVisible">
    </psi-dialog> -->
    </div>
</template>

<script setup>
import { ref, reactive, toRefs, onMounted } from 'vue'
import { format } from '@/apis/date/index.js'
import { queryAll, close, deleteById, edit, queryAllByBillno, queryOneNo, unclose, voidById } from './api/caigouyufu.js'


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
    },
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
      type: 'input',
      label: '处理状态',
      prop: 'billStage',
    },
    {
      type: 'input',
      label: '付款类型',
      prop: 'paymentType',
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
    subject: '',
    supplierId: '',
    paymentType: '',
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
      prop: 'subject',
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
      prop: 'supplierld',
      width: '184'
    },
    {
      type: 'text',
      label: '金额',
      prop: 'amt',
      width: '120'
    },
    {
      type: 'text',
      label: '审核人',
      prop: 'approver',
      width: '120'
    },
    {
      type: 'slot',
      label: '操作',
      prop: 'operation',
      slotName: 'operation'
    },
    {
      type: 'text',
      label: '单据编号',
      prop: 'billNo',
      width: '120'
    },
    {
      type: 'text',
      label: '处理状态',
      prop: 'billStage',
      width: '120'
    },
    {
      type: 'text',
      label: '已核销金额',
      prop: 'checkedAmt',
      width: '120'
    },
    {
      type: 'text',
      label: '创建人',
      prop: 'createBy',
      width: '120'
    },
    {
      type: 'text',
      label: '创建时间',
      prop: 'createTime',
      width: '120'
    },
    {
      type: 'text',
      label: '创建部门',
      prop: 'sysOrgCode',
      width: '120'
    },
    {
      type: 'text',
      label: '修改人',
      prop: 'updateBy',
      width: '120'
    },
    {
      type: 'text',
      label: '修改时间',
      prop: 'updateTime',
      width: '120'
    },
  ],
  // table 数据
  tableData: [

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

//---------------处理事件----------
function handleQuery() {
  let params = {}
  params.billDateStart = formData.value.billDateStart
  params.billDateEnd = formData.value.billDateEnd
  params.billNo = formData.value.billNo
  params.billStage = formData.value.billStage
  params.isClosed = formData.value.isClosed
  params.isEffective = formData.value.isEffective
  params.isVoided = formData.value.isVoided
  params.subject = formData.value.subject
  params.supplierId = formData.value.supplierId
  params.paymentType = formData.value.paymentType
  queryAll(
    params,
    (data) => {
      // 查询返回的是表格数据
      // 分页
      pagination.value.currentPage = data.pageIndex
      pagination.value.pageSize = data.pageSize
      pagination.value.total = data.total
      //表格数据
      tableData.value = data.rows
    },
    (msg) => {
      ElMessage.warning(msg)
    }
  )
}
//重置按钮
function handleReset() {
  handleQueryAll()
}
function handleQueryAll() {
  queryAll(
    {

    },
    // 成功回调函数

    (data) => {
      // 查询全部返回的是表格数据
      // 分页
      pagination.value.currentPage = data.pageIndex
      pagination.value.pageSize = data.pageSize
      pagination.value.total = data.total

      // 表格数据
      tableData.value = data.rows

    },
    // 失败回调函数
    (msg) => {
      ElMessage.warning(msg)
    }
  )
}
//关闭按钮
function handleClose() {
  let params = {}
  params.id = idData.value.id
  close(
    params,
    (data) => { },
    (msg) => {
      ElMessage.warning(msg)
    }
  )
}
//删除信息
function handleDelete() {
  let params = {}
  params.id = idData.value.id
  deleteById(
    params,
    (data) => { },
    (msg) => {
      ElMessage.warning(msg)
    }
  )
}
//修改采购预付单功能
function handleEdit() {
  let params = {}
  params.amt = editData.value.amt
  params.attachment = editData.value.attachment
  params.billDate = editData.value.billDate
  params.billNo = editData.value.billNo
  params.entryAmt = editData.value.entryAmt
  params.entryBankAccountld = editData.value.entryBankAccountld
  params.entryCustom1 = editData.value.entryCustom1
  params.entryCustom2 = editData.value.entryCustom2
  params.entryNo = editData.value.entryNo
  params.entryId = editData.value.entryId
  params.entryMid = editData.value.entryMid
  params.entryRemark = editData.value.entryRemark
  params.entrySettleMethod = editData.value.entrySettleMethod
  params.entrySrcBillId = editData.value.entrySrcBillId
  params.entrySrcBillType = editData.value.entrySrcBillType
  params.entrySrcNo = editData.value.entrySrcNo
  params.remark = editData.value.remark
  params.srcBillId = editData.value.srcBillId
  params.srcBillType = editData.value.srcBillType
  params.srcNo = editData.value.srcNo
  params.subject = editData.value.subject
  params.supplierId = editData.value.supplierId
  params.version = editData.value.version
  edit(
    params,
    (data) => { },
    (msg) => {
      ElMessage.warning(msg)
    }
  )
}
//付款申请单分录列表
function handlequeryAllByBillno() {
  let params = {}
  params.billNo = queryByBillNOData.value.billNo
  queryAllByBillno(
    params,
    (data) => { },
    (msg) => {
      ElMessage.warning(msg)
    }
  )
}
//查看单据详情信息
function handleQueryOneNo() {
  let params = {}
  params.billNo = oneNoData.value.billNo
  queryOneNo(
    params,
    (data) => { },
    (msg) => {
      ElMessage.warning(msg)
    }
  )
}
//反关闭操作
function handleUnclose() {
  let params = {}
  params.id = uncloseData.value.id
  unclose(
    params,
    (data) => { },
    (msg) => {
      ElMessage.warning(msg)
    }
  )
}
//作废操作
function handleVoid() {
  let params = {}
  params.id = voidData.value.id
  voidById(
    params,
    (data) => { },
    (msg) => {
      ElMessage.warning(msg)
    }
  )
}
</script>

<style scoped>
</style>
