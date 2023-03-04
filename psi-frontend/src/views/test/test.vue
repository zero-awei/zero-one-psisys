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

function handle() {
  // TODO 改的是下面这行
  // 测试业务接口
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


</script>

<style scoped></style>