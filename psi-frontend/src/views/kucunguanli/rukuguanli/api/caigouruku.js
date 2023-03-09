import Request from '@/apis/request.js'

// c5 查询单据列表（初始化页面 请求头为）
export function queryAll(data, success, fail) {
    Request.requestForm(Request.GET, '/query-cgrk-bill-list?', data)
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