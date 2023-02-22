<!--
 * @Author: Kyle5 nnkyle@163.com
 * @Date: 2023-02-21 02:03:55
 * @LastEditors: Kyle5 nnkyle@163.com
 * @LastEditTime: 2023-02-21 22:08:24
 * @FilePath: \psi-frontend\src\views\jichuziliao\ClientCheck.vue
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
<template>
  <div>
    <psi-form
      :items="items"
      :formData="formData"
      :toggleItems="toggleItems"
      @query="doQuery"
      @reset="doReset"
    ></psi-form>
    <!-- 表格数据 -->
    <psi-table
      :items="tableItems"
      :tableData="tableData"
      :attributes="attributes"
      :pagination="pagination"
    >
    </psi-table>
    <!-- 弹出框 -->
    <!-- <psi-dialog
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
    </psi-dialog> -->
  </div>
</template>
    
<script setup>
import { reactive, toRefs } from 'vue'

const formState = reactive({
  // 查询表单每一项的配置
  items: [
    {
      type: 'input',
      label: '单据编号',
      prop: 'billNo',
      placeholder: '请输入'
    },
    {
      type: 'daterange',
      label: '单据日期',
      prop: 'daterange',
      startPlaceholder: '开始日期',
      endPlaceholder: '结束日期'
    }
  ],
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
const status = reactive({
  // table列配置
  tableItems: [
    {
      label: '#',
      prop: 'name',
      width: '120',
      align: 'center',
      type: 'function',
      // ES6 的 Template Strings 模版字符串
      callback: (data) => {
        return `<span style="color:#409eff"> ${data.name}</span>`
      }
    },
    {
      type: 'text',
      label: 'Date',
      prop: 'date',
      width: '120'
    },
    {
      type: 'text',
      label: 'City',
      prop: 'city',
      width: '120'
    },
    {
      type: 'text',
      label: 'Address',
      prop: 'address',
      width: '600'
    },
    {
      type: 'text',
      label: 'Zip',
      prop: 'zip',
      width: '120'
    },
    {
      type: 'text',
      label: 'Tag',
      prop: 'tag',
      width: '120'
    },
    {
      type: 'slot',
      label: '操作',
      prop: 'operation',
      slotName: 'operation'
    }
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
      date: '2016-05-03',
      name: 'Tom1',
      state: 'California',
      city: 'Los Angeles',
      address: 'No. 189, Grove St, Los Angeles',
      zip: 'CA 90036',
      tag: 'Home'
    },
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
      date: '2016-05-03',
      name: 'Tom1',
      state: 'California',
      city: 'Los Angeles',
      address: 'No. 189, Grove St, Los Angeles',
      zip: 'CA 90036',
      tag: 'Home'
    } 
  ],
  // table 总体配置
  attributes: {
    selection: true, //是否多选框
    index: true, // 索引
    border: true
  }
})

const { tableItems, tableData, attributes } = toRefs(status)

// 分页相关配置
const pagination = reactive({
  currentPage: 2, // 当前页
  pageSize: 100, // 每页数据量
  pageSizes: [100, 200, 300, 400], // 可选择的每页展示量
  total: 400, //数据总量
  layout: 'total, sizes, prev, pager, next, jumper'
})
    
    
</script>
    
<style lang='stylus' scoped></style>
    