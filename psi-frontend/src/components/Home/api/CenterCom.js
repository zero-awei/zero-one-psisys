import Request from '@/apis/request.js'
// 定义一个功能模块基础url，方便替换
const currBaseUrl = '/homepage/onl-cgreport-head'

//1.系统收支概况
export function getSysList(data, success, fail) {
    Request.requestForm(Request.GET, currBaseUrl + 'query-Sys', data)
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

//2.查询客户数量概况
export function getCusList(data, success, fail) {
    Request.requestForm(Request.GET, currBaseUrl + 'query-Customer', data)
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


