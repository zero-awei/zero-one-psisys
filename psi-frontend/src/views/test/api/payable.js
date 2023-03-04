import * as payableCheck from '@/views/yingfuyufukuan/yingfuguanli/api/yingfuhexiao.js'
import * as otherPayable from '@/views/yingfuyufukuan/yingfuguanli/api/qitayingfu.js'
import * as finPayable from '@/views/yingfuyufukuan/yingfuguanli/api/caigouyingfu.js'
import { ElMessage } from 'element-plus'
import {
  checkTable,
  closeTable,
  deleteTable,
  exportTable,
  importTable, modifyTableSave,
  newTableSave, uncloseTable, voidTable
} from '@/views/yingfuyufukuan/yingfuguanli/api/yingfuhexiao.js'

// 应付核销

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

export function newCheckPayableSave() {
  let params = {
    amt: '202',
    approvalRemark: '',
    approvalResultType: '1',
    approver: 'psi',
    attachment: '',
    billDate: '2023-02-07',
    billNo: 'YFHX-230209-009',
    billStage: '1',
    billType: 'FinPayableCheck:2',
    bpmiInstanceId: '',
    checkPayableEntryList: [
      {
        amt: '202',
        billNo: 'YFHX-230209-009',
        checkSide: '1',
        custom1: '',
        custom2: '',
        entryNo: '101',
        id: '1623386325955944449',
        mid: '1623386325943361538',
        remark: '',
        srcBillId: '1623342154423508993',
        srcBillType: 'FinPayable:299',
        srcEntryId: '',
        srcNo: 'QTAP-230208-016',
        uncheckedAmt: '0',
        version: '0'
      }
    ],
    createBy: 'psi',
    createTime: '2023-02-09 02:20:36',
    effectiveTime: '2023-02-09 03:27:18',
    id: '1623386325943361538',
    isAuto: '0',
    isClosed: '1',
    isEffective: '1',
    isRubric: '0',
    isVoided: '0',
    payableCheckType: '2',
    remark: '',
    srcBillId: '',
    srcBillType: '',
    srcNo: '',
    subject: '3333333333',
    supplierId: '1623284221748748290',
    sysOrgCode: 'A01A05',
    updateBy: 'psi',
    updateTime: '2023-02-09 03:27:18',
    version: '0'
  }
  payableCheck.newTableSave(
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

export function newCheckPayableSubmit() {
  let params = {
    amt: '202',
    approvalRemark: '',
    approvalResultType: '1',
    approver: 'psi',
    attachment: '',
    billDate: '2023-02-07',
    billNo: 'YFHX-230209-009',
    billStage: '1',
    billType: 'FinPayableCheck:2',
    bpmiInstanceId: '',
    checkPayableEntryList: [
      {
        amt: '202',
        billNo: 'YFHX-230209-009',
        checkSide: '1',
        custom1: '',
        custom2: '',
        entryNo: '101',
        id: '1623386325955944449',
        mid: '1623386325943361538',
        remark: '',
        srcBillId: '1623342154423508993',
        srcBillType: 'FinPayable:299',
        srcEntryId: '',
        srcNo: 'QTAP-230208-016',
        uncheckedAmt: '0',
        version: '0'
      }
    ],
    createBy: 'psi',
    createTime: '2023-02-09 02:20:36',
    effectiveTime: '2023-02-09 03:27:18',
    id: '1623386325943361538',
    isAuto: '0',
    isClosed: '1',
    isEffective: '1',
    isRubric: '0',
    isVoided: '0',
    payableCheckType: '2',
    remark: '',
    srcBillId: '',
    srcBillType: '',
    srcNo: '',
    subject: '3333333333',
    supplierId: '1623284221748748290',
    sysOrgCode: 'A01A05',
    updateBy: 'psi',
    updateTime: '2023-02-09 03:27:18',
    version: '0'
  }
  payableCheck.newTableSubmit(
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


export function checkCheckPayable() {
  let params = {
    id: '1590728272959815682',
    approvalRemark: '通过',
    approvalResultType: '1'
  }
  payableCheck.checkTable(
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

export function closeCheckPayable() {
  let params = {
    ids: ['1631214631207792641']
  }
  payableCheck.closeTable(
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

export function deleteCheckPayable() {
  let params = {
    ids: ['1631214631207792641']
  }
  payableCheck.deleteTable(
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

export function exportCheckPayable() {
  let params = {}
  payableCheck.exportTable(
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

export function importCheckPayable() {
  let params = {}
  payableCheck.importTable(
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

export function modifyCheckPayableSave() {
  let params = {
    amt: '202',
    approvalRemark: '',
    approvalResultType: '1',
    approver: 'psi',
    attachment: '',
    billDate: '2023-02-07',
    billNo: 'YFHX-230209-009',
    billStage: '1',
    billType: 'FinPayableCheck:2',
    bpmiInstanceId: '',
    checkPayableEntryList: [
      {
        amt: '202',
        billNo: 'YFHX-230209-009',
        checkSide: '1',
        custom1: '',
        custom2: '',
        entryNo: '101',
        id: '1623386325955944449',
        mid: '1623386325943361538',
        remark: '',
        srcBillId: '1623342154423508993',
        srcBillType: 'FinPayable:299',
        srcEntryId: '',
        srcNo: 'QTAP-230208-016',
        uncheckedAmt: '0',
        version: '0'
      }
    ],
    createBy: 'psi',
    createTime: '2023-02-09 02:20:36',
    effectiveTime: '2023-02-09 03:27:18',
    id: '1623386325943361538',
    isAuto: '0',
    isClosed: '0',
    isEffective: '1',
    isRubric: '0',
    isVoided: '0',
    payableCheckType: '2',
    remark: '',
    srcBillId: '',
    srcBillType: '',
    srcNo: '',
    subject: '3333333333',
    supplierId: '1623284221748748290',
    sysOrgCode: 'A01A05',
    updateBy: 'psi',
    updateTime: '2023-02-09 03:27:18',
    version: 0
  }
  payableCheck.modifyTableSave(
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

export function modifyCheckPayableSubmit() {
  let params = {
    amt: '202',
    approvalRemark: '',
    approvalResultType: '1',
    approver: 'psi',
    attachment: '',
    billDate: '2023-02-07',
    billNo: 'YFHX-230209-009',
    billStage: '1',
    billType: 'FinPayableCheck:2',
    bpmiInstanceId: '',
    checkPayableEntryList: [
      {
        amt: '202',
        billNo: 'YFHX-230209-009',
        checkSide: '1',
        custom1: '',
        custom2: '',
        entryNo: '101',
        id: '1623386325955944449',
        mid: '1623386325943361538',
        remark: '',
        srcBillId: '1623342154423508993',
        srcBillType: 'FinPayable:299',
        srcEntryId: '',
        srcNo: 'QTAP-230208-016',
        uncheckedAmt: '0',
        version: '0'
      }
    ],
    createBy: 'psi',
    createTime: '2023-02-09 02:20:36',
    effectiveTime: '2023-02-09 03:27:18',
    id: '1623386325943361538',
    isAuto: '0',
    isClosed: '0',
    isEffective: '1',
    isRubric: '0',
    isVoided: '0',
    payableCheckType: '2',
    remark: '',
    srcBillId: '',
    srcBillType: '',
    srcNo: '',
    subject: '3333333333',
    supplierId: '1623284221748748290',
    sysOrgCode: 'A01A05',
    updateBy: 'psi',
    updateTime: '2023-02-09 03:27:18',
    version: 0
  }
  payableCheck.modifyTableSubmit(
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


export function uncloseCheckPayable() {
  let params = {
    ids: ['1591974873476980738']
  }
  payableCheck.uncloseTable(
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

export function voidCheckPayable() {
  let params = {
    id: '1591974873476980738'
  }
  payableCheck.voidTable(
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

// 其他应付

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

export function addOtherTable() {
  let params = {
    billNo: 'CGAP-221110-666',
    billDate: '2022-01-13 00:00:00',
    checkedAmt: '0',
    createdBy: 'psi',
    id: '1590717742358511634',
    payableType: '201',
    supplierId: '1584950950470164481',
    amt: '0'
  }
  otherPayable.addTable(
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

export function deleteOtherPayable() {
  let params = {
    billNo: 'CGAP-221110-666',
    id: '1590717742358511634'
  }
  otherPayable.deleteTable(
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

export function exportOtherPayable() {
  let params = {}
  otherPayable.exportTable(
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

export function importOtherPayable() {
  let params = {}
  otherPayable.importTable(
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

export function modifyOtherPayable() {
  let params = {
    billNo: 'CGAP-221110-123'
  }
  otherPayable.modifyTable(
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

export function updateOtherPayable() {
  let params = {
    billNo: 'CGAP-2',
    id: '828777255517433866',
    isClosed: '0',
    isVoided: '0'
  }
  otherPayable.updateTable(
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

// 采购预付

export function getPayableTableByBillNO() {
  let params = {
    billNO: 'CGAP-221110-001'
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

export function listAllTable() {
  let params = {
    billDateEnd: '2023-02-13 00:00:00',
    pageIndex: '1',
    pageSize: '10'
  }
  finPayable.listAllTable(
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

export function exportPayableTable() {
  let params = {}
  finPayable.exportTable(
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
