import Request from '@/apis/request.js'

// 定义一个功能模块基础url，方便替换
const currBaseUrl = '/systemmanagement/sys-depart/'

// export function addMenu(data, success, fail) {
//   Request.requestForm().then().catch()
// }
// 4.1 新增
export function addOri(data, success, fail) {
  Request.requestForm(Request.POST, currBaseUrl + 'insert', data)
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
