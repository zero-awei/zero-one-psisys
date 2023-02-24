const routes = [
  {
    path: '/home',
    name: 'Home',
    id: 1,
    text: '主页',
    redirect: { name: 'Dashboard' },
    component: () => import('@/views/HomeView.vue'),
    children: [
      {
        path: '/dashboard',
        name: 'Dashboard',
        id: 2,
        text: '仪表板',
        component: () => import('@/views/dashboard/Dashboard.vue')
      }
    ]
  }
]

// 读取子目录下面菜单设置为二级路由
const secondRouter = import.meta.glob('./**/index.js', { eager: true })
for (const path in secondRouter) {
  routes[0].children.push(...secondRouter[path].default)
}

export default routes
