#ifndef _BILLSTAGE_VO_
#define _BILLSTAGE_VO_

#include "../GlobalInclude.h"

	class BillStageVO
{
	// ½×¶Î±àºÅ
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ½×¶ÎÃû³Æ
	CC_SYNTHESIZE(string, name, Name);
public:
	// °ó¶¨JSON×ª»»·½·¨
	BIND_TO_JSON(BillStageVO, id, name);
};

#endif // !_SAMPLE_VO_