import { queryBasBankAccount } from '@/apis/public/index.js'

// 测试公共接口
export const handleQueryBasBankAccount = () => {
  console.log('查询供应商资金账户下拉列表')
  queryBasBankAccount(
    {},
    (data) => {
      console.log('接口数据', data)
    },
    () => {
      ElMessage.error('查询 供应商资金账户下拉列表 出现错误')
    }
  )
}
