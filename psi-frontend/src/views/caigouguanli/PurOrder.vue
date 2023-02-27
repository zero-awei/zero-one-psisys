<template>
  <div>
    <!-- 采购订单 -->
    <psi-form
      :items="items"
      :formData="formData"
      :toggleItems="toggleItems"
      @query="doQuery"
      @reset="doReset"
    ></psi-form>

    <!-- 表格数据 -->
    <!-- 修改点1 -->
    <div style="margin-top:10px">
      <psi-table
      :items="tableItems"
      :tableData="tableData"
      :attributes="attributes"
      :pagination="pagination" 
      @add="addClient"
    >
      <template v-slot:basicOperation="slot">
      <!-- 修改点2 -->
        <el-button link type="primary" @click="clientEditDialogVisible = true">编辑</el-button>

        <el-button link type="primary" @click="deleteRole(slot.data)">删除</el-button>
      </template>
  
    </psi-table>
    </div>

  </div>
</template>
    
<script setup>
import { reactive, toRefs, ref } from 'vue'

// 编辑删除
// 修改点3~5
function addClient() {
  addDialogVisible.value = true
  // addDrawerVisible.value = true
}
let clientEditDialogVisible = ref(false)

// const { clientEditDialogAttrs } = toRefs(clientEditDialogState)


const formState = reactive({
  // 查询表单每一项的配置
  // 修改点6
  items: [
    {
      type: 'input',
      label: '编码',
      prop: 'code',
      placeholder: '请输入编码'
    },
    {
      type: 'daterange',
      label: '日期',
      prop: 'daterange',
      startPlaceholder: '开始日期',
      endPlaceholder: '结束日期'
    }
  ],
  // 传给后台的查询数据，由输入框传来
  // 修改点7
  formData: {
    code: '',
    daterange: [],
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
    // 表格右侧固定的编辑和删除
    {
      type: 'slot',
      label: '操作',
      width: '120',
      slotName: 'basicOperation',
      fixed: 'right'
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
    border: true,
    maxHeight: '400',
    height: '400',
    // 待后续修改1
    headOperation: ['add', 'select'],
    // rightOperation: true
  }
})

const { tableItems, tableData, attributes } = toRefs(status)

// 分页相关配置
// 待后续修改2
const pagination = reactive({
  currentPage: 2, // 当前页
  pageSize: 100, // 每页数据量
  pageSizes: [100, 200, 300, 400], // 可选择的每页展示量
  total: 400, //数据总量
  layout: 'total, sizes, prev, pager, next, jumper'
})
</script>
    
<style lang='stylus' scoped></style>
    