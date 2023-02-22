/*
 * @Author: Kyle5 nnkyle@163.com
 * @Date: 2023-02-20 18:51:04
 * @LastEditors: Kyle5 nnkyle@163.com
 * @LastEditTime: 2023-02-21 22:58:39
 * @FilePath: \psi-frontend\src\router\main\sysmanage\index.js
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
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
  {
    path: '/pay/payable/check',
    name: 'check',
    component: () =>
      import('@/views/yingfuyufukuan/payables/FinPayableCheck.vue')
  },
  {
    path: '/1/2/3',
    name: '3',
    component: () =>
      import('@/views/yingfuyufukuan/yingfuguanli/CaiGouYingFu.vue')
  },
  {
    path: '/client',
    name: 'client',
    component: () =>
      import('@/views/jichuziliao/ClientCheck.vue')
  },
  {
    path: '/Provider',
    name: 'Provider',
    component: () =>
      import('@/views/jichuziliao/ProviderCheck.vue')
  },
  {
    path: '/Store',
    name: 'Store',
    component: () =>
      import('@/views/jichuziliao/StoreCheck.vue')
  },
  {
    path: '/MaterialSort',
    name: 'MaterialSort',
    component: () =>
      import('@/views/jichuziliao/MaterialSortCheck.vue')
  },
]

export default routes
