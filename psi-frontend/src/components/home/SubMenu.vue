
<template >
  <div class="box fx_1">
    <template v-for="(item, index) in subMenuList">
      <el-sub-menu v-if="item.children && item.children.length > 0" :key="index + 'el-submenu'" :index="item.href">
        <template slot="title">
          <el-icon>
            <!-- <Fold /> -->
            <component :is="item.icon"></component>
          </el-icon>
          <span>{{ item.text }}</span>
        </template>
        <SubMenu :subMenuList="item.children" />
      </el-sub-menu>
      <el-menu-item v-else :key="index + item.href" :index="item.href">
        <template slot="title">
          <span>{{ item.text }}</span>
        </template>
      </el-menu-item>
    </template>
  </div>
</template>
         
<script setup>

const props = defineProps({
  subMenuList: {
    //接收到的菜单信息
    type: Array,
    default: [],
  },
})
</script>
<style scoped></style>
