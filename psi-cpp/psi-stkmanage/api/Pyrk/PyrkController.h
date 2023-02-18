#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

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
#ifndef _SAMPLE_CONTROLLER_
#define _SAMPLE_CONTROLLER_

#include "../psi-stkmanage/stdafx.h"

#include "../psi-stkmanage/domain/query/Pyrk/QueryPyrkBillDetailQuery.h"
#include "../psi-stkmanage/domain/query/Pyrk/QueryPyrkBillListQuery.h"

#include "../psi-stkmanage/domain/vo/Pyrk/QueryPyrkBillDetailVO.h"
#include "../psi-stkmanage/domain/vo/Pyrk/QueryPyrkBillListVO.h"

#include "../psi-stkmanage/domain/do/Pyrk/PyrkBillDetailDO.h"
#include "../psi-stkmanage/domain/do/Pyrk/PyrkBillListDO.h"

#include "../psi-stkmanage/domain/dto/Pyrk/AddPyrkBillDTO.h"
#include "../psi-stkmanage/domain/dto/Pyrk/ModifyPyrkBillDTO.h"


#include "../psi-stkmanage/domain/vo/JsonVO.h"
#include "../psi-stkmanage/domain/vo/Message.h"
#include "../psi-stkmanage/domain/vo/PageVO.h"
#include "../psi-stkmanage/domain/vo/ResultStatus.h",

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */

class PyrkController {
public:
	CREATE_API_FUN_QUERY(queryPyrkBillDetail, execQueryPyrkBillDetail, QueryPyrkBillDetailQuery);
	CREATE_API_FUN_QUERY(queryPyrkBillList, execQueryPyrkBillList, QueryPyrkBillListQuery);
	/*CREATE_API_FUN_BODY(addPyrkBill, execAddPyrkBill, AddPyrkBillDTO);
	CREATE_API_FUN_BODY(modifyPyrkBill, execModifyPyrkBill, ModifyPyrkBillDTO);
	CREATE_API_FUN_BODY(removePyrkBill, execRemovePyrkBill, StringID);
	CREATE_API_FUN_BODY(modifyPyrkBillState, execModifyPyrkBillState, ModifyPyrkBillStateDTO);
	CREATE_API_FUN_BODY_FILE(ImportPyrkFile, execImportPyrkFile, ImportPyrkFileDTO);
	CREATE_API_FUN_QUERY3(EmportPyrkFile, execEmportPyrkFile);*/
private:
	//��ѯ������ϸ��Ϣ
	JsonVO<QueryPyrkBillDetailVO> execQueryPyrkBillDetail(const QueryPyrkBillDetailQuery& query);
	//��ѯ�����б�
	JsonVO<PageVO<QueryPyrkBillListVO>> execQueryPyrkBillList(const QueryPyrkBillListQuery& query);
	////��ӵ���
	//JsonVO<uint64_t> execAddPyrkBill(const AddPyrkBillDTO& dto);
	////�޸ĵ���
	//JsonVO<uint64_t> execModifyPyrkBill(const ModifyPyrkBillDTO& dto);
	////ɾ������
	//JsonVO<uint64_t> execRemovePyrkBill(const StringID& dto);
	////�޸ĵ���״̬
	//JsonVO<uint64_t> execModifyPyrkBillState(const ModifyPyrkBillStateDTO& dto);
	////����
	//JsonVO<uint64_t> execImportPyrkFile(const ImportPyrkFileDTO& dto);
	////����
	//JsonVO<std::string>  execEmportPyrkFile();
};

#endif // _SAMPLE_CONTROLLER_