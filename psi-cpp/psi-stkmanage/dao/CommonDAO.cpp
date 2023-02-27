#include "stdafx.h"
#include "CommonDAO.h"
#include <sstream>
#include "FastDfsClient.h"
#include "StringMapper.h"
#include "IntMapper.h"

string CommonDAO::selectOrgCodeByUsername(const string& username)
{
    string sql = "SELECT d.org_code FROM sys_depart d, sys_user u, sys_user_depart ud WHERE d.id = ud.dep_id AND u.id = ud.user_id AND u.username = ?";
    StringMapper mapper;
    list<string> ret = sqlSession->executeQuery<string, StringMapper>(sql, mapper, "%s", username);
    if (ret.empty()) {
        return "";
    }
    return *ret.begin();
}

string CommonDAO::selectBillIdByBillNo(const string& billNo)
{
    string sql = "SELECT `id` FROM `stk_io` WHERE `bill_no` = ?";
    StringMapper mapper;
    list<string> ret = sqlSession->executeQuery<string, StringMapper>(sql, mapper, "%s", billNo);
    if (ret.empty()) {
        return "";
    }
    return *ret.begin();
}

string CommonDAO::selectAttachmentByBillNo(const string& billNo)
{
    string sql = "SELECT `attachment` FROM `stk_io` WHERE `bill_no`=?";
    StringMapper mapper;
    list<string> ret = sqlSession->executeQuery<string, StringMapper>(sql, mapper, "%s", billNo);
    if (ret.empty()) {
        return "";
    }
    return *ret.begin();
}

string CommonDAO::selectWarehouseIdByAuxName(const string& warehouse)
{
    string sql = "SELECT `id` FROM `bas_warehouse` WHERE `aux_name`=?";
    StringMapper mapper;
    list<string> ret = sqlSession->executeQuery<string, StringMapper>(sql, mapper, "%s", warehouse);
    if (ret.empty()) {
        return "";
    }
    return *ret.begin();
}

string CommonDAO::selectMaterialIdByAuxName(const string& material)
{
    string sql = "SELECT `id` FROM `bas_material` WHERE `aux_name`=?";
    StringMapper mapper;
    list<string> ret = sqlSession->executeQuery<string, StringMapper>(sql, mapper, "%s", material);
    if (ret.empty()) {
        return "";
    }
    return *ret.begin();
}

string CommonDAO::selectUnitIdByName(const string& unit)
{
    string sql = "SELECT `id` FROM `bas_unit` WHERE `name`=?";
    StringMapper mapper;
    list<string> ret = sqlSession->executeQuery<string, StringMapper>(sql, mapper, "%s", unit);
    if (ret.empty()) {
        return "";
    }
    return *ret.begin();
}

string CommonDAO::selectSupplyIdByAuxName(const string& supplier)
{
    string sql = "SELECT `id` FROM `bas_supplier` WHERE `aux_name`=?";
    StringMapper mapper;
    list<string> ret = sqlSession->executeQuery<string, StringMapper>(sql, mapper, "%s", supplier);
    if (ret.empty()) {
        return "";
    }
    return *ret.begin();
}

string CommonDAO::insertAttachment(const string& fileName)
{
#ifdef LINUX
    // 定义客户端对象
    FastDfsClient client("conf/client.conf", 3);
#else
    // 定义客户端对象
    FastDfsClient client("127.0.0.1");
#endif
    return client.uploadFile(fileName);
}

bool CommonDAO::deleteAttachment(const string& fileName)
{
#ifdef LINUX
    // 定义客户端对象
    FastDfsClient client("conf/client.conf", 3);
#else
    // 定义客户端对象
    FastDfsClient client("192.168.235.251");
#endif
    return client.deleteFile(fileName);
}

list<int> CommonDAO::selectEntryNoByBillNo(const string& billNo)
{
    string sql = "SELECT `entry_no` FROM `stk_io_entry` WHERE `bill_no`=?";
    IntMapper mapper;
    list<int> ret = sqlSession->executeQuery<int, IntMapper>(sql, mapper, "%s", billNo);
    if (ret.empty()) {
        return list<int>();
    }
    return ret;
}
