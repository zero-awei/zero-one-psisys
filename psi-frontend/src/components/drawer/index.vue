<!--
 * @Author: li.ziwei
 * @Date: 2023-02-11 13:36:36
 * @LastEditTime: 2023-02-15 16:17:55
 * @LastEditors: li.ziwei
 * @Description: 
 * @FilePath: \psi-frontend\src\components\drawer\index.vue
 * 可以输入预定的版权声明、个性签名、空行等
-->
<template>
  <div>
    <psi-drawer :title="attrs.title" />
    <psi-popover :items="items" />
  </div>
</template>

<!-- 这里我使用组合式api进行编写 -->
<script setup>
import { reactive, toRefs } from '@vue/reactivity'
const attrs = reactive({
  title: '抽屉标题'
})

const status = reactive({
  items: [
    {
      label: 'option1',
      value: 1
    },
    {
      label: 'option2',
      value: 2
    },
    {
      label: 'option3',
      value: 3
    },
    {
      label: 'option4',
      value: 4
    },
    {
      label: 'option5',
      value: 5
    }
  ]
})
const { items } = toRefs(status)
</script>

<style></style>
