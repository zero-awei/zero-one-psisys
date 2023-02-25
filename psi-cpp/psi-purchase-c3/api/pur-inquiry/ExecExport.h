#pragma once

#ifndef __EXECEXPORT_H__
#define __EXECEXPORT_H__

#include "stdafx.h"
#include "api/ApiHelper.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/pur-inquiry/PurInquiryExportVO.h"


bool execexport(vector<std::string> head, string sheetname, PageVO<PurInquiryExportVO> pages);

#endif  //__EXECEXPORT_H__
