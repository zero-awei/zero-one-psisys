<template>
   <div class="header-nav">
         <el-icon style="color:white;top=12px;left:-50px;"><Search /></el-icon>
            {{ userInfo }}
            <span style="margin:0px 8px;" >当前月度:2023-2</span>
    </div>
</template>

<style lang="scss" scoped>
.header-nav{
      padding: 20px;
      background-color: #1890ff;
      color: #f8f8f8;
      z-index: 2;
      color: #fff;
      height: 59px;
      font-size: 14px;
      span{
        z-index: 2;
        color: #fff;
        height: 59px;
        font-size: 14px;
      }
    }
</style>

<script setup>
import { ref } from 'vue'
import { userStore } from '@/stores/user'
const store = userStore()

// 用户信息提示
const userInfo = ref(
  '欢迎用户：' + (store.getUser === null ? '游客' : store.getUser.username)
)

// 菜单数据
const menus = store.getMenus
</script>