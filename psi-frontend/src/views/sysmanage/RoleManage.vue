<!--
 * @Author: 160405103 1348313766@qq.com
 * @Date: 2023-02-21 15:35:40
 * @LastEditors: 160405103 1348313766@qq.com
 * @LastEditTime: 2023-03-13 22:44:49
 * @FilePath: \psi-frontend\src\views\sysmanage\RoleManage.vue
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
<template>
  <div>
    <!-- 查询 -->
    <psi-form :items="items" :formData="formData" @query="doQuery" @reset="doReset"></psi-form>

    <div style="margin-top:10px">
      <!-- <el-button type="primary" @click="addDialogVisible = true">新增</el-button> -->
      <!-- 表格数据 -->
      <psi-table :items="tableItems" :tableData="tableData" :attributes="attributes" :pagination="pagination"
        @selectionChange="selectionChange" @add="addRole">
        <!-- 头部操作行插槽，会渲染在新增、导入、导出的后面 -->
        <template v-slot:batchOperation>
          <el-button type="primary" @click="batchDeleteRole">批量删除</el-button>
        </template>
        <!-- // 表格列 el-table-column 插槽 -->
        <!-- 菜单操作 -->
        <template v-slot:menuOperation="slot">
          <!-- {{ slot.data }} -->
          <!-- slot.data是子组件的scope.row -->
          <el-button link type="primary" @click="menuEdit(slot.data)">编辑</el-button>
        </template>
        <!-- 权限操作 -->
        <template v-slot:permissionOperation="slot">
          <el-button link type="primary" @click="permissonEdit(slot.data)">编辑</el-button>
        </template>
        <!-- 角色操作 -->
        <template v-slot:basicOperation="slot">
          <el-button link type="primary" @click="editRole(slot.data)">编辑</el-button>

          <el-button link type="primary" @click="handleDeleteRole(slot.data)">删除</el-button>
        </template>
      </psi-table>
    </div>

    <!-- 对话框 -->
    <!-- 新增 对话框 -->
    <psi-dialog v-model="addDialogVisible" :attrs="addDialogAttrs" @determine="handleAddRole">
      <psi-form :items="addRoleItems" :formData="addRoleFormData" :buttonShow="false"></psi-form>
    </psi-dialog>
    <!-- 菜单编辑对话框 -->
    <psi-dialog v-model="menuEditDialogVisible" :attrs="menuEditDialogAttrs">

      <psi-table :items="editMenuTableItems" :tableData="editMenuTableData" :attributes="editMenuAttr">
        <template v-slot:menuOperation="slot">
          <!-- {{ slot.data }} -->
          <!-- slot.data是子组件的scope.row -->
          <el-button link type="primary" @click="">编辑</el-button>
          <el-button link type="primary" @click="">删除</el-button>

        </template>
      </psi-table>
    </psi-dialog>
    <!-- 权限编辑对话框 -->
    <psi-dialog v-model="permissonEditDialogVisible" :attrs="permissonEditDialogAttrs">
      <psi-table :items="editPermisssionTableItems" :tableData="editPermisssionTableData"
        :attributes="editPermisssionAttr">
        <template v-slot:permissonOperation="slot">
          <!-- {{ slot.data }} -->
          <!-- slot.data是子组件的scope.row -->
          <el-button link type="primary" @click="">编辑</el-button>
          <el-button link type="primary" @click="">删除</el-button>

        </template>
      </psi-table>
    </psi-dialog>
    <!-- 角色编辑对话框 -->
    <psi-dialog v-model="roleEditDialogVisible" :attrs="roleEditDialogAttrs" @determine="handleEditRole">
      <psi-form :items="editRoleItems" :formData="editRoleFormData" :buttonShow="false"></psi-form>

    </psi-dialog>
  </div>
</template>

<script setup>
import { ref, reactive, toRefs, onMounted } from 'vue'
import { queryAllRole, addRoleJson, deleteRole } from './api/role.js'
import { format } from '@/apis/date/index.js'
import { userStore } from '@/stores/user.js'
// import { pathStore } from '@/stores/public.js'
const store = userStore()
// const pStore = pathStore()
// 查询表单相关数据及方法
const formState = reactive({
  // 查询表单每一项的配置
  items: [
    {
      type: 'input',
      label: '角色名',
      prop: 'roleName'
    },
    {
      type: 'input',
      label: '角色编码',
      prop: 'roleCode',
    },
  ],

  // 配置数据绑定的字段
  formData: {
    roleName: '',
    roleCode: '',
  }
})
const { items, formData } = toRefs(formState)
// 表单重置
function doReset() {
  //查询表单重置，表格也要刷新
  doGetTableList()
}
// 7.5 普通查询 TODO
function doQuery(data) {
  // // console.log('父组件接收')
  // // console.log(data)
  // // // console.log('params--', params.daterange)
  // 处理表单数据 主要是开始日期和结束日期
  // TODO 前端处理数据，请求参数为 params
  let params = {}
  params.roleName = data.roleName
  params.roleCode = data.roleCode
  // params.billStage = data.billStage
  // params.isClosed = data.isClosed
  // params.isEffective = data.isEffective
  // params.isVoided = data.isVoided
  // params.subject = data.subject
  // params.supplierId = data.supplierId
  // params.billDateBegin = format(data.daterange[0], 'yyyy-MM-dd hh:mm:ss')
  // params.billDateEnd = format(data.daterange[1], 'yyyy-MM-dd hh:mm:ss')
  // // console.log('params', params)
  // TODO 前后端联调接口
  // query(
  //   {
  //     params
  //   },
  //   // 请求成功回调   
  //   (data) => {
  //     tableData = data.rows
  //     pagination.currentPage = data.pageIndex
  //     pagination.pageSize = data.pageSize
  //     pagination.pages = data.pages
  //     pagination.total = data.total
  //     // // console.log('000000',data)
  //   }
  //   // 请求失败回调
  //   ()=>{
  //
  //    }
  // )
}
// 表格相关
const tableState = reactive({
  // 查询表单每一项的配置
  tableItems: [
    {
      type: 'text',
      label: '角色id',
      prop: 'id',
      width: '120'
    },
    {
      type: 'text',
      label: '角色名',
      prop: 'roleName',
      width: '120'
    },
    {
      type: 'daterange',
      label: '角色编码',
      prop: 'roleCode',
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
      label: '修改人',
      prop: 'updateBy',
      width: '120'
    },
    {
      type: 'text',
      label: '修改时间',
      prop: 'updateTime',
      width: '200'
    },
    {
      type: 'text',
      label: '描述',
      prop: 'description',
      width: '240'
    },
    {
      type: 'slot',
      label: '菜单操作',
      width: '120',
      slotName: 'menuOperation',
      fixed: 'right'
    },
    {
      type: 'slot',
      label: '权限操作',
      width: '120',
      slotName: 'permissionOperation',
      fixed: 'right'
    },
    {
      type: 'slot',
      label: '操作',
      width: '120',
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
// 表格数据模拟
// let da = {
//   "createBy": "admin",
//   "createTime": "2018-12-21 18:03:39",
//   "description": "管理员",
//   "id": "f6817f48af4fb3af11b9e8bf182f618b",
//   "roleCode": "admin",
//   "roleName": "管理员",
//   "updateBy": "admin",
//   "updateTime": "2019-05-20 11:40:26"
// }
// // // // console.log('111111111')
// // // // console.log(tableData)
// // tableData.push(da)
// tableData.value.push(da)


// 新增角色模块
const addRoleFormState = reactive({
  // 查询表单每一项的配置
  addRoleItems: [
    // {
    //   type: 'input',
    //   label: '创建人',
    //   prop: 'createBy'
    // },
    // {
    //   type: 'datePicker',
    //   label: '创建时间',
    //   prop: 'createTime'
    // },
    {
      type: 'input',
      label: '角色名称',
      prop: 'roleName',
    },
    {
      type: 'input',
      label: '角色编码',
      prop: 'roleCode',

    },
    {
      type: 'input',
      label: '描述',
      prop: 'description',
    },
    // {
    //   type: 'input',
    //   label: '角色id',
    //   prop: 'id',
    // },
    // {
    //   type: 'input',
    //   label: '角色编码',
    //   prop: 'roleCode',
    // },

    // {
    //   type: 'input',
    //   label: '更新人',
    //   prop: 'updateBy',
    // },
    // {
    //   type: 'datePicker',
    //   label: '更新时间',
    //   prop: 'updateTime'
    // },
  ],

  // 配置数据绑定的字段
  addRoleFormData: {
    // createBy: '',
    // createTime: '',
    description: '',
    // id: '',
    // roleCode: '',
    roleName: '',
    roleCode: ''
    // updateBy: '',
    // updateTime: '',
  },
})
const { addRoleItems, addRoleFormData, } = toRefs(addRoleFormState)

// 分页相关配置
const pagination = reactive({
  currentPage: 2, // 当前页
  pageSize: 10, // 每页数据量
  pageSizes: [10, 20, 30, 40], // 可选择的每页展示量
  total: 400, //数据总量
  layout: 'total, sizes, prev, pager, next, jumper'
})


// 新增角色对话框配置

let addDialogVisible = ref(false)
const addDialogState = reactive({
  addDialogAttrs: {
    title: '角色新增',
    width: '60%',
    determine: true,
  }
})
const { addDialogAttrs } = toRefs(addDialogState)
// 新增角色调用接口

// menuEditDialog配置

let menuEditDialogVisible = ref(false)
const menuEditDialogState = reactive({
  menuEditDialogAttrs: {
    title: '菜单操作',
    width: '80%'
  }
})
const { menuEditDialogAttrs } = toRefs(menuEditDialogState)

const editMenuTableState = reactive({
  // 查询表单每一项的配置
  editMenuTableItems: [
    {
      type: 'text',
      label: '菜单id',
      prop: 'id',
      width: '120'
    },
    {
      type: 'text',
      label: '菜单名',
      prop: 'roleName',
      width: '120'
    },
    {
      type: 'daterange',
      label: '描述',
      prop: 'roleCode',
      width: '120'
    },
    {
      type: 'slot',
      label: '菜单操作',
      width: '120',
      slotName: 'menuOperation',
      fixed: 'right'
    },

  ],

  // 配置数据绑定的字段
  editMenuTableData: [],
  editMenuAttr: {
    selection: true, //是否多选框
    index: true, // 索引
    border: true,
    maxHeight: '400',
    height: '400',
    headOperation: ['add', 'select']
  }
})
const { editMenuTableItems, editMenuTableData, editMenuAttr } = toRefs(editMenuTableState)

const editPermissionTableState = reactive({
  // 查询表单每一项的配置
  editPermisssionTableItems: [
    {
      type: 'text',
      label: '权限id',
      prop: 'id',
      width: '120'
    },
    {
      type: 'text',
      label: '权限名',
      prop: 'roleName',
      width: '120'
    },
    {
      type: 'daterange',
      label: '描述',
      prop: 'roleCode',
      width: '120'
    },
    {
      type: 'slot',
      label: '权限操作',
      width: '120',
      slotName: 'permissonOperation',
      fixed: 'right'
    },

  ],

  // 配置数据绑定的字段
  editPermisssionTableData: [],
  editPermisssionAttr: {
    selection: true, //是否多选框
    index: true, // 索引
    border: true,
    maxHeight: '400',
    height: '400',
    headOperation: ['add', 'select']
  }
})
const { editPermisssionTableItems, editPermisssionTableData, editPermisssionAttr } = toRefs(editPermissionTableState)




// 权限编辑permissonEditDialog配置
let permissonEditDialogVisible = ref(false)
const permissonEditDialogState = reactive({
  permissonEditDialogAttrs: {
    title: '权限操作',
    width: '80%'
  }
})
const { permissonEditDialogAttrs } = toRefs(permissonEditDialogState)

//roleEditDialog 配置
let roleEditDialogVisible = ref(false)
const roleEditDialogState = reactive({
  roleEditDialogAttrs: {
    title: '编辑角色',
    width: '80%',
    determine: true
  }
})
const { roleEditDialogAttrs } = toRefs(roleEditDialogState)
const editRoleFormState = reactive({
  // 查询表单每一项的配置
  editRoleItems: [
    {
      type: 'input',
      label: '创建人',
      prop: 'createBy'
    },
    {
      type: 'datePicker',
      label: '创建时间',
      prop: 'createTime'
    },
    {
      type: 'input',
      label: '描述',
      prop: 'description',
    },
    {
      type: 'input',
      label: '角色id',
      prop: 'id',
    },
    {
      type: 'input',
      label: '角色编码',
      prop: 'roleCode',
    },
    {
      type: 'input',
      label: '角色名称',
      prop: 'roleName',
    },

    {
      type: 'input',
      label: '更新人',
      prop: 'updateBy',
    },
    {
      type: 'datePicker',
      label: '更新时间',
      prop: 'updateTime'
    },
  ],

  // 配置数据绑定的字段
  editRoleFormData: {
    createBy: '',
    createTime: '',
    description: '',
    id: '',
    roleCode: '',
    roleName: '',
    updateBy: '',
    updateTime: '',
  }
})
const { editRoleItems, editRoleFormData } = toRefs(editRoleFormState)
// 进入页面时查询表格所有单据
onMounted(() => {
  doQueryAllRole()

})

// ------------------------ 方法---------------------------
// 6.3 分页查询所有用户
function doQueryAllRole() {
  let param = {
    pageIndex: 1,
    pageSize: 10,
  }
  queryAllRole(
    param,
    (data) => {
      // 查询全部返回的是表格数据
      // 分页
      console.log('---查询所有角色', data)
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

// 新增角色打开对话框
function addRole() {
  addDialogVisible.value = true
}
// 新增角色表单清空
function resetAddRole() {
  // addRoleFormData.createBy = ''
  // addRoleFormData.createTime = ''
  addRoleFormData.description = ''
  // addRoleFormData.id = ''
  // addRoleFormData.roleCode = ''
  addRoleFormData.roleName = ''
  addRoleFormData.roleCode = ''
  // addRoleFormData.updateBy = ''
  // addRoleFormData.updateTime = ''
}
// 6.2 新增角色
function handleAddRole() {
  // TODO前后端联调
  // // console.log("pinia00000000", store.getUser)
  const param = {}
  param.roleName = addRoleFormData.roleName
  param.description = addRoleFormData.description
  param.roleCode = addRoleFormData.roleCode
  // const nDate = new Date()
  // param.createTime = format(nDate, 'yyyy-MM-dd hh:mm:ss')
  // param.createBy = store.getUser.roles[0]
  addRoleJson(
    param,
    (data) => {

      //新增成功后清空表单,并且重新查询
      resetAddRole()
      doQueryAllRole()
    },
    () => {



    }
  )
  // param.id =

}
// 6.1 删除角色
function handleDeleteRole(data) {
  // TODO 前后端接口
  console.log('删除角色id', data)
  // 
  let ids = data.id
  deleteRole(
    ids,
    (data) => {
      if (data.code === 10000) {
        // 删除成功后更新列表
        doQueryAllRole()
      } else {
        Elmessage.warn('删除失败')
      }
    },
    () => {

    }

  )
}


function editRole(data) {
  roleEditDialogVisible.value = true
}
// 6.4 编辑角色
function handleEditRole() {

}


function menuEdit(data) {
  menuEditDialogVisible.value = true
  // 弹出框内的表格数据和data配置
  // // console.log("menuDialog数据", data)
}


// 权限编辑
function permissonEdit(data) {
  console.log('权限编辑data', data)
  permissonEditDialogVisible.value = true
}


// 多选
const changeList = ref([])
function selectionChange(val) {
  // TODO 写个函数防抖
  changeList = val
}
// 批量删除角色
function batchDeleteRole() {
  // TODO 前后端接口
}
</script>

<style scoped></style>
