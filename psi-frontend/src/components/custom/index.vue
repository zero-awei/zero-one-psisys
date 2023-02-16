<!--
 * @Author: li.ziwei
 * @Date: 2023-02-11 13:36:36
 * @LastEditTime: 2023-02-15 16:17:55
 * @LastEditors: li.ziwei
 * @Description: 
 * @FilePath: \psi-frontend\src\components\custom\index.vue
 * 可以输入预定的版权声明、个性签名、空行等
-->

<template>
  <div>
      <psi-popover 
      :items="status.items" 
      :placement="attrs.placement"
      :title="attrs.title"
      :width="attrs.width"
      :trigger="attrs.trigger"
      />
  </div>
</template>

<script setup>
import { reactive } from '@vue/reactivity'

  const attrs = reactive({
    placement: "left-start", //占位符在左边，也就是文字右对齐
    title: "自定义列", //标题
    width: "260", //弹出框的宽度
    trigger: "click", //如何触发
  })


  // 后端数据放到这里
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
</script>

<style>

</style>