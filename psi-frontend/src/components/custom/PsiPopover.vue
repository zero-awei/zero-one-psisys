<!--
 * @Author: li.ziwei
 * @Date: 2023-02-20 19:55:14
 * @LastEditTime: 2023-02-24 09:59:47
 * @LastEditors: 160405103 1348313766@qq.com
 * @Description: 
 * @FilePath: \psi-frontend\src\components\custom\PsiPopover.vue
 * 可以输入预定的版权声明、个性签名、空行等
-->
<template>
  <div>
    <el-popover :items="items" :placement="placement" :title="title" :width="width" :trigger="trigger">
      <!-- content是没有内容的时候填充的 -->

      <template #reference>
        <el-button class="m-2">{{ props.title }}</el-button>
      </template>
      <el-checkbox-group v-model="checkList" @change="handleCheckedChange">
        <el-row>
          <el-col>
            <el-checkbox v-for="item in items" :name="item.value" :label="item.label"></el-checkbox>
          </el-col>
        </el-row>
      </el-checkbox-group>
    </el-popover>
  </div>
</template>

<script setup>
import { ref, reactive, toRefs, nextTick  } from 'vue'
import { computed, onMounted } from 'vue'

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
//第一种方式：在created生命周期完成，没有效果
const arr=[]
// // console.log('1111111111')
// // console.log(props.items)
props.items.forEach((value, index) => {
  // // console.log(value.label)
  arr.push(value.label)
  // checkList.value.push(value.label)
})
const checkList = ref(arr)
// const { items } = toRefs(props)
// const checkList = ref([])
// // // console.log(items)
// // // console.log(props.items)
// props.items.forEach((value, index) => {
//   // // console.log(value.label)
//   checkList.value.push(value.label)
// })
// items.forEach((value, index) => {
//   checkList.value.push(value.label)
// })
// const checkList = computed({
//   get:()=>{
//     // 写法有待改进
//     const arr=[]
//     props.items.forEach((value, index) => {
//       arr.push(value.label)
//     })
//   }
// })
// 2.计算属性 会导致另外一个bug
// const checkList = computed(() => {

//       const arr=[]
//       props.items.forEach((value, index) => {
//         // // console.log('222222222')
//         arr.push(value.label)
//       })
//       return arr
// })
// 3.nextTick和onmounted配合使用，没有效果
// async function refToLabel() {
//   // // console.log("挂载33333")
//   props.items.forEach((value, index) => {
//     // // console.log(value.label)
//     checkList.value.push(value.label)
//   })
//   await nextTick()
// }
// onMounted(() => {
//   // // console.log("挂载2222222")
  
//   refToLabel()
// })
const emit = defineEmits(['change'])
function handleCheckedChange(value) {
  emit('change', value)
}
</script>
