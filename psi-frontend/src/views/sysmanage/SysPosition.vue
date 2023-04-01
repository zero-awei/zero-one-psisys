<!--
 * @Author: 160405103 1348313766@qq.com
 * @Date: 2023-02-23 13:15:02
 * @LastEditors: 160405103 1348313766@qq.com
 * @LastEditTime: 2023-03-13 22:45:53
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

    <psi-dialog ref="addPosDialog" v-model="addPosDialogVisible" :attrs="addPosDialogAttrs" @determine="handleAddPos">
      <psi-form :items="addPosItems" :formData="addPosFormData" :buttonShow="false"></psi-form>
    </psi-dialog>
  </div>
</template>

<script setup>
import { ref, reactive, toRefs, onMounted } from 'vue'
// 引入方法
// import { } from './api/caigouruku.js'
// 引入日期格式化方法
import { format } from '@/apis/date/index.js'
import { queryAll, addPosition } from './api/positionmanagement'

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
        return `<span style="color:#409eff"> ${data.code}</span>`
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
      type: 'slot',
      label: '操作',
      width: '200',
      slotName: 'basicOperation',
      fixed: 'right'
    }
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


// addPosDialog配置

let addPosDialogVisible = ref(false)
const addPosDialogState = reactive({
  addPosDialogAttrs: {
    title: '新增职务',
    width: '80%',
    determine: true
  }
})
const { addPosDialogAttrs } = toRefs(addPosDialogState)

// 新增用户对话框的数据配置
const addPosState = reactive({
  addPosItems: [
    {
      type: 'input',
      label: '职务编码',
      prop: 'code',
      placeholder: '请输入'
    },
    {
      type: 'input',
      label: '职务名称',
      prop: 'name',
      placeholder: '请输入'
    },
    {
      type: 'select',
      prop: 'postRank',
      label: '职级',
      placeholder: '请选择',
      options: [
        {
          label: '原级',
          value: '1'
        },
        {
          label: '助级',
          value: '2'
        },
        {
          label: '中级',
          value: '3'
        },
        {
          label: '副高级',
          value: '4'
        },
        {
          label: '正高级',
          value: '5'
        }
      ]
    }
  ],
  addPosFormData: {
    code: '',// 用户名
    name: '',// 密码
    postRank: '',// 电子邮箱
  }
})

const { addPosItems, addPosFormData } = toRefs(addPosState)

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
  addPosDialogVisible.value = true
}

function resetAddRole() {

}

function handleAddPos() {
  const param = {}
  param.code = addPosFormData.code
  param.name = addPosFormData.name
  param.postRank = addPosFormData.postRank

  addPosition(
    param,
    (data) => {

      //新增成功后清空表单,并且重新查询
      resetAddRole()
      handleQuery()
    },
    () => {
    }
  )
}

// 6.2 删除职务
function handleDeletePosition(data) {

}

// 6.5 修改职务
function editPosition(data) {

}

// 6.3/6.4 查询职级/查询所有职务
function handleQuery(data) {
  let param = {
    pageIndex: 1,
    pageSize: 5,
  }
  queryAll(
    param,
    // {},
    // 成功回调函数

    (data) => {
      // 查询全部返回的是表格数据
      // 分页
      // console.log('---通讯录', data)
      pagination.currentPage = data.pageIndex
      pagination.pageSize = data.pageSize
      pagination.total = data.total

      // 表格数据
      tableData.value = data.rows

    },
    // 失败回调函数
    (msg) => {
      ElMessage.warning(msg)
    }
  )
}

onMounted(() => {
  handleQuery()
})
</script>

<style scoped></style>
