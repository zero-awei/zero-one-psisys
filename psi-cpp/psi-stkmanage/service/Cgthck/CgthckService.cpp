#include "stdafx.h"
#include "CgthckService.h"


PageVO<QueryCgthckBillDetailVO> CgthckService::listAll(const QueryCgthckBillQuery& query)
{
    return PageVO<QueryCgthckBillDetailVO>();
}

uint64_t CgthckService::saveData(const AddCgthckBillDTO& dto)
{
    return uint64_t();
}

bool CgthckService::updateData(const ModifyCgthckBillDTO& dto)
{
    return false;
}

bool CgthckService::removeData(uint64_t id)
{
    return false;
}
