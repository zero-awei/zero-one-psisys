# psi 进销存组件库

## 1.search查询组件

本质上是嵌套表单的组件

### 第一版

#### 示例 (演示路径 /component/search)

```
<template>
  <div>
    <psi-search
      :items="items"
      :toggle-items="toggleItems"
      :formData="formData"
      @search="search"
    />
  </div>
</template>

<script setup>
import { reactive, toRefs } from 'vue'
const state = reactive({
  // 查询表单展开项的配置
  items: [
    {
      type: 'input',
      label: '单据编号',
      prop: 'billNo',
      placeholder: '请输入'
    },
    {
      type: 'daterange',
      label: '单据日期',
      prop: 'daterange',
      startPlaceholder: '开始日期',
      endPlaceholder: '结束日期'
    }
  ],
  // 查询表单折叠项的配置
  toggleItems: [
    {
      type: 'input',
      label: '单据主题',
      prop: 'subject',
      placeholder: '请输入'
    },
    {
      type: 'select',
      label: '供应商',
      prop: 'supplierId',
      placeholder: '请选择',
      options: [
        {
          label: '供应商1',
          value: 0
        },
        {
          label: '供应商2',
          value: 1
        },
        {
          label: '供应商3',
          value: 2
        }
      ]
    },
    {
      type: 'select',
      label: '单据阶段',
      prop: 'billStage',
      placeholder: '请选择',
      options: [
        {
          label: '阶段1',
          value: 0
        },
        {
          label: '阶段2',
          value: 1
        },
        {
          label: '阶段3',
          value: 2
        }
      ]
    },
    {
      type: 'select',
      label: '已生效',
      prop: 'isEffective',
      placeholder: '请选择',
      options: [
        {
          label: '是',
          value: 0
        },
        {
          label: '否',
          value: 1
        }
      ]
    },
    {
      type: 'select',
      label: '已关闭',
      prop: 'isClosed',
      placeholder: '请选择',
      options: [
        {
          label: '是',
          value: 0
        },
        {
          label: '否',
          value: 1
        }
      ]
    },
    {
      type: 'select',
      label: '已作废',
      prop: 'isVoided',
      placeholder: '请选择',
      options: [
        {
          label: '是',
          value: 0
        },
        {
          label: '否',
          value: 1
        }
      ]
    }
  ],

  // 配置数据绑定的字段
  formData: {
    billNo: '',
    daterange: [],
    subject: '',
    supplierId: '',
    billStage: '',
    isEffective: '',
    isClosed: '',
    isVoided: ''
  }
})
const { items, toggleItems, formData } = toRefs(state2)

function search(res) {
  // res 就是 formdata
  console.log('----接收search组件传递的参数', res)
}
</script>
```

### 属性

| 属性名       | 说明                                                   | 类型                              | 默认 |
| ---------- | ------------------------------------------------------------- | --------------------------------- | ------- |
| formData     | 表单的响应式数据 | Object                        | Object       |
| items        |  展开域的标签及组件配置
| toggleItems                                        | 折叠域的标签及组件配置          | —       |

### items/toggleItems 属性

| 属性名       | 说明                                                   | 类型                              | 默认 |
| ---------- | ------------------------------------------------------------- | --------------------------------- | ------- |
| type     | 表单项对应的标签名 | Object                        | ——       |
| label        |  表单项名 |string|——
| prop                                        | model 的键名          | string       |——
| placeholder                                        |  占位文本          |string       |——

### 事件

| 事件名       | 说明                                                   | 回调参数       | 参数说明       |
| ---------- | ------------------------------------------------------------- | --------------------------------- | -----|
|   search   | 点击查询按钮触发的事件 | formData                        | 表单的响应式数据       |

### type 提供标签

| 标签名       | 说明       |对应数据
| ---------- | -------------------------------------------------------------|------|
|   input  | 输入框 |      string
|   select        | 选择框 |string
|datePicker | 日期选择 |string
|daterange     | 日期选择(开始日期，结束日期)  | Array (Array[0]对应开始日期, Array[1]对应结束日期)

### 第二版需要提供功能

1.表单项的配置
2.表单的总体配置
3.查询功能提供接口，只需配置url即可发出请求
4.查询插槽的自定义还是通过配置

## 2.table 表格组件

### 第一版(尚未完善)

#### 示例 (演示路径 /component/table)

```
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

### 属性

| 属性名       | 说明                                                   | 类型                              | 默认 |
| ---------- | ------------------------------------------------------------- | --------------------------------- | ------- |
| tableData     | 表格数据| Object                        | ——       |
| items        |  表格列的标题及相关配置 |Object|——
| pagination        |  分页相关配置|Object|——

### items 属性

| 属性名       | 说明                                                   | 类型                              | 默认 |
| ---------- | ------------------------------------------------------------- | --------------------------------- | ------- |
| label     | 表格列名 | string                        | ——
| prop      | model 的键名          | string       |——
| width     |  表格列宽度          |string       |50
| align     |  表格列对齐方式(left / center / right)          |string       |left
| fixed     |  表格列固定方式          |string(left/right)       |——

### [pagination分页相关配置](https://element-plus.gitee.io/zh-CN/component/pagination.html)

| 属性名       | 说明                                                   | 类型                              | 默认 |
| ---------- | ------------------------------------------------------------- | --------------------------------- | ------- |
| currentPage     | 当前页 | number                        | ——
| pageSize      | 每页数据量          | string       |——
| pageSizes     |  可选择的每页展示量          |Array       |——
| total     |  数据总量          |number       |——
| layout     |  表示需要显示的内容          |string       | prev, pager, next, jumper, ->, total

### 第二版需要提供功能

1.表单项的配置
2.表单的总体配置
3.分页功能交互
4.共选择了xx项
