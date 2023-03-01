import * as payableCheck from '@/views/yingfuyufukuan/yingfuguanli/api/yingfuhexiao.js'
import { ElMessage } from 'element-plus'


export function queryTableEntries() {
  let params = {
    mainid: '1591811712127950850'
  }
  payableCheck.queryTableEntries(
    params,
    (data) => {
      console.log('请求data: ', data)
    },
    (msg) => {
      console.log('msg', msg)
      ElMessage.error('错误信息')
    }
  )
}

export function listTable() {

}

export function queryPayableBySupplier() {

}

export function queryPaymentBySupplier() {

}