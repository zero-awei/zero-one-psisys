/*
 * @Author: 160405103 1348313766@qq.com
 * @Date: 2023-02-26 14:32:14
 * @LastEditors: 160405103 1348313766@qq.com
 * @LastEditTime: 2023-03-17 15:53:57
 * @FilePath: \psi-frontend\src\views\jichuziliao\api\account.js
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
import Request from '@/apis/request.js'

const currBaseUrl = '/'
// j2 3.1 新增账号
export function addCustomer(data, success, fail) {
  Request.requestJson(
    Request.POST,
    currBaseUrl + 'query-bankaccount-list',
    data,
    {
      baseURL: import.meta.env.VITE_API_J2_BASE
    }
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

// j2 3.10 普通条件分页查询
export function queryCondition(data, success, fail) {
  Request.requestForm(
    Request.POST,
    currBaseUrl + 'query-bankaccount-list',
    data,
    {
      baseURL: import.meta.env.VITE_API_C1
    }
  )
    .then((data) => {
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
