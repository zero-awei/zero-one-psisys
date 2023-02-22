<!--
 * @Author: li.ziwei
 * @Date: 2023-02-15 15:14:57
 * @LastEditTime: 2023-02-22 22:49:24
 * @LastEditors: Kyle5 nnkyle@163.com
 * @Description: 
 * @FilePath: \psi-frontend\src\components\drawer\com\PsiDrawer.vue
 * 可以输入预定的版权声明、个性签名、空行等
-->
<!--
 * @Author: li.ziwei
 * @Date: 2023-02-15 15:14:57
 * @LastEditTime: 2023-02-15 15:47:04
 * @LastEditors: li.ziwei
 * @Description: 
 * @FilePath: \psi-frontend\src\components\drawer\com\Drawer.vue
 * 可以输入预定的版权声明、个性签名、空行等
-->
<template>
  <div>
    <el-drawer v-model="drawer" size="40%">
      <psi-drawer-collapse :items="items" :title="title"></psi-drawer-collapse>
    </el-drawer>

    <el-button
      type="primary"
      style="margin-left: 16px"
      @click="drawer = true"
      link
    >
      open
    </el-button>
  </div>
</template>

<script setup>
import PsiDrawerCollapse from './PsiDrawerCollapse.vue'
import { ref } from 'vue'

const props = defineProps({
  title: {
    type: String,
    default: () => {
      return ''
    }
  },
  items: Array //传给子组件的数据
})
const drawer = ref(false)

</script>