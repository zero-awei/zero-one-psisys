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
import { handleAddMenu } from './api/menu.js'   // 引入 业务接口测试方法
import { handleQueryBasBankAccount } from './api/public.js'  //引入公共接口测试方法
import { handleQuery } from './api/addressbook.js'
import { handleQueryOrganizationName } from './api/addressbook.js'
import { handleQueryOrganizationTreeName } from './api/addressbook.js'
import { handleExcel } from './api/addressbook.js'
import { handleExcelUrl } from './api/addressbook.js'

import { handleDelete } from './api/classifieddictionary.js'
import { handleInsert } from './api/classifieddictionary.js'
import { handleQueryAll } from './api/classifieddictionary.js'
import { handleUpdateOne } from './api/classifieddictionary.js'
import { handleQueryOne } from './api/classifieddictionary.js'

import { handleGetBillList } from './api/purprepaymentapply.js'  //查询单据列表
import { handleGetDetailBill } from './api/purprepaymentapply.js'  //查看指定单据
import { handleGetPrepaybill } from './api/purprepaymentapply.js'  //采购订单列表
import { handleGetPrepaybillDetail } from './api/purprepaymentapply.js'  //采购订单分列表
import { handlePostAdd } from './api/purprepaymentapply.js'  //添加采购预付申请单
import { handlePutModifyPay } from './api/purprepaymentapply.js'  //修改采购预付申请
import { handleDeleteMenu } from './api/purprepaymentapply.js'  //删除采购预付申请单
import { handleModifyBillStatus } from './api/purprepaymentapply.js'  //采购预付申请修改单据状态(关闭/反关闭/作废)

import { handlePaymentApplyBill } from './api/purpaymentapply.js'  //查询单据列表
import { handleFinPaymentReqEntry } from './api/purpaymentapply.js'  //查看指定单据详细信息
import { handleAppPayment } from './api/purpaymentapply.js'  //添加采购付款申请单（保存/提交）
import { handleChangePayment } from './api/purpaymentapply.js'  //修改采购付款申请单（保存/提交/审核）----修改状态
import { handleModPaymentReq } from './api/purpaymentapply.js'  //修改采购付款申请单（保存/提交/审核）----修改内容
import { handleDeleteById } from './api/purpaymentapply.js'  //删除采购付款申请单
import { handleModifyPaymentStatus } from './api/purpaymentapply.js'  //修改单据状态（关闭/作废/反关闭）

import { handleListPurOrder } from './api/purorder.js'  //查询单据列表
import { handleQueryPurOrderEntryByMainId } from './api/purorder.js'  //查看指定单据详细信息
import { handleQueryPurReqEntryByMainId } from './api/purorder.js'  //采购申请单列表
import { handleListPurReq } from './api/purorder.js'  //采购申请单分录列表
import { handleListPurCom } from './api/purorder.js'  //比价单列表
import { handleListEntrysPurCom } from './api/purorder.js'  //比价单分录列表
import { handleAddPurOrder } from './api/purorder.js'  //添加采购订单（保存/提交）
import { handleEditPurOrder } from './api/purorder.js'  //修改采购订单（保存/提交/审核）
import { handleDeletePurOrder } from './api/purorder.js'  //删除采购订单----根据单据编号删除
import { handleDeleteByIdPurOrder } from './api/purorder.js'  //删除采购订单----根据ID删除
import { handleModifyStatusPurOrder } from './api/purorder.js'  //修改单据状态（关闭/作废/反关闭）


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
  //=====================================通讯录
  // TODO 改的是下面这行
  // 测试业务接口
  //
  // handleAddMenu()
  // // 测试公共接口
  // handleQueryBasBankAccount()
  // handleQuery()
  // handleQueryOrganizationName()
  // handleQueryOrganizationTreeName()
  // handleExcel()
  // handleExcelUrl()
  //===================================根字典
  // handleDelete()
  // handleInsert()
  // handleQueryAll()
  // handleUpdateOne()
  handleQueryOne()

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
  handleModifyStatusPurOrder()

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
