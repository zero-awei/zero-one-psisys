#include "stdafx.h"
#include "CreateReceiptController.h"
#include<time.h> 
#include <sstream>

JsonVO<CreateReceiptVO> CreateReceiptController::execCreateReceipt(CreateReceiptDTO& dto)
{
    if (dto.getType() == "111") {

    }
    //dto.setType("CGSQ");
    CreateReceiptVO cr;
    /*
        xsbj
        xsdd
        cgsq
        cgxj
        gybj
        cgbj
        cgdd
        cgyfsq
        cgfksq
        cgrk
        pyrk
        zdrk
        qtrk
        xsck
        pkck
        qtck
        kcdb
        cbtz
        kcpd
        xsar
        qtar
        yshx
        xsys
        qtsk
        xssk
        xsthtksq
        xsthtk
        qtsk
        cgap
        qtap
        yfhx
        cgyf
        qtyfsq
        qtyf
        cgfk
        cgthtk
        qtfksq
        qtfk
        xsfp
        cgfp
    */
    string result = dto.getType();
    time_t now = time(NULL);
    tm* tm_t = localtime(&now);
    std::stringstream ss;
    map<string, int> ma;
    auto it = ma.find(result);
    int i = 1;
    if (it != ma.end()) {
        i = ++it->second;
    }
    else {
        ma.insert(pair<string, int>(result, 1));
    }
    string liushui;
    std::cout << i << endl;
    if (i < 10) liushui += "00" + to_string(i) + ""; 
    else if(i<100) liushui += "0" + to_string(i) + "";
    else if(i<1000) liushui += "0" + to_string(i) + "";
    result += "-" + to_string((tm_t->tm_year + 1900) % 100) + to_string(tm_t->tm_mon + 1) + to_string(tm_t->tm_mday) + "-" +liushui;
    //cr.setResult("CGSQ-230214-034");
    cr.setResult(result);
    JsonVO<CreateReceiptVO> res;
    res.success(cr);
    return res;
}
