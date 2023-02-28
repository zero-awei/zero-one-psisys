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
import { queryArea } from '@/apis/public/index.js'
import { queryMaterialType } from '@/apis/public/index.js'
import { queryPaymethodType } from '@/apis/public/index.js'
import { queryDeliverymethodType } from '@/apis/public/index.js'
import { querySuppliersName } from '@/apis/public/index.js'
import { querySuppliersLevel } from '@/apis/public/index.js'
import { querySupplierAdvancedCriteria } from '@/apis/public/index.js'
import { queryDepart } from '@/apis/public/index.js'
import { getUser } from '@/apis/public/index.js'
import { getMaterial } from '@/apis/public/index.js'
import { getDepart } from '@/apis/public/index.js'
import { queryBasWareHouseTreeList } from '@/apis/public/index.js'
import { queryMaterialTreeList } from '@/apis/public/index.js'
import { createReceipt } from '@/apis/public/index.js'

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
  queryTaxScaleType(
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
  queryInvoiceMethodType(
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
  queryTransportMethod(
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
  querySettleMethod(
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
  queryCurrencyType(
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
  queryDeliveryType(
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
  queryWarehouse(
    {},
    (data) => {
      console.log('接口数据', data)
    },
    () => {
      ElMessage.error('查询 仓库下拉列表 出现错误')
    }
  )
}
// 13. 选区数据（省市区）|  queryArea
// 14. 物料类型下拉列表 | queryMaterialType
export const handleQueryMaterialType = () => {
  console.log('物料类型下拉列表')
  queryMaterialType(
    {},
    (data) => {
      console.log('接口数据', data)
    },
    () => {
      ElMessage.error('查询 物料类型下拉列表 出现错误')
    }
  )
}
// 15. 付款方式下拉列表 | queryPaymethodType
export const handleQueryPaymethodType = () => {
  console.log('付款方式下拉列表')
  queryPaymethodType(
    {},
    (data) => {
      console.log('接口数据', data)
    },
    () => {
      ElMessage.error('查询 付款方式下拉列表 出现错误')
    }
  )
}
// 16. 交货方式下拉列表 | queryDeliverymethodType
export const handleQueryDeliverymethodType = () => {
  console.log('交货方式下拉列表')
  queryDeliverymethodType(
    {},
    (data) => {
      console.log('接口数据', data)
    },
    () => {
      ElMessage.error('查询 交货方式下拉列表 出现错误')
    }
  )
}
// 17. 供应商名称下拉列表 | querySuppliersName
export const handleQuerySuppliersName = () => {
  console.log('供应商名称下拉列表')
  querySuppliersName(
    {},
    (data) => {
      console.log('接口数据', data)
    },
    () => {
      ElMessage.error('查询 供应商名称下拉列表 出现错误')
    }
  )
}
// 18. 供应商等级下拉列表 | querySuppliersLevel
export const handleQuerySuppliersLevel = () => {
  console.log('供应商等级下拉列表')
  querySuppliersLevel(
    {},
    (data) => {
      console.log('接口数据', data)
    },
    () => {
      ElMessage.error('查询 供应商等级下拉列表 出现错误')
    }
  )
}
// 19. 供应商高级查询条件下拉列表 | querySupplierAdvancedCriteria
export const handleQuerySupplierAdvancedCriteria = () => {
  console.log('供应商高级查询条件下拉列表')
  querySupplierAdvancedCriteria(
    {},
    (data) => {
      console.log('接口数据', data)
    },
    () => {
      ElMessage.error('查询 供应商高级查询条件下拉列表 出现错误')
    }
  )
}
// 20. 下拉框获取部门列表 | queryDepart
export const handleQueryDepart = () => {
  console.log('下拉框获取部门列表')
  queryDepart(
    {},
    (data) => {
      console.log('接口数据', data)
    },
    () => {
      ElMessage.error('查询 下拉框获取部门列表 出现错误')
    }
  )
}

// 21. 选择用户  | getUser
// 22. 查询指定物料规格型号/单位 | getMaterial
// 23. 业务部门结构（用于输入查询条件）| getDepart
// 24. 仓库树状结构列表 | queryBasWareHouseTreeList
// 25. 物料分类树状结构列表 | queryMaterialTreeList
// 26. 请求新单据编号（根据新增类型生成新单据编号） | createReceipt