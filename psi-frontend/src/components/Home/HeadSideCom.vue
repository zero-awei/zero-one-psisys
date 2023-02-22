<template>
   <div class="header-nav">
         <el-icon
         ><Search @click="handleSearch"/></el-icon>
        <SearchCom :panelShow="panelShow"/>
        <!--  :panelShow.sync="panelShow" -->

<!-- <div v-show="show">
      <el-select :v-show="panelShow" v-model="value" filterable placeholder="搜索菜单">
        <el-option
          v-for="item in options"
          :key="item.value"
          :label="item.label"
          :value="item.value"
        />
      </el-select> -->
   </div >





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
}
      .el-icon{
        color:white;
        top:px;
        left:-50px;
      }

      span{
        z-index: 2;
        color: #fff;
        height: 59px;
        font-size: 14px;
      }
</style>

<script setup>
import { ref ,watch} from 'vue'
import { userStore } from '@/stores/user'
import SearchCom from '@/components/Home/SearchCom.vue'
const store = userStore()
// 用户信息提示
const userInfo = ref(
  '欢迎用户：' + (store.getUser === null ? '游客' : store.getUser.username)
)
let panelShow=ref(false)
function handleSearch() {
  panelShow.value=true
  // console.log(panelShow)
}

// 菜单数据
const menus = store.getMenus
</script>