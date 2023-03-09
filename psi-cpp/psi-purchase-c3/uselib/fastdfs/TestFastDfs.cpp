/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/24 23:29:51

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
#include "stdafx.h"
#include "TestFastDfs.h"
#include "FastDfsClient.h"
#include <iostream>

void TestFastDfs::testDfs(string fileName)
{
#ifdef LINUX
	//����ͻ��˶���
	FastDfsClient client("conf/client.conf", 3);
#else
	//����ͻ��˶���
	//FastDfsClient client("192.168.220.128");
	FastDfsClient client("1.15.240.108");			//������Ҫдfastdfs�������������Ǳ��ط�����
#endif

	//�����ϴ�
	std::string fieldName = client.uploadFile(fileName);
	std::cout << "upload fieldname is : " << fieldName << std::endl;
	//��������
	if (!fieldName.empty())
	{
		std::string path = "./public/fastdfs";
		fileName = client.downloadFile(fieldName, &path);
		std::cout << "download savepath is : " << fileName << std::endl;
	}
	//����ɾ���ļ�
	/*
	if (!fieldName.empty())
	{
		std::cout << "delete file result is : " << client.deleteFile(fieldName) << std::endl;
	}
	*/
}