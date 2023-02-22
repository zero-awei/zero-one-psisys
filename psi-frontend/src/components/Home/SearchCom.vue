<template>
   <!-- <div v-show="show"> -->
      <el-select :v-show="props.panelShow" v-model="value" filterable placeholder="搜索菜单">
        <el-option
          v-for="item in options"
          :key="item.value"
          :label="item.label"
          :value="item.value"
        />
      </el-select>
   <!-- </div > -->
</template>

<script setup>
import { ref} from 'vue'
const value = ref('')
const props = defineProps({
  panelShow:{
    type:Boolean,
    default: () => false
}
})
// let show = true
/* const panelShow = defineProps({
  panelShow
})
this.$emit('update:panelShow', false) */

const options = [
  {
    value: 'Option1',
    label: 'Option1',
  },
  {
    value: 'Option2',
    label: 'Option2',
  },
  {
    value: 'Option3',
    label: 'Option3',
  },
  {
    value: 'Option4',
    label: 'Option4',
  },
  {
    value: 'Option5',
    label: 'Option5',
  },
]
</script>
