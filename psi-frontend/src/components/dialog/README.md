# psi-dialog 对话框组件

## 第一版

### 示例 (演示路径 /component/dialog)

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
    width: '80%'
  }
})
const { attrs } = toRefs(state)
// 点击确定触发，发送请求
function confirm(){
}
</script>

<style></style>
```

## 属性

| 属性名       | 说明                                                   | 类型                              | 默认 |
| ---------- | ------------------------------------------------------------- | --------------------------------- | ------- |
| attrs     | 对话框属性| Object                        | ——       |

## attrs 属性

| 属性名       | 说明                                                   | 类型                              | 默认 |
| ---------- | ------------------------------------------------------------- | --------------------------------- | ------- |
| title     |  标题          |string       |——
| width     | 宽度 | string                        | ——

