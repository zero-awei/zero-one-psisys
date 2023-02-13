#include "stdafx.h"
#ifndef __INQUIRYHUILAICONTROLLER_H__
#define __INQUIRYHUILAICONTROLLER_H__
#include "domain/vo/JsonVO.h"
#include "domain/dto/inquiry-huilai/InquiryHuilaiDTO.h"
#include "domain/vo/inquiry-huilai/InquiryHuilaiVO.h"



class InquiryHuilaiController
{
public:
	CREATE_API_FUN_BODY(addPurInquiry, execAddPurInquiry, InquiryHuilaiDTO);
	CREATE_API_FUN_BODY(modifyPurInquiry, execModifyPurInquiry, InquiryHuilaiDTO);
	CREATE_API_FUN_BODY(removePurInquiry, execRemovePurInquiry, InquiryHuilaiDTO);
	CREATE_API_FUN_BODY_FILE(modifyPurInquiryInfo, execModifyPurInquiryInfo, InquiryHuilaiDTO);
	CREATE_API_FUN_BODY_FILE(modifyPurInquiryIn, execModifyPurInquiryIn, InquiryHuilaiDTO);

private:
	//添加数据
	JsonVO<uint64_t> execAddPurInquiry(const InquiryHuilaiDTO& dto);

	//修改数据
	JsonVO<uint64_t> execModifyPurInquiry(const InquiryHuilaiDTO& dto);

	//删除数据
	JsonVO<uint64_t> execRemovePurInquiry(const InquiryHuilaiDTO& dto);

	//文件上传
	JsonVO<InquiryHuilaiVO> execModifyPurInquiryInfo(const InquiryHuilaiDTO& dto);

	//文件下载
	JsonVO<InquiryHuilaiVO> execModifyPurInquiryIn(const InquiryHuilaiDTO& dto);


};

#endif  //__INQUIRYHUILAICONTROLLER_H__
