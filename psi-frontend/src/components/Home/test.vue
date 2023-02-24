<!--
 * @Author: li.ziwei
 * @Date: 2023-02-19 21:06:50
 * @LastEditTime: 2023-02-20 16:13:02
 * @LastEditors: li.ziwei
 * @Description: 
 * @FilePath: \psi-frontend\src\components\home\test.vue
 * 可以输入预定的版权声明、个性签名、空行等
--> 
<style scoped>
/* .menu-wrap{
  height:1080px;
  overflow:hidden;
} */

</style>


<template>
  <!-- 侧边栏菜单  <el-scrollbar max-height="100vh">-->
  <div class="menu-wrap">
    <el-scrollbar>
      <el-menu
        default-active="2"
        class="el-menu-vertical-demo"
        active-text-color="#1890ff"
        text-color="#545c64"
        background-color="#fff"
        unique-opened
        router
         :collapse="props.label"
          @open="handleOpen"
          @close="handleClose"
      >
        <el-menu-item index="/home">
          <el-icon>
            <icon-menu />
          </el-icon>
          <span>首页</span>
        </el-menu-item>
        <el-sub-menu v-for="item in menus" :key="item.id" :index="item.id + ''">
          <!-- 一级菜单 item-->
          <!-- TODO 这里加div或template都会报错 -->
          <template #title>
            <el-icon>
              <component :is="item.icon" />
            </el-icon>
            <span>{{ item.text }}</span>
          </template>
          <!-- <div v-if="!item.children.children"> -->
          <el-menu-item-group>
            <!-- 二级菜单i -->
            <template v-for="iTwo in item.children">
              <!-- 如果没有三级菜单 -->
              <template v-if="!iTwo.children">
                <el-menu-item :key="iTwo.id" :index="iTwo.href">
                  <el-icon>
                    <component :is="iTwo.icon" />
                  </el-icon>
                  <span>{{ iTwo.text }}</span>
                </el-menu-item>
              </template>
              <template v-else-if="iTwo.children">
                <el-sub-menu :key="item.id" :index="item.id + ''">
                  <template #title>
                    <el-icon>
                      <component :is="iTwo.icon" />
                    </el-icon>
                    <span>{{ iTwo.text }}</span>
                  </template>
                  <el-menu-item-group v-for="iThree in iTwo.children">
                    <el-menu-item :key="iThree.id" :index="iThree.href">
                      <el-icon>
                        <component :is="iThree.icon" />
                      </el-icon>
                      <span>{{ iThree.text }}</span>
                    </el-menu-item>
                  </el-menu-item-group>
                </el-sub-menu>
              </template>
            </template>
          </el-menu-item-group>
          <!-- </div> -->
        </el-sub-menu>
      </el-menu>
    </el-scrollbar>
  </div>
</template>

<script setup>
import { userStore } from '@/stores/user.js'
import { ref } from 'vue'
const store = userStore()
// 菜单数据
const menus = store.getMenus

const props = defineProps({
  label:{
    type:Boolean,
    default: () => []
}
})
// console.log(props.label)

const handleOpen = (key, keyPath) => {
  console.log(key, keyPath)
}
const handleClose = (key, keyPath) => {
  console.log(key, keyPath)
}
</script>
