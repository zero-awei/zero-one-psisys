/*
 * @Author: li.ziwei
 * @Date: 2023-02-19 17:03:44
 * @LastEditTime: 2023-02-19 19:36:44
 * @LastEditors: li.ziwei
 * @Description:
 * @FilePath: \psi-frontend\src\views\yingfuyufukuan\payables\methods.js
 * 可以输入预定的版权声明、个性签名、空行等
 */

/**
 * @author spk
 * @description 完善接口
 * @since 2023-03-01
 */

import Request from '@/apis/request.js'

// 定义一个功能模块基础url，方便替换
const currBaseUrl = '/payablemanagement/checkmanagement/'


//NOTE - 用于复制粘贴
/*
export function NAME(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'detail', data)
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
*/

//ANCHOR 新增应付核销单

export function newTable(data, success, fail) {
  Request.requestForm(Request.POST, currBaseUrl + 'add/{action}', data)
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

//ANCHOR 审核应付核销单

export function checkTable(data, success, fail) {
  Request.requestForm(Request.PUT, currBaseUrl + 'check', data)
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

//ANCHOR 关闭应付核销单（批量）

export function closeTable(data, success, fail) {
  Request.requestForm(Request.PUT, currBaseUrl + 'close', data)
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

//ANCHOR 删除应付核销单（批量）

export function deleteTable(data, success, fail) {
  Request.requestForm(Request.DELETE, currBaseUrl + 'delete', data)
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

//ANCHOR 查询指定单据详情信息（明细列表）

export function queryTableEntries(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'entry', data)
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

//ANCHOR 应付核销导出功能
//TODO 导入导出没有data怎么说

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

//ANCHOR 应付核销导入功能

export function importTable(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'import', data)
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

//ANCHOR 查询单据列表

export function listTable(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'list', data)
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

//ANCHOR 修改应付核销单

export function modifyTable(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'modify/{action}', data)
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

//ANCHOR 根据供应商ID查询应付单

export function queryPayableBySupplier(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'queryPayableBySupplier', data)
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

//ANCHOR 根据供应商ID查询付款单

export function queryPaymentBySupplier(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'queryPaymentBySupplier', data)
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


//ANCHOR 反关闭应付核销单（批量）

export function uncloseTable(data, success, fail) {
  Request.requestForm(Request.PUT, currBaseUrl + 'unclose', data)
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

//ANCHOR 作废应付核销单

export function voidTable(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'void', data)
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