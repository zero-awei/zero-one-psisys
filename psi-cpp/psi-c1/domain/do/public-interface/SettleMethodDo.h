/**
 *Author c1-ruizi
 * 2023/2/22  15:46
 * �ӿڣ����㷽ʽ
 */

#pragma once
#ifndef _SETTLEMETHOD_DO_
#define _SETTLEMETHOD_DO_
#include "../DoInclude.h"

 /**
  * ���ݿ�ʵ����
  */
class SettleMethodDO
{
	// ���
	CC_SYNTHESIZE(string, id, Id);
	// ������
	CC_SYNTHESIZE(string, name, Name);
public:
	SettleMethodDO() {
		id = "";
		name = "";
	}
};

#endif // !_SETTLEMETHOD_DO_