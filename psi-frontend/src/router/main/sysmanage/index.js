/*
 * @Author: Kyle5 nnkyle@163.com
 * @Date: 2023-02-20 18:51:04
 * @LastEditors: 160405103 1348313766@qq.com
 * @LastEditTime: 2023-02-26 11:42:13
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
  // ↓↓↓↓↓↓↓↓↓↓↓↓↓基础资料↓↓↓↓↓↓↓↓↓↓↓↓↓
  {
    path: '/client',
    name: 'client',
    component: () => import('@/views/jichuziliao/ClientCheck.vue')
  },
  {
    path: '/Provider',
    name: 'Provider',
    component: () => import('@/views/jichuziliao/ProviderCheck.vue')
  },
  {
    path: '/Currency',
    name: 'Currency',
    component: () => import('@/views/jichuziliao/CurrencyCheck.vue')
  },
  {
    path: '/MaterialSort',
    name: 'MaterialSort',
    component: () => import('@/views/jichuziliao/MaterialSortCheck.vue')
  },
  {
    path: '/Material',
    name: 'Material',
    component: () => import('@/views/jichuziliao/MaterialCheck.vue')
  },
  {
    path: '/Measurement',
    name: 'Measurement',
    component: () => import('@/views/jichuziliao/MeasurementCheck.vue')
  },
  {
    path: '/Account',
    name: 'Account',
    component: () => import('@/views/jichuziliao/AccountCheck.vue')
  },
  {
    path: '/Store',
    name: 'Store',
    component: () => import('@/views/jichuziliao/StoreCheck.vue')
  },
  // ↓↓↓↓↓↓↓↓↓↓↓↓↓采购管理↓↓↓↓↓↓↓↓↓↓↓↓↓
  {
    path: '/PurInquiry',
    name: 'PurInquiry',
    component: () => import('@/views/caigouguanli/PurInquiry.vue')
  },
  {
    path: '/PurOrder',
    name: 'PurOrder',
    component: () => import('@/views/caigouguanli/PurOrder.vue')
  },
  {
    path: '/PurPaymentApply',
    name: 'PurPaymentApply',
    component: () => import('@/views/caigouguanli/PurPaymentApply.vue')
  },
  {
    path: '/PurRequisition',
    name: 'PurRequisition',
    component: () => import('@/views/caigouguanli/PurRequisition.vue')
  },
  {
    path: '/PurComparison',
    name: 'PurComparison',
    component: () => import('@/views/caigouguanli/PurComparison.vue')
  },
  {
    path: '/PurPrepaymentApply',
    name: 'PurPrepaymentApply',
    component: () => import('@/views/caigouguanli/PurPrepaymentApply.vue')
  },
  {
    path: '/SupplyQuotation',
    name: 'SupplyQuotation',
    component: () => import('@/views/caigouguanli/SupplyQuotation.vue')
  },
  // ↓↓↓↓↓↓↓↓↓↓↓↓↓系统管理↓↓↓↓↓↓↓↓↓↓↓↓↓
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
    component: () => import('@/views/sysmanage/AddressBook.vue')
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
  // ↓↓↓↓↓↓↓↓↓↓↓↓↓应付与付款--应付管理↓↓↓↓↓↓↓↓↓↓↓↓↓
  // 采购应付
  {
    path: '/pay/payable/purchase',
    name: 'payablePurchase',
    component: () =>
      import('@/views/yingfuyufukuan/yingfuguanli/CaiGouYingFu.vue')
  },
  // 其他应付
  {
    path: '/pay/payable/other',
    name: 'payableOther',
    component: () =>
      import('@/views/yingfuyufukuan/yingfuguanli/QiTaYingFu.vue')
  },
  // 应付核销
  {
    path: '/pay/payable/check',
    name: 'check',
    component: () =>
      import('@/views/yingfuyufukuan/yingfuguanli/YingFuHeXiao.vue')
  },
  // ↓↓↓↓↓↓↓↓↓↓↓↓↓应付与付款--预付管理↓↓↓↓↓↓↓↓↓↓↓↓↓
  // 采购预付(有申请)
  {
    path: '/paymentApply',
    name: 'paymentApply',
    component: () =>
      import('@/views/yingfuyufukuan/yufuguanli/CaiGouYuFuApply.vue')
  },
  // 采购预付(无申请)
  {
    path: '/payment',
    name: 'payment',
    component: () => import('@/views/yingfuyufukuan/yufuguanli/CaiGouYuFu.vue')
  },
  // ↓↓↓↓↓↓↓↓↓↓↓↓↓应付与付款--付款管理↓↓↓↓↓↓↓↓↓↓↓↓↓
  // 采购付款(有申请)
  {
    path: '/purchaseApply',
    name: 'purchaseApply',
    component: () =>
      import('@/views/yingfuyufukuan/fukuanguanli/CaiGouFuKuanApply.vue')
  },
  // 采购付款(无申请)
  {
    path: '/purchase',
    name: 'caigouPurchase',
    component: () =>
      import('@/views/yingfuyufukuan/fukuanguanli/CaiGouFuKuan.vue')
  },
  // 采购退货退款(红付)
  {
    path: '/purchaseHongfu',
    name: 'purchaseHongfu',
    component: () =>
      import('@/views/yingfuyufukuan/fukuanguanli/CaiGouTuiHuoTuiKuan.vue')
  },
  // ↓↓↓↓↓↓↓↓↓↓↓↓↓库存管理↓↓↓↓↓↓↓↓↓↓↓↓↓
  // 采购入库
  {
    path: '/inventory/purchase',
    name: 'purchase',
    component: () => import('@/views/kucunguanli/rukuguanli/CaiGouRuKu.vue')
  },
  // 采购入库退货出库（红入）
  {
    path: '/inventory/salesreturn',
    name: 'salesreturn',
    component: () =>
      import('@/views/kucunguanli/rukuguanli/CaiGouRuKuTuiHuoChuKu.vue')
  },
  // 盘盈入库
  {
    path: '/inventory/inventoryprofit',
    name: 'inventoryprofit',
    component: () => import('@/views/kucunguanli/rukuguanli/PanYingRuKu.vue')
  },
  // 涨吨入库
  {
    path: '/inventory/rise',
    name: 'rise',
    component: () => import('@/views/kucunguanli/rukuguanli/ZhangDunRuKu.vue')
  },
  // 其他入库
  {
    path: '/inventory/other',
    name: 'other',
    component: () => import('@/views/kucunguanli/rukuguanli/QiTaRuKu.vue')
  }
  // {
  //   path: '/inventory/purchase',
  //   name: 'check',
  //   component: () =>
  //     import('@/views/yingfuyufukuan/yingfuguanli/YingFuHeXiao.vue')
  // },
  // {
  //   path: '/inventory/purchase',
  //   name: 'check',
  //   component: () =>
  //     import('@/views/yingfuyufukuan/yingfuguanli/YingFuHeXiao.vue')
  // },
  // {
  //   path: '/inventory/purchase',
  //   name: 'check',
  //   component: () =>
  //     import('@/views/yingfuyufukuan/yingfuguanli/YingFuHeXiao.vue')
  // },
  // {
  //   path: '/inventory/purchase',
  //   name: 'check',
  //   component: () =>
  //     import('@/views/yingfuyufukuan/yingfuguanli/YingFuHeXiao.vue')
  // },
  // {
  //   path: '/inventory/purchase',
  //   name: 'check',
  //   component: () =>
  //     import('@/views/yingfuyufukuan/yingfuguanli/YingFuHeXiao.vue')
  // },
  // {
  //   path: '/inventory/purchase',
  //   name: 'check',
  //   component: () =>
  //     import('@/views/yingfuyufukuan/yingfuguanli/YingFuHeXiao.vue')
  // },
  // {
  //   path: '/sysmanagement/rolemanagement',
  //   name: '出入库明细',
  //   component: () =>
  //     import('@/views/yingfuyufukuan/yingfuguanli/YingFuHeXiao.vue')
  // }
]

export default routes
