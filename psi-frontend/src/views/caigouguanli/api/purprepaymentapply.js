import Request from '@/apis/request.js'

// 定义一个功能模块基础url，方便替换
const currBaseUrl = '/purprepaymentapply/'

// c4 1.查询单据列表
export function getBillList(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'get-bill-list', data)
    .then((data) => {
      console.log('后端返回data----', data)
      // data是后端的响应示例
      // 可以console.log(data) 在浏览器控制台查看数据
      console.log(data)

      if (data.data) {
        success(data.data)
        return
      }
      fail(data.message)
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

// c4 2.查看指定单据
export function getDetailBill(data, success, fail) {
  Request.requestForm(Request.GET,currBaseUrl + 'get-detail-bill',data)
    .then((data) => {
      console.log('后端返回data----', data)
      // data是后端的响应示例
      // 可以console.log(data) 在浏览器控制台查看数据
      if (data.data) {
        success(data.data)
        return
      }
      fail(data.message)
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

// c4 3.采购订单列表
export function getPrepaybill(data, success, fail) {
  Request.requestForm(Request.GET,currBaseUrl + 'get-prepaybill',data)
    .then((data) => {
      console.log('后端返回data----', data)
      // data是后端的响应示例
      // 可以console.log(data) 在浏览器控制台查看数据
      if (data.data) {
        success(data.data)
        return
      }
      fail(data.message)
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

// c4 4.采购订单分列表
export function getPrepaybillDetail(data, success, fail) {
  Request.requestForm(Request.GET,currBaseUrl + 'get-prepaybill-detail',data)
    .then((data) => {
      console.log('后端返回data----', data)
      // data是后端的响应示例
      // 可以console.log(data) 在浏览器控制台查看数据
      if (data.data) {
        success(data.data)
        return
      }
      fail(data.message)
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

// c4 5.添加采购预付申请单
export function postAdd(data, success, fail) {
  Request.requestForm(Request.POST, currBaseUrl + 'post-add', data)
    .then((data) => {
      // 可以console.log(data) 在浏览器控制台查看数据
      if (data.data) {
        success(data.data)
        return
      }
      fail(data.message)
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

// c4 6.修改采购预付申请
export function putModifyPay(data, success, fail) {
  Request.requestForm(Request.PUT, currBaseUrl + 'put-modifyPay', data)
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

// c4 7.删除采购预付申请单
export function deleteMenu(data, success, fail) {
  Request.requestForm(Request.DELETE, currBaseUrl + 'delete-t-prepay-id', data)
    .then((data) => {
      // 可以console.log(data) 在浏览器控制台查看数据
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

// c4 8.采购预付申请修改单据状态(关闭/反关闭/作废)
export function modifyBillStatus(data, success, fail) {
  Request.requestForm(Request.PUT, currBaseUrl + 'modify-bill-status', data)
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

// c4 9.导入
export function payInto(data, success, fail) {
  Request.requestForm(Request.POST, currBaseUrl + 'pay-into', data)
    .then((data) => {
      // 可以console.log(data) 在浏览器控制台查看数据
      if (data.data) {
        success(data.data)
        return
      }
      fail(data.message)
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

// c4 10.导出
export function payExport(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'pay-export', data)
    .then((data) => {
      console.log('后端返回data----', data)
      // data是后端的响应示例
      // 可以console.log(data) 在浏览器控制台查看数据
      console.log(data)

      if (data.data) {
        success(data.data)
        return
      }
      fail(data.message)
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}