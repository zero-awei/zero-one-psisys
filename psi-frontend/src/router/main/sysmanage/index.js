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
    path: '/component/form',
    name: 'search',
    component: () => import('@/components/form/demo.vue')
    // component: () => import('../../../components/psiSearch/demo.vue')
  },
  {
    path: '/component/table',
    name: 'table',
    component: () => import('@/components/table/demo.vue')
  },
  {
    path: '/component/dialog',
    name: 'dialog',
    component: () => import('@/components/dialog/demo.vue')
  },
  {
    path: '/component/drawer',
    name: 'drawer',
    component: () => import('@/components/drawer/demo.vue')
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
  },
  // 系统管理
  {
    path: '/sysmanagement/rolemanagement',
    name: 'rolemanagement',
    component: () => import('@/views/sysmanage/RoleManage.vue')
  },
  {
    path: '/sysmanagement/menumanagement',
    name: 'menumanagement',
    component: () => import('@/views/sysmanage/MenuManage.vue')
  },
  {
    path: '/sysmanagement/usermanagement',
    name: 'usermanagement',
    component: () => import('@/views/sysmanage/UserManage.vue')
  },
  {
    path: '/sysmanagement/addressbook',
    name: 'addressbook',
    component: () => import('@/views/sysmanage/Addressbook.vue')
  },
  {
    path: '/sysmanagement/Category',
    name: 'Category',
    component: () => import('@/views/sysmanage/Category.vue')
  },
  {
    path: '/sysmanagement/orimanage',
    name: 'orimanage',
    component: () => import('@/views/sysmanage/OriManage.vue')
  },
  {
    path: '/sysmanagement/sysposition',
    name: 'sysposition',
    component: () => import('@/views/sysmanage/SysPosition.vue')
  },
  // 应付管理
  // 采购应付
  {
    path: '/pay/payable/purchase',
    name: 'purchase',
    component: () =>
      import('@/views/yingfuyufukuan/yingfuguanli/CaiGouYingFu.vue')
  },
  // 其他应付
  {
    path: '/pay/payable/other',
    name: 'other',
    component: () =>
      import('@/views/yingfuyufukuan/yingfuguanli/QiTaYingFu.vue')
  },
  // 应付核销
  {
    path: '/pay/payable/check',
    name: 'check',
    component: () =>
      import('@/views/yingfuyufukuan/yingfuguanli/YingFuHeXiao.vue')
  }
]

export default routes
