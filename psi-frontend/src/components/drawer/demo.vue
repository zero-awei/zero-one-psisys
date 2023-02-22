<!--
 * @Author: li.ziwei
 * @Date: 2023-02-11 13:36:36
 * @LastEditTime: 2023-02-22 22:07:25
 * @LastEditors: 160405103 1348313766@qq.com
 * @Description: 
 * @FilePath: \psi-frontend\src\components\drawer\index.vue
 * 可以输入预定的版权声明、个性签名、空行等
-->
<template>
  <div>
    <el-button type="primary" @click="drawerVisible = true">打开</el-button>
    <psi-drawer v-model="drawerVisible" :title="attrs.title" :items="items.arr" />
  </div>
</template>

<!-- 这里我使用组合式api进行编写 -->
<script setup>
import { reactive, toRefs } from '@vue/reactivity'
const attrs = reactive({
  title: '抽屉标题'
})

const items = reactive({
  // 后台接收的数据放到这里，就可以传值了
  arr: ["开票信息", "办款资料", "收件信息"]
})

let drawerVisible = ref(false)
// const { items } = toRefs(status)
</script>

<style></style>
