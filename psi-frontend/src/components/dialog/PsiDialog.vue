<template>
  <div>
    <el-dialog v-model="visible" :title="attrs.title" :width="attrs.width ?? '30%'" :before-close="handleClose"
      class="my-dialog">
      <!-- :fullscreen="attrs.fullscreen"
<template #header="{ close, titleId, titleClass }">
      <div class="my-header">
        <h4 :id="titleId" :class="titleClass">{{ attrs.title }}</h4>
        <div class="icon" style="margin-right: 20px">
          <el-button circle @click="attrs.fullscreen = true">
            <el-icon><FullScreen /></el-icon>
          </el-button>
          <el-button circle @click="close">
            <el-icon><Close /></el-icon>
          </el-button>
           <el-icon><CircleCloseFilled /></el-icon>
        </div>

        <el-button type="danger" @click="close">
          <el-icon class="el-icon--left" ><CircleCloseFilled /></el-icon>
          Close
        </el-button>
      </div>
    </template> -->
      <!-- :before-close="handleClose" -->
      <slot></slot>
      <template #footer>
        <span class="dialog-footer">
          <el-button v-if="attrs.determine" @click="determine">确定</el-button>
          <el-button @click="visible = false">取消</el-button>
          <el-button type="primary" @click="visible = false"> 关闭 </el-button>
        </span>
      </template>
    </el-dialog>
  </div>
</template>

<script setup>
import { ref } from 'vue'
import { computed } from 'vue'

// const props = defineProps(['modelValue'])
const props = defineProps({
  modelValue: null,
  attrs: {
    type: Object,
    default: () => { }
  },
})
const emit = defineEmits(['update:modelValue', 'confim'])
const visible = computed({
  get() {
    return props.modelValue
  },
  set(visible) {
    emit('update:modelValue', visible)
  }
})

const handleClose = (done) => {
  ElMessageBox.confirm('确定关闭对话框?')
    .then(() => {
      done()
    })
    .catch(() => {
      // catch error
    })
}
function determine() {
  emit('determine')
}
</script>

<style scoped>
:deep(.el-dialog__body) {
  border-bottom: 1px solid rgba(60, 60, 60, 0.12);
  border-top: 1px solid rgba(60, 60, 60, 0.12);
}
</style>