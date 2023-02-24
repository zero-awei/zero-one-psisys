<!--
 * @Author: li.ziwei
 * @Date: 2023-02-13 14:25:07
 * @LastEditTime: 2023-02-24 13:07:55
 * @LastEditors: 160405103 1348313766@qq.com
 * @Description: 
 * @FilePath: \psi-frontend\src\components\table\PsiTable.vue
 * 可以输入预定的版权声明、个性签名、空行等
-->
<template>
  <div class="psi-table">
    <el-row class="operaion" justify="space-between" v-if="attributes.headOperation.length > 0">
      <el-col :span="12">
        <el-button v-if="attributes.headOperation.indexOf('add') >= 0" type="primary" @click="add"> 新增 </el-button>
        <el-button v-if="attributes.headOperation.indexOf('importData') >= 0" type="primary" @click="importData"> 导入
        </el-button>
        <el-button v-if="attributes.headOperation.indexOf('exportData') >= 0" type="primary" @click="exportData"> 导出
        </el-button>
        <el-button link v-if="attributes.headOperation.indexOf('select') >= 0">
          已选择 &nbsp;<span style="color: #409eff">
            {{ selectNum }} &nbsp;

          </span>
          项
        </el-button>
        <!-- 批量操作插槽 -->
        <slot name="batchOperation">

        </slot>
      </el-col>
      <el-col :span="6" style="flex: none">
        <!-- <el-button type="primary">自定义列</el-button> -->
        <psi-popover :items="customStatus.items" :placement="attrs.placement" :title="attrs.title" :width="attrs.width"
          :trigger="attrs.trigger" @change="handleCustomChange" />
      </el-col>
    </el-row>
    <el-table style="margin-top: 10px;" ref="singleTableRef" :data="tableData" :border="attributes.border"
      table-layout="fixed" :default-sort="{ prop: 'date', order: 'descending' }" :max-height="attributes.maxHeight"
      :height="attributes.height" @selection-change="handleSelectionChange">
      <el-table-column v-if="attributes.selection" fixed type="selection" width="50">
      </el-table-column>
      <el-table-column v-if="attributes.index" fixed type="index" width="50" align="center">
      </el-table-column>

      <template v-for="item in items" :key="item.prop">
        <!-- 自定义渲染文本 -->
        <el-table-column v-if="item.type === 'function'" :label="item.label ?? ''" :prop="item.prop ?? ''"
          :width="item.width ?? 50" :type="item.type ?? ''" :fixed="item.fixed ?? false" :align="item.align ?? 'center'">
          <template #default="scope">
            <div v-html="item.callback && item.callback(scope.row)"></div>
          </template>
        </el-table-column>
        <!-- 自定义操作 -->
        <el-table-column v-else-if="item.type === 'slot'" :label="item.label ?? ''" :prop="item.prop ?? ''"
          :width="item.width ?? 50" :type="item.type ?? ''" :fixed="item.fixed ?? false" :align="item.align ?? 'center'">
        <template #default="scope">
          <slot :name="item.slotName" :data="scope.row"></slot>
        </template>
      </el-table-column>
      <!-- 正常文本显示 -->
      <el-table-column v-else :label="item.label ?? ''" :prop="item.prop ?? ''" :width="item.width ?? 50"
        :type="item.type ?? ''" :fixed="item.fixed ?? false" :align="item.align ?? 'center'"></el-table-column>
    </template>
    <!-- <el-table-column v-if="attributes.rightOperation" fixed="right" label="操作" width="150" align="center">
        <template #default="scope">
          <el-button link type="primary" @click="edit(scope.row)">编辑</el-button>
          |
          <el-dropdown>
            <span class="el-dropdown-link" style="padding-top: 2px; color: #409eff">
              更多
              <el-icon class="el-icon--right" style="padding-top: 2px; color: #409eff">
                <arrow-down />
              </el-icon>
            </span>
            <template #dropdown>
              <el-dropdown-menu>
                      <el-dropdown-item>删除</el-dropdown-item>
                      <el-dropdown-item>审核</el-dropdown-item>
                      <el-dropdown-item>作废</el-dropdown-item>
              <el-dropdown-item disabled>打印</el-dropdown-item>
                      <el-dropdown-item divided>反关闭</el-dropdown-item>
                    </el-dropdown-menu>
                  </template>
                </el-dropdown>
              </template>    -->
      <!-- <template #default> -->
      <!-- <slot></slot> -->
      <!-- <el-button link type="primary" size="small">Detail</el-button>
          <el-button link type="primary" size="small">Edit</el-button> -->
      <!-- </template> -->
      <!-- </el-table-column> -->
    </el-table>
    <div class="demo-pagination-block">
      <!-- <div class="demonstration">All combined</div> -->
      <el-pagination v-model:current-page="pagination.currentPage" v-model:page-size="pagination.pageSize"
        :page-sizes="pagination.pageSizes" :layout="pagination.layout" :total="pagination.total" 
        @size-change="handleSizeChange"
        @current-change="handleCurrentChange"
        @prev-click = "handlePrevClickChange"
        @next-click="handleNextClickChange"
        />
      <!--  @size-change="handleSizeChange"
                                    @current-change="handleCurrentChange" -->
    </div>
  </div>
</template>

<script setup>
import { ref, reactive, onMounted } from 'vue'
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
    default: () => { }
  },
  pagination: {
    type: Object,
    default: () => { }
  }
})

const selectNum = ref(0)
const emit = defineEmits(['selectionChange', 'add', 'importData', 'exportData','sizeChange','currentChange','prevClick','nextClick'])
const exportDataList = ref([])
const handleSelectionChange = (val) => {
  // // console.log('---', val)
  selectNum.value = val.length
  exportDataList = val //不知道能不能赋值
  emit('selectionChange', val)
}
function add() {
  emit('add')
}
function importData() {
  emit('importData')
}
function exportData() {
  emit('exportData', exportDataList)
}
// const handleSizeChange = (val) => {
//   // // console.log(`${val} items per page`)
// }
// const handleCurrentChange = (val) => {
//   // // console.log(`current page: ${val}`)
// }

// 自定义列相关配置
const attrs = reactive({
  placement: 'left-start', //占位符在左边，也就是文字右对齐
  title: '自定义列', //标题
  width: 260, //弹出框的宽度
  trigger: 'click' //如何触发
})
const customStatus = reactive({
  items: []
})

function handleCustomChange(){}
function refToColumn() {
  prop.items.forEach((value, index) => {
    // // // console.log(index, '--', value)
    let item = reactive({})
    item.label = value.label
    // item.value = value.prop
    item.value = value.prop
    customStatus.items.push(item)
  })
  // // // console.log('123', status.items)
}

function handleSizeChange(value) {
  console.log("handleSizeChange", value)
  emit('sizeChange',value)
}

function handleCurrentChange(value) {
  console.log("handleCurrentChange", value)
  emit('currentChange', value)
}


function handlePrevClickChange(value) {
  console.log("handlePrevClickChange", value)
  emit('prevClick', value)
}


function handleNextClickChange(value) {
  console.log("handleNextClickChange", value)
  emit('nextClick', value)
}




onMounted(() => {
  refToColumn()
})

</script>

<style scoped>
.demo-pagination-block {
  float: right;
  margin: 10px 0;
}
</style>
