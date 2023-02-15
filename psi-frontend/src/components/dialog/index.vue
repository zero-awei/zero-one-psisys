<template>
  <div>
    <el-button @click="dialogVisible = true">弹出对话框</el-button>

    <psi-dialog v-model="dialogVisible" :attrs="attrs">
      <template #default>
        <span>This is a message</span>
      </template>
    </psi-dialog>
  </div>
</template>

<script setup>
import { ref, reactive, toRefs } from 'vue'

let dialogVisible = ref(false)
const state = reactive({
  attrs: {
    title: '单据',
    width: '80%',
    fullscreen: true
  }
})
const { attrs } = toRefs(state)
// const dialogref = ref()
// console.log('----', dialogref)
</script>

<style></style>
