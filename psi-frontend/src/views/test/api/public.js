import { queryBasBankAccount } from '@/apis/public/index.js'
import { queryInvoiceType } from '@/apis/public/index.js'
import { queryBillStage } from '@/apis/public/index.js'
import { queryPurchaseType } from '@/apis/public/index.js'
import { queryTaxType } from '@/apis/public/index.js'
import { queryTaxScaleType } from '@/apis/public/index.js'
import { queryInvoiceMethodType } from '@/apis/public/index.js'
import { queryTransportMethod } from '@/apis/public/index.js'
import { querySettleMethod } from '@/apis/public/index.js'
import { queryCurrencyType } from '@/apis/public/index.js'
import { queryDeliveryType } from '@/apis/public/index.js'
import { queryWarehouse } from '@/apis/public/index.js'
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

//6. 纳税规模下拉列表  | queryTaxScaleType
export const handleQueryTaxScaleType = () => {
  console.log('纳税规模下拉列表')
  queryTaxType(
    {},
    (data) => {
      console.log('接口数据', data)
    },
    () => {
      ElMessage.error('查询 纳税规模下拉列表 出现错误')
    }
  )
}
//7. 开票方式下拉列表  | queryInvoiceMethodType
export const handleQueryInvoiceMethodType = () => {
  console.log('开票方式下拉列表')
  queryTaxType(
    {},
    (data) => {
      console.log('接口数据', data)
    },
    () => {
      ElMessage.error('查询 开票方式下拉列表 出现错误')
    }
  )
}
//8. 运输方式下拉列表  |  queryTransportMethod
export const handleQueryTransportMethod = () => {
  console.log('运输方式下拉列表')
  queryTaxType(
    {},
    (data) => {
      console.log('接口数据', data)
    },
    () => {
      ElMessage.error('查询 运输方式下拉列表 出现错误')
    }
  )
}
//9. 结算方式下拉列表  | querySettleMethod
export const handleQuerySettleMethod = () => {
  console.log('结算方式下拉列表')
  queryTaxType(
    {},
    (data) => {
      console.log('接口数据', data)
    },
    () => {
      ElMessage.error('查询 结算方式下拉列表 出现错误')
    }
  )
}
//10. 货币类型下拉列表 | queryCurrencyType
export const handleQueryCurrencyType = () => {
  console.log('货币类型下拉列表')
  queryTaxType(
    {},
    (data) => {
      console.log('接口数据', data)
    },
    () => {
      ElMessage.error('查询 货币类型下拉列表 出现错误')
    }
  )
}
//11. 交货方式下拉列表 | queryDeliveryType
export const handleQueryDeliveryType = () => {
  console.log('交货方式下拉列表')
  queryTaxType(
    {},
    (data) => {
      console.log('接口数据', data)
    },
    () => {
      ElMessage.error('查询 交货方式下拉列表 出现错误')
    }
  )
}
//12. 仓库下拉列表   | queryWarehouse
export const handleQueryWarehouse = () => {
  console.log('仓库下拉列表')
  queryTaxType(
    {},
    (data) => {
      console.log('接口数据', data)
    },
    () => {
      ElMessage.error('查询 仓库下拉列表 出现错误')
    }
  )
}