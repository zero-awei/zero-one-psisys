import { queryAll, close, deleteById, edit, queryAllByBillno, queryOneNo, unclose, voidById } from '@/views/yingfuyufukuan/yufuguanli/api/caigouyufu.js'

export function handleQuery() {
    // 自定义请求参数
    let params = {}
    queryAll(
      params,
      (data) => {
        console.log('全部请求data----', data)
        // 查询返回的是表格数据
        // 分页
        pagination.value.currentPage = data.pageIndex
        pagination.value.pageSize = data.pageSize
        pagination.value.total = data.total
  
        // 表格数据
        tableData.value = data.rows
      },
      (msg) => {
        ElMessage.warning(msg)
      }
    )
  }

export  function handleClose(){
    let params = {}
    params.id = idData.value.id
    close(
      params,
      (data) => {
        console.log('全部请求data----', data)
      },
      (msg) => {
        ElMessage.warning(msg)
      }
    )
  }
  //删除信息
export  function handleDelete(){
    let params = {}
    params.id = idData.value.id
    deleteById(
      params,
      (data) => {
        console.log('全部请求data----', data)
      },
      (msg) => {
        ElMessage.warning(msg)
      }
    )
  }
  //修改采购预付单功能
export  function handleEdit(){
    let params = {}
    params.amt = editData.value.amt
    params.attachment = editData.value.attachment
    params.billDate = editData.value.billDate
    params.billNo = editData.value.billNo
    params.entryAmt = editData.value.entryAmt
    params.entryBankAccountld = editData.value.entryBankAccountld
    params.entryCustom1 = editData.value.entryCustom1
    params.entryCustom2 = editData.value.entryCustom2
    params.entryNo = editData.value.entryNo
    params.entryId = editData.value.entryId
    params.entryMid = editData.value.entryMid
    params.entryRemark = editData.value.entryRemark
    params.entrySettleMethod = editData.value.entrySettleMethod
    params.entrySrcBillId = editData.value.entrySrcBillId
    params.entrySrcBillType = editData.value.entrySrcBillType
    params.entrySrcNo = editData.value.entrySrcNo
    params.remark = editData.value.remark
    params.srcBillId = editData.value.srcBillId
    params.srcBillType = editData.value.srcBillType
    params.srcNo = editData.value.srcNo
    params.subject = editData.value.subject
    params.supplierId = editData.value.supplierId
    params.version = editData.value.version
    edit(
      params,
      (data) => {
        console.log('全部请求data----', data)
      },
      (msg) => {
        ElMessage.warning(msg)
      }
    )
  }
  //付款申请单分录列表
export  function handlequeryAllByBillno(){
    let params = {}
    params.billNo = queryByBillNOData.value.billNo
    queryAllByBillno(
      params,
      (data) => {
        console.log('全部请求data----', data)
      },
      (msg) => {
        ElMessage.warning(msg)
      }
    )
  }
  //查看单据详情信息
export  function handleQueryOneNo(){
    let params = {}
    params.billNo = oneNoData.value.billNo
    queryOneNo(
      params,
      (data) => {
        console.log('全部请求data----', data)
      },
      (msg) => {
        ElMessage.warning(msg)
      }
    )
  }
  //反关闭操作
export  function handleUnclose(){
    let params = {}
    params.id = uncloseData.value.id
    unclose(
      params,
      (data) => {
        console.log('全部请求data----', data)
      },
      (msg) => {
        ElMessage.warning(msg)
      }
    )
  }
  //作废操作
export  function handleVoid(){
    let params = {}
    params.id = voidData.value.id
    voidById(
      params,
      (data) => {
        console.log('全部请求data----', data)
      },
      (msg) => {
        ElMessage.warning(msg)
      }
    )
  }