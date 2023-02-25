<template>
  <div>
    <el-button @click="handle"></el-button>

  </div>
</template>

<script setup>
import { handleAddMenu } from './api/menu'

function handle() {
  // 改的是下面这行
  handleAddMenu()
}


</script>

<style></style>