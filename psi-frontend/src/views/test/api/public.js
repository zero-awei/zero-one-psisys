import { queryBasBankAccount } from '@/apis/public/index.js'
import { queryInvoiceType } from '@/apis/public/index.js'
import { queryBillStage } from '@/apis/public/index.js'
import { queryPurchaseType } from '@/apis/public/index.js'
import { queryTaxType } from '@/apis/public/index.js'
//1. 供应商资金账户下拉列表 |  queryBasBankAccount
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
//2. 发票类型下拉列表       | queryInvoiceType
export const handleQueryInvoiceType = () => {
  console.log('发票类型下拉列表')
  queryInvoiceType(
    {},
    (data) => {
      console.log('接口数据', data)
    },
    () => {
      ElMessage.error('查询 发票类型下拉列表 出现错误')
    }
  )
}
//3. 单据阶段下拉列表      |  queryBillStage
export const handleQueryBillStage = () => {
  console.log('单据阶段下拉列表')
  queryBillStage(
    {},
    (data) => {
      console.log('接口数据', data)
    },
    () => {
      ElMessage.error('查询 单据阶段下拉列表 出现错误')
    }
  )
}
//4. 采购类型下拉列表      |  queryPurchaseType
export const handleQueryPurchaseType = () => {
  console.log('采购类型下拉列表')
  queryPurchaseType(
    {},
    (data) => {
      console.log('接口数据', data)
    },
    () => {
      ElMessage.error('查询 采购类型下拉列表 出现错误')
    }
  )
}
//5. 税率下拉列表         |  queryTaxType
export const handleQueryTaxType = () => {
  console.log('税率下拉列表')
  queryTaxType(
    {},
    (data) => {
      console.log('接口数据', data)
    },
    () => {
      ElMessage.error('查询 税率下拉列表 出现错误')
    }
  )
}
