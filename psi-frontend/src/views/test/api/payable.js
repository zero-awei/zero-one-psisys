import * as payableCheck from '@/views/yingfuyufukuan/yingfuguanli/api/yingfuhexiao.js'
import * as otherPayable from '@/views/yingfuyufukuan/yingfuguanli/api/qitayingfu.js'
import * as finPayable from '@/views/yingfuyufukuan/yingfuguanli/api/caigouyufu.js'
import { ElMessage } from 'element-plus'

//SECTION 应付核销

//SECTION 查询

export function queryTableEntries() {
  let params = {
    mainId: '1591811712127950850'
  }
  payableCheck.queryTableEntries(
    params,
    (data) => {
      console.log('请求data: ', data)
    },
    (msg) => {
      console.log('msg', msg)
      ElMessage.error('错误信息')
    }
  )
}

export function getTableList() {
  let params = {
    billDateEnd: '2023-02-07',
    pageIndex: '1',
    pageSize: '10'
  }
  payableCheck.getTableList(
    params,
    (data) => {
      console.log('请求data: ', data)
    },
    (msg) => {
      console.log('msg', msg)
      ElMessage.error('错误信息')
    }
  )
}

export function queryPayableBySupplier() {
  let params = {
    supplierId: '1584950950470164481',
    pageIndex: '1',
    pageSize: '10'
  }
  payableCheck.queryPayableBySupplier(
    params,
    (data) => {
      console.log('请求data: ', data)
    },
    (msg) => {
      console.log('msg', msg)
      ElMessage.error('错误信息')
    }
  )
}

export function queryPaymentBySupplier() {
  let params = {
    supplierId: '1584950950470164481',
    pageIndex: '1',
    pageSize: '10'
  }
  payableCheck.queryPaymentBySupplier(
    params,
    (data) => {
      console.log('请求data: ', data)
    },
    (msg) => {
      console.log('msg', msg)
      ElMessage.error('错误信息')
    }
  )
}

// !SECTION 查询

// !SECTION 应付核销

// SECTION 其他应付

// SECTION 查询

export function listOtherTable() {
  let params = {
    billDateEnd: '2023-02-13 00:00:00',
    pageIndex: '1',
    pageSize: '10'
  }
  otherPayable.listOtherTable(
    params,
    (data) => {
      console.log('请求data: ', data)
    },
    (msg) => {
      console.log('msg', msg)
      ElMessage.error('错误信息')
    }
  )
}

export function getTableByBillNo() {
  let params = {
    bill_no: 'CGAP-221110-001'
  }
  otherPayable.getTableByBillNo(
    params,
    (data) => {
      console.log('请求data: ', data)
    },
    (msg) => {
      console.log('msg', msg)
      ElMessage.error('错误信息')
    }
  )
}


// !SECTION 查询

// !SECTION 其他应付


// SECTION 采购预付

//SECTION 查询

export function getTableByBillNO() {
  let params = {
    bill_no: 'CGAP-221110-001'
  }
  finPayable.getTableByBillNO(
    params,
    (data) => {
      console.log('请求data: ', data)
    },
    (msg) => {
      console.log('msg', msg)
      ElMessage.error('错误信息')
    }
  )
}
//!SECTION 查询

// !SECTION 采购预付