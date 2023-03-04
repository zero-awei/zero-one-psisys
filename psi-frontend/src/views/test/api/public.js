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
// {
// 	"id": 1,
// 	"value": "1584913699556106242"
// }
// {
//       label: '部门1',
//       value: '1'
//     },
export const handleQueryBasBankAccount = () => {
  console.log('查询供应商资金账户下拉列表')
  queryBasBankAccount(
    {},
    (data) => {
      const list = []
      if (!localStorage.getItem('BasBankAccount')) {
        data.forEach((item) => {
          let temp = {}
          temp.label = item.value
          temp.value = item.id.toString()
          list.push(temp)
          // this.BasBankAccount.push(temp)
        })
        localStorage.setItem('BasBankAccount', list)
        // localStorage.setItem('BasBankAccount', this.BasBankAccount)
      }
    },
    () => {
      ElMessage.error('查询 供应商资金账户下拉列表 出现错误')
    }
  )
}
//2. 发票类型下拉列表       | queryInvoiceType
// "id": 1,
// 	"name": "审核中"
export const handleQueryInvoiceType = () => {
  console.log('发票类型下拉列表')
  queryInvoiceType(
    {},
    (data) => {
      const list = []
      if (!localStorage.getItem('InvoiceType')) {
        data.forEach((item) => {
          let temp = {}
          temp.label = item.name
          temp.value = item.id.toString()
          list.push(temp)
        })
        localStorage.setItem('InvoiceType', list)
      }
    },
    () => {
      ElMessage.error('查询 发票类型下拉列表 出现错误')
    }
  )
}
//3. 单据阶段下拉列表      |  queryBillStage
// {
// 	"id": -81367038,
// 	"name": "核批完"
// },
export const handleQueryBillStage = () => {
  console.log('单据阶段下拉列表')
  queryBillStage(
    {},
    (data) => {
      const list = []
      if (!localStorage.getItem('BillStage')) {
        data.forEach((item) => {
          let temp = {}
          temp.label = item.name
          temp.value = item.id.toString()
          list.push(temp)
        })
        localStorage.setItem('BillStage', list)
      }
    },
    () => {
      ElMessage.error('查询 单据阶段下拉列表 出现错误')
    }
  )
}
//4. 采购类型下拉列表      |  queryPurchaseType
// {
// 	"id": 1349517314,
// 	"name": "生产原料"
// },
export const handleQueryPurchaseType = () => {
  console.log('采购类型下拉列表')
  queryPurchaseType(
    {},
    (data) => {
      const list = []
      if (!localStorage.getItem('PurchaseType')) {
        data.forEach((item) => {
          let temp = {}
          temp.label = item.name
          temp.value = item.id.toString()
          list.push(temp)
        })
        localStorage.setItem('PurchaseType', list)
      }
    },
    () => {
      ElMessage.error('查询 采购类型下拉列表 出现错误')
    }
  )
}
//5. 税率下拉列表         |  queryTaxType
// {
// 	"id": -2131726335,
// 	"rate": "13"
// },
export const handleQueryTaxType = () => {
  console.log('税率下拉列表')
  queryTaxType(
    {},
    (data) => {
      const list = []
      if (!localStorage.getItem('TaxType')) {
        data.forEach((item) => {
          let temp = {}
          temp.label = item.rate
          temp.value = item.id.toString()
          list.push(temp)
        })
        localStorage.setItem('TaxType', list)
      }
    },
    () => {
      ElMessage.error('查询 税率下拉列表 出现错误')
    }
  )
}

//6. 纳税规模下拉列表  | queryTaxScaleType
// {
// 	"id": 2120617985,
// 	"name": "一般纳税人"
// }
export const handleQueryTaxScaleType = () => {
  console.log('纳税规模下拉列表')
  queryTaxScaleType(
    {},
    (data) => {
      const list = []
      if (!localStorage.getItem('TaxScaleType')) {
        data.forEach((item) => {
          let temp = {}
          temp.label = item.name
          temp.value = item.id.toString()
          list.push(temp)
        })
        localStorage.setItem('TaxScaleType', list)
      }
    },
    () => {
      ElMessage.error('查询 纳税规模下拉列表 出现错误')
    }
  )
}
//7. 开票方式下拉列表  | queryInvoiceMethodType
// {
// 	"id": 1,
// 	"name": "审核中"
// }
export const handleQueryInvoiceMethodType = () => {
  console.log('开票方式下拉列表')
  queryInvoiceMethodType(
    {},
    (data) => {
      const list = []
      if (!localStorage.getItem('InvoiceMethodType')) {
        data.forEach((item) => {
          let temp = {}
          temp.label = item.name
          temp.value = item.id.toString()
          list.push(temp)
        })
        localStorage.setItem('InvoiceMethodType', list)
      }
    },
    () => {
      ElMessage.error('查询 开票方式下拉列表 出现错误')
    }
  )
}
//8. 运输方式下拉列表  |  queryTransportMethod
// {
// 	"id": 1,
// 	"name": "审核中"
// }
export const handleQueryTransportMethod = () => {
  console.log('运输方式下拉列表')
  queryTransportMethod(
    {},
    (data) => {
      const list = []
      if (!localStorage.getItem('TransportMethod')) {
        data.forEach((item) => {
          let temp = {}
          temp.label = item.name
          temp.value = item.id.toString()
          list.push(temp)
        })
        localStorage.setItem('TransportMethod', list)
      }
    },
    () => {
      ElMessage.error('查询 运输方式下拉列表 出现错误')
    }
  )
}
//9. 结算方式下拉列表  | querySettleMethod
//  {
// 		"id": 1,
// 		"name": "审核中"
// 	}
export const handleQuerySettleMethod = () => {
  console.log('结算方式下拉列表')
  querySettleMethod(
    {},
    (data) => {
      const list = []
      if (!localStorage.getItem('SettleMethod')) {
        data.forEach((item) => {
          let temp = {}
          temp.label = item.name
          temp.value = item.id.toString()
          list.push(temp)
        })
        localStorage.setItem('SettleMethod', list)
      }
    },
    () => {
      ElMessage.error('查询 结算方式下拉列表 出现错误')
    }
  )
}
//10. 货币类型下拉列表 | queryCurrencyType
// {
// 	"id": "1250264330398093314",
// 	"name": "人民币"
// },
export const handleQueryCurrencyType = () => {
  console.log('货币类型下拉列表')
  queryCurrencyType(
    {},
    (data) => {
      const list = []
      if (!localStorage.getItem('CurrencyType')) {
        data.forEach((item) => {
          let temp = {}
          temp.label = item.name
          temp.value = item.id.toString()
          list.push(temp)
        })
        localStorage.setItem('CurrencyType', list)
      }
    },
    () => {
      ElMessage.error('查询 货币类型下拉列表 出现错误')
    }
  )
}
//11. 交货方式下拉列表 | queryDeliveryType
// {
// 	"id": 1,
// 	"name": "送货上门"
// }
export const handleQueryDeliveryType = () => {
  console.log('交货方式下拉列表')
  queryDeliveryType(
    {},
    (data) => {
      const list = []
      if (!localStorage.getItem('DeliveryType')) {
        data.forEach((item) => {
          let temp = {}
          temp.label = item.name
          temp.value = item.id.toString()
          list.push(temp)
        })
        localStorage.setItem('DeliveryType', list)
      }
    },
    () => {
      ElMessage.error('查询 交货方式下拉列表 出现错误')
    }
  )
}
//12. 仓库下拉列表   | queryWarehouse
// {
// 	"id": "1584936383497183234",
// 	"name": "01 一号仓库"
// },
export const handleQueryWarehouse = () => {
  console.log('仓库下拉列表')
  queryWarehouse(
    {},
    (data) => {
      const list = []
      if (!localStorage.getItem('Warehouse')) {
        data.forEach((item) => {
          let temp = {}
          temp.label = item.name
          temp.value = item.id.toString()
          list.push(temp)
        })
        localStorage.setItem('Warehouse', list)
      }
    },
    () => {
      ElMessage.error('查询 仓库下拉列表 出现错误')
    }
  )
}
// TODO 13. 选区数据（省市区）|  queryArea
// {
// 	"name": "1230769620021972993"
// },
// export const handleQueryArea = () => {
//   console.log('选区数据（省市区）')
//   queryArea(
//     {},
//     (data) => {
//       const list=[]
//       if (!localStorage.getItem('Area')) {
//         data.forEach((item) => {
//           let temp = {}
//           temp.label = item.name
//           temp.value = item.name
//           list.push(temp)
//         })
//         localStorage.setItem('Area', list)
//       }
//     },
//     () => {
//       ElMessage.error('查询 选区数据（省市区） 出现错误')
//     }
//   )
// }

// 14. 物料类型下拉列表 | queryMaterialType
// 	"id": "123",
// 	"name": "01图灵"
// }
export const handleQueryMaterialType = () => {
  console.log('物料类型下拉列表')
  queryMaterialType(
    {},
    (data) => {
      const list = []
      if (!localStorage.getItem('MaterialType')) {
        data.forEach((item) => {
          let temp = {}
          temp.label = item.name
          temp.value = item.id.toString()
          list.push(temp)
        })
        localStorage.setItem('MaterialType', list)
      }
    },
    () => {
      ElMessage.error('查询 物料类型下拉列表 出现错误')
    }
  )
}
// TODO 15. 付款方式下拉列表 | queryPaymethodType
// {
// 	"dict_id": "",
// 	"id": "123",
// 	"name": "01图灵"
// }
export const handleQueryPaymethodType = () => {
  console.log('付款方式下拉列表')
  queryPaymethodType(
    {},
    (data) => {
      const list = []
      if (!localStorage.getItem('PaymethodType')) {
        data.forEach((item) => {
          let temp = {}
          temp.label = item.name
          temp.value = item.id.toString()
          list.push(temp)
        })
        localStorage.setItem('PaymethodType', list)
      }
    },
    () => {
      ElMessage.error('查询 付款方式下拉列表 出现错误')
    }
  )
}
// 16. 交货方式下拉列表 | queryDeliverymethodType
// {
// 	"dict_id": "",
// 	"id": "123",
// 	"name": "01图灵"
// }
export const handleQueryDeliverymethodType = () => {
  console.log('交货方式下拉列表')
  queryDeliverymethodType(
    {},
    (data) => {
      const list = []
      if (!localStorage.getItem('DeliverymethodType')) {
        data.forEach((item) => {
          let temp = {}
          temp.label = item.name
          temp.value = item.id.toString()
          list.push(temp)
        })
        localStorage.setItem('DeliverymethodType', list)
      }
    },
    () => {
      ElMessage.error('查询 交货方式下拉列表 出现错误')
    }
  )
}
// 17. 供应商名称下拉列表 | querySuppliersName
// {
// 	"id": "111",
// 	"name": "qwyed"
// }
export const handleQuerySuppliersName = () => {
  console.log('供应商名称下拉列表')
  querySuppliersName(
    {},
    (data) => {
      const list = []
      if (!localStorage.getItem('SuppliersName')) {
        data.forEach((item) => {
          let temp = {}
          temp.label = item.name
          temp.value = item.id.toString()
          list.push(temp)
        })
        localStorage.setItem('SuppliersName', list)
      }
    },
    () => {
      ElMessage.error('查询 供应商名称下拉列表 出现错误')
    }
  )
}
// 18. 供应商等级下拉列表 | querySuppliersLevel
// {
//   "id": -765018110,
//   "name": "一级"
// }
export const handleQuerySuppliersLevel = () => {
  console.log('供应商等级下拉列表')
  querySuppliersLevel(
    {},
    (data) => {
      const list = []
      if (!localStorage.getItem('SuppliersLevel')) {
        data.forEach((item) => {
          let temp = {}
          temp.label = item.name
          temp.value = item.id.toString()
          list.push(temp)
        })
        localStorage.setItem('SuppliersLevel', list)
      }
    },
    () => {
      ElMessage.error('查询 供应商等级下拉列表 出现错误')
    }
  )
}

// 19. 供应商高级查询条件下拉列表 | querySupplierAdvancedCriteria
// {
//   "id": 37,
//   "name": "纳税规模"
// }
export const handleQuerySupplierAdvancedCriteria = () => {
  console.log('供应商高级查询条件下拉列表')
  querySupplierAdvancedCriteria(
    {},
    (data) => {
      const list = []
      if (!localStorage.getItem('SupplierAdvancedCriteria')) {
        data.forEach((item) => {
          let temp = {}
          temp.label = item.name
          temp.value = item.id.toString()
          list.push(temp)
        })
        localStorage.setItem('SupplierAdvancedCriteria', list)
      }
    },
    () => {
      ElMessage.error('查询 供应商高级查询条件下拉列表 出现错误')
    }
  )
}

// 20. 下拉框获取部门列表 | queryDepart
//c1组无此接口
// export const handleQueryDepart = () => {
//   console.log('下拉框获取部门列表')
//   queryDepart(
//     {},
//     (data) => {
//       const list=[]
//       if (!localStorage.getItem('Depart')) {
//         data.forEach((item) => {
//           let temp = {}
//           temp.label = item.name
//           temp.value = item.id.toString()
//           list.push(temp)
//         })
//         localStorage.setItem('Depart', list)
//       }
//     },
//     () => {
//       ElMessage.error('查询 下拉框获取部门列表 出现错误')
//     }
//   )
// }

// TODO 21. 选择用户  | getUser 不确定
// {
//   "pageIndex": 1,
//   "pageSize": 1,
//   "pages": 0,
//   "rows": [
//     {
//       "department": "naowubu",
//       "id": 1,
//       "realname": "awei",
//       "sex": "man",
//       "username": "awei"
//     },
//     {
//       "department": "naowubu",
//       "id": 1,
//       "realname": "awei",
//       "sex": "man",
//       "username": "awei"
//     },
//     {
//       "department": "naowubu",
//       "id": 1,
//       "realname": "awei",
//       "sex": "man",
//       "username": "awei"
//     }
//   ],
//   "total": 0
// }
export const handleGetUser = () => {
  console.log('选择用户')
  getUser(
    {},
    (data) => {
      const list = []
      if (!localStorage.getItem('User')) {
        data.rows.forEach((item) => {
          let temp = {}
          temp.label = item.username
          temp.value = item.id.toString()
          list.push(temp)
        })
        localStorage.setItem('User', list)
      }
    },
    () => {
      ElMessage.error('选择用户 出现错误')
    }
  )
}
// TODO 22. 查询指定物料规格型号/单位 | getMaterial 不确定
// {
//   "pageIndex": 1,
//   "pageSize": 1,
//   "pages": 0,
//   "rows": [
//     {
//       "auxName": "aa",
//       "categoryId": 90,
//       "categoryIdDictText": "",
//       "code": 111,
//       "createBy": "a",
//       "createTime": "",
//       "id": 1,
//       "isEnabledDictText": "a",
//       "model": "500L",
//       "name": "aaa",
//       "price": 114514,
//       "remake": "",
//       "taxCode": "1919810",
//       "unitIdDictText": "a",
//       "updateBy": "",
//       "updateTime": ""
//     },
//     {
//       "auxName": "aa",
//       "categoryId": 90,
//       "categoryIdDictText": "",
//       "code": 111,
//       "createBy": "a",
//       "createTime": "",
//       "id": 1,
//       "isEnabledDictText": "a",
//       "model": "500L",
//       "name": "aaa",
//       "price": 114514,
//       "remake": "",
//       "taxCode": "1919810",
//       "unitIdDictText": "a",
//       "updateBy": "",
//       "updateTime": ""
//     },
//     {
//       "auxName": "aa",
//       "categoryId": 90,
//       "categoryIdDictText": "",
//       "code": 111,
//       "createBy": "a",
//       "createTime": "",
//       "id": 1,
//       "isEnabledDictText": "a",
//       "model": "500L",
//       "name": "aaa",
//       "price": 114514,
//       "remake": "",
//       "taxCode": "1919810",
//       "unitIdDictText": "a",
//       "updateBy": "",
//       "updateTime": ""
//     }
//   ],
//   "total": 0
// }
// export const handleGetMaterial = () => {
//   console.log('查询指定物料规格型号')
//   getMaterial(
//     {},
//     (data) => {
//       const list=[]
//       if (!localStorage.getItem('SuppliersName')) {
//         data.forEach((item) => {
//           let temp = {}
//           temp.label = item.name
//           temp.value = item.id.toString()
//           list.push(temp)
//         })
//         localStorage.setItem('SuppliersName', list)
//       }
//     },
//     () => {
//       ElMessage.error('查询指定物料规格型号 出现错误')
//     }
//   )
// }

// 23. 业务部门结构（用于输入查询条件）| getDepart
// {
//   "departname": "yingxiaobu",
//   "id": 1
// }
export const handleGetDepart = () => {
  console.log('业务部门结构（用于输入查询条件）')
  getDepart(
    {},
    (data) => {
      const list = []
      if (!localStorage.getItem('DepartName')) {
        data.forEach((item) => {
          let temp = {}
          temp.label = item.departname
          temp.value = item.id.toString()
          list.push(temp)
        })
        localStorage.setItem('DepartName', list)
      }
    },
    () => {
      ElMessage.error('查询 业务部门结构（用于输入查询条件） 出现错误')
    }
  )
}
// TODO 24. 仓库树状结构列表 | queryBasWareHouseTreeList
// export const handleQueryBasWareHouseTreeList = () => {
//   console.log('仓库树状结构列表')
//   queryBasWareHouseTreeList(
//     {},
//     (data) => {
//       const list=[]
//       if (!localStorage.getItem('SuppliersName')) {
//         data.forEach((item) => {
//           let temp = {}
//           temp.label = item.name
//           temp.value = item.id.toString()
//           list.push(temp)
//         })
//         localStorage.setItem('SuppliersName', list)
//       }
//     },
//     () => {
//       ElMessage.error('查询 仓库树状结构列表 出现错误')
//     }
//   )
// }

// TODO 25. 物料分类树状结构列表 | queryMaterialTreeList
// export const handleQueryMaterialTreeList = () => {
//   console.log('物料分类树状结构列表')
//   queryMaterialTreeList(
//     {},
//     (data) => {
//       const list=[]
//       if (!localStorage.getItem('SuppliersName')) {
//         data.forEach((item) => {
//           let temp = {}
//           temp.label = item.name
//           temp.value = item.id.toString()
//           list.push(temp)
//         })
//         localStorage.setItem('SuppliersName', list)
//       }
//     },
//     () => {
//       ElMessage.error('查询 物料分类树状结构列表 出现错误')
//     }
//   )
// }

// TODO 26. 请求新单据编号（根据新增类型生成新单据编号） | createReceipt
// {
//   "result": "CGSQ-230214-034"
// }
export const handleCreateReceipt = () => {
  console.log('请求新单据编号（根据新增类型生成新单据编号）')
  createReceipt(
    {},
    (data) => {
      const list = []
      if (!localStorage.getItem('CreateReceipt')) {
        data.forEach((item) => {
          let temp = {}
          temp.label = item.result
          temp.value = item.result
          list.push(temp)
        })
        localStorage.setItem('CreateReceipt', list)
      }
    },
    () => {
      ElMessage.error(
        '查询 请求新单据编号（根据新增类型生成新单据编号） 出现错误'
      )
    }
  )
}
//公共接口测试
