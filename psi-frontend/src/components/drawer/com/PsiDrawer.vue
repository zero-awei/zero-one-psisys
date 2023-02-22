<!--
 * @Author: li.ziwei
 * @Date: 2023-02-15 15:14:57
 * @LastEditTime: 2023-02-22 22:07:07
 * @LastEditors: 160405103 1348313766@qq.com
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
    <el-drawer v-model="visible" :title="title" size="40%">
      <psi-drawer-collapse :items="items"></psi-drawer-collapse>
    </el-drawer>
  </div>
</template>

<script setup>
import PsiDrawerCollapse from './PsiDrawerCollapse.vue'
import { ref, computed } from 'vue'

const props = defineProps({
  modelValue: null,
  title: {
    type: String,
    default: () => {
      return ''
    }
  },
  items: Array //传给子组件的数据
})
const drawer = ref(false)

const emit = defineEmits(['update:modelValue'])
const visible = computed({
  get() {
    return props.modelValue
  },
  set(visible) {
    emit('update:modelValue', visible)
  }
})
</script>
