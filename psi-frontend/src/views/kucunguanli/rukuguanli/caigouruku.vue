<template>
<!-- 采购应付 -->
  <div>
    <!-- 查询 -->
    <psi-form :items="items" :formData="formData" :toggleItems="toggleItems" @query="handleQuery"
      @reset="handleReset"></psi-form>
  </div>
  <!-- 表格数据 -->
    <psi-table :items="tableItems" :tableData="tableData" :attributes="attributes" :pagination="pagination"
      @add="handleAdd">
    </psi-table>

    <!-- 弹出框 -->
    <psi-dialog ref="editDialog" v-model="editDialogVisible" :attrs="editDialogVisible">
    </psi-dialog>
    <psi-dialog ref="editDialog" v-model="examineDialogVisible" :attrs="examineDialogVisible">
    </psi-dialog>
</template>

<script setup>
import { ref, reactive, toRefs, onMounted } from 'vue'
// 引入方法

// 引入日期格式化方法
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
      placeholder: '请选择',
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
      placeholder: '请选择',
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
    daterange: [],
    isClosed: 0,
    isEffective: 0,
    isVoided: 0,
    subject: '',
    supplierId: ''
  }
})
const { items, toggleItems, formData } = toRefs(formState)



// ------------ 方法 ------------


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
  // 后端调用接口
  // query(
  //   {
  //     params
  //   },
  //   (data) => {
  //     tableData = data.rows
  //     pagination.currentPage = data.pageIndex
  //     pagination.pageSize = data.pageSize
  //     pagination.pages = data.pages
  //   }
  // )
}

// 表单重置
function handleReset() {
  //查询表单重置，表格也要刷新
  // doGetTableList()
}
</script>


<style scoped></style>
