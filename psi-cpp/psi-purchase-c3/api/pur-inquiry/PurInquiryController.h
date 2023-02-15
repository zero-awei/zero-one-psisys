#include "stdafx.h"
#include "domain/vo/JsonVO.h"
#include "domain/dto/pur-inquiry/PurInquiryDTO.h"
#include "domain/query/pur-inquiry/PurInquiryQuery.h"
#include "domain/vo/pur-inquiry/PurInquiryVO.h"
#ifndef __PURINQUIRYCONTROLLER_H__
#define __PURINQUIRYCONTROLLER_H__

class PurInquiryController
{
public:
	CREATE_API_FUN_BODY(addPurInquiry, execAddPurInquiry, InquiryDTO);
	CREATE_API_FUN_BODY(modifyPurInquiry, execModifyPurInquiry, InquiryDTO);
	CREATE_API_FUN_BODY(removePurInquiry, execRemovePurInquiry, PurInquiryRemoveDTO);
	CREATE_API_FUN_BODY_FILE(PurInquiryInto, execPurInquiryInto, PurInquiryDTO);
	CREATE_API_FUN_QUERY(PurInquiryExport, execPurInquiryExport, PurInquiryQurey);

private:
	//添加数据
	JsonVO<uint64_t> execAddPurInquiry(const InquiryDTO& dto);

	//修改数据
	JsonVO<uint64_t> execModifyPurInquiry(const InquiryDTO& dto);

	//删除数据
	JsonVO<uint64_t> execRemovePurInquiry(const PurInquiryRemoveDTO& dto);

	//文件上传
	JsonVO<PurInquiryVO> execPurInquiryInto(const PurInquiryDTO& dto);

	//文件下载
	JsonVO<std::string> execPurInquiryExport(const PurInquiryQurey& qurry);


};

#endif  //__PURINQUIRYCONTROLLER_H__
