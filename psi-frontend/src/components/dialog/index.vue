<template>
  <div>
    <el-button @click="dialogVisible = true">弹出对话框</el-button>

    <psi-dialog :dialogVisible="true" />
  </div>
</template>

<script>
import { ref } from 'vue'
let dialogVisible = ref(false)
</script>

<style></style>
