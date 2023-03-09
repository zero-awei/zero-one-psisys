/*
 * @Author: 160405103 1348313766@qq.com
 * @Date: 2023-02-23 17:13:14
 * @LastEditors: 160405103 1348313766@qq.com
 * @LastEditTime: 2023-02-25 15:35:12
 * @FilePath: \psi-frontend\src\stores\path.js
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
import { defineStore } from 'pinia'
import {
  queryBasBankAccount,
  queryInvoiceType,
  queryBillStage,
  queryPurchaseType,
  queryTaxType,
  queryTaxScaleType,
  queryInvoiceMethodType,
  queryTransportMethod,
  querySettleMethod,
  queryCurrencyType,
  queryDeliveryType,
  queryWarehouse,
  queryMaterialType,
  queryPaymethodType,
  queryDeliverymethodType,
  querySuppliersName,
  querySuppliersLevel,
  querySupplierAdvancedCriteria,
  queryDepart
} from '../apis/public/index'
export const publickStore = defineStore('path', {
  state: () => ({
    BasBankAccount: [], // 供应商资金账户下拉列表
    InvoiceType: [], // 发票类型下拉列表
    BillStage: [], // 单据阶段下拉列表
    PurchaseType: [], // 采购类型下拉列表
    TaxType: [], // 税率下拉列表
    TaxScaleType: [], // 纳税规模下拉列表
    InvoiceMethodType: [], //开票方式下拉列表
    TransportMethod: [], // 运输方式下拉列表
    SettleMethod: [], // 结算方式下拉列表
    CurrencyType: [], // 货币类型下拉列表
    DeliveryType: [], //  交货方式下拉列表
    Warehouse: [], // 仓库下拉列表
    MaterialType: [], // 物料类型下拉列表
    PaymethodType: [], // 付款方式下拉列表
    DeliverymethodType: [], // 交货方式下拉列表
    SuppliersName: [], // 供应商名称下拉列表
    SuppliersLevel: [], //供应商等级下拉列表
    SupplierAdvancedCriteria: [], //供应商高级查询条件下拉列表
    Depart: [] // 部门列表
  }),
  getters: {
    getBasBankAccount: (state) =>
      state.BasBankAccount || localStorage.getItem('BasBankAccount'),
    getInvoiceType: (state) =>
      state.InvoiceType || localStorage.getItem('InvoiceType'),
    getBillStage: (state) =>
      state.BillStage || localStorage.getItem('BillStage'),
    getPurchaseType: (state) =>
      state.PurchaseType || localStorage.getItem('PurchaseType'),
    getTaxType: (state) => state.TaxType || localStorage.getItem('TaxType'),
    getTaxScaleType: (state) =>
      state.TaxScaleType || localStorage.getItem('TaxScaleType'),
    getInvoiceMethodType: (state) =>
      state.InvoiceMethodType || localStorage.getItem('InvoiceMethodType'),
    getTransportMethod: (state) =>
      state.TransportMethod || localStorage.getItem('TransportMethod'),
    getSettleMethod: (state) =>
      state.SettleMethod || localStorage.getItem('SettleMethod'),
    getCurrencyType: (state) =>
      state.CurrencyType || localStorage.getItem('CurrencyType'),
    getDeliveryType: (state) =>
      state.DeliveryType || localStorage.getItem('DeliveryType'),
    getWarehouse: (state) =>
      state.Warehouse || localStorage.getItem('Warehouse'),
    getMaterialType: (state) =>
      state.MaterialType || localStorage.getItem('MaterialType'),
    getPaymethodType: (state) =>
      state.PaymethodType || localStorage.getItem('PaymethodType'),
    getDeliverymethodType: (state) =>
      state.DeliverymethodType || localStorage.getItem('DeliverymethodType'),
    getSuppliersName: (state) =>
      state.SuppliersName || localStorage.getItem('SuppliersName'),
    getSuppliersLevel: (state) =>
      state.SuppliersLevel || localStorage.getItem('SuppliersLevel'),
    getSupplierAdvancedCriteria: (state) =>
      state.SupplierAdvancedCriteria ||
      localStorage.getItem('SupplierAdvancedCriteria'),
    getDepart: (state) => state.Depart || localStorage.getItem('Depart')
  },
  actions: {
    async doQueryAll() {
      await this.doQueryBasBankAccount
      await this.doQueryInvoiceType
      await this.doQueryBillStage
      await this.doQueryPurchaseType
      await this.doQueryTaxType
      await this.doQueryTaxScaleType
      await this.doQueryInvoiceMethodType
      await this.doQueryTransportMethod
      await this.doQuerySettleMethod
      await this.doQueryCurrencyType
      await this.doQueryDeliveryType
      await this.doQueryWarehouse
      await this.doQueryMaterialType
      await this.doQueryPaymethodType
      await this.doQueryDeliverymethodType
      await this.doQuerySuppliersName
      await this.doQuerySuppliersLevel
      await this.doQuerySupplierAdvancedCriteria
      await this.doQueryDepart
    },
    // 1.查询供应商资金账户下拉列表
    // {
    // 	"id": 1,
    // 	"value": "1584913699556106242"
    // }
    // {
    //       label: '部门1',
    //       value: '1'
    //     },
    doQueryBasBankAccount() {
      console.log('查询供应商资金账户下拉列表')
      queryBasBankAccount(
        {},
        (data) => {
          if (!localStorage.getItem('BasBankAccount')) {
            data.forEach((item) => {
              let temp = {}
              temp.label = item.value
              temp.value = item.id.toString()
              this.BasBankAccount.push(temp)
            })
            localStorage.setItem('BasBankAccount', this.BasBankAccount)
          }
        },
        () => {
          ElMessage.error('查询 供应商资金账户下拉列表 出现错误')
        }
      )
    },

    // 2. 发票类型下拉列表
    // "id": 1,
    // 	"name": "审核中"
    doQueryInvoiceType() {
      queryInvoiceType(
        {},
        (data) => {
          if (!localStorage.getItem('InvoiceType')) {
            data.forEach((item) => {
              let temp = {}
              temp.label = item.name
              temp.value = item.id.toString()
              this.InvoiceType.push(temp)
            })
            localStorage.setItem('InvoiceType', this.InvoiceType)
          }
        },
        () => {
          ElMessage.error('查询 发票类型下拉列表 出现错误')
        }
      )
    },

    // 3.单据阶段下拉列表
    // {
    // 	"id": -81367038,
    // 	"name": "核批完"
    // },
    doQueryBillStage() {
      queryBillStage(
        {},
        (data) => {
          if (!localStorage.getItem('BillStage')) {
            data.forEach((item) => {
              let temp = {}
              temp.label = item.name
              temp.value = item.id.toString()
              this.BillStage.push(temp)
            })
            localStorage.setItem('BillStage', this.BillStage)
          }
        },
        () => {
          ElMessage.error('查询 单据阶段下拉列表 出现错误')
        }
      )
    },

    // 4.采购类型下拉列表
    // {
    // 	"id": 1349517314,
    // 	"name": "生产原料"
    // },
    doQueryPurchaseType() {
      queryPurchaseType(
        {},
        (data) => {
          if (!localStorage.getItem('PurchaseType')) {
            data.forEach((item) => {
              let temp = {}
              temp.label = item.name
              temp.value = item.id.toString()
              this.PurchaseType.push(temp)
            })
            localStorage.setItem('PurchaseType', this.PurchaseType)
          }
        },
        () => {
          ElMessage.error('查询 采购类型下拉列表 出现错误')
        }
      )
    },

    // 5.税率下拉列表
    // {
    // 	"id": -2131726335,
    // 	"rate": "13"
    // },
    doQueryTaxType() {
      queryTaxType(
        {},
        (data) => {
          if (!localStorage.getItem('TaxType')) {
            data.forEach((item) => {
              let temp = {}
              temp.label = item.rate
              temp.value = item.id.toString()
              this.TaxType.push(temp)
            })
            localStorage.setItem('TaxType', this.TaxType)
          }
        },
        () => {
          ElMessage.error('查询 税率下拉列表 出现错误')
        }
      )
    },
    // 6.纳税规模下拉列表
    // {
    // 	"id": 2120617985,
    // 	"name": "一般纳税人"
    // }
    doQueryTaxScaleType() {
      queryTaxScaleType(
        {},
        (data) => {
          if (!localStorage.getItem('TaxScaleType')) {
            data.forEach((item) => {
              let temp = {}
              temp.label = item.name
              temp.value = item.id.toString()
              this.TaxScaleType.push(temp)
            })
            localStorage.setItem('TaxScaleType', this.TaxScaleType)
          }
        },
        () => {
          ElMessage.error('查询 纳税规模下拉列表 出现错误')
        }
      )
    },
    //7.开票方式下拉列表
    // {
    // 	"id": 1,
    // 	"name": "审核中"
    // }
    doQueryInvoiceMethodType() {
      queryInvoiceMethodType(
        {},
        (data) => {
          if (!localStorage.getItem('InvoiceMethodType')) {
            data.forEach((item) => {
              let temp = {}
              temp.label = item.name
              temp.value = item.id.toString()
              this.InvoiceMethodType.push(temp)
            })
            localStorage.setItem('InvoiceMethodType', this.InvoiceMethodType)
          }
        },
        () => {
          ElMessage.error('查询 开票方式下拉列表 出现错误')
        }
      )
    },
    //8.运输方式下拉列表
    // {
    // 	"id": 1,
    // 	"name": "审核中"
    // }
    doQueryTransportMethod() {
      queryTransportMethod(
        {},
        (data) => {
          if (!localStorage.getItem('TransportMethod')) {
            data.forEach((item) => {
              let temp = {}
              temp.label = item.name
              temp.value = item.id.toString()
              this.TransportMethod.push(temp)
            })
            localStorage.setItem('TransportMethod', this.TransportMethod)
          }
        },
        () => {
          ElMessage.error('查询 运输方式下拉列表 出现错误')
        }
      )
    },
    //9.结算方式下拉列表
    //  {
    // 		"id": 1,
    // 		"name": "审核中"
    // 	}
    doQuerySettleMethod() {
      querySettleMethod(
        {},
        (data) => {
          if (!localStorage.getItem('SettleMethod')) {
            data.forEach((item) => {
              let temp = {}
              temp.label = item.name
              temp.value = item.id.toString()
              this.SettleMethod.push(temp)
            })
            localStorage.setItem('SettleMethod', this.SettleMethod)
          }
        },
        () => {
          ElMessage.error('查询 结算方式下拉列表 出现错误')
        }
      )
    },
    //10.货币类型下拉列表
    // {
    // 	"id": "1250264330398093314",
    // 	"name": "人民币"
    // },
    doQueryCurrencyType() {
      queryCurrencyType(
        {},
        (data) => {
          if (!localStorage.getItem('CurrencyType')) {
            data.forEach((item) => {
              let temp = {}
              temp.label = item.name
              temp.value = item.id.toString()
              this.CurrencyType.push(temp)
            })
            localStorage.setItem('CurrencyType', this.CurrencyType)
          }
        },
        () => {
          ElMessage.error('查询 单据阶段下拉列表 出现错误')
        }
      )
    },
    //11.交货方式下拉列表
    // {
    // 	"id": 1,
    // 	"name": "送货上门"
    // }
    doQueryDeliveryType() {
      queryDeliveryType(
        {},
        (data) => {
          if (!localStorage.getItem('DeliveryType')) {
            data.forEach((item) => {
              let temp = {}
              temp.label = item.name
              temp.value = item.id.toString()
              this.DeliveryType.push(temp)
            })
            localStorage.setItem('DeliveryType', this.DeliveryType)
          }
        },
        () => {
          ElMessage.error('查询 交货方式下拉列表 出现错误')
        }
      )
    },
    //12.仓库下拉列表
    // {
    // 	"id": "1584936383497183234",
    // 	"name": "01 一号仓库"
    // },
    doQueryWarehouse() {
      queryWarehouse(
        {},
        (data) => {
          if (!localStorage.getItem('Warehouse')) {
            data.forEach((item) => {
              let temp = {}
              temp.label = item.name
              temp.value = item.id.toString()
              this.Warehouse.push(temp)
            })
            localStorage.setItem('Warehouse', this.Warehouse)
          }
        },
        () => {
          ElMessage.error('查询 仓库下拉列表 出现错误')
        }
      )
    },
    // 13.选区数据（省市区） TODO
    // {
    // 	"name": "1230769620021972993"
    // },
    // doQueryPurchaseType() {
    //   queryPurchaseType(
    //     {},
    //     (data) => {
    //       data.forEach((item) => {
    //         let temp = {}
    //         temp.label = item.name
    //         temp.value = item.id.toString()
    //         this.typeList.InvoiceType.push(temp)
    //       })
    //     },
    //     () => {
    //       ElMessage.error('查询 单据阶段下拉列表 出现错误')
    //     }
    //   )
    // },
    // 14.物料类型下拉列表
    // {
    // 	"id": "123",
    // 	"name": "01图灵"
    // }
    doQueryMaterialType() {
      queryMaterialType(
        {},
        (data) => {
          if (!localStorage.getItem('MaterialType')) {
            data.forEach((item) => {
              let temp = {}
              temp.label = item.name
              temp.value = item.id.toString()
              this.MaterialType.push(temp)
            })
            localStorage.setItem('MaterialType', this.MaterialType)
          }
        },
        () => {
          ElMessage.error('查询 物料类型下拉列表 出现错误')
        }
      )
    },
    // 15. 付款方式下拉列表 TODO
    // {
    // 	"dict_id": "",
    // 	"id": "123",
    // 	"name": "01图灵"
    // }
    doQueryPaymethodType() {
      queryPaymethodType(
        {},
        (data) => {
          if (!localStorage.getItem('PaymethodType')) {
            data.forEach((item) => {
              let temp = {}
              temp.label = item.name
              temp.value = item.id.toString()
              this.PaymethodType.push(temp)
            })
            localStorage.setItem('PaymethodType', this.PaymethodType)
          }
        },
        () => {
          ElMessage.error('查询 付款方式下拉列表 出现错误')
        }
      )
    },
    // 16. 交货方式下拉列表 TODO
    // {
    // 	"dict_id": "",
    // 	"id": "123",
    // 	"name": "01图灵"
    // }
    doQueryDeliverymethodType() {
      queryDeliverymethodType(
        {},
        (data) => {
          if (!localStorage.getItem('DeliverymethodType')) {
            data.forEach((item) => {
              let temp = {}
              temp.label = item.name
              temp.value = item.id.toString()
              this.DeliverymethodType.push(temp)
            })
            localStorage.setItem('DeliverymethodType', this.DeliverymethodType)
          }
        },
        () => {
          ElMessage.error('查询 交货方式下拉列表 出现错误')
        }
      )
    },
    //17.供应商名称下拉列表
    // {
    // 	"id": "111",
    // 	"name": "qwyed"
    // }
    doQuerySuppliersName() {
      querySuppliersName(
        {},
        (data) => {
          if (!localStorage.getItem('SuppliersName')) {
            data.forEach((item) => {
              let temp = {}
              temp.label = item.name
              temp.value = item.id.toString()
              this.SuppliersName.push(temp)
            })
            localStorage.setItem('SuppliersName', this.SuppliersName)
          }
        },
        () => {
          ElMessage.error('查询 供应商名称下拉列表 出现错误')
        }
      )
    },
    // 18.供应商等级下拉列表
    // {
    // 	"id": -765018110,
    // 	"name": "一级"
    // },
    doQuerySuppliersLevel() {
      querySuppliersLevel(
        {},
        (data) => {
          if (!localStorage.getItem('SuppliersLevel')) {
            data.forEach((item) => {
              let temp = {}
              temp.label = item.name
              temp.value = item.id.toString()
              this.SuppliersLevel.push(temp)
            })
            localStorage.setItem('SuppliersLevel', this.SuppliersLevel)
          }
        },
        () => {
          ElMessage.error('查询 供应商等级下拉列表 出现错误')
        }
      )
    },
    // 19.供应商高级查询条件下拉列表
    // {
    // 	"id": 37,
    // 	"name": "纳税规模"
    // },
    doQuerySupplierAdvancedCriteria() {
      querySupplierAdvancedCriteria(
        {},
        (data) => {
          if (!localStorage.getItem('SupplierAdvancedCriteria')) {
            data.forEach((item) => {
              let temp = {}
              temp.label = item.name
              temp.value = item.id.toString()
              this.SupplierAdvancedCriteria.push(temp)
            })
            localStorage.setItem(
              'SupplierAdvancedCriteria',
              this.SupplierAdvancedCriteria
            )
          }
        },
        () => {
          ElMessage.error('查询 供应商高级查询条件下拉列表 出现错误')
        }
      )
    },
    // 20.供应商高级查询条件下拉列表
    // {
    // 	"id": 37,
    // 	"name": "纳税规模"
    // },
    doQueryDepart() {
      queryDepart(
        {},
        (data) => {
          if (!localStorage.getItem('Depart')) {
            data.forEach((item) => {
              let temp = {}
              temp.label = item.name
              temp.value = item.id.toString()
              this.Depart.push(temp)
            })
            localStorage.setItem('Depart', this.Depart)
          }
        },
        () => {
          ElMessage.error('查询 部门列表 出现错误')
        }
      )
    }
  }
})
