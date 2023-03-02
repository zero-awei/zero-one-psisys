import { 
    getBillList,    //查询单据列表
    getDetailBill,    //查看指定单据
    getPrepaybill,     //采购订单列表
    getPrepaybillDetail,    //采购订单分列表
    postAdd,      //添加采购预付申请单
    putModifyPay,    //修改采购预付申请
    deleteMenu,     //删除采购预付申请单
    modifyBillStatus,    //采购预付申请修改单据状态(关闭/反关闭/作废)
    payInto,     //导入
    payExport    //导出
} from '@/views/caigouguanli/api/purprepaymentapply.js'



export function handleGetBillList() {
  // 自定义请求参数
  let params = {
    pageIndex:0,
    pageSize:0,
    bill_no:"", 
    bill_begin_date:"",
    bill_end_date:"",
    subject: "",
	supplier_id: "",
	bill_stage: "",
	is_effective: "-1",
	is_closed: "-1",
	is_voided: "-1"
  }
  params.pageIndex = 1
  params.pageSize = 10
  let pagniation={}
  getBillList(
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
