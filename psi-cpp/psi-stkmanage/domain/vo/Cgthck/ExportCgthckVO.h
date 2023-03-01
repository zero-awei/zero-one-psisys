#pragma once
#ifndef _EXPORT_CGTHCK_VO_
#define _EXPORT_CGTHCK_VO_\

#include "../../GlobalInclude.h"
class ExportCgthckVO
{
	CC_SYNTHESIZE(std::string, fileName, FileName);
public:
	BIND_TO_JSON(ExportCgthckVO, fileName);
	ExportCgthckVO() = default;
	ExportCgthckVO(std::string& fName) : fileName(fName){}
};

#endif // !_EXPORT_CGTHCK_VO_
