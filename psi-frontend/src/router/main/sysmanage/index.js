const routes = [
  {
    path: '/un-1',
    name: 'UN1',
    component: () => import('@/views/status/404.vue')
  },
  {
    path: '/un-2',
    name: 'UN2',
    component: () => import('@/views/status/403.vue')
  },
  {
    path: '/un-3',
    name: 'UN3',
    component: () => import('@/views/status/404.vue')
  },
  {
    path: '/un-4',
    name: 'UN4',
    component: () => import('@/views/status/403.vue')
  },
  {
    path: '/un-5',
    name: 'UN5',
    component: () => import('@/views/status/404.vue')
  },
  {
    path: '/un-6',
    name: 'UN6',
    component: () => import('@/views/status/403.vue')
  },
  {
    path: '/component/search',
    name: 'search',
    // component: () => import('@/components/search/index.vue')
    component: () => import('../../../components/search/index.vue')
  },
  {
    path: '/component/table',
    name: 'table',
    component: () => import('@/components/table/index.vue')
  },
  {
    path: '/component/dialog',
    name: 'dialog',
    component: () => import('@/components/dialog/index.vue')
  },
  {
    path: '/component/drawer',
    name: 'drawer',
    component: () => import('@/components/drawer/index.vue')
  },
  {
    path: '/component/custom',
    name: 'custom',
    component: () => import('@/components/custom/index.vue')
  },
  {
    path: '/component/center',
    name: 'center',
    component: () => import('@/components/center/index.vue')
  }
]

export default routes
