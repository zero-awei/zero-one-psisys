#table 表格组件

## 第一版(尚未完善)

### 示例 (演示路径 /component/table)

```javascript
<template>
  <div class="main">
    <psi-table
      :items="items"
      :tableData="tableData"
      :attributes="attributes"
      :pagination="pagination"
    />
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
    border: true
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
</script>

<style></style>
```

## 属性

| 属性名       | 说明                                                   | 类型                              | 默认 |
| ---------- | ------------------------------------------------------------- | --------------------------------- | ------- |
| tableData     | 表格数据| Object                        | ——       |
| items        |  表格列的标题及相关配置 |Object|——
| pagination        |  分页相关配置|Object|——

## items 属性

| 属性名       | 说明                                                   | 类型                              | 默认 |
| ---------- | ------------------------------------------------------------- | --------------------------------- | ------- |
| label     | 表格列名 | string                        | ——
| prop      | model 的键名          | string       |——
| width     |  表格列宽度          |string       |50
| align     |  表格列对齐方式(left / center / right)          |string       |left
| fixed     |  表格列固定方式          |string(left/right)       |——

## [pagination分页相关配置](https://element-plus.gitee.io/zh-CN/component/pagination.html)

| 属性名       | 说明                                                   | 类型                              | 默认 |
| ---------- | ------------------------------------------------------------- | --------------------------------- | ------- |
| currentPage     | 当前页 | number                        | ——
| pageSize      | 每页数据量          | string       |——
| pageSizes     |  可选择的每页展示量          |Array       |——
| total     |  数据总量          |number       |——
| layout     |  表示需要显示的内容          |string       | prev, pager, next, jumper, ->, total

## 第二版需要提供功能

1.表单项的配置
2.表单的总体配置
3.分页功能交互
4.共选择了xx项
