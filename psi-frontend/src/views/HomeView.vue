<template>
  <div class="layout-container">
    <el-container>
      <!-- 左侧侧边栏 -->
      <el-aside :class="{ 'dark-aside': isDarkThem }">
        <!-- background-color: #ffffff -->
        <div class="logo-box" style="">
          <el-image style="width: 28px; height: 32px" :src="url"></el-image>
          <span class="manage-title" v-if="collapse = !collapse">进销存</span>
        </div>
        <!-- 使用自定义侧边菜单组件 -->
        <!-- <AsideCom /> -->
        <div class="menu-class">
          <test :label="collapse = !collapse" />
          <!-- <Menu :label="collapse = !collapse" :menuList="menus"></Menu> -->
        </div>
        <!-- @selectChange='addTab' -->
        <!-- 默认true -->
      </el-aside>

      <!-- 右侧内容 -->
      <el-container>
        <!-- 导航栏 -->
        <!-- 头部 -->
        <el-header style="">
          <el-icon size="30" @click="collapse = !collapse" style="color:#1890ff">
            <!-- <Fold /> -->
            <component :is="headerleft"></component>
          </el-icon>
          <HeadSideCom>


          </HeadSideCom>
        </el-header>
        <!--  style="background-color: #363637;" -->
        <el-main>
          <el-tabs v-model="editableTabsValue" type="card" class="demo-tabs" @tab-remove="removeTab"
            @tab-click="tabClick">

            <el-tab-pane v-for="item in editableTabs" :key="item.name" :label="item.title" :name="item.name"
              :closable="item.title != '首页'">
              <!-- :closable="item.title != '首页'" -->
            </el-tab-pane>
          </el-tabs>
          <!-- <el-card> -->
          <!-- 布局路由 -->
          <!-- KeepAlive 不会用 -->
          <!-- <KeepAlive> -->
          <div class="right-main">
            <el-card>
              <router-view />
            </el-card>
          </div>
          <!-- </KeepAlive> -->

          <!-- </el-card> -->
        </el-main>
      </el-container>
    </el-container>
  </div>
</template>

<script>
import { ref, } from 'vue'
import { storeToRefs } from 'pinia'
import { userStore } from '../stores/user'
import { pathStore } from '../stores/path'
import { themeStore } from '@/stores/theme'
import { useRouter } from 'vue-router'
//引入图标
import { Fold, Expand, Sunny, MoonNight } from '@element-plus/icons-vue'
//导入侧边栏组件 @代表src路径
// import AsideCom from "@/components/Home/AsideCom.vue"
import test from '@/components/home/test.vue'
//导入logo
import File from '@/assets/1.png'
//导入UserNameCom
import HeadSideCom from "@/components/Home/HeadSideCom.vue"
//导入面包屑 
import NavHeadCom from "@/components/Home/NavHeadCom.vue"

import { useDark, useToggle } from '@vueuse/core'
const store = userStore()
const pathstore = pathStore()

const isDark = useDark()
// let themIsDark = themStore.getIsDark
export default {
  data() {
    return {
      url: File,
      collapse: false,
      label: true,
    }
  },
  //计算属性
  computed: {
    headerleft() {
      return this.collapse ? 'Expand' : 'Fold'
    },
    asideWidth() {
      return this.collapse ? "60px" : "200px"
    },
  },
  //注册组件
  components: {
    Fold,
    Expand,
    // AsideCom,
    test,
    HeadSideCom,
    NavHeadCom
  },
  setup() {
    // 亮色、黑暗模式选择
    const switchMode = ref(true)
    const isDarkThem = ref(false)
    const themStore = themeStore()
    const { isDarkTheme } = storeToRefs(themStore)
    const subscribe = themStore.$subscribe((mutation, state) => {
      console.log('77777777', state.isDarkTheme)
      isDarkThem.value = state.isDarkTheme

    })
    // 标签页相关
    const editableTabsValue = ref('1')
    const editableTabs = ref([
      {
        title: '首页',
        name: 'Home',
        href: '/home',
        id: 0
      }
    ])
    const pathIdSet = pathstore.getPathIdSet
    const pathList = pathstore.getPathList
    const $router = useRouter()
    //  {
    //   title: '首页',
    //     name: 'Home',
    //       href: '/home'
    // }
    // 刚进页面,pathList肯定只有一个值
    // // console.log("editableTabs初始化", pathList)

    // pathList.forEach((item)=>{

    // })
    // let temp = pathList[pathList.length - 1]
    let temp = pathList[0]
    if (temp.href === '/dashboard' || temp.href === '/home') {

      editableTabsValue.value = "Home"
    } else {
      // 用户点击路由
      let item = {}
      item.title = temp.text
      item.name = temp.name
      item.href = temp.href
      item.id = temp.id
      // 除了 /home /dashboard 都有id
      item.id = temp.id

      // 再添加其他页面
      editableTabs.value.push(item)
      editableTabsValue.value = item.name
    }

    // // console.log('初始化后editableTabs', editableTabs)

    function removeTab(targetName) {

      const tabs = editableTabs.value
      // console.log("标签关闭前editableTabs", tabs)
      // [ { title: '首页', name: 'Home', href: '/home', id: 0 }]
      let activeName = editableTabsValue.value  // menus的name
      // console.log("标签关闭前activeName", activeName)
      // // console.log("标签关闭前targetName", targetName)
      let removeId = ''
      if (activeName === targetName) {
        // 如果要关闭的tab和已经激活的tab是同一个
        tabs.forEach((tab, index) => {
          if (tab.name === targetName) {
            removeId = tab.id
            // 前后随机选一个跳转
            // const nextTab = tabs[index + 1] || tabs[index - 1]
            // 选一个跳转
            const nextTab = tabs[index - 1]
            if (nextTab) {
              activeName = nextTab.name
              // // console.log("nextTab", nextTab)
              pathstore.removePathIdSet(removeId)
              $router.push(nextTab.href)
            }
          }
        })
      }
      // $router.go(-1)
      // 如果要关闭的tab和已经激活的tab不是同一个
      // // console.log("标签关闭后activeName", activeName)
      editableTabsValue.value = activeName
      editableTabs.value = tabs.filter((tab) => tab.name !== targetName)
      pathstore.removePathIdSet(removeId)
      // // console.log("结束editableTabs", editableTabs)
      // $router.push()
    }
    const tabClick = (TabsPaneContext) => {
      // // console.log("标签点击", TabsPaneContext.props.name)
      const targetName = TabsPaneContext.props.name
      const tabs = editableTabs.value
      // 找到要激活的标签页
      for (let i = 0; i < tabs.length; i++) {
        if (tabs[i].name === targetName) {
          // activeName = nextTab.name
          // // console.log("tabs[i]", tabs[i])
          $router.push(tabs[i].href)
          editableTabsValue.value = targetName
          break
        }
      }

    }

    // // console.log("---------pathstore.getPathIdSet-------------", pathIdSet)
    function handleTabs(list) {
      console.log("关闭时")
      let nextTab = list[list.length - 1]
      console.log("---------pathIdSet-------------", pathIdSet)
      console.log("---------nextTab-------------", nextTab)
      const pathIdList = [...pathIdSet]
      // pathIdSet 和 pathList是同步更新，所以pathIdSet.has(nextTab.id)一定为true
      // if (pathIdList[pathIdList.length - 1] === nextTab.id) {
      if (!pathIdSet.has(nextTab.id)) {
        // 如果是同步更新，说明是新的标签页
        let tabItem = {}
        tabItem.title = nextTab.text
        tabItem.id = nextTab.id
        tabItem.name = nextTab.name
        tabItem.href = nextTab.href
        if (tabItem.name !== 'Dashboard') {

          editableTabs.value.push(tabItem)
          editableTabsValue.value = tabItem.name
        }
        pathstore.addPathIdSet(tabItem.id)
      } else if (pathIdSet.has(nextTab.id)) {
        // 如果不同步，而且已经打开了这个路由，激活该tab,
        editableTabsValue.value = nextTab.name
      }
      // if (pathIdSet.has(nextTab.id)) {
      //   // 如果tab页已经有该路由,激活该tab,
      //   // // console.log('909909090editableTabs, 不是新路由')
      //   // // console.log('909909090editableTabs', editableTabs)
      //   editableTabsValue.value = nextTab.id
      // } else {
      //   // // console.log('909909090editableTabs, 是新路由')
      //   // 否则生成新tab
      //   let tabItem = {}
      //   tabItem.title = nextTab.text
      //   tabItem.id = nextTab.id
      //   tabItem.name = nextTab.id
      //   tabItem.path = nextTab.href
      //   editableTabs.value.push(tabItem)
      //   editableTabsValue.value = tabItem.name
      // }
    }

    const menus = ref([])
    menus.value = store.getMenus
    return {
      editableTabsValue,
      editableTabs,
      // addTab,
      removeTab,
      tabClick,
      pathList,
      pathIdSet,
      // lastPath,
      handleTabs,
      menus,
      switchMode,
      isDarkThem
    }
  },
  watch: {
    // 当用户点击能跳转的路由，pathList会发生变化
    pathList: {
      deep: true,//true为进行深度监听,false为不进行深度监听
      handler(newVal) {
        // // console.log('监听pathList-------------------', newVal);
        this.handleTabs(newVal)
      }
    },
    // lastPath: {
    //   deep: true,
    //   handler(newVal) {
    //     // // console.log('监听lastPath-------------------', newVal);
    //   }
    // },
    // themIsDark: {
    //   handler(newVal) {
    //     console.log('监听themStore-------------------', newVal);
    //   }
    // }
  },
  methods: {
    switchThemes() {
      const toggleDark = useToggle(isDark)
      console.log(toggleDark())
    }
  }
}



</script>

<style lang="scss" scoped>
* {
  margin: 0;
  padding: 0;
}

.el-container {
  height: 100vh;

  //  background-color:rgba(226, 225, 225, 0.03);
  .el-aside {
    // background-color: #fff;
    //直接将计算属性的值拿过来
    width: v-bind(asideWidth);
    overflow: hidden;
    transition: all 0.3s;

    .logo-box {
      height: 60px;
      display: flex;
      align-items: center;
      box-sizing: border-box;

      .el-image {
        left: 20px;
        margin-right: 10px;
      }

      .manage-title {
        color: #1890ff;
        font-size: 18px;
        left: 10px;
        margin: 0 0 0 8px;
        font-weight: bold;
      }
    }
  }

}

.el-header {
  // background-color: #1890ff;
  // background-color: #363637;
  display: flex;
  justify-content: space-between;
  align-items: center;

  .el-icon {
    top: 2px;
    width: 2em;
    height: 2em;
    color: white;
  }
}



:deep(.el-main) {
  --el-main-padding: 10px;
}

:deep(.demo-tabs) {
  height: 40px;
}

:deep(.el-menu) {
  border: none;
}



.right-main {
  background-color: #f2eeee80;
  padding: 7px;
}

.menu-class {
  height: 100%;
  // overflow: scroll;
}

:deep(.el-card__body) {
  padding: 8px;
}

.dark-aside {
  background-color: #1c1c1d;

  span {
    color: white;
  }

  .menu-class {
    background-color: #1c1c1d;
  }

  :deep(.el-sub-menu__title) {
    background-color: #1c1c1d !important;
  }

  :deep(.el-menu-item) {
    background-color: #1c1c1d !important;
  }
}
</style>


