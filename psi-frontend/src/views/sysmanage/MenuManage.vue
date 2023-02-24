<template>
  <div>
    <!-- 菜单查询 -->
    <psi-form :items="items" :formData="formData" @query="doQuery" @reset="doReset">
    </psi-form>
    <!-- 表格 -->
    <div style="margin-top:10px">
      <psi-table :items="tableItems" :tableData="tableData" :attributes="attributes" :pagination="pagination"
        @selectionChange="selectionChange" @add="addMenu">
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
          <el-button link type="primary" @click="menuEditDialogVisible = true">编辑</el-button>
          |
          <el-button link type="primary" @click="deleteMenu(slot.data)">删除</el-button>
        </template>
      </psi-table>
    </div>

    <!-- 新增 对话框 -->
    <psi-dialog ref="menuAddDialog" v-model="menuAddDialogVisible" :attrs="addDialogAttrs" @determine="determine">
      <!-- <psi-form :items="addRoleItems" :formData="addRoleFormData" :buttonShow="false"></psi-form> -->
    </psi-dialog>

    <!-- 菜单编辑对话框 -->
    <psi-dialog ref="menuEditDialog" v-model="menuEditDialogVisible" :attrs="menuEditDialogAttrs">
    </psi-dialog>
  </div>
</template>


<script setup>
import { ref, reactive, toRefs, onMounted } from 'vue'
const formState = reactive({
  // 查询表单每一项的配置
  items: [
    {
      type: 'input',
      label: '菜单名',
      prop: 'name'
    },
  ],

  // 配置数据绑定的字段
  formData: {
    name: '',
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
}]
// // // console.log('111111111')
// // // console.log(tableData)
// tableData.push(da)
tableData.value = da
// 多选
function selectionChange(val) {

}
// 添加菜单
function addMenu() {

}

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
const addDialogState = reactive({
  addDialogAttrs: {
    title: '新增菜单',
    width: '50%',
    determine: true,
  }
})
const { addDialogAttrs } = toRefs(addDialogState)


// menuEditDialog配置

let menuEditDialogVisible = ref(false)
const menuEditDialogState = reactive({
  menuEditDialogAttrs: {
    title: '修改菜单',
    width: '80%'
  }
})
const { menuEditDialogAttrs } = toRefs(menuEditDialogState)
function menuEdit(data) {
  menuEditDialogVisible.value = true
  // 弹出框内的表格数据和data配置
  // // console.log("menuDialog数据", data)
}
</script>

<style></style>