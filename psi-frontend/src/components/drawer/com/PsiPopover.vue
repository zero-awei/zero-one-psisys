<template>
  <div>
    <el-popover
      placement="left-start"
      title="Title"
      :width="300"
      trigger="click"
    >
      <!-- content是没有内容的时候填充的 -->

      <template #reference>
        <el-button class="m-2">Hover to activate</el-button>
      </template>
      <el-checkbox
        v-for="item in items"
        v-model="item.value"
        :label="item.label"
      ></el-checkbox>
    </el-popover>
  </div>
</template>

<script setup>
import { ref } from 'vue'
import { computed } from 'vue'
const checked1 = ref(true)
const props = defineProps({
  items: {
    type: Array,
    default: () => {
      return []
    }
  }
})
</script>
