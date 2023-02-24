<!--
 * @Author: li.ziwei
 * @Date: 2023-02-15 15:14:03
 * @LastEditTime: 2023-02-15 16:36:36
 * @LastEditors: li.ziwei
 * @Description: 
 * @FilePath: \psi-frontend\src\components\Home\HeadSideCom.vue
 * 可以输入预定的版权声明、个性签名、空行等
-->
<template>
   <div class="header-nav">
        <!--  <el-icon
         ><Search @click="handleSearch"/></el-icon> -->
        <SearchCom />
<div>
<!-- 改造的下拉菜单 -->
  <el-dropdown>
    <span class="el-dropdown-link">
      {{ userInfo }}
        <arrow-down />
    </span>
      <template #dropdown>
        <el-dropdown-menu class="newDrop">
          <el-dropdown-item>切换部门</el-dropdown-item>
          <el-dropdown-item>密码修改</el-dropdown-item>
          <el-dropdown-item>系统设置</el-dropdown-item>
          <el-dropdown-item>清理缓存</el-dropdown-item>
          <el-dropdown-item @click="handleClick">退出登录</el-dropdown-item>
        </el-dropdown-menu>
       </template>
  </el-dropdown>
      <span style="margin:0px 10px;left:10px;top:-4px;" >当前月度:2023-2</span>
    </div>
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
 .example-showcase .el-dropdown-link {
  cursor: pointer;
  color: var(--el-color-primary);
  display: flex;
  align-items: center;
}

.newDrop{
  width:150px;
  text-align:center;
  left:30px;
  font-size:14px;
}

/* .lang-select-dropdown {
  position: absolute;
  top: 30px;
  left: 0px;
  margin: 0px;
  padding: 0px;
  min-width: max-content;
  text-align: center;
} */
</style>

<script setup>
import { ref ,watch} from 'vue'
import { userStore } from '@/stores/user'
import SearchCom from '@/components/Home/SearchCom.vue'
import { ArrowDown } from '@element-plus/icons-vue'
import { useRouter } from 'vue-router'

// 获取router对象
const $router = useRouter()
const store = userStore()
// 用户信息提示
const userInfo = ref(
  '欢迎用户：' + (store.getUser === null ? '游客' : store.getUser.username)
)
/* let panelShow=ref(false)
function handleSearch() {
  panelShow.value=true
  }*/

function handleClick(){
  /* if(command === 'cancel'){
     //清除token
  // Cookie.remove('token')
  //跳到登录页面
  $router.push(/login)
  } */
 $router.push('/')
}
  
// 菜单数据
const menus = store.getMenus
</script>
