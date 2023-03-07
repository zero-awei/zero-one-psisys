/*
 * @Author: 160405103 1348313766@qq.com
 * @Date: 2023-02-07 13:55:16
 * @LastEditors: 160405103 1348313766@qq.com
 * @LastEditTime: 2023-03-06 15:25:00
 * @FilePath: \psi-frontend\src\apis\login\index.js
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
import Request from '../request'
import { userStore } from '@/stores/user'

// 定义一个功能模块基础url，方便替换
const currBaseUrl = '/login/'

/**
 * 登录接口
 * @param data 登录数据
 * @param success 登录成功回调
 * @param fail 登录失败回调
 */
export const login = (data, success, fail) => {
  const $store = userStore()
  Request.requestForm(Request.POST, currBaseUrl + 'auth-login', data, {
    baseURL: import.meta.env.VITE_API_J1_LOGIN
  })
    .then((data) => {
      // 记录Token到本地
      if (data.data) {
        $store.setToken(data.data)
        // 执行成功回调
        success()
        return
      }
      // 执行失败回调
      fail(data.message)
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}
