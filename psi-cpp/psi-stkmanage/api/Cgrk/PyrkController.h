//#pragma once
///*
// Copyright Zero One Star. All rights reserved.
//
// @Author: awei
// @Date: 2022/10/25 0:27:04
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//	  https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//*/
//#ifndef _SAMPLE_CONTROLLER_
//#define _SAMPLE_CONTROLLER_
//
//#include "../psi-stkmanage/domain/do/PyrkBillDetailDO.h"
//#include "../psi-stkmanage/domain/do/PyrkBillListDO.h"
//#include "../psi-stkmanage/domain/dto/AddPyrkBillDTO.h"
//#include "../psi-stkmanage/domain/dto/ModifyPyrkBillDTO.h"
//#include "../psi-stkmanage/domain/query/QueryPyrkBillDetailQuery.h"
//#include "../psi-stkmanage/domain/query/QueryPyrkBillListQuery.h"
//#include "../psi-stkmanage/domain/vo/JsonVO.h"
//#include "../psi-stkmanage/domain/vo/Message.h"
//#include "../psi-stkmanage/domain/vo/PageVO.h"
//#include "../psi-stkmanage/domain/vo/ResultStatus.h"
//
////#include "../../domain/dto/sample/SampleDTO.h"
////#include "../../domain/dto/IDDTO.h"
////#include "../../domain/vo/sample/SampleVO.h"
////#include "../../domain/vo/PageVO.h"
////#include "../../domain/vo/JsonVO.h"
////#include "../../domain/dto/user/UserDTO.h"
////#include "../../domain/vo/user/UserVO.h"
//
///**
// * ʾ������������ʾ�����ӿڵ�ʹ��
// */
//class SampleController
//{
//public:
//	CREATE_API_FUN_QUERY_PAYLOAD(querySample, execQuerySample, SampleQuery);
//	CREATE_API_FUN_BODY(addSample, execAddSample, SampleDTO);
//	CREATE_API_FUN_BODY(modifySample, execModifySample, SampleDTO);
//	CREATE_API_FUN_BODY(removeSample, execRemoveSample, SampleDTO);
//	CREATE_API_FUN_BODY(removeById, execRemoveById, IntID);
//	CREATE_API_FUN_JSON(jsonSample, execJsonSample, SampleDTO);
//	CREATE_API_FUN_BODY_FILE(modifyUserInfo, execModifyUserInfo, UserDTO);
//private:
//	//��ʾ��ѯ����
//	JsonVO<PageVO<SampleVO>> execQuerySample(const SampleQuery& query, const PayloadDTO& payload);
//	//��ʾ��������
//	JsonVO<uint64_t> execAddSample(const SampleDTO& dto);
//	//��ʾ�޸�����
//	JsonVO<uint64_t> execModifySample(const SampleDTO& dto);
//
//};
//
//#endif // _SAMPLE_CONTROLLER_