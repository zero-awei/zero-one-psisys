<!--
 * @Author: 160405103 1348313766@qq.com
 * @Date: 2023-02-23 13:15:02
 * @LastEditors: 160405103 1348313766@qq.com
 * @LastEditTime: 2023-03-05 17:47:45
 * @FilePath: \psi-frontend\src\views\sysmanage\SysPosition.vue
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
<template>
  <div>
    <!-- 组织结构管理 -->
    <!-- 查询 -->
    <psi-form :items="formItems" :formData="formData" @query="handleQuery" @reset="handleReset"></psi-form>

    <!-- 表格 -->
    <el-row style="margin-top:10px;margin-bottom:5px">
      <el-button type="primary" @click="orgAddDialogVisible = true">新增</el-button>
    </el-row>
    <el-table :data="tableData" style="width: 100%" row-key="id" border lazy :load="load"
      :tree-props="{ children: 'children', hasChildren: 'hasChildren' }" :height="400" :max-height="400">
      <el-table-column fixed type="selection" width="50" align="center" />
      <el-table-column fixed type="index" width="50" align="center" />
      <el-table-column prop="name" label="部门名称" align="center" sortablealign="center" />
      <el-table-column prop="code" label="部门编码" align="center">
      </el-table-column>
      <el-table-column label="操作" :width="300" align="center">
        <template #default="scope">
          <!-- @click="handleEdit(scope.$index, scope.row) -->
          <el-popover placement="bottom" :width="300" trigger="click">
            <template #reference>
              <el-button style="margin-right: 16px">添加下级</el-button>
            </template>
            <el-form :model="addSubOriData" label-position="right">
              <el-form-item label="父分类" prop="pid">
                <el-input v-model="addSubOriData.pid" />
              </el-form-item>
              <el-form-item label="部门名称" prop="name">
                <el-input v-model="addSubOriData.name" />
              </el-form-item>
            </el-form>
            <el-button @click="handleAddSubCategory(scope.row)">确定</el-button>
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
        @size-change="handleSizeChange" @current-change="handleCurrentChange" />
      <!--  @size-change="handleSizeChange"
                                                                        @current-change="handleCurrentChange" -->
    </div>
    <!-- 新增 对话框 -->
    <psi-dialog ref="orgAddDialog" v-model="orgAddDialogVisible" :attrs="orgAddDialogAttrs" @determine="handleAddOrg">
      <psi-form :items="addOrgItems" :formData="addOrgFormData" :buttonShow="false"></psi-form>

    </psi-dialog>

    <!-- 编辑对话框 -->
    <psi-dialog ref="orgEditDialog" v-model="editOrgDialogVisible" :attrs="orgEditDialogAttrs" @determine="handleEditOrg">
      <psi-form :items="editOrgItems" :formData="editOrgFormData" :buttonShow="false"></psi-form>

    </psi-dialog>
  </div>
</template>

<script setup>
import { ref, reactive, toRefs, onMounted } from 'vue'
import { queryAll, insert } from './api/organizationmanagement.js'

// 查询表单相关数据及方法
const formState = reactive({
  // 查询表单每一项的配置
  formItems: [
    {
      type: 'input',
      label: '部门名称',  // 标签名
      prop: 'departName', // 对应字段
      placeholder: '请输入'
    },
  ],

  // 配置数据绑定的字段
  formData: {
    departName: '',
  }
})
const { formItems, formData } = toRefs(formState)

// 表格相关
const tableState = reactive({


  // 配置表格数据绑定的字段
  tableData: [],
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


// 新增组织结构对话框配置
let orgAddDialogVisible = ref(false)
const orgAddDialogState = reactive({
  orgAddDialogAttrs: {
    title: '新增组织结构',
    width: '80%',
    determine: true,  //对话框的确定按钮生效
  }
})

const { orgAddDialogAttrs } = toRefs(orgAddDialogState)

const addOrgState = reactive({
  addOrgItems: [
    {
      type: 'input',
      label: '机构/部门名称',
      prop: 'departName',
      placeholder: '请输入',
    },
    {
      type: 'input',
      label: '地址',
      prop: 'address',
      placeholder: '请输入',
    },
    {
      type: 'input',
      label: '创始人',
      prop: 'creatBy',
      placeholder: '请输入',
    },
    {
      type: 'input',
      label: '缩写',
      prop: 'departNameAbbr',
      placeholder: '请输入',
    },
    {
      type: 'input',
      label: '英文名',
      prop: 'departNameEn',
      placeholder: '请输入',
    },
    {
      type: 'input',
      label: '描述',
      prop: 'description',
      placeholder: '请输入',
    },



  ],
  addOrgFormData: {
    address: '',     // 地址
    creatBy: '',
    departNameAbbr: '',
    departName: '',
    departNameEn: '',
    description: ''
  }
})

const { addOrgItems, addOrgFormData, } = toRefs(addOrgState)

// 修改组织机构对话框配置

let orgEditDialogVisible = ref(false)
const orgEditDialogState = reactive({
  orgEditDialogAttrs: {
    title: '修改菜单',
    width: '80%',
    determine: true,
  }
})
const { orgEditDialogAttrs } = toRefs(orgEditDialogState)

const editOrgState = reactive({
  editOrgItems: [

    {
      type: 'input',
      label: '组织结构名称',
      prop: 'departName',
      placeholder: '请输入',
    },
  ],
  editOrgFormData: {
    departName: '',
  }
})

const { editOrgItems, editOrgFormData, } = toRefs(editOrgState)

const parentId = ref('')


onMounted(() => {
  handleQueryAll()
})


// ---------- 方法-------------
// f2 5.3 查询组织结构列表
function handleQuery() {

}

function handleQueryAll() {
  let param = {
    pageIndex: 1,
    pageSize: 1,
    pages: 100,
  }
  queryAll(
    { ...param },
    // {},
    // 成功回调函数

    (data) => {
      // 查询全部返回的是表格数据
      // 分页
      console.log('---组织结构管理', data)
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
// 重置
function handleReset() {

}

function addOrganization() {

  orgAddDialogVisible.value = true
}
// j2 5.2 新增组织结构
function handleAddOrg() {

  let params = {}
  params.address = addOrgFormData.value.address
  params.creatBy = addOrgFormData.value.creatBy
  params.departNameAbbr = addOrgFormData.value.departNameAbbr
  params.departName = addOrgFormData.value.departName
  params.departNameEn = addOrgFormData.value.departNameEn
  params.description = addOrgFormData.value.description
  console.log('params', params)
  insert(
    params,
    // {},
    // 成功回调函数

    (data) => {
      // 查询全部返回的是表格数据
      // 分页
      console.log('---组织结构管理新增', data)
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

// j2 5.1 删除组织结构
function handleDeleteOrg(data) {
  // 1.处理参数
  let params = {}
  params.departName = data.departName
}

// j2 5.5 修改组织结构
function editOrg(data) {

  editOrgFormData.departName = data.departName
  editOrgDialogVisible.value = true
}

// j2 5.4 查询指定结构树
function handleQueryParent(data) {
  let params = {}
  params.departName = data.departName
  // 调用接口

}
</script>

<style scoped></style>