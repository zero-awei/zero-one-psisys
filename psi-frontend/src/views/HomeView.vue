<template>
  <div class="layout-container">
    <el-container>

      <!-- 左侧侧边栏 -->
      <el-aside >
       <div class="logo-box" style="background-color:#1890ff">
          <el-image style="width:28px; height:32px;" :src="url"></el-image>
          <span class="manage-title" v-show="collapse">进销存</span>
        </div>
        <!-- 使用自定义侧边菜单组件 -->
        <!-- <AsideCom /> -->
        <test />
      </el-aside>

     <!-- 右侧内容 -->
      <el-container>
        <!-- 导航栏 -->
        <!-- 头部 -->
        <el-header>
          <el-icon size="30" @click="collapse = !collapse" color="white">
            <!-- <Fold /> -->
            <component :is="headerleft"></component>
          </el-icon>

        <el-icon style="color:white;top=8px;left:425px;"><Search /></el-icon>

          <div class="header-nav">
            <!-- 欢迎您,管理员 -->
            {{ userInfo }}
            <span style="margin:0px 8px;" >当前月度:2023-2</span>
          </div>

        </el-header>
        <el-main>
          <!-- 布局路由 -->
          <router-view />
        </el-main>
      </el-container>
    </el-container>
  </div>
</template>

<style lang="scss" scoped>
.el-container {
  height: 100vh;

  .el-aside {
    background-color:#fff;
    //直接将计算属性的值拿过来
    width: v-bind(asideWidth);
    // overflow: hidden;
    transition:all 0.3s;

    .logo-box{
      height:60px;
      display:flex;
      align-items: center;
      box-sizing: border-box;

      .el-image {
        left:20px;
        margin-right: 10px;
      }
      .manage-title{
        color: #fff;
        font-size: 18px;
        left:10px;
        margin: 0 0 0 8px;
        font-weight: bold;
      }
    }
    }
}


  .el-header{
    background-color: #1890ff;
    display: flex;
    justify-content: space-between;
    align-items: center;
    .el-icon{
      top:2px;
      width:2em;
      height:2em;
      color:white;
    }

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
  }

/*   .el-main{

  } */

</style>

<script>
import {onMounted,ref } from 'vue'
import { userStore } from '../stores/user'
//引入图标
import {Fold,Expand} from '@element-plus/icons-vue'
//导入侧边栏组件 @代表src路径
// import AsideCom from "@/components/Home/AsideCom.vue"
import test from "@/components/Home/test.vue"
//导入logo
import File from "@/assets/1.png"

const store = userStore()
export default {
   // 用户信息提示
   setup() {
    const userInfo = ref(null)
    const getUsers = () => {
      ref('欢迎用户：' + (store.getUser === null ? 
      '游客' : store.getUser.username))
    }
    onMounted(() => {
      getUsers();
    })
    return userInfo
   },
  data() {
    return {
      url:File,
      collapse:false,
    }
  },
  //计算属性
  computed:{
    headerleft(){
      return this.collapse ? 'Fold' : 'Expand'
    },
    asideWidth () {
      return this.collapse ? "200px" :"50px"
    }
  },
  //注册组件
  components: {
    Fold,
    Expand,
    // AsideCom,
    test
  }
}

// 菜单数据
const menus = store.getMenus
</script>

