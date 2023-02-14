<!--
 * @Author: li.ziwei
 * @Date: 2023-02-11 13:36:36
 * @LastEditTime: 2023-02-11 14:13:09
 * @LastEditors: li.ziwei
 * @Description: 
 * @FilePath: \psi-frontend\src\components\drawer\index.vue
 * 可以输入预定的版权声明、个性签名、空行等
-->
<template>
  <div>
    <Drawer/>
    <Popover/>
  </div>
</template>

<!-- 这里我使用组合式api进行编写 -->
<script setup>
import Drawer from './components/Drawer.vue'
import Popover from './components/Popover.vue'

</script>

<style>

</style>