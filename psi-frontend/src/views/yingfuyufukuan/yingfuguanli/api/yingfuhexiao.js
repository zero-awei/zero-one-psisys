/*
 * @Author: li.ziwei
 * @Date: 2023-02-19 17:03:44
 * @LastEditTime: 2023-02-19 19:36:44
 * @LastEditors: li.ziwei
 * @Description:
 * @FilePath: \psi-frontend\src\views\yingfuyufukuan\payables\methods.js
 * 可以输入预定的版权声明、个性签名、空行等
 */
import Request from '@/apis/request.js'

// 定义一个功能模块基础url，方便替换
const currBaseUrl = '/fin-payable-check/'

// 7.1 单据详情
export function getTableDetail(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'detail', data)
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

// 7.2 列出所有单据
export function getTableList(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'list-all', data)
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

// 7.5 普通查询
export function query(data, success, fail) {
  Request.requestForm(Request.GET, currBaseUrl + 'query', data)
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
