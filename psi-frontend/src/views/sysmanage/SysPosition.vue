<!--
 * @Author: 160405103 1348313766@qq.com
 * @Date: 2023-02-23 13:15:02
 * @LastEditors: 160405103 1348313766@qq.com
 * @LastEditTime: 2023-02-25 19:04:02
 * @FilePath: \psi-frontend\src\views\sysmanage\SysPosition.vue
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
<template>
  <div>
    <!-- 部门/职务管理 -->
    <div>
      <!-- 查询 -->
      <psi-form :items="items" :formData="formData" @query="handleQuery" @reset="handleReset"></psi-form>
    </div>
    <div style="margin-top:10px">
      <!-- 表格数据 -->
      <psi-table :items="tableItems" :tableData="tableData" :attributes="attributes" :pagination="pagination"
        @add="handleAdd">
        <template v-slot:basicOperation="slot">
          <el-button link type="primary" @click="editPosition(slot.data)">修改</el-button>
          |
          <el-button link type="primary" @click="handleDeletePosition(slot.data)">删除</el-button>
        </template>

      </psi-table>
    </div>
  </div>
</template>

<script setup>
import { ref, reactive, toRefs, onMounted } from 'vue'
// 引入方法
// import { } from './api/caigouruku.js'
// 引入日期格式化方法
import { format } from '@/apis/date/index.js'

// 查询表单相关数据及方法
const formState = reactive({
  // 查询表单每一项的配置
  items: [
    {
      type: 'input',
      label: '职务编码',
      prop: 'code',
      placeholder: "请输入"
    },
    {
      type: 'input',
      label: '职务名称',
      prop: 'name',
      placeholder: "请输入"
    },
    {
      type: 'input',
      label: '职级',
      prop: 'postRank',
      placeholder: "请输入"
    },

  ],

  // 配置数据绑定的字段
  formData: {
    code: '',
    name: '',
    postRank: '',
  }
})
const { items, formData } = toRefs(formState)

const tableStatus = reactive({
  // table列配置
  tableItems: [
    {
      label: '职务编码',
      prop: 'code',
      width: '120',
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
      label: '职务名称',
      prop: 'name',
      width: '120'
    },
    {
      type: 'text',
      label: '职级',
      prop: 'postRank',
      width: '120'
    },
    {
      type: 'text',
      label: '组织机构编码',
      prop: 'sysOrgCode',
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
      type: 'slot',
      label: '操作',
      width: '200',
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




// ------------ 方法 ------------
// 6.1 添加职务
function handleAdd() {

}


// 6.2 删除职务
function handleDeletePosition(data) {

}

// 6.5 修改职务
function editPosition(data) {

}

// 6.3/6.4 查询职级/查询所有职务
function handleQuery(data) {

}

</script>

<style scoped></style>
