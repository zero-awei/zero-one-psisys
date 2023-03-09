<template>
  <div>
    <el-dialog v-model="visible" :title="attrs.title" :width="attrs.width ?? '30%'" :before-close="handleClose"
      class="my-dialog">
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