#include "stdafx.h"
#include "BillStageService.h"

#include "../../dao/publicInterfaceDAO/BillStageDAO.h"

list<BillStageVO> BillStageService::listAll()
{
    BillStageDAO dao;
    list<BillStageDO> result = dao.selectBillStage();
    list<BillStageVO> vr;
    
    for (BillStageDO sub : result)
    {
        BillStageVO vo;
        vo.setId(sub.getId());
        vo.setName(sub.getName());
        vr.push_back(vo);
    }
    return vr;
}