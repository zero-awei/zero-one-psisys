<!--
 * @Author: 160405103 1348313766@qq.com
 * @Date: 2023-02-21 15:35:08
 * @LastEditors: 160405103 1348313766@qq.com
 * @LastEditTime: 2023-02-28 11:08:38
 * @FilePath: \psi-frontend\src\views\sysmanage\MenuManage.vue
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
<template>
  <div>
    <!-- 菜单管理 -->
    <!-- 菜单查询 -->
    <psi-form :items="items" :formData="formData" @query="handleQuery" @reset="handleReset">
    </psi-form>
    <!-- 表格 -->
    <el-row style="margin-top:10px;margin-bottom:5px">
      <el-button type="primary" @click="menuAddDialogVisible = true">新增</el-button>
    </el-row>
    <el-table :data="tableData" style="width: 100%" row-key="id" border lazy :load="load"
      :tree-props="{ children: 'children', hasChildren: 'hasChildren' }" :height="400" :max-height="400">
      <el-table-column fixed type="selection" width="50" align="center" />
      <el-table-column fixed type="index" width="50" align="center" />
      <el-table-column prop="name" label="菜单名称" sortablealign="center" />
      <el-table-column prop="type" label="类型" align="center">
        <template #default="scope">
          <el-button v-if="scope.row.type === 0" type="primary" size="small">
            根目录
            <!-- {{ slot.data.type }} -->
          </el-button>
          <el-button v-else-if="scope.row.type === 1" type="success" size="small">
            一级菜单
          </el-button>
          <el-button v-else-if="scope.row.type === 2" type="warning" size="small">
            二级菜单
          </el-button>
          <el-button v-else="scope.row.type === 3" type="info" size="small">
            三级菜单
          </el-button>
        </template>
      </el-table-column>
      <el-table-column prop="href" label="菜单url" sortable align="center" />
      <el-table-column prop="permissionId" label="权限码" align="center" />
      <el-table-column label="操作" :width="300" align="center">
        <template #default="scope">
          <!-- @click="handleEdit(scope.$index, scope.row) -->
          <el-popover placement="bottom" :width="300" trigger="click">
            <template #reference>
              <el-button style="margin-right: 16px">添加子目录</el-button>
            </template>
            <el-form :model="addSubMenuData" label-position="right">
              <el-form-item label="菜单名称">
                <el-input v-model="addSubMenuData.name" />
              </el-form-item>
              <el-form-item label="url路径">
                <el-input v-model="addSubMenuData.path" />
              </el-form-item>
              <el-form-item label="权限码">
                <el-input v-model="addSubMenuData.permissionId" />
              </el-form-item>
            </el-form>
            <el-button @click="handleAddSubMenu(scope.row)">确定</el-button>
            <el-button @click="popoverVisible = false">取消</el-button>
          </el-popover>
          |
          <el-button link type="primary" @click="editMenu(scope.row)">修改</el-button>
          |
          <el-button link type="primary" @click="handleDeleteMenu(scope.row)">删除</el-button>

        </template>
      </el-table-column>
  </el-table>
    <div class="demo-pagination-block">
      <!-- <div class="demonstration">All combined</div> -->
      <el-pagination v-model:current-page="pagination.currentPage" v-model:page-size="pagination.pageSize"
      :page-sizes="pagination.pageSizes" :layout="pagination.layout" :total="pagination.total"
      @size-change="handleSizeChange" @current-change="handleCurrentChange" @prev-click="handlePrevClickChange"
      @next-click="handleNextClickChange" />
      <!--  @size-change="handleSizeChange"
                                                        @current-change="handleCurrentChange" -->
    </div>
    <!-- <div style="margin-top:10px"> -->
    <!-- <psi-table :items="tableItems" :tableData="tableData" :attributes="attributes" :pagination="pagination"
                                      @selectionChange="selectionChange" @add="menuAddDialogVisible = true" @sizeChange="handleSizeChange"
                                      @currentChange="handleCurrentChange" @prevClick="handlePrevClickChange" @nextClick="handleNextClickChange">
                                      <template v-slot:labelText="slot"> -->
  <!-- {{ slot.data.type === 0 }} -->
  <!-- <el-button v-if="slot.data.type === 0" type="primary" size="small"> -->
  <!-- 根目录 -->
  <!-- {{ slot.data.type }} -->
  <!-- </el-button> -->
  <!-- <el-button v-else-if="slot.data.type === 1" type="success" size="small"> -->
  <!-- 一级菜单 -->
  <!-- </el-button>
                                        <el-button v-else-if="slot.data.type === 2" type="warning" size="small">
                                          二级菜单
                                        </el-button>
          <el-button v-else="slot.data.type === 3" type="info" size="small">
            三级菜单
          </el-button>
        </template>
        <template v-slot:basicOperation="slot"> -->
  <!-- todo 有问题 -->
  <!-- @click="popoverVisible = true"  :visible="popoverVisible"-->
  <!-- <el-popover placement="bottom" :width="300" trigger="click">
            <template #reference>
              <el-button style="margin-right: 16px">添加子目录</el-button>
            </template>
            <el-form :model="addSubMenuData" label-position="right">
              <el-form-item label="菜单名称">
                <el-input v-model="addSubMenuData.name" />
              </el-form-item>
              <el-form-item label="url路径">
                <el-input v-model="addSubMenuData.path" />
              </el-form-item>
              <el-form-item label="权限码">
                <el-input v-model="addSubMenuData.permissionId" />
              </el-form-item>
            </el-form>
            <el-button @click="handleAddSubMenu(slot.data)">确定</el-button>
                                          <el-button @click="popoverVisible = false">取消</el-button>
                                        </el-popover>
                                        |
                                        <el-button link type="primary" @click="editMenu(slot.data)">修改</el-button>
                                        |
                                        <el-button link type="primary" @click="handleDeleteMenu(slot.data)">删除</el-button>
                                      </template>
                                    </psi-table> -->
    <!-- </div> -->

    <!-- 新增 对话框 -->
    <psi-dialog ref="menuAddDialog" v-model="menuAddDialogVisible" :attrs="menuAddDialogAttrs" @determine="handleAddMenu">
      <psi-form :items="addMenuItems" :formData="addMenuFormData" :buttonShow="false"></psi-form>

    </psi-dialog>

    <!-- 菜单编辑对话框 -->
    <psi-dialog ref="menuEditDialog" v-model="menuEditDialogVisible" :attrs="menuEditDialogAttrs"
      @determine="handleEditMenu">
      <psi-form :items="editMenuItems" :formData="editMenuFormData" :buttonShow="false"></psi-form>

    </psi-dialog>
  </div>
</template>


<script setup>
// ---------引入相关依赖----------
import { ref, reactive, toRefs, onMounted } from 'vue'
import { addMenu, deleteMenu, query, queryMenus, update } from './api/menu.js'
import { userStore } from '@/stores/user';

// 父目录选择框的相关数据
const parentMenusOptions = []

const uStore = userStore()
// -------------------- 数据部分 --------------
// 表单相关
const formState = reactive({
  // 查询表单每一项的配置
  items: [
    {
      type: 'input',
      label: '菜单名',
      prop: 'id'
    },
    {
      type: 'input',
      label: '父菜单名',
      prop: 'parentId'
    },
  ],

  // 配置数据绑定的字段
  formData: {
    id: '',
    parentId: ''
  }
})
const { items, formData } = toRefs(formState)

// 表格相关
const tableState = reactive({
  // 查询表单每一项的配置
  tableItems: [
    {
      type: 'text',
      label: '菜单名称',
      prop: 'name',
      width: '120'
    },
    {
      type: 'slot',
      label: '类型',
      prop: 'type',
      width: '120',
      slotName: 'labelText',
    },
    {
      type: 'daterange',
      label: '菜单url',
      prop: 'href',
      width: '120'
    },
    // TODO 权限码有问题
    {
      type: 'text',
      label: '权限码',
      prop: 'permissionId',
      width: '300'
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
    rowKey: 'id',//当 row 中包含 children 字段时，被视为树形数据。 渲染嵌套数据需要 prop 的 row-key(比如id)
    defaultExpandAll: false,// 是否默认展开所有行，当 Table 包含展开行存在或者为树形表格时有效
    lazy: true,
    headOperation: ['add', 'select']
  }
})
const { tableItems, tableData, attributes } = toRefs(tableState)

// 表格数据模拟
let da = [
  {
    id: 1,
    name: '系统管理',
    icon: 'IconSetting',
    type: 0,
    hasChildren: true,
    href: '/',
  },
  {

    id: 2,
    name: '库存管理',
    icon: 'IconSetting',
    type: 0,
    href: '/',
  }
]
tableData.value = da


// 添加子目录相关
const addSubMenuData = reactive({
  name: '',
  path: '',
  permissionId: ''
})
// 分页相关配置
const pagination = reactive({
  currentPage: 2, // 当前页
  pageSize: 100, // 每页数据量
  pageSizes: [100, 200, 300, 400], // 可选择的每页展示量
  total: 400, //数据总量
  layout: 'total, sizes, prev, pager, next, jumper'
})

// 新增菜单对话框配置
let menuAddDialogVisible = ref(false)
const menuAddDialogState = reactive({
  menuAddDialogAttrs: {
    title: '新增菜单',
    width: '50%',
    determine: true,  //对话框的确定按钮生效
  }
})

const { menuAddDialogAttrs } = toRefs(menuAddDialogState)


const addMenuState = reactive({
  addMenuItems: [

    {
      type: 'input',
      label: '菜单名称',
      prop: 'name',
      placeholder: '请输入',
    },
    {
      type: 'select',
      label: '父目录',
      prop: 'parentId',
      placeholder: '请选择',
      options: parentMenusOptions
    },
    {
      type: 'input',
      label: 'url路径',
      prop: 'path',
      placeholder: '请输入',
    },
    {
      type: 'input',
      label: '权限码',
      prop: 'permissionId',
      placeholder: '请输入',
    },

  ],
  addMenuFormData: {
    name: '',     // 菜单名称
    parentId: '', // 父目录
    path: '',     // url路径
    permissionId: '',// 权限码
  }
})

const { addMenuItems, addMenuFormData, } = toRefs(addMenuState)

// menuEditDialog配置

let menuEditDialogVisible = ref(false)
const menuEditDialogState = reactive({
  menuEditDialogAttrs: {
    title: '修改菜单',
    width: '80%',
    determine: true,
  }
})
const { menuEditDialogAttrs } = toRefs(menuEditDialogState)

const editMenuState = reactive({
  editMenuItems: [

    {
      type: 'input',
      label: '菜单名称',
      prop: 'name',
      placeholder: '请输入',
    },
    {
      type: 'select',
      label: '父目录',
      prop: 'parentId',
      placeholder: '请选择',
      options: parentMenusOptions
    },
    {
      type: 'input',
      label: 'url路径',
      prop: 'path',
      placeholder: '请输入',
    },
    {
      type: 'input',
      label: '权限码',
      prop: 'permissionId',
      placeholder: '请输入',
    },

  ],
  editMenuFormData: {
    name: '',     // 菜单名称
    parentMenuId: '', // 父目录
    path: '',     // url路径
    permissionId: '',// 权限码
  }
})

const { editMenuItems, editMenuFormData, } = toRefs(editMenuState)

// 弹出框 popover
let popoverVisible = ref(false)

onMounted(() => {
  getType()
})


// -------------------- 函数部分 ----------------
//配置select选择框 

function getType() {
  // 父目录
  const temp = uStore.getParentMenus
  // console.log("获取父目录", temp)

  temp.forEach((item) => {
    let temp = {}
    temp.label = item.text
    temp.value = item.id
    parentMenusOptions.push(temp)
  })
}

// 多选框多选时触发
function selectionChange(val) {

}

// 分页相关方法
// page-size 改变时触发
function handleSizeChange(value) {
  // console.log("handleSizeChange", value)
}

// current-page 改变时触发
function handleCurrentChange(value) {
  // console.log("handleCurrentChange", value)
}

// 用户点击上一页按钮改变当前页时触发
function handlePrevClickChange(value) {
  // console.log("handlePrevClickChange", value)
}

// 用户点击下一页按钮改变当前页时触发
function handleNextClhandleMenuDeleteickChange(value) {
  // console.log("handleNextClickChange", value)
}

// 菜单接口是不是没有分页
// j1 4.1 实现新增菜单功能
function handleAddMenu() {
  // 1.前端处理参数
  let params = {}
  // console.log('新增菜单addMenuFormData', addMenuFormData.value.name)
  params.name = addMenuFormData.value.name
  params.parentId = addMenuFormData.value.parentId
  params.path = addMenuFormData.value.path
  params.permissionId = addMenuFormData.value.permissionId
  // console.log('新增菜单', params)
  //2. 调用menujs的addMenu方法
  addMenu(
    {
      params
    },
    // 3.调用成功返回参数成功执行这个方法
    (data) => {
      // TODO 需要前后端字段匹配
      tableData = data.rows
      pagination.currentPage = data.pageIndex
      pagination.pageSize = data.pageSize
      pagination.pages = data.pages
    },
    // 4.执行失败给出提示信息
    (msg) => {
      ElMessage.error(msg)
    }
  )

}

// 点击添加子目录实现新增菜单
function handleAddSubMenu(data) {
  // console.log("------data", data)
  let params = {}
  // console.log("------addSubMenuData", addSubMenuData)
  params.parentId = data.id  // 父菜单id
  params.name = addSubMenuData.name ?? ''
  params.path = addSubMenuData.path ?? ''
  params.permissionId = addSubMenuData.permissionId ?? ''

  //2. 调用menujs的addMenu方法
  addMenu(
    {
      params
    },
    // 3.调用成功返回参数成功执行这个方法,并且关闭弹出框
    (data) => {
      // TODO 需要前后端字段匹配

      tableData = data.rows
      pagination.currentPage = data.pageIndex
      pagination.pageSize = data.pageSize
      pagination.pages = data.pages

    },
    // 4.执行失败给出提示信息
    () => {
      ElMessage.error('添加子目录出现错误')
    }
  )
  popoverVisible.value = false
}
// j1 4.2 删除菜单
function handleDeleteMenu(data) {
  let params = {}
  params.id = data.id
  // console.log('删除菜单', data)
  deleteMenu(
    {
      params
    },
    (data) => {

    },
    () => {
      ElMessage.error('deleteMenu查询数据出现错误')
    }
  )
}

// 4.3 查询菜单(id)  4.4 查询菜单(parentId)  不知道是不是接口问题
function handleQuery() {
  let params = {}
  // 根据是否有id/parentId 调用query/queryMenus

}

// j1 4.5 修改菜单
// 点击修改，打开修改菜单对话框
function editMenu(data) {
  menuEditDialogVisible.value = true
  // console.log("点击编辑行传来的数据", data)
  // 给修改菜单对话框内的表单赋值
  editMenuFormData.value.name = data.name
  editMenuFormData.value.parentMenuId = data.parentMenuId
  editMenuFormData.value.path = data.path
  editMenuFormData.value.permissionId = data.permissionId
}
// 点击确定，向后端发送数据
function handleEditMenu() {
  let params = {}
  // console.log('新增菜单addMenuFormData', addMenuFormData.value.name)
  params.name = editMenuFormData.value.name
  params.parentId = editMenuFormData.value.parentId
  params.path = editMenuFormData.value.path
  params.permissionId = editMenuFormData.value.permissionId
  // console.log("修改菜单点击确定", params)
  update(
    {
      params
    },
    // 更新成功，关闭对话框，更新表格
    (data) => {
      tableData.value = data
      menuEditDialogVisible.value = false

    },
    // 更新失败
    () => {
      ElMessage.error("更新菜单出现错误")
    }
  )
}

const load = (row, treeNode, resolve) => {
  setTimeout(() => {
    resolve([
      {
        id: 2,
        name: '角色管理',
        href: '/sysmanagement/rolemanagement',
        icon: 'IconSetting',
      },
      {
        id: 3,
        name: '菜单管理',
        href: '/sysmanagement/menumanagement',
        icon: 'IconSetting',
      },
      {
        id: 4,
        name: '用户管理',
        href: '/sysmanagement/usermanagement',
        icon: 'IconSetting',
      },
      {
        id: 5,
        name: '部门管理',
        href: '/sysmanagement/sysposition',
        icon: 'IconSetting',
      },
      {
        id: 6,
        name: '组织结构管理',
        href: '/sysmanagement/orimanage',
        icon: 'IconSetting',
      },
      {
        id: 7,
        name: '分类字典',
        icon: 'IconTickets',
        href: '/sysmanagement/Category',
      },
      {
        id: 8,
        name: '通讯录',
        icon: 'IconTickets',
        href: '/sysmanagement/addressbook',
      }
    ])
  }, 1000)
}
</script>

<style scoped>
.demo-pagination-block {
  float: right;
  margin: 10px 0;
}
</style>