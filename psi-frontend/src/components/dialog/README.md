# psi-dialog 对话框组件

## 第一版

### 示例 

```vue
<template>
  <div class="main">
    <el-button @click="dialogVisible = true">弹出对话框</el-button>
    <psi-dialog v-model="dialogVisible" :attrs="attrs" @determine="confirm">
      <!-- 默认插槽，自家插入表单，表格或其他组件-->
    </psi-dialog>
  </div>
</template>

<script setup>
import { ref,reactive, toRefs } from 'vue'
let dialogVisible = ref(false)
const state = reactive({
  attrs: {
    title: '单据',
    width: '80%',
    determine:true
  }
})
const { attrs } = toRefs(state)
// 点击确定触发，发送请求
function confirm(){
}
</script>

<style scoped></style>
```

## psi-dialog 属性

| 属性名       | 说明                                                   | 类型                              | 默认 |
| ---------- | ------------------------------------------------------------- | --------------------------------- | ------- |
| attrs     | 对话框属性| Object                        | ——       |

组件需要 v-model 绑定一个 Boolean 值
## attrs 属性

| 属性名       | 说明                                                   | 类型                              | 默认 |
| ---------- | ------------------------------------------------------------- | --------------------------------- | ------- |
| title     |  标题          |string       |——
| width     | 宽度 | string                        | ——
| determine     | 对话框的确定按钮是否生效 | Boolean                        | false


## 事件

| 事件名       | 说明                                                   | 类型                              | 默认 |
| ---------- | ------------------------------------------------------------- | --------------------------------- | ------- |
| determine     |  点击弹出框的确定按钮触发该事件          |——       |——
