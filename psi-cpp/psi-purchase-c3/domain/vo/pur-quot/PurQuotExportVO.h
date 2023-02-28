#pragma once
#ifndef _PUR_QUOT_EXPORT_VO_
#define _PUR_QUOT_EXPORT_VO_

#include "../../GlobalInclude.h"
class PurQuotExportVO {
  CC_SYNTHESIZE(std::string, file_name, File_name)
public:
  BIND_TO_JSON(PurQuotExportVO, file_name);
  PurQuotExportVO(){}
  PurQuotExportVO(std::string &filed_name) : file_name(filed_name){}
};

#endif // !
