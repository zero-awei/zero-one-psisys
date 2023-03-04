import Request from '@/apis/request.js'

// 定义一个功能模块基础url，方便替换
const currBaseUrl = '/payment/'

// j4 2.9 查询采购预付单功能
export function queryAll(data, success, fail) {
    Request.requestForm(Request.GET, currBaseUrl + 'query-all', data)
      .then((data) => {
        // 可以console.log(data) 在浏览器控制台查看数据
        console.log('后端返回data------',data)
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
// j4 2.2 关闭操作
export function close(data, success, fail) {
  Request.requestForm(Request.PUT, currBaseUrl + 'close', data)
    .then((data) => {
      // 可以console.log(data) 在浏览器控制台查看数据
      console.log('后端返回data------',data)
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
// j4 2.3 删除信息
export function deleteById(data, success, fail) {
  Request.requestForm(Request.DELETE, currBaseUrl + 'delete', data)
    .then((data) => {
      // 可以console.log(data) 在浏览器控制台查看数据
      console.log('后端返回data------',data)
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
// j4 2.4 修改采购预付单功能
export function edit(data, success, fail) {
  Request.requestForm(Request.PUT, currBaseUrl + 'edit', data)
    .then((data) => {
      // 可以console.log(data) 在浏览器控制台查看数据
      console.log('后端返回data------',data)
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
// j4 2.10 付款申请单分录列表查询
export function queryAllByBillno(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'query-all-by-billno', data)
    .then((data) => {
      // 可以console.log(data) 在浏览器控制台查看数据
      console.log('后端返回data------',data)
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
// j4 2.11 查看单据详情信息
export function queryOneHav(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'query-one-hav', data)
    .then((data) => {
      // 可以console.log(data) 在浏览器控制台查看数据
      console.log('后端返回data------',data)
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
// j4 2.13 反关闭操作
export function unclose(data, success, fail) {
  Request.requestForm(Request.PUT, currBaseUrl + 'unclose', data)
    .then((data) => {
      // 可以console.log(data) 在浏览器控制台查看数据
      console.log('后端返回data------',data)
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
// j4 2.14 作废操作
export function voidById(data, success, fail) {
  Request.requestForm(Request.PUT, currBaseUrl + 'void', data)
    .then((data) => {
      // 可以console.log(data) 在浏览器控制台查看数据
      console.log('后端返回data------',data)
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