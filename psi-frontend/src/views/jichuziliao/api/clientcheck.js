import Request from '@/apis/request.js'

const currBaseUrl = '/basedetail/customer-management/'
// j2 3.1 新增客户
export function addCustomer(data, success, fail) {
  Request.requestJson(Request.POST, currBaseUrl + 'add-Customer', data, {
    baseURL: import.meta.env.VITE_API_J2_BASE
  })
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

// j2 3.10 普通条件分页查询
export function queryCondition(data, success, fail) {
  Request.requestForm(Request.POST, currBaseUrl + 'query-condition', data, {
    baseURL: import.meta.env.VITE_API_J2_BASE
  })
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
