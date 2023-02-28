#include "stdafx.h"
#include "PurTypeService.h"
#include "../../dao/publicInterfaceDAO/PurTypeDAO.h"

list<PurTypeVO> PurTypeService::listAll()
{
    PurTypeDAO dao;
    list<PurTypeDO> result = dao.selectPurType();
    list<PurTypeVO> vr;

    for (PurTypeDO sub : result)
    {
        PurTypeVO vo;
        vo.setId(sub.getId());
        vo.setName(sub.getName());
        vr.push_back(vo);
    }
    return vr;
}
