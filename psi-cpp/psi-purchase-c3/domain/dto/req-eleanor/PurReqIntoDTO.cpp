#include "stdafx.h"
#include "PurReqIntoDTO.h"

void from_json(const json& j, PurReqIntoDTO& t) { // NOLINT
	
	BIND_FROM_TO_ULL (j, t, purReqSubject);

	// 采购类型	（公共接口）
	// 需求部门	（公共接口）
	// 需求人	（选择用户公共接口）

	BIND_FROM_TO_ULL(j, t, purReqRequestTime);
	BIND_FROM_TO_ULL(j, t, purReqSrcEntryNo);
	BIND_FROM_TO_ULL(j, t, purReqMaterialId);

	// 规格型号（公共接口）

	BIND_FROM_TO_ULL(j, t, purReqUnitId);
	BIND_FROM_TO_D(j, t, purReqQty);
	BIND_FROM_TO_D(j, t, purReqTaxRate);
	BIND_FROM_TO_D(j, t, purReqPrice);
	BIND_FROM_TO_D(j, t, purReqAmt);

	// 建议供应商（公共接口）

	BIND_FROM_TO_ULL(j, t, purReqRemark);
	BIND_FROM_TO_ULL(j, t, purReqCustom1);
	BIND_FROM_TO_ULL(j, t, purReqCustom2);

}