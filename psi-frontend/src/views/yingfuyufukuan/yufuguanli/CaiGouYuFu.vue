<template>
  <div>
    <!-- 采购预付（无申请） -->
    <psi-form :items="items" :formData="formData" @query="handleQuery" @reset="handleReset"></psi-form>

</div>
</template>

<script setup>
import { ElMessage } from 'element-plus'
import { ref, reactive, toRefs } from 'vue'
import { queryAll, close, deleteById, edit, queryAllByBillno, queryOneNo, unclose, voidById } from './api/caigouyufu.js'

const name = ref('')
// 查询表单相关数据及方法
const formState = reactive({
// 查询表单每一项的配置
items: [
  {
    type: 'input',
    label: '单据日期-开始',
    prop: 'billDateStart'
  },
  {
    type: 'input',
    label: '单据日期-结束',
    prop: 'billDateEnd'
  },
  {
    type: 'input',
    label: '单据编号',
    prop: 'billNo',
  },
  {
    type: 'input',
    label: '处理状态',
    prop: 'billStage',
  },
  {
    type: 'input',
    label: '已关闭',
    prop: 'isClosed',
  },
  {
    type: 'input',
    label: '是否生效',
    prop: 'isEffective',
  },
  {
    type: 'input',
    label: '是否作废',
    prop: 'isVoided',
  },
  {
    type: 'input',
    label: '单据主题',
    prop: 'subject',
  },
  {
    type: 'input',
    label: '供应商',
    prop: 'supplierId',
  },
  {
    type: 'input',
    label: '付款类型',
    prop: 'paymentType',
  },
],

// 配置数据绑定的字段
formData: {
  billDateStart: '',
  billDateEnd: '',
  billNo: '',
  billStage: '',
  isClosed: '',
  isEffective: '',
  isVoided: '',
  subject: '',
  supplierId: '',
  paymentType: '',
}
})
const { items, formData } = toRefs(formState)
//表格
const tableState = reactive({
//每一列
tableItems: [
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
    type: 'text',
    label: '单据日期',
    prop: 'billDate',
    width: '120'
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
    label: '生效日期',
    prop: 'effectiveTime',
    width: '120'
  },
  {
    type: 'text',
    label: '是否自动单据',
    prop: 'isAuto',
    width: '120'
  },
  {
    type: 'text',
    label: '已关闭',
    prop: 'isClosed',
    width: '120'
  },
  {
    type: 'text',
    label: '是否生效',
    prop: 'isEffective',
    width: '120'
  },
  {
    type: 'text',
    label: '是否红字',
    prop: 'isRubric',
    width: '120'
  },
  {
    type: 'text',
    label: '是否作废',
    prop: 'isVoided',
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
    label: '单据主题',
    prop: 'subject',
    width: '120'
  },
  {
    type: 'text',
    label: '供应商',
    prop: 'supplierld',
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
// 配置表格数据绑定的字段
tableData: [],
attributes: {
  index: true, // 索引
  border: true,
  maxHeight: '400',
  height: '400',
  headOperation: []
}
})
const { tableItems, tableData, attributes } = toRefs(tableState)
//id-关闭操作，删除信息
const idState = reactive({
idItems: [
{
    type: 'text',
    label: 'id',
    prop: 'id',
  },
],
idData: {
  id: '',
}
})
const { idItems, idData } = toRefs(idState)
//付款申请单分录列表
const queryByBillNO = reactive({
queryByBillNOItems: [
{
    type: 'text',
    label: 'billNo',
    prop: 'billNo',
  },
],
queryByBillNOData: {
  billNo: '',
}
})
const { queryByBillNOItems, queryByBillNOData } = toRefs(queryAllByBillno)
//修改采购预付单
const editState = reactive({
editItems: [
  {
    type: 'text',
    label: '金额',
    prop: 'amt',
  },
  {
    type: 'text',
    label: '附件',
    prop: 'attachment',
  },
  {
    type: 'text',
    label: '单据日期',
    prop: 'billDate',
  },
  {
    type: 'text',
    label: '单据编号',
    prop: 'billNo',
  },
  {
    type: 'text',
    label: '金额',
    prop: 'entryAmt',
  },
  {
    type: 'text',
    label: '资金账户',
    prop: 'entryBankAccountld',
  },
  {
    type: 'text',
    label: '自定义1',
    prop: 'entryCustom1',
  },
  {
    type: 'text',
    label: '自定义2',
    prop: 'entryCustom2',
  },
  {
    type: 'text',
    label: '分录号',
    prop: 'entryNo',
  },
  {
    type: 'text',
    label: 'id',
    prop: 'entryId',
  },
  {
    type: 'text',
    label: 'mid',
    prop: 'entryMid',
  },
  {
    type: 'text',
    label: '备注',
    prop: 'entryRemark',
  },
  {
    type: 'text',
    label: '结算方式',
    prop: 'entrySettleMethod',
  },
  {
    type: 'text',
    label: '源单id',
    prop: 'srcBillId',
  },
  {
    type: 'text',
    label: '源单类型',
    prop: 'srcBillType',
  },
  {
    type: 'text',
    label: '源单号',
    prop: 'srcNo',
  },
  {
    type: 'text',
    label: '单据主题',
    prop: 'subject',
  },
  {
    type: 'text',
    label: '供应商',
    prop: 'supplierld',
  },
  {
    type: 'text',
    label: '版本',
    prop: 'version',
  },
],
editData: {
  amt: '',
  attachment: '',
  billDate: '',
  billNo: '',
  entryAmt: '',
  entryBankAccountld: '',
  entryCustom1: '',
  entryCustom2: '',
  entryNo: '',
  entryId: '',
  entryMid: '',
  entryRemark: '',
  entrySettleMethod: '',
  entrySrcBillId: '',
  entrySrcBillType: '',
  entrySrcNo: '',
  remark: '',
  srcBillId: '',
  srcBillType: '',
  srcNo: '',
  subject: '',
  supplierId: '',
  version: '',
}
})
const { editItems, editData } = toRefs(editState)
//查看单据详情信息
const queryOneNoState = reactive({
oneNoItems: [
{
    type: 'text',
    label: '单据编号',
    prop: 'billNo',
  },
],
oneNoData: {
  billNo: '',
}
})
const { oneNoItems, oneNoData } = toRefs(queryOneNoState)
//反关闭操作
const uncloseState = reactive({
uncloseItems: [
{
    type: 'text',
    label: 'id',
    prop: 'id',
  },
],
uncloseData: {
  id: '',
}
})
const { uncloseItems, uncloseData } = toRefs(uncloseState)
//作废操作
const voidState = reactive({
voidItems: [
{
    type: 'text',
    label: 'id',
    prop: 'id',
  },
],
voidData: {
  id: '',
}
})
const { voidItems, voidData } = toRefs(voidState)



// 分页相关配置
const pagination = reactive({
currentPage: 1, // 当前页
pageSize: 100, // 每页数据量
pageSizes: [100, 200, 300, 400], // 可选择的每页展示量
total: 400, //数据总量
layout: 'total, sizes, prev, pager, next, jumper'
})
//---------------处理事件----------
function handleQuery(){
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
function handleReset(){
handleQueryAll()
}
function handleQueryAll(){
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
function handleClose(){
let params = {}
params.id = idData.value.id
close(
  params,
  (data) => {},
  (msg) => {
    ElMessage.warning(msg)
  }
)
}
//删除信息
function handleDelete(){
let params = {}
params.id = idData.value.id
deleteById(
  params,
  (data) => {},
  (msg) => {
    ElMessage.warning(msg)
  }
)
}
//修改采购预付单功能
function handleEdit(){
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
  (data) => {},
  (msg) => {
    ElMessage.warning(msg)
  }
)
}
//付款申请单分录列表
function handlequeryAllByBillno(){
let params = {}
params.billNo = queryByBillNOData.value.billNo
queryAllByBillno(
  params,
  (data) => {},
  (msg) => {
    ElMessage.warning(msg)
  }
)
}
//查看单据详情信息
function handleQueryOneNo(){
let params = {}
params.billNo = oneNoData.value.billNo
queryOneNo(
  params,
  (data) => {},
  (msg) => {
    ElMessage.warning(msg)
  }
)
}
//反关闭操作
function handleUnclose(){
let params = {}
params.id = uncloseData.value.id
unclose(
  params,
  (data) => {},
  (msg) => {
    ElMessage.warning(msg)
  }
)
}
//作废操作
function handleVoid(){
let params = {}
params.id = voidData.value.id
voidById(
  params,
  (data) => {},
  (msg) => {
    ElMessage.warning(msg)
  }
)
}
</script>

<style scoped></style>