import Request from '@/apis/request.js'
// 定义一个功能模块基础url，方便替换
const currBaseUrl = '/homepage/'

//处理中主要单据
export function getTableList(data, success, fail) {
    Request.requestForm(Request.GET, currBaseUrl + 'queryHomeDoingBill', data)
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

//2.查询供应商
export function getSupList(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'queryBasSupplier', data)
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

