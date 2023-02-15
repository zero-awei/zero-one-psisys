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
            >
              <el-menu-item index="/home">
                <el-icon>
                  <icon-menu />
                </el-icon>
                <span>首页</span>
              </el-menu-item>
              <el-sub-menu
                v-for="item in menus"
                :key="item.id"
                :index="item.id + ''"
              >
                <template #title>
                  <el-icon>
                    <component :is="item.icon" />
                  </el-icon>
                  <span>{{ item.text }}</span>
                </template>
                <el-menu-item-group>
                  <el-menu-item
                    v-for="i in item.children"
                    :key="i.id"
                    :index="i.href"
                  >
                    <el-icon>
                      <component :is="i.icon" />
                    </el-icon>
                    {{ i.text }}
                  </el-menu-item>
                </el-menu-item-group>
              </el-sub-menu>
            </el-menu>
          </el-scrollbar>
        </div>
</template>

<script setup>
import { userStore } from '@/stores/user.js'
const store = userStore()
    // 菜单数据
const menus = store.getMenus
</script>