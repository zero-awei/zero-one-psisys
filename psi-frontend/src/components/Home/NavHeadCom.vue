<template>
  <el-tabs
    v-model="editableTabsValue"
    type="card"
    editable
    class="demo-tabs"
    @edit="handleTabsEdit"
  >
    <el-tab-pane
      v-for="item in editableTabs"
      :key="item.text"
      :label="item.text"
      :name="item.text"
    >
    </el-tab-pane>
  </el-tabs> 
 </template> 

<script setup>
import { ref } from 'vue'
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
temp = getList(datalist);

let tabIndex = 1
const editableTabsValue = ref('1')
// console.log(editableTabsValue)
const editableTabs = ref(temp)
// console.log(editableTabs)

const handleTabsEdit = (targetName, action) => {
  if (action === 'add') {
    const newTabName = `${++tabIndex}`
    editableTabs.value.push({
      title: 'New Tab',
      name: newTabName,
      content: 'New Tab content',
    })
    editableTabsValue.value = newTabName
  } else if (action === 'remove') {
    const tabs = editableTabs.value
    let activeName = editableTabsValue.value
    if (activeName === targetName) {
      tabs.forEach((tab, index) => {
        if (tab.name === targetName) {
          const nextTab = tabs[index + 1] || tabs[index - 1]
          if (nextTab) {
            activeName = nextTab.name
          }
        }
      })
    }

    editableTabsValue.value = activeName
    editableTabs.value = tabs.filter((tab) => tab.name !== targetName)
  }
}
</script>

<style scoped>
.el-tabs {
    --el-tabs-header-height: 52px;
    background-color:white;
}
.el-tabs__content{
  display:none;
}
</style>