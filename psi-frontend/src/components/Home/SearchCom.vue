<!--
 * @Author: 160405103 1348313766@qq.com
 * @Date: 2023-02-24 22:06:10
 * @LastEditors: 160405103 1348313766@qq.com
 * @LastEditTime: 2023-02-24 22:07:49
 * @FilePath: \psi-frontend\src\components\Home\SearchCom.vue
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
<template>
  <el-select v-model="value" filterable placeholder="搜索菜单">
    <el-option v-for="item in temp" :key="item.text" :label="item.text" :value="item.text"
      @click="handleJump(item.href)" />
  </el-select>
</template>

<script setup>
/* import { ref} from 'vue'
const value = ref('')
const props = defineProps({
  panelShow:{
    type:Boolean,
    default: () => false
}
})
// // console.log(props.panelShow) */
// let show = true
/* const panelShow = defineProps({
  panelShow
})
this.$emit('update:panelShow', false) */
import { userStore } from '@/stores/user.js'
import { useRouter } from 'vue-router'

// 获取router对象
const $router = useRouter()
const store = userStore()
// 菜单数据
const menus1 = store.getMenus
let datalist = [...menus1]

let temp = [];
function getList(tree) {
  for (let item in tree) {
    if (tree[item].children) {
      getList(tree[item].children)
    } else {
      temp.push(tree[item])
    }
  }
  return temp;
}
// // // console.log(getList(datalist));
temp = getList(datalist);
// // // console.log(temp);

function handleJump(el) {
  $router.push(el)
  // // // console.log(el)
}
</script>

<style lang="scss" scoped>
.el-select {
  display: inline;
  width: 180px;
  height: 30px;
  left: -280px;
}
</style>