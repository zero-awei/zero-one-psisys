<!--
 * @Author: li.ziwei
 * @Date: 2023-02-13 14:25:07
 * @LastEditTime: 2023-02-19 19:50:21
 * @LastEditors: li.ziwei
 * @Description: 
 * @FilePath: \psi-frontend\src\components\table\PsiTable.vue
 * 可以输入预定的版权声明、个性签名、空行等
-->
<template>
  <div class="psi-table">
    <el-table
      ref="singleTableRef"
      :data="tableData"
      :border="attributes.border"
      table-layout="fixed"
      :default-sort="{ prop: 'date', order: 'descending' }"
    >
      <el-table-column
        v-if="attributes.selection"
        fixed
        type="selection"
        width="50"
      >
      </el-table-column>
      <el-table-column
        v-if="attributes.index"
        fixed
        type="index"
        width="50"
        align="center"
      >
      </el-table-column>

      <template v-for="item in items" :key="item.prop">
        <!-- 自定义渲染文本 -->
        <el-table-column
          v-if="item.type === 'function'"
          :label="item.label ?? ''"
          :prop="item.prop ?? ''"
          :width="item.width ?? 50"
          :type="item.type ?? ''"
          :fixed="item.fixed ?? false"
          :align="item.align"
        >
          <template #default="scope">
            <div v-html="item.callback && item.callback(scope.row)"></div>
          </template>
        </el-table-column>
        <el-table-column
          v-else
          :label="item.label ?? ''"
          :prop="item.prop ?? ''"
          :width="item.width ?? 50"
          :type="item.type ?? ''"
          :fixed="item.fixed ?? false"
          :align="item.align"
        ></el-table-column>
      </template>
      <el-table-column fixed="right" label="操作" width="120">
        <template #default="scope">
          <el-button link type="primary" size="small" @click="edit(scope.row)"
            >编辑</el-button
          >
          <el-button link type="primary" size="small">更多</el-button>
        </template>
        <!-- <template #default> -->
        <!-- <slot></slot> -->
        <!-- <el-button link type="primary" size="small">Detail</el-button>
          <el-button link type="primary" size="small">Edit</el-button> -->
        <!-- </template> -->
      </el-table-column>
    </el-table>
    <div class="demo-pagination-block">
      <!-- <div class="demonstration">All combined</div> -->
      <el-pagination
        v-model:current-page="pagination.currentPage"
        v-model:page-size="pagination.pageSize"
        :page-sizes="pagination.pageSizes"
        :layout="pagination.layout"
        :total="pagination.total"
      />
      <!--  @size-change="handleSizeChange"
        @current-change="handleCurrentChange" -->
    </div>
  </div>
</template>

<script setup>
import { ref } from 'vue'
const prop = defineProps({
  items: {
    type: Array,
    default: () => []
  },
  tableData: {
    type: Array,
    default: () => []
  },
  attributes: {
    type: Object,
    default: () => {}
  },
  pagination: {
    type: Object,
    default: () => {}
  }
})

// const handleSizeChange = (val) => {
//   console.log(`${val} items per page`)
// }
// const handleCurrentChange = (val) => {
//   console.log(`current page: ${val}`)
// }
</script>

<style>
.demo-pagination-block {
  float: right;
  margin: 10px 0;
}
</style>
