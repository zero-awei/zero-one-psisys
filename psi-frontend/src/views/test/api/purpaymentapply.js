import { 
    paymentApplyBill,    //查询单据列表
    finPaymentReqEntry,    //查看指定单据详细信息
    appPayment,     //添加采购付款申请单（保存/提交）
    changePayment,    //修改采购付款申请单（保存/提交/审核）----修改状态
    modPaymentReq,      //修改采购付款申请单（保存/提交/审核）----修改内容
    deleteById,    //删除采购付款申请单
    modifyPaymentStatus,     //修改单据状态（关闭/作废/反关闭）
    importPayment,    //导入
    exportPayment,     //导出

} from '@/views/caigouguanli/api/purpaymentapply.js'



export function handlePaymentApplyBill() {
  // 自定义请求参数
  let params = {
    pageIndex:0,
    pageSize:0,
    billNo:"CGFKSQ-221120-001", 
    billDate:"2022-11-20",
    subject:"",
    supplierId: "",
    billStage: "",
    isEffective: "1",
    isClosed: "1",
    isVoided: "0",
  }
  params.pageIndex = 1
  params.pageSize = 10
  let pagniation={}
  paymentApplyBill(
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

export function handleFinPaymentReqEntry() {
  // 自定义请求参数
  let params = {
    billNo:"CGFKSQ-221120-001"
  }
  let pagniation={}
  finPaymentReqEntry(
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

export function handleAppPayment() {
  // 自定义请求参数
  let params = {
    bill_no: "",
	bill_date: "2023-2-22",
	src_bill_type: "123",
	src_bill_id: "123",
	src_no: "ABC",
	subject: "123",
	is_rubric: 123,
	payment_type: "132",
	supplier_id: "123",
	op_dept: "123",
	operator1: "123",
	amt: 123,
	paid_amt: 123,
	attachment: "123",
	effective_time: "123",
	is_auto: "123",
	bill_stage: "123",
	approver: "132",
	bpmi_instance_id: "123",
	approval_result_type: "312",
	approval_remark: "123132",
	is_effective: 132,
	is_closed: 123,
	is_voided: 312,
	create_by: "132",
	sys_org_code: "132",
	update_by: "123",
	create_time: "123",
	id: "123"
  }
  let pagniation={}
  appPayment(
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

export function handleChangePayment() {
  // 自定义请求参数
  let params = {
    id: 123,
	opType: "CLOSE",
	bill_no: "CSQW",
	is_closed: "1"
  }
  let pagniation={}
  changePayment(
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

export function handleModPaymentReq() {
  // 自定义请求参数
  let params = {
    billNo:"CGYFSQ-221120-001",
    billDate:"2022-11-20",
    srcBillType:"",
    srcBillId:"",
    srcNo:"",
    subject:"",
    paymentType:"",
    supplierId:"1584950950470164481",
    opDept:"A01A03",
    operator1:"li",
    remark:"",
    attachment:"",
    createBy:"",
    createTime:"2022-11-20 21:26:07",
    amt:1.0,
    isEffective:"1",
    isClosed:"1",
    isVoided:"0"
  }
  let pagniation={}
  modPaymentReq(
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

export function handleDeleteById() {
  // 自定义请求参数
  let params = {
    id: "159290032213046067"
  }
  let pagniation={}
  deleteById(
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

export function handleModifyPaymentStatus() {
  // 自定义请求参数
  let params = {
    id: "113",
	opType: "2",
	bill_no: "ABC",
	is_closed: 0,
	is_voided: 1
}
  let pagniation={}
  modifyPaymentStatus(
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

