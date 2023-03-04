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
