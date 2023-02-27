import Request from '@/apis/request.js'

// 定义一个功能模块基础url，方便替换
const currBaseUrl = '/addressbook/'

// j2 4.1 普通分页查询
export function queryAll(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'query-all', data)
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

// j2 4.3 根据姓名和工号查询通讯录
export function query(data, success, fail) {
  Request.requestForm(
    Request.GET,
    currBaseUrl + 'query-realname-and-workno',
    data
  )
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
