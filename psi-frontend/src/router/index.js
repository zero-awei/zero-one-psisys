/*
 * @Author: 160405103 1348313766@qq.com
 * @Date: 2023-02-11 14:30:03
 * @LastEditors: 160405103 1348313766@qq.com
 * @LastEditTime: 2023-02-23 18:42:32
 * @FilePath: \psi-frontend\src\router\index.js
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @Author: 160405103 1348313766@qq.com
 * @Date: 2023-02-11 14:30:03
 * @LastEditors: 160405103 1348313766@qq.com
 * @LastEditTime: 2023-02-23 17:23:23
 * @FilePath: \psi-frontend\src\router\index.js
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
import { createRouter, createWebHistory } from 'vue-router'
import { ElMessage } from 'element-plus'
import { userStore } from '../stores/user'
import { pathStore } from '../stores/path'
const routes = []
routes.push(
  {
    path: '/:pathMatch(.*)*',
    name: 'NotFound',
    component: () => import('../views/status/404.vue')
  },
  {
    path: '/forbidden',
    name: 'Forbidden',
    component: () => import('../views/status/403.vue')
  },
  {
    path: '/error',
    name: 'Error',
    component: () => import('../views/status/500.vue')
  }
)

// 读取login模块路由
const loginRouter = import.meta.glob('./login/index.js', { eager: true })
for (const path in loginRouter) {
  routes.push(...loginRouter[path].default)
}

// 读取main模块路由
const mainRouter = import.meta.glob('./main/index.js', { eager: true })
for (const path in mainRouter) {
  routes.push(...mainRouter[path].default)
}

// 定义一个路由对象
export const router = createRouter({
  history: createWebHistory(import.meta.env.BASE_URL),
  routes
})

// 添加一个路由的全局前置守卫
router.beforeEach(async function (to, from, next) {
  // 判断是否是登录页面
  if (
    to.name === 'Login' ||
    to.name === 'NotFound' ||
    to.name === 'Forbidden' ||
    to.name === 'Error'
  ) {
    next()
    return
  }
  // 判断本地是否记录token值
  let store = userStore()
  let token = store.getToken
  console.log('getToken', token)
  let pathstore = pathStore()
  // 如果有token
  if (token) {
    // 判断是否已经加载数据
    let isLoaded = store.isLoaded
    // 如果没有加载
    if (!isLoaded) {
      // 加载用户信息
      await store.loadUser()
      // 加载菜单资源
      await store.loadMenus()
      // 设置加载完毕
      store.setLoaded(true)
    }
    //添加路由
    pathstore.addPath(to)
    next()
  }
  // 如果没有token值，直接进入登录
  else {
    next({ name: 'Login' })
    ElMessage.warning('在未登录时，禁止访问其他页面！')
  }
})

export default router
