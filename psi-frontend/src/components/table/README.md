#table 表格组件

## 第一版(尚未完善)

### 示例 (演示路径 /component/table)

```vue
<template>
  <div class="main">
    <psi-table
      :items="items"
      :tableData="tableData"
      :attributes="attributes"
      :pagination="pagination"
      @selectionChange="selectionChange" 
      @add="handleAdd"
      @importData="handleImport"
      @exportData="handleExport"
      @sizeChange="handleSizeChange"
      @currentChange="handleCurrentChange" @prevClick="handlePrevClickChange" @nextClick="handleNextClickChange"
    >

    </psi-table>
  </div>
</template>

<script setup>
import { reactive, toRefs } from 'vue'
const status = reactive({
  // table列配置
  items: [
    {
      label: 'Name',
      prop: 'name',
      width: '120',
      align: 'center',
      type: 'function',
      // ES6 的 Template Strings 模版字符串
      callback: (data) => {
        return `<span style="color:#409eff"> ${data.name}</span>`
      }
    },
    {
      type: 'text',
      label: 'Date',
      prop: 'date',
      width: '120'
    },
    {
      type: 'text',
      label: 'City',
      prop: 'city',
      width: '120'
    },
    {
      type: 'text',
      label: 'Address',
      prop: 'address',
      width: '600'
    },
    {
      type: 'text',
      label: 'Zip',
      prop: 'zip',
      width: '120'
    },
    {
      type: 'text',
      label: 'Tag',
      prop: 'tag',
      width: '120'
    },
    {
      type: 'slot',
      label: '操作',
      prop: 'operation',
      slotName: 'operation'
    }
  ],
  // table 数据
  tableData: [
    {
      date: '2016-05-03',
      name: 'Tom1',
      state: 'California',
      city: 'Los Angeles',
      address: 'No. 189, Grove St, Los Angeles',
      zip: 'CA 90036',
      tag: 'Home'
    },
    {
      date: '2016-05-02',
      name: 'Tom2',
      state: 'California',
      city: 'Los Angeles',
      address: 'No. 189, Grove St, Los Angeles',
      zip: 'CA 90036',
      tag: 'Office'
    },
    {
      date: '2016-05-04',
      name: 'Tom3',
      state: 'California',
      city: 'Los Angeles',
      address: 'No. 189, Grove St, Los Angeles',
      zip: 'CA 90036',
      tag: 'Home'
    },
    {
      date: '2016-05-01',
      name: 'Tom4',
      state: 'California',
      city: 'Los Angeles',
      address: 'No. 189, Grove St, Los Angeles',
      zip: 'CA 90036',
      tag: 'Office'
    }
  ],
  // table 总体配置
  attributes: {
    selection: true, //是否多选框
    index: true, // 索引
    border: true //表格边框
    maxHeight: '400', // 表格最大高度
    height: '400',    //表格高度
    headOperation: ['add', 'select']
  }
})

const { items, tableData, attributes } = toRefs(status)

// 分页相关配置
const pagination = reactive({
  currentPage: 2, // 当前页
  pageSize: 100, // 每页数据量
  pageSizes: [100, 200, 300, 400], // 可选择的每页展示量
  total: 400, //数据总量
  layout: 'total, sizes, prev, pager, next, jumper'
})

// 点击新增按钮出触发方法
function handleAdd(){

}

// 点击导入按钮触发方法
function handleImport(){

}
// 点击导出按钮触发方法
function handleExport(){

}
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
function handleNextClickChange(value) {
  console.log("handleNextClickChange", value)
}

</script>

<style></style>
```

## psi-table 属性

| 属性名       | 说明                                                   | 类型                              | 默认 |
| ---------- | ------------------------------------------------------------- | --------------------------------- | ------- |
| tableData     | 表格数据| Object                        | ——       |
| items        |  表格列的标题及相关配置 |Object|——
| attributes        |  表格全局配置|Object|——
| pagination        |  分页相关配置|Object|——

## tableData 属性
tableData 表格数据中的对象属性需要和items属性中的prop对应

## items 属性

| 属性名       | 说明                                                   | 类型                              | 默认 |
| ---------- | ------------------------------------------------------------- | --------------------------------- | ------- |
| type     |  组件类型          |string       |——
| label     | 表格列名 | string                        | ——
| prop      | model 的键名          | string       |——
| width     |  表格列宽度          |string       |50
| align     |  表格列对齐方式(left / center / right)          |string       |left
| fixed     |  表格列固定方式          |string(left/right)       |——


## items 中的属性type

| 可选       | 说明                                                   | 类型                              | 默认 |
| ---------- | ------------------------------------------------------------- | --------------------------------- | ------- |
| text     | 文本显示 | ——                        | ——
| function      | 可实现自定义渲染文本          | ——       |——
| slot     |  可自定义插槽          |Array       |——

## attributes 配置

| 属性名       | 说明                                                   | 类型                              | 默认 |
| ---------- | ------------------------------------------------------------- | --------------------------------- | ------- |
| selection     | 是否多选 | number                        | false
| index      | 是否显示索引          | string       |false
| border     |  是否有边框          |Boolean       |false
| maxHeight     |  表格最大高度          |string       |——
| height     | 表格高度         |string       | ——
| headOperation     |  表格头部操作行['add','importData','exportData','select']          |  Array     | ——

headOperation:['add','importData','exportData','select'] 表示有新增按钮、导入导出按钮、共选择xxx项

## 插槽

| 插槽名       | 说明                                                   | 类型                              | 默认 |
| ---------- | ------------------------------------------------------------- | --------------------------------- | ------- |
| batchOperation     | 批量操作(会渲染在头部操作行) | ——                        | ——
| item.type=slot      | 声明当前列是个插槽          | ——       |——
| item.slotName     |  自定义插槽名          |——       |——

自定义的插槽会按照 item 的列顺序依次渲染


## [pagination分页相关配置](https://element-plus.gitee.io/zh-CN/component/pagination.html)

| 属性名       | 说明                                                   | 类型                              | 默认 |
| ---------- | ------------------------------------------------------------- | --------------------------------- | ------- |
| currentPage     | 当前页 | number                        | ——
| pageSize      | 每页数据量          | number       |——
| pageSizes     |  可选择的每页展示量          |Array       |——
| total     |  数据总量          |number       |——
| layout     |  表示需要显示的内容          |string       | prev, pager, next, jumper, ->, total

## pagination 事件
| 事件名       | 说明                                                   |          生效                    | 默认 |
| ---------- | ------------------------------------------------------------- | --------------------------------- | ------- |
| sizeChange     | page-size 改变时触发 | ——                       | ——
| currentChange      |  current-page 改变时触发          | ——       |——
| prevClick    |   用户点击上一页按钮改变当前页时触发          |——        |——
| nextClick    |  用户点击下一页按钮改变当前页时触发          |——      |——


## psi-table 事件

| 事件名       | 说明                                                   |          生效                    | 默认 |
| ---------- | ------------------------------------------------------------- | --------------------------------- | ------- |
| selectionChange     | 多选框勾选时触发 | attributes 配置属性selection:true                       | ——
| add      | 点击新增按钮触发          | attributes 配置属性headOperation:['add']       |——
| importData    |  点击导入数据按钮触发          |attributes 配置属性headOperation:['importData']        |——
| exportData    |  点击导出数据按钮触发          |attributes 配置属性headOperation:['exportData']       |——

自定义的插槽会按照 item 的列顺序依次渲染
## 第二版需要提供功能

1.分页功能交互
