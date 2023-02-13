#include "stdafx.h"
#ifndef __PURINQUIRYCONTROLLER_H__
#define __PURINQUIRYCONTROLLER_H__
#include "domain/dto/pur-inquiry/Pur_inquiryDTO.h"
#include "domain/vo/JsonVO.h"
#include "domain/vo/pur-inquiry/pur_inquiryVO.h"

class PurInquiryController
{
public:
    CREATE_API_FUN_BODY(addPurInquiry,execAddPurInquiry, Pur_inquiryDTO);
    CREATE_API_FUN_BODY(modifyPurInquiry, execModifyPurInquiry, Pur_inquiryDTO);
    CREATE_API_FUN_BODY(removePurInquiry, execRemovePurInquiry, Pur_inquiryDTO);
    CREATE_API_FUN_BODY_FILE(modifyPurInquiryInfo, execModifyPurInquiryInfo, Pur_inquiryDTO);
    CREATE_API_FUN_BODY_FILE(modifyPurInquiryIn, execModifyPurInquiryIn, Pur_inquiryDTO);

private:
    //添加数据
    JsonVO<uint64_t> execAddPurInquiry(const Pur_inquiryDTO& dto);

    //修改数据
    JsonVO<uint64_t> execModifyPurInquiry(const Pur_inquiryDTO& dto);

    //删除数据
    JsonVO<uint64_t> execRemovePurInquiry(const Pur_inquiryDTO& dto);

    //文件上传
    JsonVO<Pur_inquiryVO> execModifyPurInquiryInfo(const Pur_inquiryDTO& dto);

    //文件下载
    JsonVO<Pur_inquiryVO> execModifyPurInquiryIn(const Pur_inquiryDTO& dto);


};

#endif  //__PURINQUIRYCONTROLLER_H__
