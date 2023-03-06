import { 
    listPurOrder,    //查询单据列表
    queryPurOrderEntryByMainId,    //查看指定单据详细信息
    queryPurReqEntryByMainId,     //采购申请单列表
    listPurReq,    //采购申请单分录列表
    listPurCom,      //比价单列表
    listEntrysPurCom,    //比价单分录列表
    addPurOrder,     //添加采购订单（保存/提交）
    editPurOrder,    //修改采购订单（保存/提交/审核）
    deletePurOrder,     //删除采购订单----根据单据编号删除
    deleteByIdPurOrder,   //删除采购订单----根据ID删除+
    modifyStatusPurOrder   //修改单据状态（关闭/作废/反关闭）
} from '@/views/caigouguanli/api/purorder.js'



export function handleListPurOrder() {
  // 自定义请求参数
  let params = {
    pageIndex:0,
    pageSize:0,
    bill_no:"CGDD-230225-009", 
  }
  params.pageIndex = 1
  params.pageSize = 5
  let pagniation={}
  listPurOrder(
    params,
    (data) => {
      console.log('全部请求data----', data)
      // 查询返回的是表格数据
      // 分页
      let pagination = {}
      pagination.value.currentPage = data.pageIndex
      pagination.value.pageSize = data.pageSize
      pagination.value.total = data.total
      let tableData = {}
      // 表格数据
      tableData.value = data.rows
    },
    (msg) => {
      let ElMessage = {}
      //ElMessage.warning(msg)
    }
  )
}

export function handleQueryPurOrderEntryByMainId() {
  // 自定义请求参数
  let params = {
    bill_no:"CGDD-221117-000"
  }
  let pagniation={}
  queryPurOrderEntryByMainId(
    params,
    (data) => {
      console.log('全部请求data----', data)
      // 查询返回的是表格数据
      // 分页
      let pagination = {}
      pagination.value.currentPage = data.pageIndex
      pagination.value.pageSize = data.pageSize
      pagination.value.total = data.total
      let tableData = {}
      // 表格数据
      tableData.value = data.rows
    },
    (msg) => {
      let ElMessage = {}
      //ElMessage.warning(msg)
    }
  )
}

export function handleQueryPurReqEntryByMainId() {
  // 自定义请求参数
  let params = {
	id: 123
  }
  let pagniation={}
  queryPurReqEntryByMainId(
    params,
    (data) => {
      console.log('全部请求data----', data)
      // 查询返回的是表格数据
      // 分页
      let pagination = {}
      pagination.value.currentPage = data.pageIndex
      pagination.value.pageSize = data.pageSize
      pagination.value.total = data.total
      let tableData = {}
      // 表格数据
      tableData.value = data.rows
    },
    (msg) => {
      let ElMessage = {}
      //ElMessage.warning(msg)
    }
  )
}

export function handleListPurReq() {
  // 自定义请求参数
  let params = {
    //没填？？？
  }
  let pagniation={}
  listPurReq(
    params,
    (data) => {
      console.log('全部请求data----', data)
      // 查询返回的是表格数据
      // 分页
      let pagination = {}
      pagination.value.currentPage = data.pageIndex
      pagination.value.pageSize = data.pageSize
      pagination.value.total = data.total
      let tableData = {}
      // 表格数据
      tableData.value = data.rows
    },
    (msg) => {
      let ElMessage = {}
      //ElMessage.warning(msg)
    }
  )
}

export function handleListPurCom() {
  // 自定义请求参数
  let params = {
    pageIndex:1,
    pageSize:10,
    bill_no:"1111", 
  }
  params.pageIndex = 1
  params.pageSize = 10
  let pagniation={}
  listPurCom(
    params,
    (data) => {
      console.log('全部请求data----', data)
      // 查询返回的是表格数据
      // 分页
      let pagination = {}
      pagination.value.currentPage = data.pageIndex
      pagination.value.pageSize = data.pageSize
      pagination.value.total = data.total
      let tableData = {}
      // 表格数据
      tableData.value = data.rows
    },
    (msg) => {
      let ElMessage = {}
      //ElMessage.warning(msg)
    }
  )
}

export function handleListEntrysPurCom() {
  // 自定义请求参数
  let params = {
    pageIndex:1,
    pageSize:10,
    bill_no:"1111", 
  }
  let pagniation={}
  params.pageIndex = 1
  params.pageSize = 10
  listEntrysPurCom(
    params,
    (data) => {
      console.log('全部请求data----', data)
      // 查询返回的是表格数据
      // 分页
      let pagination = {}
      pagination.value.currentPage = data.pageIndex
      pagination.value.pageSize = data.pageSize
      pagination.value.total = data.total
      let tableData = {}
      // 表格数据
      tableData.value = data.rows
    },
    (msg) => {
      let ElMessage = {}
      //ElMessage.warning(msg)
    }
  )
}

export function handleAddPurOrder() {
  // 自定义请求参数
  let params = {
    bill_no: "CGDD-230226-016",
    bill_date: "2022-11-20 00:00:00",
    src_bill_type: "TQBeXakY0iS",
    src_bill_id: "ckY0o9R5R5",
    src_no: "ibvVbjyA8V",
    subject: "b0LXFPpYdN",
    is_rubric: "212",
    pur_type: "cGxPzQMIJM",
    supplier_id: "KpTuVxLdIv",
    contact: "uGUmicVW0a",
    phone: "66-659-4449",
    fax: "BQ27x7iRSg",
    email: "earl627@yahoo.com",
    op_dept: "dhI2V7tfqC",
    op_er: "bQEKF1TFHI",
    delivery_method: "ge2udZwKeO",
    delivery_place: "bbmrFRera3",
    delivery_time: "2001-02-04 02:34:40",
    transport_method: "ZwJ0zP9oGJ",
    payment_method: "Apple Pay",
    settle_method: "O5vEgpSHjg",
    settle_time: "2008-12-22 00:00:00",
    invoice_method: "rAxEu6tmfr",
    invoice_type: "yWqHh4HwCr",
    currency: "IvwDeQOJ2Q",
    exchange_rate: "189.42958",
    qty: "852.603394",
    amt: "304.58",
    prepayment_bal: "369.86",
    settle_qty: "741.047976",
    settle_amt: "669.52",
    in_qty: "138.104146",
    in_cost: "438.97",
    settled_amt: "965.4",
    invoiced_amt: "650.69",
    attachment: "pDfg94GsUo",
    remark: "Adc9r8NLtZ",
    is_auto: "21",
    bill_stage: "ZzYQ",
    approver: "TgU68IuS1F",
    bpmi_instance_id: "hRAEDy0YiN",
    approval_result_type: "irQS56d4yI",
    approval_remark: "8ZmZpZeVG3",
    is_effective: "720",
    effective_time: "2002-12-18 07:32:04",
    is_closed: "596",
    is_voided: "884",
    sys_org_code: "c2npvkCbkY",
    create_by: "w5sydfubTU",
    create_time: "2023-02-09 20:34:47",
    update_by: "2008-11-21 00:00:00",
    update_time: "2008-05-07 14:59:32",
    version: "571",
    detail: [
        {
            entry_no: "10",
            src_bill_type: "XiqemC9wJe",
            src_bill_id: "nkfKclNDvk",
            src_entry_id: "o0BKsbyrXW",
            src_no: "DXiXCv7E5Z",
            material_id: "JBZlo99x2N",
            unit_id: "1Q0RKFSh9B",
            qty: "289.898985",
            tax_rate: "121.139966",
            price: "631.312224",
            discount_rate: "523.5502",
            tax: "244.08",
            amt: "396.03",
            in_qty: "338.068657",
            in_cost: "42.89",
            settle_qty: "325.444485",
            settle_amt: "596.28",
            invoiced_qty: "831.465129",
            invoiced_amt: "840.59",
            remark: "kWyLehKNES",
            custom1: "qpDsAFudma",
            custom2: "oa7A6CP6qM",
            version: "618"
        },
        {
            entry_no: "20",
            src_bill_type: "LZjtetzHRQ",
            src_bill_id: "xz6i2Hblj0",
            src_entry_id: "AsUjaWO9Up",
            src_no: "xx8ERSd23X",
            material_id: "tEMttS1fyq",
            unit_id: "gGuDJmzMxc",
            qty: "968.322751",
            tax_rate: "486.553343",
            price: "148.553003",
            discount_rate: "318.6709",
            tax: "547.33",
            amt: "817.49",
            in_qty: "271.74871",
            in_cost: "606.58",
            settle_qty: "954.52148",
            settle_amt: "589.11",
            invoiced_qty: "956.692083",
            invoiced_amt: "787.3",
            remark: "7QoTixeEeS",
            custom1: "R2VTTzXUB8",
            custom2: "ZW9lSXMP0S",
            version: "859"
        }
    ]
}
  let pagniation={}
  addPurOrder(
    params,
    (data) => {
      console.log('全部请求data----', data)
      // 查询返回的是表格数据
      // 分页
      let pagination = {}
      pagination.value.currentPage = data.pageIndex
      pagination.value.pageSize = data.pageSize
      pagination.value.total = data.total
      let tableData = {}
      // 表格数据
      tableData.value = data.rows
    },
    (msg) => {
      let ElMessage = {}
      //ElMessage.warning(msg)
    }
  )
}

export function handleEditPurOrder() {
    // 自定义请求参数
    let params = {
        bill_no: "as",
        bill_date: "2077-11-20 00:00:00",
        src_bill_type: "Sakana",
        src_bill_id: "Sakana",
        src_no: "Sakana",
        op_dept: "Sakana",
        op_er: "Sakana",
        approval_remark: "Sakana",
        is_effective: "720",
        effective_time: "2002-12-18 07:32:04",
        is_closed: "596",
        is_voided: "884",
        sys_org_code: "c2npvkCbkY",
        create_by: "w5sydfubTU",
        create_time: "2023-02-09 20:34:47",
        update_by: "2008-11-21 00:00:00",
        update_time: "2008-05-07 14:59:32",
        version: "571",
        detail: [
            {
                id: "2",
                mid: "RMX1hKkCEo",
                bill_no: "XX7T6BUtJg",
                entry_no: "405",
                src_bill_type: "Sakana",
                src_bill_id: "Sakana",
                src_entry_id: "Sakana",
                src_no: "DXiXCv7E5Z",
                material_id: "JBZlo99x2N",
                version: "618"
            },
            {
                id: "3",
                mid: "Tqk9CcuSTC",
                bill_no: "ltmfoGKjqA",
                entry_no: "10",
                src_bill_type: "Sakana",
                src_bill_id: "Sakana",
                src_entry_id: "Sakana",
                src_no: "xx8ERSd23X",
                material_id: "tEMttS1fyq",
                tax: "547.33",
                amt: "817.49",
                in_qty: "271.74871",
                in_cost: "606.58",
                settle_qty: "954.52148",
                settle_amt: "589.11",
                invoiced_qty: "956.692083",
                invoiced_amt: "787.3",
                remark: "7QoTixeEeS",
                custom1: "R2VTTzXUB8",
                custom2: "ZW9lSXMP0S",
                version: "859"
            }
        ]
  }
    let pagniation={}
    editPurOrder(
      params,
      (data) => {
        console.log('全部请求data----', data)
        // 查询返回的是表格数据
        // 分页
        let pagination = {}
        pagination.value.currentPage = data.pageIndex
        pagination.value.pageSize = data.pageSize
        pagination.value.total = data.total
        let tableData = {}
        // 表格数据
        tableData.value = data.rows
      },
      (msg) => {
        let ElMessage = {}
        //ElMessage.warning(msg)
      }
    )
}
  
export function handleDeletePurOrder() {
    // 自定义请求参数
    let params = {
        bill_no:""
    }
    let pagniation={}
    deletePurOrder(
      params,
      (data) => {
        console.log('全部请求data----', data)
        // 查询返回的是表格数据
        // 分页
        let pagination = {}
        pagination.value.currentPage = data.pageIndex
        pagination.value.pageSize = data.pageSize
        pagination.value.total = data.total
        let tableData = {}
        // 表格数据
        tableData.value = data.rows
      },
      (msg) => {
        let ElMessage = {}
        //ElMessage.warning(msg)
      }
    )
}

export function handleDeleteByIdPurOrder() {
    // 自定义请求参数
    let params = {
        id:""
    }
    let pagniation={}
    deleteByIdPurOrder(
      params,
      (data) => {
        console.log('全部请求data----', data)
        // 查询返回的是表格数据
        // 分页
        let pagination = {}
        pagination.value.currentPage = data.pageIndex
        pagination.value.pageSize = data.pageSize
        pagination.value.total = data.total
        let tableData = {}
        // 表格数据
        tableData.value = data.rows
      },
      (msg) => {
        let ElMessage = {}
        //ElMessage.warning(msg)
      }
    )
}

export function handleModifyStatusPurOrder() {
    // 自定义请求参数
    let params = {
        id:"1590710155252645889",
        bill_no:"CGDD-221110-001",
        opType:"2"
    }
    let pagniation={}
    modifyStatusPurOrder(
      params,
      (data) => {
        console.log('全部请求data----', data)
        // 查询返回的是表格数据
        // 分页
        let pagination = {}
        pagination.value.currentPage = data.pageIndex
        pagination.value.pageSize = data.pageSize
        pagination.value.total = data.total
        let tableData = {}
        // 表格数据
        tableData.value = data.rows
      },
      (msg) => {
        let ElMessage = {}
        //ElMessage.warning(msg)
      }
    )
}