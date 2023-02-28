#pragma once

#ifndef __EXECEXPORT_H__
#define __EXECEXPORT_H__


#include "stdafx.h"
#include "api/ApiHelper.h"
#include "FastDfsClient.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/pur-inquiry/PurInquiryExportVO.h"
#include "../../domain/do/pur-inquiry/PurInquiryEntryDO.h"
#include "../../dao/pur-inquiry/PurInquiryDAO.h"


std::string execexport(vector<std::string> head, string sheetname, list<std::string>& exl);

#endif  //__EXECEXPORT_H__
