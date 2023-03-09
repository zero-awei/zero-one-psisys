#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 111
 @Date: 2023/02/15 21.02

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
#ifndef _BASMATERIALDETAIL_QUERY_
#define _BASMATERIALDETAIL_QUERY_

class BasMaterialDetailQuery {
	CC_SYNTHESIZE(uint64_t, id, Id);
public:
	friend void from_json(const json& j, BasMaterialDetailQuery& t) {
		BIND_FROM_TO_ULL(j, t, id);
	}
};
#endif // !_BASMATERIALDETAIL_QUERY_