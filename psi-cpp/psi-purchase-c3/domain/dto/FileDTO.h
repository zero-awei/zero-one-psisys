
#ifndef _FILEDTO_H_
#define _FILEDTO_H_

#include "../GlobalInclude.h"
#include <list>

/**
 * 定义一个文件上传传输数据模型
 */
class FileDTO
{
protected:
	// 上传文件路径列表
	CC_SYNTHESIZE_GET(std::list<std::string>, files, Files);
public:
	// 添加文件上传路径
	void addFile(std::string file) {
		files.push_back(file);
	}
};

#endif // _FILEDTO_H_