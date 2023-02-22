<!--
 * @Author: li.ziwei
 * @Date: 2023-02-14 15:04:49
 * @LastEditTime: 2023-02-14 16:11:02
 * @LastEditors: li.ziwei
 * @Description: 
 * @FilePath: \psi-frontend\src\components\dialog\PsiDialog.vue
 * 可以输入预定的版权声明、个性签名、空行等
-->
<template>
  <el-dialog :visible="dialogVisible" width="30%" />
</template>

<script setup>
const props = defineProps({
  dialogVisible: {
    type: Boolean,
    default: () => false
  }
})
</script>

<style></style>
