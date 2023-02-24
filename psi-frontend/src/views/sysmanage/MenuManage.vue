<!--
 * @Author: 160405103 1348313766@qq.com
 * @Date: 2023-02-21 15:35:08
 * @LastEditors: 160405103 1348313766@qq.com
 * @LastEditTime: 2023-02-25 00:48:24
 * @FilePath: \psi-frontend\src\views\sysmanage\MenuManage.vue
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
<!--
 * @Author: 160405103 1348313766@qq.com
 * @Date: 2023-02-21 15:35:08
 * @LastEditors: 160405103 1348313766@qq.com
 * @LastEditTime: 2023-02-24 13:51:41
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
    <div style="margin-top:10px">
      <psi-table :items="tableItems" :tableData="tableData" :attributes="attributes" :pagination="pagination"
        @selectionChange="selectionChange" @add="menuAddDialogVisible = true" @sizeChange="handleSizeChange"
        @currentChange="handleCurrentChange" @prevClick="handlePrevClickChange" @nextClick="handleNextClickChange">
        <template v-slot:labelText="slot">
          <!-- {{ slot.data.type === 0 }} -->
          <el-button v-if="slot.data.type === 0" type="primary" size="small">
            根目录
            <!-- {{ slot.data.type }} -->
          </el-button>
          <el-button v-else-if="slot.data.type === 1" type="success" size="small">
            一级菜单
          </el-button>
          <el-button v-else-if="slot.data.type === 2" type="warning" size="small">
            二级菜单
          </el-button>
          <el-button v-else="slot.data.type === 3" type="info" size="small">
            三级菜单
          </el-button>
        </template>
        <template v-slot:basicOperation="slot">
          <el-popover placement="bottom" :width="300" trigger="click">
            <template #reference>
              <el-button style="margin-right: 16px">添加子目录</el-button>
            </template>
            <el-form :model="addSonMenuData" label-position="right">
              <el-form-item label="菜单名称">
                <el-input v-model="addSonMenuData.name" />
              </el-form-item>
              <el-form-item label="url路径">
                <el-input v-model="addSonMenuData.path" />
              </el-form-item>
              <el-form-item label="权限码">
                <el-input v-model="addSonMenuData.permissionId" />
              </el-form-item>
            </el-form>
          </el-popover>
          |
          <el-button link type="primary" @click="menuEditDialogVisible = true">修改</el-button>
          |
          <el-button link type="primary" @click="handleDeleteMenu(slot.data)">删除</el-button>
        </template>
      </psi-table>
    </div>

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
      prop: 'path',
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
    headOperation: ['add', 'select']
  }
})
const { tableItems, tableData, attributes } = toRefs(tableState)

// 表格数据模拟
let da = [{
  "name": "根目录",
  "type": 0,
  "path": "/admin",
  "permissionId": "f6817f48af4fb3af11b9e8bf182f618b",
},
{
  "name": "一级菜单",
  "type": 1,
  "path": "/one",
  "permissionId": "f6817f48af4fb3af11b9e8bf182f618b",
},
{
  "name": "二级菜单",
  "type": 2,
  "path": "/two",
  "permissionId": "f6817f48af4fb3af11b9e8bf182f618b",
},
{
  "name": "三级菜单",
  "type": 3,
  "path": "/three",
  "permissionId": "f6817f48af4fb3af11b9e8bf182f618b",
}
]
tableData.value = da

// 添加子目录相关
const addSonMenuData = reactive({
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
      prop: 'roleName',
      placeholder: '请选择',
      options: [
        {
          label: '目录1',
          value: 0
        },
        {
          label: '目录2',
          value: 1
        }
      ]
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
    roleName: '', // 父目录
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
    width: '80%'
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
      prop: 'roleName',
      placeholder: '请选择',
      options: [
        {
          label: '目录1',
          value: 0
        },
        {
          label: '目录2',
          value: 1
        }
      ]
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
    roleName: '', // 父目录
    path: '',     // url路径
    permissionId: '',// 权限码
  }
})

const { editMenuItems, editMenuFormData, } = toRefs(editMenuState)

// -------------------- 函数部分 ----------------
// 多选框多选时触发
function selectionChange(val) {

}

// 分页相关方法
// page-size 改变时触发
function handleSizeChange(value) {
  console.log("handleSizeChange", value)
}

// current-page 改变时触发
function handleCurrentChange(value) {
  console.log("handleCurrentChange", value)
}

// 用户点击上一页按钮改变当前页时触发
function handlePrevClickChange(value) {
  console.log("handlePrevClickChange", value)
}

// 用户点击下一页按钮改变当前页时触发
function handleNextClhandleMenuDeleteickChange(value) {
  console.log("handleNextClickChange", value)
}

// 菜单接口是不是没有分页
// j1 4.1 实现新增菜单功能
function handleAddMenu() {
  // 1.前端处理参数
  let params = {}
  // console.log('新增菜单addMenuFormData', addMenuFormData.value.name)
  params.name = addMenuFormData.value.name
  params.roleName = addMenuFormData.value.roleName
  params.path = addMenuFormData.value.path
  params.permissionId = addMenuFormData.value.permissionId
  console.log('新增菜单', params)
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
    () => {
      ElMessage.error('addMenu查询数据出现错误')
    }
  )

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
function handleEditMenu() {
  let params = {}
  // console.log('新增菜单addMenuFormData', addMenuFormData.value.name)
  params.name = addMenuFormData.value.name
  params.roleName = addMenuFormData.value.roleName
  params.path = addMenuFormData.value.path
  params.permissionId = addMenuFormData.value.permissionId
}

</script>

<style scoped></style>