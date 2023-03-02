<!--
 * @Author: 160405103 1348313766@qq.com
 * @Date: 2023-02-23 13:15:02
 * @LastEditors: 160405103 1348313766@qq.com
 * @LastEditTime: 2023-02-28 11:07:12
 * @FilePath: \psi-frontend\src\views\sysmanage\SysPosition.vue
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
<template>
  <div>
    <!-- 分类字典 -->
    <el-row style="margin-top:10px;margin-bottom:5px">
      <el-button type="primary" @click="categoryAddDialogVisible = true">新增</el-button>
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
          <el-popover placement="bottom" :width="300" trigger="click">
            <template #reference>
              <el-button style="margin-right: 16px">添加下级</el-button>
            </template>
            <el-form :model="addSubCategoryData" label-position="right">
              <el-form-item label="父分类" prop="pid">
                <el-input v-model="addSubCategoryData.pid" />
              </el-form-item>
              <el-form-item label="分类名称" prop="name">
                <el-input v-model="addSubCategoryData.name" />
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
        @size-change="handleSizeChange" @current-change="handleCurrentChange" @prev-click="handlePrevClickChange"
        @next-click="handleNextClickChange" />
      <!--  @size-change="handleSizeChange"
                                                      @current-change="handleCurrentChange" -->
    </div>
  </div>
</template>

<script setup>
import { ref, reactive, toRefs } from 'vue'

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

// 添加子分类相关
const addSubCategoryData = reactive({
  pid: '',
  name: '',
})
// 弹出框 popover
let popoverVisible = ref(false)

// 分页相关配置
const pagination = reactive({
  currentPage: 2, // 当前页
  pageSize: 100, // 每页数据量
  pageSizes: [100, 200, 300, 400], // 可选择的每页展示量
  total: 400, //数据总量
  layout: 'total, sizes, prev, pager, next, jumper'
})


// -------- 方法---------
function handleAddSubCategory() {

}
</script>

<style scoped>
.demo-pagination-block {
  float: right;
  margin: 10px 0;
}
</style>