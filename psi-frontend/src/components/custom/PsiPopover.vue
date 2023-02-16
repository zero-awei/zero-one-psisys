<template>
  <div>
    <el-popover
      :items="items" 
      :placement="placement"
      :title="title"
      :width="width"
      :trigger="trigger"
    >
      <!-- content是没有内容的时候填充的 -->

      <template #reference>
        <el-button class="m-2">Hover to activate</el-button>
      </template>
      <el-checkbox
        v-for="item in items"
        :name="item.value"
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
  },
  title: String,
  placement: String,
  width: Number,
  trigger: String

})
</script>
