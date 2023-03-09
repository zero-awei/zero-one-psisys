import Request from '@/apis/request.js'

// 定义一个功能模块基础url，方便替换
const currBaseUrl = '/purpaymentapply/'

// c4 1.查询单据列表
export function paymentApplyBill(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'paymentApplyBill', data)
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

// c4 2.查看指定单据详细信息
export function finPaymentReqEntry(data, success, fail) {
  Request.requestForm(Request.GET,currBaseUrl + 'finPaymentReqEntry',data)
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

// c4 3.添加采购付款申请单（保存/提交）
export function appPayment(data, success, fail) {
  Request.requestForm(Request.PUT,currBaseUrl + 'AppPayment',data)
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

// c4 4.修改采购付款申请单（保存/提交/审核）
//修改状态
export function changePayment(data, success, fail) {
  Request.requestForm(Request.POST,currBaseUrl + 'payment-change',data)
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
//修改内容
export function modPaymentReq(data, success, fail) {
    Request.requestForm(Request.PUT,currBaseUrl + 'paymentReq/mod',data)
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

// c4 5.删除采购付款申请单
export function deleteById(data, success, fail) {
  Request.requestForm(Request.DELETE, currBaseUrl + 'DePayment', data)
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


// c4 6.修改单据状态（关闭/作废/反关闭）
export function modifyPaymentStatus(data, success, fail) {
  Request.requestForm(Request.PUT, currBaseUrl + 'modify-payment-status', data)
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

// c4 7.导入
export function importPayment(data, success, fail) {
  Request.requestForm(Request.POST, currBaseUrl + 'payment-import', data)
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

// c4 8.导出
export function exportPayment(data, success, fail) {
  Request.requestForm(Request.POST, currBaseUrl + 'payment-export', data)
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

