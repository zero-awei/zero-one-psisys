/**
 * @author spk
 * @description 采购预付apis
 * @since 2023-03-01
 * @path src/views/yingfuyufukuan/yingfuguanli/api/caigouyingfu.js
 */

import Request from '@/apis/request.js'

const currBaseUrl = '/payablemanagement/purchasemanagement/'


// TODO 采购预付导出功能，不用请求参数

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

// ANCHOR 查看单据详情

export function getTableByBillNO(data, success, fail) {
  Request.requestForm(
    Request.GET,
    currBaseUrl + 'query/get/select/purchase/detail',
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

//ANCHOR 分页查询所有数据

export function listAllTable(data, success, fail) {
  Request.requestForm(
    Request.GET,
    currBaseUrl + 'query/list/select/purchase/all',
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