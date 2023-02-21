package com.zeroone.star.titlepage.controller;

import com.zeroone.star.project.homepage.InformationApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.homepage.*;
import com.zeroone.star.titlepage.entity.HomePurchase;
import com.zeroone.star.titlepage.entity.HomeSale;
import com.zeroone.star.titlepage.service.*;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * <p>
 *  前端控制器
 * </p>
 *
 * @author yx
 * @since 2023-02-11
 */
@Controller
@RequestMapping("/homepage/onl-cgreport-head")
@Api(tags = "首页信息概况")
public class OnlCgreportHeadController implements InformationApis {

    @Autowired
    IStkInventoryService stkInventoryService;

    @Autowired
    IFinReceivableBalService receivableBalService;

    @Autowired
    IFinPayableBalService payableBalService;

    @Autowired
    IHomeSaleService homeSaleService;

    @Autowired
    IHomePurchaseService homePurchaseService;

    @Autowired
    IBasCustomerService customerService;

    @Autowired
    ISalOrderService salOrderService;

    /**
     * 查询系统收支概况
     * @return 系统收支概况，如果失败返回的数据为null
     */
    @ApiOperation("查询系统收支概况")
    @PostMapping("/query-Sys")
    @Override
    @ResponseBody
    public JsonVO<List<SystemRevenueAndExpenditureInformationVO>> querySystemInfo() {
        SystemRevenueAndExpenditureInformationVO inventoryVO = stkInventoryService.getInventoryVO();
        SystemRevenueAndExpenditureInformationVO customerDebtVO = receivableBalService.getCustomerDebtVO();
        SystemRevenueAndExpenditureInformationVO myDebtVO = payableBalService.getMyDebtVO();
        if(inventoryVO == null || customerDebtVO == null || myDebtVO == null){
            return JsonVO.fail(null);
        }
        return JsonVO.success(Arrays.asList(inventoryVO, customerDebtVO, myDebtVO));
    }

    /**
     * 查询销售概况
     * @return 销售概况视图对象，如果未能查到数据返回的数据为null
     */
    @ApiOperation("查询销售概况")
    @PostMapping("/query-Sale")
    @Override
    @ResponseBody
    public JsonVO<List<SaleInformationVO>> querySaleInfo() {
        List<HomeSale> homeSales = homeSaleService.listHomeSales();
        if(homeSales.isEmpty()){
            return JsonVO.fail(null);
        }
        List<SaleInformationVO> saleInformationVOList = new ArrayList<SaleInformationVO>();
        for(HomeSale homeSale : homeSales){
            SaleInformationVO saleInformationVO = new SaleInformationVO();
            saleInformationVO.setLabel(homeSale.getLabel());
            saleInformationVO.setMonthAmt(homeSale.getMAmt());
            saleInformationVO.setMonthCount(homeSale.getMCount());
            saleInformationVO.setTodayAmt(homeSale.getTAmt());
            saleInformationVO.setTodayCount(homeSale.getTCount());
            saleInformationVO.setWeekAmt(homeSale.getWAmt());
            saleInformationVO.setWeekCount(homeSale.getWCount());
            saleInformationVOList.add(saleInformationVO);
        }
        return JsonVO.success(saleInformationVOList);
    }

    /**
     * 查询采购概况
     * @return 采购概况视图对象，如果未能查到数据返回的数据为null
     */
    @ApiOperation("查询采购概况")
    @PostMapping("/query-Purchase")
    @Override
    @ResponseBody
    public JsonVO<List<PurchaseInformationVO>> queryPurchaseInfo() {
        List<HomePurchase> homePurchases = homePurchaseService.listHomePurchases();
        if(homePurchases.isEmpty()){
            return JsonVO.fail(null);
        }
        List<PurchaseInformationVO> purchaseInformationVOList = new ArrayList<>();
        for(HomePurchase homePurchase : homePurchases){
            PurchaseInformationVO purchaseInformationVO = new PurchaseInformationVO();
            purchaseInformationVO.setLabel(homePurchase.getLabel());
            purchaseInformationVO.setMonthAmt(homePurchase.getMAmt());
            purchaseInformationVO.setMonthCount(homePurchase.getMCount());
            purchaseInformationVO.setTodayAmt(homePurchase.getTAmt());
            purchaseInformationVO.setTodayCount(homePurchase.getTCount());
            purchaseInformationVO.setWeekAmt(homePurchase.getWAmt());
            purchaseInformationVO.setWeekCount(homePurchase.getWCount());
            purchaseInformationVOList.add(purchaseInformationVO);
        }
        return JsonVO.success(purchaseInformationVOList);
    }

    /**
     * 查询客户数量概况
     * @return 客户数量视图对象
     */
    @ApiOperation("查询客户数量概况")
    @PostMapping("/query-Customer")
    @Override
    @ResponseBody
    public JsonVO<List<CustomerInformationVO>> queryCustomerInfo() {
        ArrayList<CustomerInformationVO> customerInformationList = new ArrayList<>();
        CustomerInformationVO customerOnTheDay = customerService.countCustomerOnTheDay();
        CustomerInformationVO customerOfTheWeek = customerService.countCustomerOfTheWeek();
        CustomerInformationVO customerOnTheMonth = customerService.countCustomerOnTheMonth();
        CustomerInformationVO countTotalCustomer = customerService.countTotalCustomer();
        customerInformationList.add(customerOnTheDay);
        customerInformationList.add(customerOfTheWeek);
        customerInformationList.add(customerOnTheMonth);
        customerInformationList.add(countTotalCustomer);
        return JsonVO.success(customerInformationList);
    }

    /**
     * 查询销售金额概况
     * @return 销售金额视图对象
     */
    @ApiOperation("查询销售金额概况")
    @PostMapping("/query-SalesAmount")
    @Override
    @ResponseBody
    public JsonVO<List<SalesAmountInformationVO>> querySalesAmountInfo() {
        return JsonVO.success(salOrderService.listSalesAmount());
    }
}

