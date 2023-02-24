
# 表单组件 psi-form

本质上是嵌套表单的组件

## 第一版

### 示例

```vue
<template>
  <div>
    <psi-form
      :items="items"
      :toggle-items="toggleItems"
      :formData="formData"
      @query="doQuery" 
      @reset="doReset"
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
  ],

  // 配置数据绑定的字段
  formData: {
    billNo: '',
    daterange: [],
    subject: '',
    supplierId: '',
  }
})
const { items, toggleItems, formData } = toRefs(state2)
// 查询
function doQuery(res) {
  // res 就是 formdata
  // // console.log('----接收search组件传递的参数', res)
}
// 重置
function doReset() {
  // res 就是 formdata
  // // console.log('----接收search组件传递的参数', res)
}
</script>
```

### 属性

| 属性名       | 说明                                                   | 类型                              | 默认 |
| ---------- | ------------------------------------------------------------- | --------------------------------- | ------- |
| formData     | 表单的响应式数据 | Object                        | Object       |
| items        |  展开域的标签及组件配置
| toggleItems                                        | 折叠域的标签及组件配置          | —       |
| buttonShow                                        | 是否显示查询、重置按钮          | Boolean       |  true
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
|   query   | 点击查询按钮触发的事件 | formData                        | 表单的响应式数据       |
|   reset   | 点击重置按钮触发的事件 |          ——               |        |
### type 提供标签

| 标签名       | 说明       |对应数据
| ---------- | -------------------------------------------------------------|------|
|   input  | 输入框 |      string
|   select        | 选择框 |string
|datePicker | 日期选择 |string
|daterange     | 日期选择(开始日期，结束日期)  | Array (Array[0]对应开始日期, Array[1]对应结束日期)

<!-- ### 第二版需要提供功能

1.表单项的配置
2.表单的总体配置
3.查询功能提供接口，只需配置url即可发出请求
4.查询插槽的自定义还是通过配置 -->
