#pragma once
#ifndef _PRE_PAY_SERVICE_
#define _PRE_PAY_SERVICE_
#include <list>
//查看预付申请单列表
#include "../../domain/query/prepaymentbill/PrepayBillQuery.h"
#include "../../domain/query/prepaymentbill/PrepayDetailBillQuery.h"
#include "../../domain/vo/prepaymentbill/PrepaymentBillVO.h"
#include "../../domain/vo/prepaymentbill/PrepaymentDetailBillVO.h"
//增加修改删除预付申请单列表
#include "../../domain/dto/prepayment/AddPayDTO.h"
#include "../../domain/dto/prepayment/PrepaymentDTO.h"
#include "../../domain/dto/prepayment/DePayDTO.h"
#include "../../domain/dto/prepayment/PayModBillStatusDTO.h"
#include "../../domain/vo/prepayment/PrepaymentVO.h"
//导入导出
#include "../../domain/query/prepaymentbill/PrePayExportQuery.h"
#include "../../domain/dto/prepayment/PayIntoDTO.h"
#include "../../domain/vo/prepayment_req/PrepaymentIntoVO.h"
#include "../../domain/vo/prepayment_req/PrepaymentExportVO.h"

#include "../../domain/vo/PageVO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 * 预付申请的服务实现
 */
class PrePayService
{
public:
	// 分页查询 预付申请单所有数据(多个对象)
	PageVO<PrepaymentBillVO> listAll(const PrepayBillQuery& query);
	// 查询预付申请单详细数据(单个对象)
	PageVO<PrepaymentDetailBillVO> getAll(const PrepayDetailBillQuery& query);
	// 通过ID删除数据
	bool DePrePayId(const DePayDTO& dto);

	//// 保存数据
	//uint64_t saveData(const AddPayDTO& dto);
	//// 修改数据
	//bool updateData(const PrepaymentDTO& dto);
	//// 修改单据状态
	//bool updateStatus(const PayModBillStatusDTO& dto);
	//// 保存导入数据
	//uint64_t saveInto(const PayIntoDTO& dto);

};

#endif // !_PRE_PAY_SERVICE_
