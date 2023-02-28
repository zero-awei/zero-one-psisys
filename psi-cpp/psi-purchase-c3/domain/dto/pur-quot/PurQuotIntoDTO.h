#pragma once
#ifndef _PUR_QUOT_INTO_DTO_H_
#define _PUR_QUOT_INTO_DTO_H_
#include "../FileDTO.h"

class PurQuotIntoDTO : public FileDTO {
public:
	friend void from_json(const json& j, PurQuotIntoDTO& t) { // NOLINT
	}
};

#endif // !
