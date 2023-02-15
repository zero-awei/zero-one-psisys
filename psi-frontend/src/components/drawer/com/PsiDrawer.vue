<!--
 * @Author: li.ziwei
 * @Date: 2023-02-15 15:14:57
 * @LastEditTime: 2023-02-15 16:22:30
 * @LastEditors: li.ziwei
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
    <el-drawer v-model="drawer" :title="title" size="40%">
      <psi-drawer-collapse></psi-drawer-collapse>
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
  }
})
const drawer = ref(false)
</script>
