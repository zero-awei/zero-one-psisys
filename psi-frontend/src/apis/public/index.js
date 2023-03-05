import Request from '../request'

// 定义一个功能模块基础url，方便替换
const currBaseUrl = '/basic'

/**
 * 1.供应商资金账户下拉列表
 * @param data 数据
 * @param success 查询成功回调
 * @param fail 查询失败
 */
export const queryBasBankAccount = (data, success, fail) => {
  Request.requestForm(
    Request.GET,
    currBaseUrl + '/query-bas-bank-account',
    data,
    {
      baseURL: import.meta.env.VITE_API_C1
    }
  )
    .then((data) => {
      if (data.data) {
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

/**
 * // 2.发票类型下拉列表
 * @param data 数据
 * @param success 查询成功回调
 * @param fail 查询失败
 */

export const queryInvoiceType = (data, success, fail) => {
  Request.requestForm(Request.GET, currBaseUrl + '/query-invoice-type', data, {
    baseURL: import.meta.env.VITE_API_C1
  })
    .then((data) => {
      if (data.data) {
        // 执行成功回调
        success()
        return
      }
      // 执行失败回调
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

/**
 * // 3.单据阶段下拉列表
 * @param data 数据
 * @param success 查询成功回调
 * @param fail 查询失败
 */

export const queryBillStage = (data, success, fail) => {
  Request.requestForm(Request.GET, currBaseUrl + '/query-invoice-type', data, {
    baseURL: import.meta.env.VITE_API_C1
  })
    .then((data) => {
      if (data.data) {
        // 执行成功回调
        success()
        return
      }
      // 执行失败回调
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

/**
 * // 4.采购类型下拉列表
 * @param data 数据
 * @param success 查询成功回调
 * @param fail 查询失败
 */

export const queryPurchaseType = (data, success, fail) => {
  Request.requestForm(Request.GET, currBaseUrl + '/query-purchase-type', data, {
    baseURL: import.meta.env.VITE_API_C1
  })
    .then((data) => {
      if (data.data) {
        // 执行成功回调
        success()
        return
      }
      // 执行失败回调
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

/**
 * // 5.税率下拉列表
 * @param data 数据
 * @param success 查询成功回调
 * @param fail 查询失败
 */

export const queryTaxType = (data, success, fail) => {
  Request.requestForm(Request.GET, currBaseUrl + '/query-tax-rate', data, {
    baseURL: import.meta.env.VITE_API_C1
  })
    .then((data) => {
      if (data.data) {
        // 执行成功回调
        success()
        return
      }
      // 执行失败回调
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

/**
 * // 6.纳税规模下拉列表
 * @param data 数据
 * @param success 查询成功回调
 * @param fail 查询失败
 */

export const queryTaxScaleType = (data, success, fail) => {
  Request.requestForm(Request.GET, currBaseUrl + '/query-tax-scale', data, {
    baseURL: import.meta.env.VITE_API_C1
  })
    .then((data) => {
      if (data.data) {
        // 执行成功回调
        success()
        return
      }
      // 执行失败回调
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

/**
 * // 7.开票方式下拉列表
 * @param data 数据
 * @param success 查询成功回调
 * @param fail 查询失败
 */

export const queryInvoiceMethodType = (data, success, fail) => {
  Request.requestForm(
    Request.GET,
    currBaseUrl + '/query-invoice-method',
    data,
    {
      baseURL: import.meta.env.VITE_API_C1
    }
  )
    .then((data) => {
      if (data.data) {
        // 执行成功回调
        success()
        return
      }
      // 执行失败回调
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

/**
 * // 8.运输方式下拉列表
 * @param data 数据
 * @param success 查询成功回调
 * @param fail 查询失败
 */

export const queryTransportMethod = (data, success, fail) => {
  Request.requestForm(
    Request.GET,
    currBaseUrl + '/query-transport-method',
    data,
    {
      baseURL: import.meta.env.VITE_API_C1
    }
  )
    .then((data) => {
      if (data.data) {
        // 执行成功回调
        success()
        return
      }
      // 执行失败回调
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

/**
 * // 9.结算方式下拉列表
 * @param data 数据
 * @param success 查询成功回调
 * @param fail 查询失败
 */

export const querySettleMethod = (data, success, fail) => {
  Request.requestForm(Request.GET, currBaseUrl + '/query-settle-method', data, {
    baseURL: import.meta.env.VITE_API_C1
  })
    .then((data) => {
      if (data.data) {
        // 执行成功回调
        success()
        return
      }
      // 执行失败回调
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

/**
 * // 10.货币类型下拉列表
 * @param data 数据
 * @param success 查询成功回调
 * @param fail 查询失败
 */

export const queryCurrencyType = (data, success, fail) => {
  Request.requestForm(Request.GET, currBaseUrl + '/query-Currency-Type', data, {
    baseURL: import.meta.env.VITE_API_C1
  })
    .then((data) => {
      if (data.data) {
        // 执行成功回调
        success()
        return
      }
      // 执行失败回调
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

/**
 * // 11.交货方式下拉列表   不用
 * @param data 数据
 * @param success 查询成功回调
 * @param fail 查询失败
 */

export const queryDeliveryType = (data, success, fail) => {
  Request.requestForm(Request.GET, currBaseUrl + '/query-Delivery-Type', data, {
    baseURL: import.meta.env.VITE_API_C1
  })
    .then((data) => {
      if (data.data) {
        // 执行成功回调
        success()
        return
      }
      // 执行失败回调
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

/**
 * // 12.仓库下拉列表
 * @param data 数据
 * @param success 查询成功回调
 * @param fail 查询失败
 */

export const queryWarehouse = (data, success, fail) => {
  Request.requestForm(Request.GET, currBaseUrl + '/query-Warehouse', data, {
    baseURL: import.meta.env.VITE_API_C1
  })
    .then((data) => {
      if (data.data) {
        // 执行成功回调
        success()
        return
      }
      // 执行失败回调
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

/**
 * // 13.选区数据（省市区）
 * @param data 数据
 * @param success 查询成功回调
 * @param fail 查询失败
 */
export const queryArea = (data, success, fail) => {
  Request.requestForm(Request.GET, currBaseUrl + '/get-area', data, {
    baseURL: import.meta.env.VITE_API_C1
  })
    .then((data) => {
      if (data.data) {
        // 执行成功回调
        success(data.data)
        return
      }
      // 执行失败回调
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

/**
 * // 14.物料类型下拉列表
 * @param data 数据
 * @param success 查询成功回调
 * @param fail 查询失败
 */

export const queryMaterialType = (data, success, fail) => {
  Request.requestForm(Request.GET, currBaseUrl + '/query-material-type', data, {
    baseURL: import.meta.env.VITE_API_C1
  })
    .then((data) => {
      if (data.data) {
        // 执行成功回调
        success()
        return
      }
      // 执行失败回调
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

/**
 * // 15.付款方式下拉列表
 * @param data 数据
 * @param success 查询成功回调
 * @param fail 查询失败
 */

export const queryPaymethodType = (data, success, fail) => {
  Request.requestForm(
    Request.GET,
    currBaseUrl + '/query-paymethod-type',
    data,
    {
      baseURL: import.meta.env.VITE_API_C1
    }
  )
    .then((data) => {
      if (data.data) {
        // 执行成功回调
        success()
        return
      }
      // 执行失败回调
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

/**
 * // 16.交货方式下拉列表
 * @param data 数据
 * @param success 查询成功回调
 * @param fail 查询失败
 */

export const queryDeliverymethodType = (data, success, fail) => {
  Request.requestForm(
    Request.GET,
    currBaseUrl + '/query-deliverymothod-type',
    data,
    {
      baseURL: import.meta.env.VITE_API_C1
    }
  )
    .then((data) => {
      if (data.data) {
        // 执行成功回调
        success()
        return
      }
      // 执行失败回调
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

/**
 * // 17.供应商名称下拉列表
 * @param data 数据
 * @param success 查询成功回调
 * @param fail 查询失败
 */

export const querySuppliersName = (data, success, fail) => {
  Request.requestForm(
    Request.GET,
    currBaseUrl + '/query-suppliers-name',
    data,
    {
      baseURL: import.meta.env.VITE_API_C1
    }
  )
    .then((data) => {
      if (data.data) {
        // 执行成功回调
        success()
        return
      }
      // 执行失败回调
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

/**
 * // 18.供应商等级下拉列表
 * @param data 数据
 * @param success 查询成功回调
 * @param fail 查询失败
 */

export const querySuppliersLevel = (data, success, fail) => {
  Request.requestForm(
    Request.GET,
    currBaseUrl + '/qurey-supplier-level',
    data,
    {
      baseURL: import.meta.env.VITE_API_C1
    }
  )
    .then((data) => {
      if (data.data) {
        // 执行成功回调
        success()
        return
      }
      // 执行失败回调
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

/**
 * // 19.供应商高级查询条件下拉列表
 * @param data 数据
 * @param success 查询成功回调
 * @param fail 查询失败
 */

export const querySupplierAdvancedCriteria = (data, success, fail) => {
  Request.requestForm(
    Request.GET,
    currBaseUrl + '/qurey-supplier-advanced_criteria',
    data,
    {
      baseURL: import.meta.env.VITE_API_C1
    }
  )
    .then((data) => {
      if (data.data) {
        // 执行成功回调
        success()
        return
      }
      // 执行失败回调
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

/**
 * // 20.下拉框获取部门列表  j1 3.6
 * @param data 数据
 * @param success 查询成功回调
 * @param fail 查询失败
 */

export const queryDepart = (data, success, fail) => {
  Request.requestForm(
    Request.GET,
    '/sysmanagement/usermanagement/list-depart',
    data,
    {
      baseURL: import.meta.env.VITE_API_C1
    }
  )
    .then((data) => {
      if (data.data) {
        // 执行成功回调
        success()
        return
      }
      // 执行失败回调
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}
/**
 * // 21.选择用户
 * @param data 数据
 * @param success 查询成功回调
 * @param fail 查询失败
 */
export const getUser = (data, success, fail) => {
  Request.requestForm(Request.GET, currBaseUrl + '/get-user', data, {
    baseURL: import.meta.env.VITE_API_C1
  })
    .then((data) => {
      if (data.data) {
        // 执行成功回调
        success(data.data)
        return
      }
      // 执行失败回调
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

// 22.查询指定物料规格型号/单位
export const getMaterial = (data, success, fail) => {
  Request.requestForm(Request.GET, currBaseUrl + '/get-material', data, {
    baseURL: import.meta.env.VITE_API_C1
  })
    .then((data) => {
      if (data.data) {
        // 执行成功回调
        success(data.data)
        return
      }
      // 执行失败回调
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

// 23.业务部门结构（用于输入查询条件）
export const getDepart = (data, success, fail) => {
  Request.requestForm(Request.GET, currBaseUrl + '/get-depart', data, {
    baseURL: import.meta.env.VITE_API_C1
  })
    .then((data) => {
      if (data.data) {
        // 执行成功回调
        success(data.data)
        return
      }
      // 执行失败回调
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

// 24仓库树状结构列表
export const queryBasWareHouseTreeList = (data, success, fail) => {
  Request.requestForm(
    Request.GET,
    currBaseUrl + '/query-bas-ware-house-tree-list',
    data,
    {
      baseURL: import.meta.env.VITE_API_C1
    }
  )
    .then((data) => {
      if (data.data) {
        // 执行成功回调
        success(data.data)
        return
      }
      // 执行失败回调
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

// 25 物料分类树状结构列表
export const queryMaterialTreeList = (data, success, fail) => {
  Request.requestForm(
    Request.GET,
    currBaseUrl + '/query-material-type-tree-list',
    data,
    {
      baseURL: import.meta.env.VITE_API_C1
    }
  )
    .then((data) => {
      if (data.data) {
        // 执行成功回调
        success(data.data)
        return
      }
      // 执行失败回调
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

//26 请求新单据编号（根据新增类型生成新单据编号）
export const createReceipt = (data, success, fail) => {
  Request.requestForm(Request.PUT, currBaseUrl + '/create-receipt', data, {
    baseURL: import.meta.env.VITE_API_C1
  })
    .then((data) => {
      if (data.data) {
        // 执行成功回调
        success(data.data)
        return
      }
      // 执行失败回调
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}
