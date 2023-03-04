
#include "stdafx.h"
#include "Router.h"
#include "Zdrk/ZdrkController.h"
#include "api/Aspect.h"
#include "domain/vo/JsonVO.h"
#include "Pyrk/PyrkController.h"

#include "Cgthck/CgthckController.h"
#include "cgrk/CgrkController.h"
#include "Qtrk/QtrkController.h"
#include "Pyrk/PyrkController.h"


#ifdef HTTP_SERVER_DEMO
#include "sample/SampleController.h"
#include "user/DepartController.h"
#include "uselib/ws/TestWs.h"
#endif

Router::Router(http_server* sever)
{
	this->server = sever;
}

void Router::initRouter()
{
	
	server->set_public_root_directory("public");
	server->set_static_dir("static/file");



	createCgrkRouter();
	createIncreaseTonRouter();
	createCgthckRouter();
	createQtrkRouter();
	createPyrkRouter();




}


//采购入库路由
void Router::createCgrkRouter()
{
	BIND_GET_ROUTER(server, "/query-cgrk-bill-list", &CgrkController::queryCgrkBillList, nullptr);
	BIND_POST_ROUTER(server, "/query-cgrk-bill-list-advanced", &CgrkController::queryCgrkBillListAdvanced, nullptr);
	BIND_GET_ROUTER(server, "/query-cgrk-bill-details", &CgrkController::queryCgrkBillDetails, nullptr);
	BIND_GET_ROUTER(server, "/query-pur-order-list", &CgrkController::queryPurOrderList, nullptr);
	BIND_GET_ROUTER(server, "/query-pur-order-entry", &CgrkController::queryPurOrderEntry, nullptr);
	BIND_POST_ROUTER(server, "/add-cgrk-bill", &CgrkController::addCgrkBill, nullptr);
	BIND_PUT_ROUTER(server, "/modify-cgrk-bill", &CgrkController::modifyCgrkBill, nullptr);
	BIND_DEL_ROUTER(server, "/delete-cgrk-bill", &CgrkController::removeCgrkBill, nullptr);
	BIND_PUT_ROUTER(server, "/modify-cgrk-bill-state", &CgrkController::modifyCgrkBillState, nullptr);
	BIND_POST_ROUTER(server, "/import-cgrk-file", &CgrkController::importCgrkFile, nullptr);
	BIND_GET_ROUTER(server, "/export-cgrk-file", &CgrkController::exportCgrkFile, nullptr);
}
//涨吨入库路由
void Router::createIncreaseTonRouter()
{
	BIND_GET_ROUTER(server, "/query-zdrk-bill-list", &ZdrkController::queryZdrkBillList, nullptr);
	BIND_GET_ROUTER(server, "/query-zdrk-bill-details", &ZdrkController::queryZdrkBillDetails, nullptr);
	BIND_POST_ROUTER(server, "/post-zdrk-bill", &ZdrkController::addZdrkrkBill, nullptr);
	BIND_PUT_ROUTER(server, "/modify-zdrk-bill-approval", &ZdrkController::modifyBillApproval, nullptr);
	BIND_PUT_ROUTER(server, "/modify-zdrk-bill", &ZdrkController::modifyZdrkBill, nullptr);
	BIND_DEL_ROUTER(server, "/delete-zdrk-bill-by-id", &ZdrkController::removeZdrkBill, nullptr);
	BIND_PUT_ROUTER(server, "/modify-zdrk-bill-state-to-close", &ZdrkController::modifyZdrkBillStateToClose, nullptr);
	BIND_PUT_ROUTER(server, "/modify-zdrk-bill-state-to-unclose", &ZdrkController::modifyZdrkBillStateToUnclose, nullptr);
	BIND_PUT_ROUTER(server, "/modify-zdrk-bill-state-to-void", &ZdrkController::modifyZdrkBillStateToVoid, nullptr);
}
//采购退货出库路由
void Router::createCgthckRouter()
{
	BIND_GET_ROUTER(server, "/query-cgthck-bill-list", &CgthckController::queryCgthcBillk, nullptr);
	BIND_GET_ROUTER(server, "/query-cgthck-bill-details", &CgthckController::queryCgthckBillDetail, nullptr);
	BIND_GET_ROUTER(server, "/query-cgrk-bill-list", &CgthckController::queryCgrkEntryList, nullptr);
	BIND_POST_ROUTER(server, "/add-cgthck-bill", &CgthckController::addCgthckBill, nullptr);
	BIND_PUT_ROUTER(server, "/modify-cgthck-bill", &CgthckController::modifyCgthckBill, nullptr);
	BIND_PUT_ROUTER(server, "/modify-cgthck-bill-approval", &CgthckController::modifyCgthckApproval, nullptr);
	BIND_PUT_ROUTER(server, "/modify-cgthck-bill-status-to-close", &CgthckController::modifyCgthckBillStatusToClosed, nullptr);
	BIND_PUT_ROUTER(server, "/modify-cgthck-bill-status-to-unclose", &CgthckController::modifyCgthckBillStatusToUnclosed, nullptr);
	BIND_PUT_ROUTER(server, "/modify-cgthck-bill-status-to-voided", &CgthckController::modifyCgthckBillStatusToVoided, nullptr);
	BIND_DEL_ROUTER(server, "/delete-cgthck-bill-by-id", &CgthckController::deleteCgthckBill, nullptr);
	BIND_DEL_ROUTER(server, "/delete-cgthck-bill-detail-by-id", &CgthckController::deleteCgthckBillDetail, nullptr);
	BIND_POST_ROUTER(server, "/import-cgthck-file", &CgthckController::importCgthckFile, nullptr);
	BIND_GET_ROUTER(server, "/export-cgthck-file", &CgthckController::exportCgthckFile, nullptr);
}

//其他入库路由
void Router::createQtrkRouter()
{
	
	BIND_GET_ROUTER(server, "/query-qtrk-bill-list", &QtrkController::queryQtrk, nullptr);
	BIND_GET_ROUTER(server, "/query-qtrk-bill-details", &QtrkController::queryQtrkBillDetails, nullptr);
	BIND_POST_ROUTER(server, "/add-qtrk-bill", &QtrkController::addQtrk, nullptr);
	BIND_PUT_ROUTER(server, "/modify-qtrk-bill", &QtrkController::modifyQtrk, nullptr);
	BIND_PUT_ROUTER(server, "/modify-qtrk-bill-approval", &QtrkController::modifyQtrkApproval, nullptr);
	BIND_DEL_ROUTER(server, "/delete-qtrk-bill", &QtrkController::removeQtrk, nullptr);
	BIND_PUT_ROUTER(server, "/modify-qtrk-bill-state", &QtrkController::modifyQtrkState, nullptr);
	//BIND_POST_ROUTER(server, "/import-qtrk-file", &QtrkController::importFileQtrk, nullptr);
	//BIND_POST_ROUTER(server, "/export-qtrk-file", &QtrkController::exportFileQtrk, nullptr);

}

//盘盈入库路由
void Router::createPyrkRouter()
{
	BIND_PUT_ROUTER(server, "/modify-pyrk-bill-approval", &PyrkController::modifyBillApproval, nullptr);
	BIND_GET_ROUTER(server, "/query-pyrk-bill-list", &PyrkController::queryPyrkBillList, nullptr);
	BIND_GET_ROUTER(server, "/query-pyrk-bill-details", &PyrkController::queryPyrkBillDetails, nullptr);
	BIND_POST_ROUTER(server, "/add-pyrk-bill", &PyrkController::addBillDetailed, nullptr);
	BIND_PUT_ROUTER(server, "/modify-pyrk-bill", &PyrkController::updateBillDetailed, nullptr);
	BIND_DEL_ROUTER(server, "/delete-pyrk-bill-by-id", &PyrkController::removePyrkBillById, nullptr);
	BIND_PUT_ROUTER(server, "/modify-pyrk-bill-state-to-close", &PyrkController::modifyPyrkBillStateToClose, nullptr);
	BIND_PUT_ROUTER(server, "/modify-pyrk-bill-state-to-unclose", &PyrkController::modifyPyrkBillStateToUnclose, nullptr);
	BIND_PUT_ROUTER(server, "/modify-pyrk-bill-state-to-void", &PyrkController::modifyPyrkBillStateToVoid, nullptr);
	BIND_POST_ROUTER(server, "/import-pyrk-file", &PyrkController::importPyrkFile, nullptr);
	BIND_GET_ROUTER(server, "/export-pyrk-file", &PyrkController::exportPyrkFile, nullptr);
}

