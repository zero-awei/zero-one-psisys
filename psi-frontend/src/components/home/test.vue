<template>
  <!-- 侧边栏菜单  <el-scrollbar max-height="100vh">-->
  <div class="menu-wrap">
    <!-- <el-scrollbar> -->
    <el-menu default-active="2" class="el-menu-demo" active-text-color="#1890ff" text-color="#545c64"
      background-color="#fff" unique-opened router @select="menuSelect" :collapse="props.label" @open="handleOpen"
      @close="handleClose">
      <el-menu-item index="/home">
        <el-icon>
          <!-- <icon-menu /> -->
          <House />
        </el-icon>
        <span>首页</span>
      </el-menu-item>
      <el-sub-menu v-for="item in menus" :key="item.id" :index="item.id + ''" class="submenu">
        <!-- 一级菜单 item-->
        <!-- TODO 这里加div或template都会报错 -->
        <template #title>
          <el-icon>
            <component :is="item.icon" />
          </el-icon>
          <span>{{ item.text }}</span>
        </template>
        <!-- <div v-if="!item.children.children"> -->
        <!-- <el-menu-item-group> -->
        <!-- 二级菜单i -->
        <template v-for="iTwo in item.children">
          <!-- 如果没有三级菜单 -->
          <!-- <template v-if="!iTwo.children"> -->
          <el-menu-item v-if="!iTwo.children" :key="iTwo.id" :index="iTwo.href">
            <!-- <el-icon><component :is="iTwo.icon" /></el-icon> -->
            <span>{{ iTwo.text }}</span>
          </el-menu-item>
          <!-- </template> -->
          <!-- 如果有三级菜单 -->
          <template v-else-if="iTwo.children">
            <el-sub-menu :key="iTwo.id" :index="iTwo.id + ''">

              <template #title>
                <!-- <el-icon><component :is="iTwo.icon" /></el-icon> -->
                <span>{{ iTwo.text }}</span>
              </template>
              <!-- <el-menu-item-group v-for="iThree in iTwo.children"> -->
              <el-menu-item v-for="iThree in iTwo.children" :key="iThree.id" :index="iThree.href">
                <span>{{ iThree.text }}</span>
              </el-menu-item>
              <!-- </el-menu-item-group> -->
            </el-sub-menu>
          </template>
        </template>
        <!-- </el-menu-item-group> -->
        <!-- </div> -->
      </el-sub-menu>
    </el-menu>
    <!-- </el-scrollbar> -->
  </div>
</template>

<script setup>
import { userStore } from '@/stores/user.js'
import { ref } from 'vue'
const store = userStore()
// 菜单数据
const menus = store.getMenus

// document.getElementsByClassName('el - sub - menu__title').setAttribute('style', '');
// console.log('')
// console.log('00000000000', document.getElementsByClassName('el-sub-menu__title'))
const props = defineProps({
  label: {
    type: Boolean,
    default: () => []
  }
})
// // // console.log(props.label)

const handleOpen = (key, keyPath) => {
  // // console.log(key, keyPath)
}
const handleClose = (key, keyPath) => {
  // // console.log(key, keyPath)
}

const emit = defineEmits(['selectChange'])
function menuSelect(index, indexPath, item, routeResult) {
  // 
  // // // console.log('----------')
  // // // console.log('index', index)  //选中菜单项的 index
  // // // console.log('indexPath', indexPath)  //选中菜单项的 index path, 
  // // // console.log('item', item)  // 选中菜单项
  // // // console.log('routeResult', routeResult) // vue-router 的返回值（如果 router 为 true）
  emit('selectChange', item.route)
}
</script>

<style lang="scss" scoped>
.el-menu-demo {
  :deep(.el-menu-item) {
    height: 50px;
    // color: white;
    // background-color: #363637;
  }

  :deep(.el-menu-item-group__title) {
    display: none
  }
}

.el-menu-demo {
  :deep(.el-sub-menu__title) {
    height: 50px;
    color: white;
    background-color: #363637;
  }
}
</style>