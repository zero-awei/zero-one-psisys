#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: kiva
 @Date: 2023/2/18 19:53

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#ifndef _BASBANKACCOUNTDO_H_
#define _BASBANKACCOUNTDO_H_
#include"../DoInclude.h"
class BasBankAccountDO {
	CC_SYNTHESIZE(string, id, Id);

	CC_SYNTHESIZE(std::string, value, Value);

public:
	BasBankAccountDO() {
		id = "";
		value = "";
	}

};
#endif