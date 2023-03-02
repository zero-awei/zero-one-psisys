/**
 * @author spk
 * @description 其他应付apis
 * @since 2023-03-01
 * @path src/views/yingfuyufukuan/yingfuguanli/api/qitayingfu.js
 */

import Request from '@/apis/request.js'

const currBaseUrl = '/payablemanagement/othermanagement/'

//ANCHOR 添加其他应付单

export function addTable(data, success, fail) {
  Request.requestForm(Request.POST, currBaseUrl + 'addOtherPayable', data)
    .then((data) => {
      if (data.data) {
        success(data.data)
        return
      }
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

// TODO 删除其他应付单，等待后端修改bug

export function deleteTable(data, success, fail) {
  Request.requestForm(Request.DELETE, currBaseUrl + 'deleteOtherPayable', data)
    .then((data) => {
      if (data.data) {
        success(data.data)
        return
      }
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

// TODO 其他应付导出功能

export function exportTable(data, success, fail) {
  Request.requestForm(Request.POST, currBaseUrl + 'export', data)
    .then((data) => {
      if (data.data) {
        success(data.data)
        return
      }
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

// TODO 其他应付导入功能

export function importTable(data, success, fail) {
  Request.requestForm(Request.POST, currBaseUrl + 'import', data)
    .then((data) => {
      if (data.data) {
        success(data.data)
        return
      }
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

// ANCHOR 根据条件分页查询

export function listOtherTable(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'query-all', data)
    .then((data) => {
      if (data.data) {
        success(data.data)
        return
      }
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

// ANCHOR 示例单据编号查询

export function getTableByBillNo(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'query-one', data)
    .then((data) => {
      if (data.data) {
        success(data.data)
        return
      }
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

// ANCHOR 修改其他应付单

export function modifyTable(data, success, fail) {
  Request.requestForm(Request.PUT, currBaseUrl + 'updateOtherPayable', data)
    .then((data) => {
      if (data.data) {
        success(data.data)
        return
      }
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

// ANCHOR 更新其他应付单状态

export function updateTable(data, success, fail) {
  Request.requestForm(
    Request.PUT,
    currBaseUrl + 'updateOtherPayableStatus',
    data
  )
    .then((data) => {
      if (data.data) {
        success(data.data)
        return
      }
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}
