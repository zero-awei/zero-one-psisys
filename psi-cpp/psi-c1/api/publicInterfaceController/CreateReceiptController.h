#pragma once
#ifndef _CREATERECEIPTCONTROLLER_H_
#define _CREATERECEIPTCONTROLLER_H_
#include"../../domain/vo/JsonVO.h"
#include"../../domain/vo/publicInterfaceVO/CreateReceiptVO.h"
#include"../../domain/dto/publicInterfaceDTO/CreateReceiptDTO.h"
class CreateReceiptController {
public:
	CREATE_API_FUN_BODY(createReceipt, execCreateReceipt, CreateReceiptDTO);

private:
	JsonVO<CreateReceiptVO> execCreateReceipt(CreateReceiptDTO& dto);

	static map<string, int> ma;

};


#endif