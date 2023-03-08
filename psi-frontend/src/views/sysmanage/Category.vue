<!--
 * @Author: 160405103 1348313766@qq.com
 * @Date: 2023-03-07 13:46:40
 * @LastEditors: 160405103 1348313766@qq.com
 * @LastEditTime: 2023-03-08 13:32:13
 * @FilePath: \psi-frontend\src\views\sysmanage\Category.vue
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
<!--
 * @Author: 160405103 1348313766@qq.com
 * @Date: 2023-02-23 13:15:02load
 * @LastEditors: 160405103 1348313766@qq.com
 * @LastEditTime: 2023-03-07 22:44:42
 * @FilePath: \psi-frontend\src\views\sysmanage\SysPosition.vue
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
<template>
  <div>
  <!-- 分类字典 -->

    <el-row style="margin-top:10px;margin-bottom:5px">
      <el-button type="primary" @click="addNewCategory">新增</el-button>
    </el-row>
    <el-table :data="tableData" style="width: 100%" row-key="id" border lazy :load="load"
      :tree-props="{ children: 'children', hasChildren: 'hasChildren' }" :height="400" :max-height="400">
      <el-table-column fixed type="selection" width="50" align="center" />
      <el-table-column fixed type="index" width="50" align="center" />
      <el-table-column prop="name" label="分类名称" sortablealign="center" />
      <el-table-column prop="code" label="分类编码" align="center">
      </el-table-column>
      <el-table-column label="操作" :width="300" align="center">
        <template #default="scope">
          <!-- @click="handleEdit(scope.$index, scope.row) -->
          <!-- <el-popover placement="bottom" :width="300" trigger="click">
                                                                                                                  <template #reference> -->
        <el-button link type="primary" @click="addSubCategory(scope.row)">添加下级</el-button>
          |
          <el-button link type="primary" @click="editCategory(scope.row)">修改</el-button>
          |
          <el-button link type="primary" @click="handleDeleteCategory(scope.row)">删除</el-button>

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


    <!-- 新增分类 -->
    <psi-dialog v-model="categoryAddDialogVisible" :attrs="categoryAddDialogAttrs" @determine="handleAddCategory">
      <psi-form :items="addCategoryItems" :formData="addCategoryFormData" :buttonShow="false"></psi-form>

    </psi-dialog>
    <!-- 新增子分类 -->
    <psi-dialog v-model="subCategoryAddDialogVisible" :attrs="subCategoryAddDialogAttrs"
      @determine="handleAddSubCategory">
      <psi-form :items="addSubCategoryItems" :formData="addSubCategoryFormData" :buttonShow="false"></psi-form>

    </psi-dialog>
    <!-- 编辑分类 -->
    <psi-dialog v-model="categoryEditDialogVisible" :attrs="categoryEditDialogAttrs" @determine="handleEditCategory">
      <psi-form :items="editCategoryItems" :formData="editCategoryFormData" :buttonShow="false"></psi-form>

    </psi-dialog>




  </div>
</template>

<script setup>
import { ref, reactive, toRefs, onMounted } from 'vue'
import { queryAll, queryOne, insert, deleteDict, updateOne } from './api/classifieddictionary.js'


let pCategoryOptions = []
// 表格相关
const tableState = reactive({
  // 查询表单每一项的配置
  tableItems: [
    {
      type: 'text',
      label: '分类名称',
      prop: 'name',
      width: '120'
    },
    {
      type: 'text',
      label: '分类编码',
      prop: 'code',
      width: '120'
    },
  ],

  // 配置表格数据绑定的字段
  tableData: [],
})
const { tableItems, tableData } = toRefs(tableState)

// 弹出框 popover
let popoverVisible = ref(false)

// 分页相关配置
const pagination = reactive({
  currentPage: 1, // 当前页
  pageSize: 5, // 每页数据量
  pageSizes: [5, 10, 20, 30,40,50], // 可选择的每页展示量
  total: 5, //数据总量
  layout: 'total, sizes, prev, pager, next, jumper'
})
// 新增分类对话框配置
let categoryAddDialogVisible = ref(false)
const categoryAddDialogState = reactive({
  categoryAddDialogAttrs: {
    title: '新增分类',
    width: '50%',
    determine: true,  //对话框的确定按钮生效
  }
})
const { categoryAddDialogAttrs } = toRefs(categoryAddDialogState)

const addCategoryState = reactive({
  addCategoryItems: [

    {
      type: 'input',
      label: '分类名称',
      prop: 'name',
      placeholder: '请输入',
    },
    // {
    //   type: 'select',
    //   label: '父目录',
    //   prop: 'parentId',
    //   placeholder: '请选择',
    //   options: parentMenusOptions
    // },

  ],
  addCategoryFormData: {
    name: '',     // 分类名称
  }
})

const { addCategoryItems, addCategoryFormData, } = toRefs(addCategoryState)

// const parentMenusOptions=[]
// 新增子分类对话框配置
let subCategoryAddDialogVisible = ref(false)
const subCategoryAddDialogState = reactive({
  subCategoryAddDialogAttrs: {
    title: '新增子分类',
    width: '50%',
    determine: true,  //对话框的确定按钮生效
  }
})
const { subCategoryAddDialogAttrs } = toRefs(subCategoryAddDialogState)

const addSubCategoryState = reactive({
  addSubCategoryItems: [

    {
      type: 'select',
      label: '父级节点',
      prop: 'pid',
      placeholder: '请选择',
      options: []
    },
    {
      type: 'input',
      label: '分类名称',
      prop: 'name',
      placeholder: '请输入',
    },
  ],
  addSubCategoryFormData: {
    pid: '',     // 父id
    name: '', // 分类名
  }
})

const { addSubCategoryItems, addSubCategoryFormData } = toRefs(addSubCategoryState)

// 编辑分类
let categoryEditDialogVisible = ref(false)
const categoryEditDialogState = reactive({
  categoryEditDialogAttrs: {
    title: '新增分类',
    width: '50%',
    determine: true,  //对话框的确定按钮生效
  }
})
const { categoryEditDialogAttrs } = toRefs(categoryEditDialogState)

const editCategoryState = reactive({
  editCategoryItems: [
    {
      type: 'input',
      label: '分类名称',
      prop: 'name',
      placeholder: '请输入',
    },

  ],
  editCategoryFormData: {
    id: '',//i分类d
    name: '', // 分类名
  }
})

const { editCategoryItems, editCategoryFormData } = toRefs(editCategoryState)


onMounted(() => {
  handleQueryAll()
})
// -------- 方法---------



function handleQueryAll() {
  tableData.value = []
  let param = {
    pageIndex: 1,
    pageSize: 10,
  }
  queryAll(
    { ...param },
    // {},
    // 成功回调函数

    (data) => {
      // 查询全部返回的是表格数据
      // 分页
      console.log('---分类字典', data)
      pagination.currentPage = data.pageIndex
      pagination.pageSize = data.pageSize
      pagination.total = data.total

      // 表格数据
      // tableData.value = data.rows
      // 处理表格数据,根据是否有hasChild 加children属性
      pCategoryOptions = []
      data.rows.forEach((item) => {
        let temp = {}
        if (item.hasChild === "1") {
          temp.name = item.name
          temp.code = item.code
          temp.id = item.id
          temp.hasChildren = true
        } else {
          temp.name = item.name
          temp.code = item.code
          temp.id = item.id
          temp.hasChildren = false
        }
        tableData.value.push(temp)
        pCategoryOptions.push({
          label: temp.name,
          value: temp.id
        })
      })


      console.log('addSubCategoryItems------', addSubCategoryItems.value[0])
      addSubCategoryItems.value[0].options = pCategoryOptions
      editCategoryItems.value[0].options = pCategoryOptions
      console.log('data------', data)
      console.log('tableData------', tableData)
      console.log('pCategoryOptions------', pCategoryOptions)
    },
    // 失败回调函数
    (msg) => {
      ElMessage.warning(msg)
    }
  )
}

const load = (row, treeNode, resolve) => {
  let params = {}
  console.log('懒加载', row)
  params.pid = row.id
  queryOne(
    params,
    (data) => {
      console.log('查询指定得到data', data)
      if (data.rows) {
        // 如果有数据
        let resolvelist = []
        data.rows.forEach((item) => {
          let temp = {}
          if (item.hasChild === "1") {
            temp.name = item.name
            temp.code = item.code
            temp.id = item.id
            temp.hasChildren = true
          } else {
            temp.name = item.name
            temp.code = item.code
            temp.id = item.id
            temp.hasChildren = false
          }
          resolvelist.push(temp)
          pCategoryOptions.push({
            label: temp.name,
            value: temp.id
          })
        })
        resolve(resolvelist)
      } else {
        // 如果没有数据
        ElMessage.warning('该分类字典没有子分类')
        resolve([])
      }
    },
    () => {

    }
  )
}

function addNewCategory() {
  addCategoryFormData.value.name = ''
  categoryAddDialogVisible.value = true
}

function handleAddCategory() {
  // console.log('addCategoryFormData', addCategoryFormData.name)
  //  console.log('addCategoryFormData value', addCategoryFormData.value.name)
  let param = {}
  param.pid = 0
  param.name = addCategoryFormData.value.name
  insert(
    param,
    (data) => {
      ElMessage.success(data)
      categoryAddDialogVisible.value = false
      // 新增成功后更新列表
      handleQueryAll()
    },
    () => {

    }
  )
}
function addSubCategory(row) {

  addSubCategoryFormData.value.pid = row.id
  addSubCategoryFormData.value.name = ''
  console.log('addSubCategoryFormData', addSubCategoryFormData.value)
  subCategoryAddDialogVisible.value = true
}
function handleAddSubCategory() {
  let param = {}
  param.pid = addSubCategoryFormData.value.pid
  param.name = addSubCategoryFormData.value.name
  insert(
    param,
    (data) => {
      ElMessage.success(data)
      subCategoryAddDialogVisible.value = false
      // 新增成功后更新列表
      handleQueryAll()
    },
    () => {

    }
  )
}

function handleDeleteCategory(row) {
  console.log("id", row.id)
  let param = {}
  param.id = row.id
  deleteDict(
    param,
    (data) => {
      ElMessage.success(data)
      // 新增成功后更新列表
      handleQueryAll()
    },
    () => {

    }
  )
}

function editCategory(row) {
  editCategoryFormData.value.id = row.id
  editCategoryFormData.value.name = row.name
  categoryEditDialogVisible.value = true
}

function handleEditCategory() {
  updateOne(
    { ...editCategoryFormData.value },
    (msg) => {
      ElMessage.success(msg)
      categoryEditDialogVisible.value = false
      // 新增成功后更新列表
      handleQueryAll()

    },
    () => {

    }
  )
}
// 分页相关方法
// page-size 改变时触发   点击每页显示多少条数据时触发
function handleSizeChange(value) {
  tableData.value = []
  console.log("handleSizeChange", value)
  let param = {
  }
  param.pageSize = value
  param.pageIndex = pagination.currentPage
  queryAll(
    { ...param },
    // {},
    // 成功回调函数

    (data) => {
      // 查询全部返回的是表格数据
      // 分页
      console.log('---分类字典', data)
      pagination.currentPage = data.pageIndex
      pagination.pageSize = data.pageSize
      pagination.total = data.total

      // 表格数据
      // tableData.value = data.rows
      // 处理表格数据,根据是否有hasChild 加children属性
      pCategoryOptions = []
      data.rows.forEach((item) => {
        let temp = {}
        if (item.hasChild === "1") {
          temp.name = item.name
          temp.code = item.code
          temp.id = item.id
          temp.hasChildren = true
        } else {
          temp.name = item.name
          temp.code = item.code
          temp.id = item.id
          temp.hasChildren = false
        }
        tableData.value.push(temp)
        pCategoryOptions.push({
          label: temp.name,
          value: temp.id
        })
      })


      console.log('addSubCategoryItems------', addSubCategoryItems.value[0])
      addSubCategoryItems.value[0].options = pCategoryOptions
      editCategoryItems.value[0].options = pCategoryOptions
      console.log('data------', data)
      console.log('tableData------', tableData)
      console.log('pCategoryOptions------', pCategoryOptions)
    },
    // 失败回调函数
    (msg) => {
      ElMessage.warning(msg)
    }
  )
}

// current-page 改变时触发   跳转到第x页时触发
function handleCurrentChange(value) {
  tableData.value = []
  console.log("handleSizeChange", value)
  param.pageSize = pagination.pageSize
  param.pageIndex = value
  queryAll(
    { ...param },
    // {},
    // 成功回调函数

    (data) => {
      // 查询全部返回的是表格数据
      // 分页
      console.log('---分类字典', data)
      pagination.currentPage = data.pageIndex
      pagination.pageSize = data.pageSize
      pagination.total = data.total

      // 表格数据
      // tableData.value = data.rows
      // 处理表格数据,根据是否有hasChild 加children属性
      pCategoryOptions = []
      data.rows.forEach((item) => {
        let temp = {}
        if (item.hasChild === "1") {
          temp.name = item.name
          temp.code = item.code
          temp.id = item.id
          temp.hasChildren = true
        } else {
          temp.name = item.name
          temp.code = item.code
          temp.id = item.id
          temp.hasChildren = false
        }
        tableData.value.push(temp)
        pCategoryOptions.push({
          label: temp.name,
          value: temp.id
        })
      })


      console.log('addSubCategoryItems------', addSubCategoryItems.value[0])
      addSubCategoryItems.value[0].options = pCategoryOptions
      editCategoryItems.value[0].options = pCategoryOptions
      console.log('data------', data)
      console.log('tableData------', tableData)
      console.log('pCategoryOptions------', pCategoryOptions)
    },
    // 失败回调函数
    (msg) => {
      ElMessage.warning(msg)
    }
  )
}
</script>

<style scoped>
.demo-pagination-block {
  float: right;
  margin: 10px 0;
}

:deep(.el-button) {
  margin-left: 0px;
  /* margin-left: 12px; */
}
</style>