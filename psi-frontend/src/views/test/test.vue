<template>
  <div>
    <el-button @click="handle">测试接口</el-button>
  </div>
</template>

<script setup>
// ./api/xxx.js 定义的是测试接口的方法
// src/views/xxx/api/xxx.js 定义的是测试接口
// src/apis/public/index.js 定义的是公共接口
// src/views/test/api       定义的是测试接口的方法
// 业务页面里写的也是  测试接口的方法

// 区分测试接口、 测试接口的方法
// 测试接口是xxx, 需要写好url参数，请求方式
// 测试接口的方法是 handleXXX,  需要传请求参数params

// TODO 引入的方法需要改 import {Xxx} from ''
//import { handleQuery } from './api/addressbook.js'
// import { handleQuery, handleClose, handleDelete, handleEdit, handlequeryAllByBillno, handleQueryOneHav, handleUnclose, handleVoid } from './api/caigouyufuapply.js'
// import { handleQueryOneNo } from './api/caigouyufu.js'
// import { handleAddMenu } from './api/menu.js' // 引入 业务接口测试方法
// import { handleQueryBasBankAccount } from './api/public.js' //引入公共接口测试方法
// import { handleQuery } from './api/addressbook.js'
// import { newCheckPayableSave } from "./api/payable.js";

// import {
//   handleSavePermission,
//   handleDeletePermission,
//   handleListPermission
// } from '@/views/sysmanage/api/rolepermission.js'
// import {
//   handleSaveMenu,
//   handleDeleteMenu,
//   handleListMenu
// } from '@/views/sysmanage/api/rolemenu.js'
import { handleQueryAllROle } from '@/views/sysmanage/api/rolemanagement.js'
// const savePermissionData = {
//   fatherPermissionId: '2e42e3835c2b44ec9f7bc26c146ee531',
//   instruction: 'nihao',
//   permissionId: '1',
//   permissionName: '成功',
//   permissionType: 2,
//   url: '/result/success'
// }
// const deletePermissionData = {
//   permissionId: '1'
// }
// const listPermissionData = {
//   RId: '00a2a0ae65cdca5e93209cdbde97cbe6'
// }
// const saveMenuData = {
//   icon: 'null',
//   id: '12345678',
//   name: '菜单1',
//   parentId: '00a2a0ae65cdca5e93209cdbde97cbe6',
//   sortNo: '1.1',
//   url: '/main/1'
// }
// const deleteMenuData = {
//   id: '1'
// }
// const listMenuData = {
//   RId: '043780fa095ff1b2bec4dc406d76f023'
// }
// const Data = {
//   fatherPermissionName: '性能监控',
//   fatherUrl: '/monitor',
//   instruction: '拥有该权限的人可以对后台redis进行监控',
//   permissionId: '00a2a0ae65cdca5e93209cdbde97cbe6',
//   permissionName: 'Redis监控',
//   permissionType: 1,
//   url: '/monitor/redis/info'
// }
const data = {
  pageIndex: '1',
  pageSize: '10',
  roleCode: 'third_role',
  roleName: '第三方登录角色'
}
/**
 * 接口测试函数
 */
function handle() {
  // TODO 改的是下面这行
  // 测试业务接口
  //
  // handleAddMenu()
  // // 测试公共接口
  // handleQueryBasBankAccount()

  // handleQuery()
  // handleClose()
  // handleDelete()
  // handleEdit()
  // handlequeryAllByBillno()
  // handleQueryOneHav()
  // handleQueryOneNo()
  // handleUnclose()
  // handleVoid()
  // handleQuery()

  //测试应付核销接口
  // payable.queryTableEntries()
  // payable.getTableList()
  // payable.queryPayableBySupplier()
  // payable.queryPaymentBySupplier()
  // payable.newCheckPayableSave()
  // payable.newCheckPayableSubmit()
  // payable.checkCheckPayable()
  // payable.closeCheckPayable()
  // payable.deleteCheckPayable()
  //导出无需测试
  // payable.exportCheckPayable()
  //导入无需测试
  // payable.importCheckPayable()
  // payable.modifyCheckPayableSave()
  // payable.modifyCheckPayableSubmit()
  // payable.uncloseCheckPayable()
  // payable.voidCheckPayable()

  //测试其他应付接口
  // payable.listOtherTable()
  // payable.getTableByBillNo()
  // payable.addOtherTable()
  // payable.deleteOtherPayable()
  //导出无需测试
  // payable.exportPayableTable()
  //导入无需测试
  // payable.importOtherPayable()
  // payable.modifyOtherPayable()
  // payable.updateOtherPayable()

  //测试采购应付接口
  // payable.getPayableTableByBillNO()
  // payable.listAllTable()
  //导出无需测试
  // payable.exportPayableTable()
}
// 查看是否调用成功，可以在 测试接口(./api/menu.js 定义的方法中 console.log())
//                 也可以浏览器 控制台 f12->network 查看

  // handleSavePermission(
  //   savePermissionData,
  //   (item) => item, // success
  //   (item) => item // fail
  // )
  // handleDeletePermission(
  //   deletePermissionData,
  //   (item) => item, // success
  //   (item) => item // fail
  // )
  // handleListPermission(
  //   listPermissionData,
  //   (item) => item, // success
  //   (item) => item // fail
  // )
  // handleSaveMenu(
  //   saveMenuData,
  //   (item) => item, // success
  //   (item) => item // fail
  // )
  // handleDeleteMenu(
  //   deleteMenuData,
  //   (item) => item, // success
  //   (item) => item // fail
  // )
  // handleListMenu(
  //   listMenuData,
  //   (item) => item, // success
  //   (item) => item // fail
  // )
  // handleQueryAllROle(
  //   data,
  //   (item) => item, // success
  //   (item) => item // fail)
  // )

// }
// 查看是否调用成功，可以在 测试接口(./api/menu.js 定义的方法中 console.log())
//                 也可以浏览器 控制台 f12->network 查看
</script>

<style></style>
