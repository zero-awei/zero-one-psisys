<template>
  <div>
    <!--用户管理 -->
    <!-- 查询 -->
    <psi-form :items="items" :formData="formData" @query="doQuery" @reset="doReset"></psi-form>
    <!-- 表格数据 -->
    <div style="margin-top:10px">
      <psi-table :items="tableItems" :tableData="tableData" :attributes="attributes" :pagination="pagination"
        @add="addUserDialogVisible = true">
        <!-- 批量操作 -->
        <template v-slot:batchOperation="slot">
          <el-button>批量操作</el-button>
        </template>
        <template v-slot:basicOperation="slot">


          <el-button link type="primary" @click="editUser">编辑</el-button>
          |
          <el-button link type="primary" @click="handleDeleteUser(slot.data)">删除</el-button>
          |
          <el-button v-if="userState === '1'" link type="primary" @click="handleStatus()">冻结</el-button>
          <el-button v-else="userState === '2'" link type="danger" @click="handleStatus()">解冻</el-button>
        </template>
      </psi-table>
    </div>
    <!-- 弹出框 -->
    <!-- 新增用户对话框 -->
    <psi-dialog ref="addUserDialog" v-model="addUserDialogVisible" :attrs="addUserDialogAttrs" @determine="handleAddUser">
      <psi-form :items="addUserItems" :formData="addUserFormData" :buttonShow="false"></psi-form>
    </psi-dialog>
    <!-- 编辑用户对话框 -->
    <psi-dialog ref="editUserDialog" v-model="editUserDialogVisible" :attrs="editUserDialogAttrs"
      @determine="handleEditUser">

      <psi-form :items="editUserItems" :formData="editUserFormData" :buttonShow="false"></psi-form>
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

// addUserDialog配置

let addUserDialogVisible = ref(false)
const addUserDialogState = reactive({
  addUserDialogAttrs: {
    title: '新增用户',
    width: '80%'
  }
})
const { addUserDialogAttrs } = toRefs(addUserDialogState)

// editUserDialog配置

let editUserDialogVisible = ref(false)
const editUserDialogState = reactive({
  editUserDialogAttrs: {
    title: '修改用户',
    width: '80%'
  }
})
const { editUserDialogAttrs } = toRefs(editUserDialogState)

// 新增用户对话框的数据配置
const addUserState = reactive({
  addUserItems: [
    {
      type: 'input',
      label: '用户名',
      prop: 'username',
      placeholder: '请输入'
    },
    {
      type: 'input',
      label: '用户名',
      prop: 'username',
      placeholder: '请输入'
    },
    {
      type: 'input',
      label: '密码',
      prop: 'password',
      placeholder: '请输入'
    },
    {
      type: 'input',
      label: '电子邮箱',
      prop: 'email',
      placeholder: '请输入'
    },
    {
      type: 'select',
      prop: 'departIds',
      label: '部门',
      placeholder: '请选择',
      options: [
        {
          label: '部门1',
          value: '1'
        },
        {
          label: '部门2',
          value: '2'
        }
      ]
    }
  ],
  addUserFormData: {
    username: '',// 用户名
    password: '',// 密码
    email: '',// 电子邮箱
    departIds: ''// 部门id
  }
})

const { addUserItems, addUserFormData } = toRefs(addUserState)

const userState = ref('1') //用户状态默认正常

const editUserState = reactive({
  editUserItems: [
    {
      type: 'input',
      label: '用户名',
      prop: 'username',
      placeholder: '请输入'
    },
    {
      type: 'input',
      label: '用户名',
      prop: 'username',
      placeholder: '请输入'
    },
    {
      type: 'input',
      label: '密码',
      prop: 'password',
      placeholder: '请输入'
    },
    {
      type: 'input',
      label: '电子邮箱',
      prop: 'email',
      placeholder: '请输入'
    },
    {
      type: 'select',
      prop: 'departIds',
      label: '部门',
      placeholder: '请选择',
      options: [
        {
          label: '部门1',
          value: '1'
        },
        {
          label: '部门2',
          value: '2'
        }
      ]
    }
  ],
  editUserFormData: {
    username: '',// 用户名
    password: '',// 密码
    email: '',// 电子邮箱
    departIds: ''// 部门id
  }
})

const { editUserItems, editUserFormData } = toRefs(editUserState)

// ------------------方法--------------------


// j1 3.1新增用户
function handleAddUser() {
  let params = {}
  // addUserFormData.value

  // 请求后端

}

// j1 3.2删除用户
function handleDeleteUser(data) {

}

// j1 3.5 查询用户列表  3.8 查询用户是什么场景下使用 TODO
function doQuery() {

}



// j1 3.7 修改用户信息 3.9修改用户信息(回显)什么场景下使用 TODO
function editUser() {
  let param = {}
  // param.xx = editMenuFormData.xx
  editUserDialogVisible = true
  // 弹出框内的表格数据和data配置


}
function handleEditUser() {

}

// j1 3.10 冻结/解冻
function handleStatus() {

}

// 删除用户


</script>

<style scoped></style>
