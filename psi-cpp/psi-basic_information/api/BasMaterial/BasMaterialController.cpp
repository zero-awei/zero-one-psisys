#include "stdafx.h"
#include "BasMaterialController.h"
/*
//普通查询数据
JsonVO<PageVO<BasMaterialVO>> execQueryBasMaterial(const BasMaterialQuery& query, const PayloadDTO& payload) {

	//查询数据
	PageVO<BasMaterialVO> result;
	//响应结果
	return JsonVO<PageVO<BasMaterialVO>>(result, RS_SUCCESS);
}
//查看指定物料详情信息，即上述所有信息
JsonVO<BasMaterialVO> execQueryDetail(const BasMaterialQuery& query, const PayloadDTO& payload) {

	JsonVO <BasMaterialVO> result;
	return result;
}
//新增数据
JsonVO<BasMaterialVO> execAddBasMaterial(const BasMaterialDTO& dto) {
	JsonVO <BasMaterialVO> result;
	return result;
}
//修改数据
JsonVO<BasMaterialVO> execModifyBasMaterial(const BasMaterialDTO& dto) {
	JsonVO <BasMaterialVO> result;
	return result;
}
//删除数据
JsonVO<BasMaterialVO> execRemoveBasMaterial(const BasMaterialDTO& dto) {
	JsonVO <BasMaterialVO> result;
	return result;
}
//导入
JsonVO<PageVO<BasMaterialVO>> execImportBasMaterial(const BasMaterialDTO& dto) {
	//查询数据
	PageVO<BasMaterialVO> result;
	//响应结果
	return JsonVO<PageVO<BasMaterialVO>>(result, RS_SUCCESS);
}
//导出
JsonVO<string> execExportExecl(const BasMaterialQuery& query, const PayloadDTO& payload) {
	JsonVO <string> result;
	return result;
}
*/

JsonVO<PageVO<BasMaterialVO>> BasMaterialController::execQueryBasMaterial(const BasMaterialQuery& query, const PayloadDTO& payload)
{
	return JsonVO<PageVO<BasMaterialVO>>();
}

JsonVO<BasMaterialVO> BasMaterialController::execQueryDetail(const BasMaterialQuery& query, const PayloadDTO& payload)
{
	return JsonVO<BasMaterialVO>();
}

JsonVO<BasMaterialVO> BasMaterialController::execAddBasMaterial(const BasMaterialDTO& dto)
{
	return JsonVO<BasMaterialVO>();
}

JsonVO<BasMaterialVO> BasMaterialController::execModifyBasMaterial(const BasMaterialDTO& dto)
{
	return JsonVO<BasMaterialVO>();
}

JsonVO<BasMaterialVO> BasMaterialController::execRemoveBasMaterial(const BasMaterialDTO& dto)
{
	return JsonVO<BasMaterialVO>();
}

JsonVO<PageVO<BasMaterialVO>> BasMaterialController::execImportBasMaterial(const BasMaterialDTO& dto)
{
	return JsonVO<PageVO<BasMaterialVO>>();
}

JsonVO<string> BasMaterialController::execExportExecl(const BasMaterialQuery& query, const PayloadDTO& payload)
{
	return JsonVO<string>();
}
