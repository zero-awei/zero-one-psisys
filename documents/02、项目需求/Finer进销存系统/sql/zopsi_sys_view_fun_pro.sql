-- Change DataBase
USE `zopsi_sys`;
SET FOREIGN_KEY_CHECKS = 0;
SET GLOBAL log_bin_trust_function_creators = 1;

-- ----------------------------
-- Function structure for fn_first_day
-- ----------------------------
DROP FUNCTION IF EXISTS `fn_first_day`;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` FUNCTION `fn_first_day`(`d` date) RETURNS date
BEGIN
	RETURN date_sub(date_format(d,'%y-%m-%d'),interval extract(day from d)-1 day);
END
;;
DELIMITER ;

-- ----------------------------
-- Function structure for fn_first_day_of_ym
-- ----------------------------
DROP FUNCTION IF EXISTS `fn_first_day_of_ym`;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` FUNCTION `fn_first_day_of_ym`(`y` smallint,`m` smallint) RETURNS date
BEGIN
	RETURN DATE(CONCAT(y, '-', m, '-', 1));
END
;;
DELIMITER ;

-- ----------------------------
-- Function structure for fn_last_day_of_ym
-- ----------------------------
DROP FUNCTION IF EXISTS `fn_last_day_of_ym`;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` FUNCTION `fn_last_day_of_ym`(`y` smallint,`m` smallint) RETURNS date
BEGIN
	RETURN LAST_DAY(DATE(CONCAT(y, '-', m, '-', 1)));
END
;;
DELIMITER ;


-- ----------------------------
-- View structure for stk_io_entry_std
-- ----------------------------
DROP VIEW IF EXISTS `stk_io_entry_std`;
CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `stk_io_entry_std` AS select `e`.`id` AS `id`,`e`.`mid` AS `mid`,`e`.`material_id` AS `material_id`,`e`.`warehouse_id` AS `warehouse_id`,`e`.`batch_no` AS `batch_no`,`m`.`unit_id` AS `unit_id`,`e`.`stock_io_direction` AS `stock_io_direction`,round(((`e`.`qty` * `eu`.`factor`) / `mu`.`factor`),3) AS `qty`,`e`.`cost` AS `cost` from (((`stk_io_entry` `e` join `bas_unit` `eu` on((`e`.`unit_id` = `eu`.`id`))) join `bas_material` `m` on((`e`.`material_id` = `m`.`id`))) join `bas_unit` `mu` on((`m`.`unit_id` = `mu`.`id`))) ;

-- ----------------------------
-- View structure for bill_not_effective
-- ----------------------------
DROP VIEW IF EXISTS `bill_not_effective`;
CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `bill_not_effective` AS select 1 AS `seq`,'销售报价' AS `name`,`b`.`id` AS `id`,`b`.`bill_no` AS `bill_no`,`b`.`bill_date` AS `bill_date` from `sal_quot` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0) and (`b`.`is_effective` = 0)) union select 2 AS `seq`,'销售订单' AS `name`,`b`.`id` AS `id`,`b`.`bill_no` AS `bill_no`,`b`.`bill_date` AS `bill_date` from `sal_order` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0) and (`b`.`is_effective` = 0)) union select 3 AS `seq`,'出库单' AS `name`,`b`.`id` AS `id`,`b`.`bill_no` AS `bill_no`,`b`.`bill_date` AS `bill_date` from `stk_io` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0) and (`b`.`is_effective` = 0) and (`b`.`stock_io_type` like '2%')) union select 4 AS `seq`,'应收单' AS `name`,`b`.`id` AS `id`,`b`.`bill_no` AS `bill_no`,`b`.`bill_date` AS `bill_date` from `fin_receivable` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0) and (`b`.`is_effective` = 0)) union select 5 AS `seq`,'销售退货退款申请' AS `name`,`b`.`id` AS `id`,`b`.`bill_no` AS `bill_no`,`b`.`bill_date` AS `bill_date` from `fin_receipt_req` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0) and (`b`.`is_effective` = 0)) union select 6 AS `seq`,'收款单' AS `name`,`b`.`id` AS `id`,`b`.`bill_no` AS `bill_no`,`b`.`bill_date` AS `bill_date` from `fin_receipt` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0) and (`b`.`is_effective` = 0)) union select 7 AS `seq`,'应收核销' AS `name`,`b`.`id` AS `id`,`b`.`bill_no` AS `bill_no`,`b`.`bill_date` AS `bill_date` from `fin_receivable_check` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0) and (`b`.`is_effective` = 0)) union select 8 AS `seq`,'销售发票登记' AS `name`,`b`.`id` AS `id`,`b`.`bill_no` AS `bill_no`,`b`.`bill_date` AS `bill_date` from `fin_sal_invoice` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0) and (`b`.`is_effective` = 0)) union select 9 AS `seq`,'采购申请' AS `name`,`b`.`id` AS `id`,`b`.`bill_no` AS `bill_no`,`b`.`bill_date` AS `bill_date` from `pur_req` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0) and (`b`.`is_effective` = 0)) union select 10 AS `seq`,'采购询价' AS `name`,`b`.`id` AS `id`,`b`.`bill_no` AS `bill_no`,`b`.`bill_date` AS `bill_date` from `pur_inquiry` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0) and (`b`.`is_effective` = 0)) union select 11 AS `seq`,'供应报价' AS `name`,`b`.`id` AS `id`,`b`.`bill_no` AS `bill_no`,`b`.`bill_date` AS `bill_date` from `pur_quot` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0) and (`b`.`is_effective` = 0)) union select 12 AS `seq`,'采购比价' AS `name`,`b`.`id` AS `id`,`b`.`bill_no` AS `bill_no`,`b`.`bill_date` AS `bill_date` from `pur_compare` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0) and (`b`.`is_effective` = 0)) union select 13 AS `seq`,'采购订单' AS `name`,`b`.`id` AS `id`,`b`.`bill_no` AS `bill_no`,`b`.`bill_date` AS `bill_date` from `pur_order` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0) and (`b`.`is_effective` = 0)) union select 14 AS `seq`,'入库单' AS `name`,`b`.`id` AS `id`,`b`.`bill_no` AS `bill_no`,`b`.`bill_date` AS `bill_date` from `stk_io` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0) and (`b`.`is_effective` = 0) and (`b`.`stock_io_type` like '1%')) union select 15 AS `seq`,'应付单' AS `name`,`b`.`id` AS `id`,`b`.`bill_no` AS `bill_no`,`b`.`bill_date` AS `bill_date` from `fin_payable` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0) and (`b`.`is_effective` = 0)) union select 16 AS `seq`,'付款申请' AS `name`,`b`.`id` AS `id`,`b`.`bill_no` AS `bill_no`,`b`.`bill_date` AS `bill_date` from `fin_payment_req` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0) and (`b`.`is_effective` = 0)) union select 17 AS `seq`,'付款单' AS `name`,`b`.`id` AS `id`,`b`.`bill_no` AS `bill_no`,`b`.`bill_date` AS `bill_date` from `fin_payment` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0) and (`b`.`is_effective` = 0)) union select 18 AS `seq`,'应付核销' AS `name`,`b`.`id` AS `id`,`b`.`bill_no` AS `bill_no`,`b`.`bill_date` AS `bill_date` from `fin_payable_check` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0) and (`b`.`is_effective` = 0)) union select 19 AS `seq`,'采购发票登记' AS `name`,`b`.`id` AS `id`,`b`.`bill_no` AS `bill_no`,`b`.`bill_date` AS `bill_date` from `fin_pur_invoice` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0) and (`b`.`is_effective` = 0)) union select 20 AS `seq`,'库存调拨、成本调整' AS `name`,`b`.`id` AS `id`,`b`.`bill_no` AS `bill_no`,`b`.`bill_date` AS `bill_date` from `stk_io` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0) and (`b`.`is_effective` = 0) and (`b`.`stock_io_type` > '2')) union select 21 AS `seq`,'库存盘点' AS `name`,`b`.`id` AS `id`,`b`.`bill_no` AS `bill_no`,`b`.`bill_date` AS `bill_date` from `stk_check` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0) and (`b`.`is_effective` = 0));

-- ----------------------------
-- View structure for fin_payable_bal
-- ----------------------------
DROP VIEW IF EXISTS `fin_payable_bal`;
CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `fin_payable_bal` AS select `c`.`id` AS `id`,`c`.`id` AS `supplier_id`,`c`.`name` AS `supplier_name`,((ifnull(`s`.`begin_credit_bal`,0) + ifnull(`pyb`.`amt`,0)) - ifnull(`pyt`.`amt`,0)) AS `credit_bal` from (((`zopsi_sys`.`bas_supplier` `c` left join `zopsi_sys`.`fin_payable_sum` `s` on(((`c`.`id` = `s`.`supplier_id`) and (((`s`.`year` * 100) + `s`.`month`) = (select ((`zopsi_sys`.`bas_biz_period`.`year` * 100) + `zopsi_sys`.`bas_biz_period`.`month`) from `zopsi_sys`.`bas_biz_period` limit 1))))) left join (select `zopsi_sys`.`fin_payable`.`supplier_id` AS `supplier_id`,sum(`zopsi_sys`.`fin_payable`.`amt`) AS `amt` from `zopsi_sys`.`fin_payable` where ((`zopsi_sys`.`fin_payable`.`is_effective` = 1) and (`zopsi_sys`.`fin_payable`.`is_voided` = 0) and (`zopsi_sys`.`fin_payable`.`bill_date` >= (select `fn_first_day_of_ym`(`zopsi_sys`.`bas_biz_period`.`year`,`zopsi_sys`.`bas_biz_period`.`month`) from `zopsi_sys`.`bas_biz_period` limit 1))) group by `zopsi_sys`.`fin_payable`.`supplier_id`) `pyb` on((`c`.`id` = `pyb`.`supplier_id`))) left join (select `zopsi_sys`.`fin_payment`.`supplier_id` AS `supplier_id`,sum(`zopsi_sys`.`fin_payment`.`amt`) AS `amt` from `zopsi_sys`.`fin_payment` where ((`zopsi_sys`.`fin_payment`.`is_effective` = 1) and (`zopsi_sys`.`fin_payment`.`is_voided` = 0) and (`zopsi_sys`.`fin_payment`.`bill_date` >= (select `fn_first_day_of_ym`(`zopsi_sys`.`bas_biz_period`.`year`,`zopsi_sys`.`bas_biz_period`.`month`) from `zopsi_sys`.`bas_biz_period` limit 1))) group by `zopsi_sys`.`fin_payment`.`supplier_id`) `pyt` on((`c`.`id` = `pyt`.`supplier_id`))) where (`c`.`is_enabled` = 1) ;

-- ----------------------------
-- View structure for fin_receivable_bal
-- ----------------------------
DROP VIEW IF EXISTS `fin_receivable_bal`;
CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `fin_receivable_bal` AS select `c`.`id` AS `id`,`c`.`id` AS `customer_id`,`c`.`name` AS `customer_name`,((ifnull(`s`.`begin_debit_bal`,0) + ifnull(`rcv`.`amt`,0)) - ifnull(`rcp`.`amt`,0)) AS `debit_bal` from (((`zopsi_sys`.`bas_customer` `c` left join `zopsi_sys`.`fin_receivable_sum` `s` on(((`c`.`id` = `s`.`customer_id`) and (((`s`.`year` * 100) + `s`.`month`) = (select ((`zopsi_sys`.`bas_biz_period`.`year` * 100) + `zopsi_sys`.`bas_biz_period`.`month`) from `zopsi_sys`.`bas_biz_period` limit 1))))) left join (select `zopsi_sys`.`fin_receivable`.`customer_id` AS `customer_id`,sum(`zopsi_sys`.`fin_receivable`.`amt`) AS `amt` from `zopsi_sys`.`fin_receivable` where ((`zopsi_sys`.`fin_receivable`.`is_effective` = 1) and (`zopsi_sys`.`fin_receivable`.`is_voided` = 0) and (`zopsi_sys`.`fin_receivable`.`bill_date` >= (select `fn_first_day_of_ym`(`zopsi_sys`.`bas_biz_period`.`year`,`zopsi_sys`.`bas_biz_period`.`month`) from `zopsi_sys`.`bas_biz_period` limit 1))) group by `zopsi_sys`.`fin_receivable`.`customer_id`) `rcv` on((`c`.`id` = `rcv`.`customer_id`))) left join (select `zopsi_sys`.`fin_receipt`.`customer_id` AS `customer_id`,sum(`zopsi_sys`.`fin_receipt`.`amt`) AS `amt` from `zopsi_sys`.`fin_receipt` where ((`zopsi_sys`.`fin_receipt`.`is_effective` = 1) and (`zopsi_sys`.`fin_receipt`.`is_voided` = 0) and (`zopsi_sys`.`fin_receipt`.`bill_date` >= (select `fn_first_day_of_ym`(`zopsi_sys`.`bas_biz_period`.`year`,`zopsi_sys`.`bas_biz_period`.`month`) from `zopsi_sys`.`bas_biz_period` limit 1))) group by `zopsi_sys`.`fin_receipt`.`customer_id`) `rcp` on((`c`.`id` = `rcp`.`customer_id`))) where (`c`.`is_enabled` = 1) ;

-- ----------------------------
-- View structure for home_purchase
-- ----------------------------
DROP VIEW IF EXISTS `home_purchase`;
CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `home_purchase` AS select '订单' AS `label`,`t`.`count` AS `t_count`,`t`.`amt` AS `t_amt`,`w`.`count` AS `w_count`,`w`.`amt` AS `w_amt`,`m`.`count` AS `m_count`,`m`.`amt` AS `m_amt` from ((((select count(1) AS `count`,ifnull(sum(`zopsi_sys`.`pur_order`.`amt`),0) AS `amt` from `zopsi_sys`.`pur_order` where ((`zopsi_sys`.`pur_order`.`is_effective` = 1) and (`zopsi_sys`.`pur_order`.`is_voided` = 0) and (`zopsi_sys`.`pur_order`.`effective_time` >= cast(sysdate() as date))))) `t` join (select count(1) AS `count`,ifnull(sum(`zopsi_sys`.`pur_order`.`amt`),0) AS `amt` from `zopsi_sys`.`pur_order` where ((`zopsi_sys`.`pur_order`.`is_effective` = 1) and (`zopsi_sys`.`pur_order`.`is_voided` = 0) and (yearweek(`zopsi_sys`.`pur_order`.`effective_time`,1) = yearweek(sysdate(),1)))) `w`) join (select count(1) AS `count`,ifnull(sum(`zopsi_sys`.`pur_order`.`amt`),0) AS `amt` from `zopsi_sys`.`pur_order` where ((`zopsi_sys`.`pur_order`.`is_effective` = 1) and (`zopsi_sys`.`pur_order`.`is_voided` = 0) and (year(`zopsi_sys`.`pur_order`.`effective_time`) = year(sysdate())) and (month(`zopsi_sys`.`pur_order`.`effective_time`) = month(sysdate())))) `m`) union select '入库' AS `label`,`t`.`count` AS `t_count`,`t`.`amt` AS `t_amt`,`w`.`count` AS `w_count`,`w`.`amt` AS `w_amt`,`m`.`count` AS `m_count`,`m`.`amt` AS `m_amt` from ((((select count(1) AS `count`,ifnull(sum(`zopsi_sys`.`stk_io`.`cost`),0) AS `amt` from `zopsi_sys`.`stk_io` where ((`zopsi_sys`.`stk_io`.`is_effective` = 1) and (`zopsi_sys`.`stk_io`.`is_voided` = 0) and (`zopsi_sys`.`stk_io`.`stock_io_type` like '1%') and (`zopsi_sys`.`stk_io`.`effective_time` >= cast(sysdate() as date))))) `t` join (select count(1) AS `count`,ifnull(sum(`zopsi_sys`.`stk_io`.`cost`),0) AS `amt` from `zopsi_sys`.`stk_io` where ((`zopsi_sys`.`stk_io`.`is_effective` = 1) and (`zopsi_sys`.`stk_io`.`is_voided` = 0) and (`zopsi_sys`.`stk_io`.`stock_io_type` like '1%') and (yearweek(`zopsi_sys`.`stk_io`.`effective_time`,1) = yearweek(sysdate(),1)))) `w`) join (select count(1) AS `count`,ifnull(sum(`zopsi_sys`.`stk_io`.`cost`),0) AS `amt` from `zopsi_sys`.`stk_io` where ((`zopsi_sys`.`stk_io`.`is_effective` = 1) and (`zopsi_sys`.`stk_io`.`is_voided` = 0) and (`zopsi_sys`.`stk_io`.`stock_io_type` like '1%') and (year(`zopsi_sys`.`stk_io`.`effective_time`) = year(sysdate())) and (month(`zopsi_sys`.`stk_io`.`effective_time`) = month(sysdate())))) `m`) union select '应付' AS `label`,`t`.`count` AS `t_count`,`t`.`amt` AS `t_amt`,`w`.`count` AS `w_count`,`w`.`amt` AS `w_amt`,`m`.`count` AS `m_count`,`m`.`amt` AS `m_amt` from ((((select count(1) AS `count`,ifnull(sum(`zopsi_sys`.`fin_payable`.`amt`),0) AS `amt` from `zopsi_sys`.`fin_payable` where ((`zopsi_sys`.`fin_payable`.`is_effective` = 1) and (`zopsi_sys`.`fin_payable`.`is_voided` = 0) and (`zopsi_sys`.`fin_payable`.`effective_time` >= cast(sysdate() as date))))) `t` join (select count(1) AS `count`,ifnull(sum(`zopsi_sys`.`fin_payable`.`amt`),0) AS `amt` from `zopsi_sys`.`fin_payable` where ((`zopsi_sys`.`fin_payable`.`is_effective` = 1) and (`zopsi_sys`.`fin_payable`.`is_voided` = 0) and (yearweek(`zopsi_sys`.`fin_payable`.`effective_time`,1) = yearweek(sysdate(),1)))) `w`) join (select count(1) AS `count`,ifnull(sum(`zopsi_sys`.`fin_payable`.`amt`),0) AS `amt` from `zopsi_sys`.`fin_payable` where ((`zopsi_sys`.`fin_payable`.`is_effective` = 1) and (`zopsi_sys`.`fin_payable`.`is_voided` = 0) and (year(`zopsi_sys`.`fin_payable`.`effective_time`) = year(sysdate())) and (month(`zopsi_sys`.`fin_payable`.`effective_time`) = month(sysdate())))) `m`) union select '付款' AS `label`,`t`.`count` AS `t_count`,`t`.`amt` AS `t_amt`,`w`.`count` AS `w_count`,`w`.`amt` AS `w_amt`,`m`.`count` AS `m_count`,`m`.`amt` AS `m_amt` from ((((select count(1) AS `count`,ifnull(sum(`zopsi_sys`.`fin_payment`.`amt`),0) AS `amt` from `zopsi_sys`.`fin_payment` where ((`zopsi_sys`.`fin_payment`.`is_effective` = 1) and (`zopsi_sys`.`fin_payment`.`is_voided` = 0) and (`zopsi_sys`.`fin_payment`.`effective_time` >= cast(sysdate() as date))))) `t` join (select count(1) AS `count`,ifnull(sum(`zopsi_sys`.`fin_payment`.`amt`),0) AS `amt` from `zopsi_sys`.`fin_payment` where ((`zopsi_sys`.`fin_payment`.`is_effective` = 1) and (`zopsi_sys`.`fin_payment`.`is_voided` = 0) and (yearweek(`zopsi_sys`.`fin_payment`.`effective_time`,1) = yearweek(sysdate(),1)))) `w`) join (select count(1) AS `count`,ifnull(sum(`zopsi_sys`.`fin_payment`.`amt`),0) AS `amt` from `zopsi_sys`.`fin_payment` where ((`zopsi_sys`.`fin_payment`.`is_effective` = 1) and (`zopsi_sys`.`fin_payment`.`is_voided` = 0) and (year(`zopsi_sys`.`fin_payment`.`effective_time`) = year(sysdate())) and (month(`zopsi_sys`.`fin_payment`.`effective_time`) = month(sysdate())))) `m`);

-- ----------------------------
-- View structure for home_sale
-- ----------------------------
DROP VIEW IF EXISTS `home_sale`;
CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `home_sale` AS select '订单' AS `label`,`t`.`count` AS `t_count`,`t`.`amt` AS `t_amt`,`w`.`count` AS `w_count`,`w`.`amt` AS `w_amt`,`m`.`count` AS `m_count`,`m`.`amt` AS `m_amt` from ((((select count(1) AS `count`,ifnull(sum(`zopsi_sys`.`sal_order`.`amt`),0) AS `amt` from `zopsi_sys`.`sal_order` where ((`zopsi_sys`.`sal_order`.`is_effective` = 1) and (`zopsi_sys`.`sal_order`.`is_voided` = 0) and (`zopsi_sys`.`sal_order`.`effective_time` >= cast(sysdate() as date))))) `t` join (select count(1) AS `count`,ifnull(sum(`zopsi_sys`.`sal_order`.`amt`),0) AS `amt` from `zopsi_sys`.`sal_order` where ((`zopsi_sys`.`sal_order`.`is_effective` = 1) and (`zopsi_sys`.`sal_order`.`is_voided` = 0) and (yearweek(`zopsi_sys`.`sal_order`.`effective_time`,1) = yearweek(sysdate(),1)))) `w`) join (select count(1) AS `count`,ifnull(sum(`zopsi_sys`.`sal_order`.`amt`),0) AS `amt` from `zopsi_sys`.`sal_order` where ((`zopsi_sys`.`sal_order`.`is_effective` = 1) and (`zopsi_sys`.`sal_order`.`is_voided` = 0) and (year(`zopsi_sys`.`sal_order`.`effective_time`) = year(sysdate())) and (month(`zopsi_sys`.`sal_order`.`effective_time`) = month(sysdate())))) `m`) union select '出库' AS `label`,`t`.`count` AS `t_count`,`t`.`amt` AS `t_amt`,`w`.`count` AS `w_count`,`w`.`amt` AS `w_amt`,`m`.`count` AS `m_count`,`m`.`amt` AS `m_amt` from ((((select count(1) AS `count`,ifnull(sum(`zopsi_sys`.`stk_io`.`cost`),0) AS `amt` from `zopsi_sys`.`stk_io` where ((`zopsi_sys`.`stk_io`.`is_effective` = 1) and (`zopsi_sys`.`stk_io`.`is_voided` = 0) and (`zopsi_sys`.`stk_io`.`stock_io_type` like '2%') and (`zopsi_sys`.`stk_io`.`effective_time` >= cast(sysdate() as date))))) `t` join (select count(1) AS `count`,ifnull(sum(`zopsi_sys`.`stk_io`.`cost`),0) AS `amt` from `zopsi_sys`.`stk_io` where ((`zopsi_sys`.`stk_io`.`is_effective` = 1) and (`zopsi_sys`.`stk_io`.`is_voided` = 0) and (`zopsi_sys`.`stk_io`.`stock_io_type` like '2%') and (yearweek(`zopsi_sys`.`stk_io`.`effective_time`,1) = yearweek(sysdate(),1)))) `w`) join (select count(1) AS `count`,ifnull(sum(`zopsi_sys`.`stk_io`.`cost`),0) AS `amt` from `zopsi_sys`.`stk_io` where ((`zopsi_sys`.`stk_io`.`is_effective` = 1) and (`zopsi_sys`.`stk_io`.`is_voided` = 0) and (`zopsi_sys`.`stk_io`.`stock_io_type` like '2%') and (year(`zopsi_sys`.`stk_io`.`effective_time`) = year(sysdate())) and (month(`zopsi_sys`.`stk_io`.`effective_time`) = month(sysdate())))) `m`) union select '应收' AS `label`,`t`.`count` AS `t_count`,`t`.`amt` AS `t_amt`,`w`.`count` AS `w_count`,`w`.`amt` AS `w_amt`,`m`.`count` AS `m_count`,`m`.`amt` AS `m_amt` from ((((select count(1) AS `count`,ifnull(sum(`zopsi_sys`.`fin_receivable`.`amt`),0) AS `amt` from `zopsi_sys`.`fin_receivable` where ((`zopsi_sys`.`fin_receivable`.`is_effective` = 1) and (`zopsi_sys`.`fin_receivable`.`is_voided` = 0) and (`zopsi_sys`.`fin_receivable`.`effective_time` >= cast(sysdate() as date))))) `t` join (select count(1) AS `count`,ifnull(sum(`zopsi_sys`.`fin_receivable`.`amt`),0) AS `amt` from `zopsi_sys`.`fin_receivable` where ((`zopsi_sys`.`fin_receivable`.`is_effective` = 1) and (`zopsi_sys`.`fin_receivable`.`is_voided` = 0) and (yearweek(`zopsi_sys`.`fin_receivable`.`effective_time`,1) = yearweek(sysdate(),1)))) `w`) join (select count(1) AS `count`,ifnull(sum(`zopsi_sys`.`fin_receivable`.`amt`),0) AS `amt` from `zopsi_sys`.`fin_receivable` where ((`zopsi_sys`.`fin_receivable`.`is_effective` = 1) and (`zopsi_sys`.`fin_receivable`.`is_voided` = 0) and (year(`zopsi_sys`.`fin_receivable`.`effective_time`) = year(sysdate())) and (month(`zopsi_sys`.`fin_receivable`.`effective_time`) = month(sysdate())))) `m`) union select '收款' AS `label`,`t`.`count` AS `t_count`,`t`.`amt` AS `t_amt`,`w`.`count` AS `w_count`,`w`.`amt` AS `w_amt`,`m`.`count` AS `m_count`,`m`.`amt` AS `m_amt` from ((((select count(1) AS `count`,ifnull(sum(`zopsi_sys`.`fin_receipt`.`amt`),0) AS `amt` from `zopsi_sys`.`fin_receipt` where ((`zopsi_sys`.`fin_receipt`.`is_effective` = 1) and (`zopsi_sys`.`fin_receipt`.`is_voided` = 0) and (`zopsi_sys`.`fin_receipt`.`effective_time` >= cast(sysdate() as date))))) `t` join (select count(1) AS `count`,ifnull(sum(`zopsi_sys`.`fin_receipt`.`amt`),0) AS `amt` from `zopsi_sys`.`fin_receipt` where ((`zopsi_sys`.`fin_receipt`.`is_effective` = 1) and (`zopsi_sys`.`fin_receipt`.`is_voided` = 0) and (yearweek(`zopsi_sys`.`fin_receipt`.`effective_time`,1) = yearweek(sysdate(),1)))) `w`) join (select count(1) AS `count`,ifnull(sum(`zopsi_sys`.`fin_receipt`.`amt`),0) AS `amt` from `zopsi_sys`.`fin_receipt` where ((`zopsi_sys`.`fin_receipt`.`is_effective` = 1) and (`zopsi_sys`.`fin_receipt`.`is_voided` = 0) and (year(`zopsi_sys`.`fin_receipt`.`effective_time`) = year(sysdate())) and (month(`zopsi_sys`.`fin_receipt`.`effective_time`) = month(sysdate())))) `m`);

-- ----------------------------
-- View structure for stk_batch
-- ----------------------------
DROP VIEW IF EXISTS `stk_batch`;
CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `stk_batch` AS select distinct `stk_inventory`.`batch_no` AS `batch_no` from `stk_inventory` where (`stk_inventory`.`is_closed` = 0) ;

-- ----------------------------
-- View structure for stk_io_day_sum
-- ----------------------------
DROP VIEW IF EXISTS `stk_io_day_sum`;
CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `stk_io_day_sum` AS select max(`e`.`id`) AS `id`,`b`.`bill_date` AS `bill_date`,`e`.`warehouse_id` AS `warehouse_id`,`e`.`material_id` AS `material_id`,`e`.`batch_no` AS `batch_no`,`e`.`unit_id` AS `unit_id`,sum((case `e`.`stock_io_direction` when '1' then `e`.`qty` else 0 end)) AS `in_qty`,sum((case `e`.`stock_io_direction` when '1' then `e`.`cost` else 0 end)) AS `in_cost`,sum((case `e`.`stock_io_direction` when '2' then `e`.`qty` else 0 end)) AS `out_qty`,sum((case `e`.`stock_io_direction` when '2' then `e`.`cost` else 0 end)) AS `out_cost` from (`stk_io` `b` join `stk_io_entry_std` `e` on((`b`.`id` = `e`.`mid`))) where ((`b`.`is_effective` = 1) and (`b`.`is_voided` = 0)) group by `b`.`bill_date`,`e`.`warehouse_id`,`e`.`material_id`,`e`.`batch_no`,`e`.`unit_id` ;

-- ----------------------------
-- View structure for stk_material_qty
-- ----------------------------
DROP VIEW IF EXISTS `stk_material_qty`;
CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `stk_material_qty` AS select `m`.`id` AS `id`,max(`m`.`unit_id`) AS `unit_id`,sum(((`i`.`qty` * `iu`.`factor`) / `mu`.`factor`)) AS `qty` from (((`bas_material` `m` join `stk_inventory` `i` on(((`m`.`id` = `i`.`material_id`) and (`i`.`is_closed` = 0)))) join `bas_unit` `mu` on((`m`.`unit_id` = `mu`.`id`))) join `bas_unit` `iu` on((`i`.`unit_id` = `iu`.`id`))) group by `m`.`id` ;

-- ----------------------------
-- View structure for sys_user_dept
-- ----------------------------
DROP VIEW IF EXISTS `sys_user_dept`;
CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `sys_user_dept` AS select `ud`.`dep_id` AS `dept_id`,`u`.`username` AS `username` from (`sys_user` `u` join `sys_user_depart` `ud` on((`u`.`id` = `ud`.`user_id`))) ;

-- ----------------------------
-- View structure for home_doing_bill
-- ----------------------------
DROP VIEW IF EXISTS `home_doing_bill`;
CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `home_doing_bill` AS select `t`.`name` AS `name`,ifnull(`t`.`edit`,0) AS `edit`,ifnull(`t`.`appr`,0) AS `appr`,ifnull(`t`.`exec`,0) AS `exec` from (select '销售报价' AS `name`,sum((case `b`.`bill_stage` when '12' then 1 else 0 end)) AS `edit`,sum((case when ((`b`.`bill_stage` in ('14','22')) and (`b`.`is_effective` = 0)) then 1 else 0 end)) AS `appr`,sum((case when ((`b`.`bill_stage` in ('24','32')) and (`b`.`is_effective` = 1)) then 1 else 0 end)) AS `exec` from `zopsi_sys`.`sal_quot` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0)) union select '销售订单' AS `name`,sum((case `b`.`bill_stage` when '12' then 1 else 0 end)) AS `edit`,sum((case when ((`b`.`bill_stage` in ('14','22')) and (`b`.`is_effective` = 0)) then 1 else 0 end)) AS `appr`,sum((case when ((`b`.`bill_stage` in ('24','32')) and (`b`.`is_effective` = 1)) then 1 else 0 end)) AS `exec` from `zopsi_sys`.`sal_order` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0)) union select '出库单' AS `name`,sum((case `b`.`bill_stage` when '12' then 1 else 0 end)) AS `edit`,sum((case when ((`b`.`bill_stage` in ('14','22')) and (`b`.`is_effective` = 0)) then 1 else 0 end)) AS `appr`,sum((case when ((`b`.`bill_stage` in ('24','32')) and (`b`.`is_effective` = 1)) then 1 else 0 end)) AS `exec` from `zopsi_sys`.`stk_io` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0) and (`b`.`stock_io_type` like '2%')) union select '应收单' AS `name`,sum((case `b`.`bill_stage` when '12' then 1 else 0 end)) AS `edit`,sum((case when ((`b`.`bill_stage` in ('14','22')) and (`b`.`is_effective` = 0)) then 1 else 0 end)) AS `appr`,sum((case when ((`b`.`bill_stage` in ('24','32')) and (`b`.`is_effective` = 1)) then 1 else 0 end)) AS `exec` from `zopsi_sys`.`fin_receivable` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0)) union select '收款单' AS `name`,sum((case `b`.`bill_stage` when '12' then 1 else 0 end)) AS `edit`,sum((case when ((`b`.`bill_stage` in ('14','22')) and (`b`.`is_effective` = 0)) then 1 else 0 end)) AS `appr`,sum((case when ((`b`.`bill_stage` in ('24','32')) and (`b`.`is_effective` = 1)) then 1 else 0 end)) AS `exec` from `zopsi_sys`.`fin_receipt` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0)) union select '销售发票' AS `name`,sum((case `b`.`bill_stage` when '12' then 1 else 0 end)) AS `edit`,sum((case when ((`b`.`bill_stage` in ('14','22')) and (`b`.`is_effective` = 0)) then 1 else 0 end)) AS `appr`,sum((case when ((`b`.`bill_stage` in ('24','32')) and (`b`.`is_effective` = 1)) then 1 else 0 end)) AS `exec` from `zopsi_sys`.`fin_sal_invoice` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0)) union select '采购申请' AS `name`,sum((case `b`.`bill_stage` when '12' then 1 else 0 end)) AS `edit`,sum((case when ((`b`.`bill_stage` in ('14','22')) and (`b`.`is_effective` = 0)) then 1 else 0 end)) AS `appr`,sum((case when ((`b`.`bill_stage` in ('24','32')) and (`b`.`is_effective` = 1)) then 1 else 0 end)) AS `exec` from `zopsi_sys`.`pur_req` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0)) union select '采购询价' AS `name`,sum((case `b`.`bill_stage` when '12' then 1 else 0 end)) AS `edit`,sum((case when ((`b`.`bill_stage` in ('14','22')) and (`b`.`is_effective` = 0)) then 1 else 0 end)) AS `appr`,sum((case when ((`b`.`bill_stage` in ('24','32')) and (`b`.`is_effective` = 1)) then 1 else 0 end)) AS `exec` from `zopsi_sys`.`pur_inquiry` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0)) union select '供应报价' AS `name`,sum((case `b`.`bill_stage` when '12' then 1 else 0 end)) AS `edit`,sum((case when ((`b`.`bill_stage` in ('14','22')) and (`b`.`is_effective` = 0)) then 1 else 0 end)) AS `appr`,sum((case when ((`b`.`bill_stage` in ('24','32')) and (`b`.`is_effective` = 1)) then 1 else 0 end)) AS `exec` from `zopsi_sys`.`pur_quot` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0)) union select '采购比价' AS `name`,sum((case `b`.`bill_stage` when '12' then 1 else 0 end)) AS `edit`,sum((case when ((`b`.`bill_stage` in ('14','22')) and (`b`.`is_effective` = 0)) then 1 else 0 end)) AS `appr`,sum((case when ((`b`.`bill_stage` in ('24','32')) and (`b`.`is_effective` = 1)) then 1 else 0 end)) AS `exec` from `zopsi_sys`.`pur_compare` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0)) union select '采购订单' AS `name`,sum((case `b`.`bill_stage` when '12' then 1 else 0 end)) AS `edit`,sum((case when ((`b`.`bill_stage` in ('14','22')) and (`b`.`is_effective` = 0)) then 1 else 0 end)) AS `appr`,sum((case when ((`b`.`bill_stage` in ('24','32')) and (`b`.`is_effective` = 1)) then 1 else 0 end)) AS `exec` from `zopsi_sys`.`pur_order` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0)) union select '入库单' AS `name`,sum((case `b`.`bill_stage` when '12' then 1 else 0 end)) AS `edit`,sum((case when ((`b`.`bill_stage` in ('14','22')) and (`b`.`is_effective` = 0)) then 1 else 0 end)) AS `appr`,sum((case when ((`b`.`bill_stage` in ('24','32')) and (`b`.`is_effective` = 1)) then 1 else 0 end)) AS `exec` from `zopsi_sys`.`stk_io` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0) and (`b`.`stock_io_type` like '1%')) union select '应付单' AS `name`,sum((case `b`.`bill_stage` when '12' then 1 else 0 end)) AS `edit`,sum((case when ((`b`.`bill_stage` in ('14','22')) and (`b`.`is_effective` = 0)) then 1 else 0 end)) AS `appr`,sum((case when ((`b`.`bill_stage` in ('24','32')) and (`b`.`is_effective` = 1)) then 1 else 0 end)) AS `exec` from `zopsi_sys`.`fin_payable` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0)) union select '付款申请' AS `name`,sum((case `b`.`bill_stage` when '12' then 1 else 0 end)) AS `edit`,sum((case when ((`b`.`bill_stage` in ('14','22')) and (`b`.`is_effective` = 0)) then 1 else 0 end)) AS `appr`,sum((case when ((`b`.`bill_stage` in ('24','32')) and (`b`.`is_effective` = 1)) then 1 else 0 end)) AS `exec` from `zopsi_sys`.`fin_payment_req` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0)) union select '付款单' AS `name`,sum((case `b`.`bill_stage` when '12' then 1 else 0 end)) AS `edit`,sum((case when ((`b`.`bill_stage` in ('14','22')) and (`b`.`is_effective` = 0)) then 1 else 0 end)) AS `appr`,sum((case when ((`b`.`bill_stage` in ('24','32')) and (`b`.`is_effective` = 1)) then 1 else 0 end)) AS `exec` from `zopsi_sys`.`fin_payment` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0)) union select '采购发票' AS `name`,sum((case `b`.`bill_stage` when '12' then 1 else 0 end)) AS `edit`,sum((case when ((`b`.`bill_stage` in ('14','22')) and (`b`.`is_effective` = 0)) then 1 else 0 end)) AS `appr`,sum((case when ((`b`.`bill_stage` in ('24','32')) and (`b`.`is_effective` = 1)) then 1 else 0 end)) AS `exec` from `zopsi_sys`.`fin_pur_invoice` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0)) union select '库存盘点' AS `name`,sum((case `b`.`bill_stage` when '12' then 1 else 0 end)) AS `edit`,sum((case when ((`b`.`bill_stage` in ('14','22')) and (`b`.`is_effective` = 0)) then 1 else 0 end)) AS `appr`,sum((case when ((`b`.`bill_stage` in ('24','32')) and (`b`.`is_effective` = 1)) then 1 else 0 end)) AS `exec` from `zopsi_sys`.`stk_check` `b` where ((`b`.`is_closed` = 0) and (`b`.`is_voided` = 0))) `t`;




-- ----------------------------
-- Procedure structure for sp_fin_payable_sum
-- ----------------------------
DROP PROCEDURE IF EXISTS `sp_fin_payable_sum`;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `sp_fin_payable_sum`(IN `p_year` smallint,IN `p_month` tinyint)
BEGIN
	DECLARE n_year SMALLINT;
	DECLARE n_month TINYINT;

	DROP TABLE IF EXISTS `tmp`;
	CREATE TEMPORARY TABLE tmp(
		supplier_id VARCHAR(36),
		amt DECIMAL(18,2) DEFAULT 0
	);
	
	#初始金额:上月汇总已生成本月的期初数据
	UPDATE fin_payable_sum b 
		 SET b.debit_amt = 0, b.credit_amt = 0
	 WHERE b.`year` = p_year
	   AND b.`month` = p_month;
	
	#贷方金额
	INSERT INTO tmp(supplier_id, amt)
		SELECT p.supplier_id, SUM(p.amt) amt
			FROM fin_payable p
		 WHERE p.is_effective = 1 
			 AND p.is_voided = 0
			 AND p.bill_date BETWEEN fn_first_day_of_ym(p_year,p_month) AND fn_last_day_of_ym(p_year,p_month)
		 GROUP BY p.supplier_id;

	UPDATE fin_payable_sum b
	 INNER JOIN tmp a
			ON b.supplier_id = a.supplier_id
		 AND b.`year` = p_year
		 AND b.`month` = p_month
		 SET b.credit_amt = a.amt;

	#本月新增
	INSERT INTO fin_payable_sum(id, `year`, `month`, supplier_id, begin_credit_bal, debit_amt, credit_amt)
		SELECT MD5(UUID()), p_year, p_month, a.supplier_id, 0, 0, a.amt
			FROM tmp a
			LEFT JOIN fin_payable_sum b
				ON a.supplier_id = b.supplier_id
			 AND b.`year` = p_year
			 AND b.`month` = p_month
		 WHERE b.supplier_id IS NULL;

	SELECT IFNULL(SUM(amt), 0) INTO @credit_amt FROM tmp;

	DELETE FROM tmp;
	
	#借方金额
	INSERT INTO tmp(supplier_id, amt)
		SELECT p.supplier_id, SUM(p.amt) amt
			FROM fin_payment p
		 WHERE p.is_effective = 1 
			 AND p.is_voided = 0
			 AND p.bill_date BETWEEN fn_first_day_of_ym(p_year,p_month) AND fn_last_day_of_ym(p_year,p_month)
		 GROUP BY p.supplier_id;

	UPDATE fin_payable_sum b
	 INNER JOIN tmp a
			ON b.supplier_id = a.supplier_id
		 AND b.`year` = p_year
		 AND b.`month` = p_month
		 SET b.debit_amt = a.amt;

	#本月新增
	INSERT INTO fin_payable_sum(id, `year`, `month`, supplier_id, begin_credit_bal, debit_amt, credit_amt)
		SELECT MD5(UUID()), p_year, p_month, a.supplier_id, 0, a.amt, 0
			FROM tmp a
			LEFT JOIN fin_payable_sum b
				ON a.supplier_id = b.supplier_id
			 AND b.`year` = p_year
			 AND b.`month` = p_month
		 WHERE b.supplier_id IS NULL;	

	SELECT IFNULL(SUM(amt), 0) INTO @debit_amt FROM tmp;

	#金额合计
	SELECT COUNT(b.id) 
		INTO @num
		FROM fin_payable_sum b
	 WHERE b.`year` = p_year
		 AND b.`month` = p_month
		 AND b.supplier_id IS NULL;

	IF @num = 0 THEN
		INSERT INTO fin_payable_sum(id, `year`, `month`, supplier_id, begin_credit_bal, debit_amt, credit_amt)
			SELECT MD5(UUID()), p_year, p_month, NULL, IFNULL(SUM(b.begin_credit_bal), 0), IFNULL(SUM(b.debit_amt), 0), IFNULL(SUM(b.credit_amt), 0)
				FROM fin_payable_sum b
			 WHERE b.`year` = p_year
				 AND b.`month` = p_month
				 AND b.supplier_id IS NOT NULL;
	ELSE
		UPDATE fin_payable_sum b 
			 SET b.debit_amt = @debit_amt, b.credit_amt = @credit_amt
		 WHERE b.`year` = p_year
			 AND b.`month` = p_month
			 AND b.supplier_id IS NULL;
	END IF;

  #期末余额
	UPDATE fin_payable_sum b 
		 SET b.credit_bal = IFNULL(b.begin_credit_bal,0) - IFNULL(b.debit_amt,0) + IFNULL(b.credit_amt, 0)
	 WHERE b.`year` = p_year
		 AND b.`month` = p_month;

	#结转下月
	IF p_month < 12 THEN
		SET @n_year = p_year, @n_month = p_month + 1;
	ELSE
		SET @n_year = p_year + 1, @n_month = 1;
	END IF;

	DELETE FROM fin_payable_sum
	 WHERE `year` = @n_year
		 AND `month` = @n_month;

	INSERT INTO fin_payable_sum(id, `year`, `month`, supplier_id, begin_credit_bal, debit_amt, credit_amt)
		SELECT MD5(UUID()), @n_year, @n_month, IFNULL(b.supplier_id, c.id), b.credit_bal, 0, 0
			FROM fin_payable_sum b
			LEFT JOIN bas_supplier c
				ON b.supplier_id = c.id
			 AND c.is_enabled = 1	
		 WHERE b.credit_bal != 0
			 AND b.`year` = p_year
			 AND b.`month` = p_month;
END
;;
DELIMITER ;

-- ----------------------------
-- Procedure structure for sp_fin_receivable_sum
-- ----------------------------
DROP PROCEDURE IF EXISTS `sp_fin_receivable_sum`;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `sp_fin_receivable_sum`(IN `p_year` smallint,IN `p_month` tinyint)
BEGIN
	DECLARE n_year SMALLINT;
	DECLARE n_month TINYINT;

	DROP TABLE IF EXISTS `tmp`;
	CREATE TEMPORARY TABLE tmp(
		customer_id VARCHAR(36),
		amt DECIMAL(18,2) DEFAULT 0
	);
	
	#初始金额:上月汇总已生成本月的期初数据
	UPDATE fin_receivable_sum b 
		 SET b.debit_amt = 0, b.credit_amt = 0
	 WHERE b.`year` = p_year
	   AND b.`month` = p_month;

	#借方金额
	INSERT INTO tmp(customer_id, amt)
		SELECT r.customer_id, SUM(r.amt) amt
			FROM fin_receivable r
		 WHERE r.is_effective = 1 
			 AND r.is_voided = 0
			 AND r.bill_date BETWEEN fn_first_day_of_ym(p_year, p_month) AND fn_last_day_of_ym(p_year, p_month)
		 GROUP BY r.customer_id;

	UPDATE fin_receivable_sum b
	 INNER JOIN tmp a
			ON b.customer_id = a.customer_id
		 AND b.`year` = p_year
		 AND b.`month` = p_month
		 SET b.debit_amt = a.amt;

	#本月新增
	INSERT INTO fin_receivable_sum(id, `year`, `month`, customer_id, begin_debit_bal, debit_amt, credit_amt)
		SELECT MD5(UUID()), p_year, p_month, a.customer_id, 0, a.amt, 0
			FROM tmp a
			LEFT JOIN fin_receivable_sum b
				ON a.customer_id = b.customer_id
			 AND b.`year` = p_year
			 AND b.`month` = p_month
		 WHERE b.customer_id IS NULL;

	SELECT IFNULL(SUM(amt), 0) INTO @debit_amt FROM tmp;

	DELETE FROM tmp;
	
	#贷方金额
	INSERT INTO tmp(customer_id, amt)
		SELECT r.customer_id, SUM(r.amt) amt
			FROM fin_receipt r
		 WHERE r.is_effective = 1 
			 AND r.is_voided = 0
			 AND r.bill_date BETWEEN fn_first_day_of_ym(p_year, p_month) AND fn_last_day_of_ym(p_year, p_month)
		 GROUP BY r.customer_id;

	UPDATE fin_receivable_sum b
	 INNER JOIN tmp a
			ON b.customer_id = a.customer_id
		 AND b.`year` = p_year
		 AND b.`month` = p_month
		 SET b.credit_amt = a.amt;

	#本月新增
	INSERT INTO fin_receivable_sum(id, `year`, `month`, customer_id, begin_debit_bal, debit_amt, credit_amt)
		SELECT MD5(UUID()), p_year, p_month, a.customer_id, 0, 0, a.amt
			FROM tmp a
			LEFT JOIN fin_receivable_sum b
				ON a.customer_id = b.customer_id
			 AND b.`year` = p_year
			 AND b.`month` = p_month
		 WHERE b.customer_id IS NULL;	

	SELECT IFNULL(SUM(amt), 0) INTO @credit_amt FROM tmp;


	#金额合计
	SELECT COUNT(b.id) 
		INTO @num
		FROM fin_receivable_sum b
	 WHERE b.`year` = p_year
		 AND b.`month` = p_month
		 AND b.customer_id IS NULL;

	IF @num = 0 THEN
		INSERT INTO fin_receivable_sum(id, `year`, `month`, customer_id, begin_debit_bal, debit_amt, credit_amt)
			SELECT MD5(UUID()), p_year, p_month, NULL, IFNULL(SUM(b.begin_debit_bal), 0), IFNULL(SUM(b.debit_amt), 0), IFNULL(SUM(b.credit_amt),0)
				FROM fin_receivable_sum b
			 WHERE b.`year` = p_year
				 AND b.`month` = p_month
				 AND b.customer_id IS NOT NULL;
	ELSE
		UPDATE fin_receivable_sum b 
			 SET b.debit_amt = @debit_amt, b.credit_amt = @credit_amt
		 WHERE b.`year` = p_year
			 AND b.`month` = p_month
			 AND b.customer_id IS NULL;
	END IF;

  #期末余额
	UPDATE fin_receivable_sum b 
		 SET b.debit_bal = IFNULL(b.begin_debit_bal,0) + IFNULL(b.debit_amt,0) - IFNULL(b.credit_amt,0)
	 WHERE b.`year` = p_year
		 AND b.`month` = p_month;

	#结转下月
	IF p_month < 12 THEN
		SET @n_year = p_year, @n_month = p_month + 1;
	ELSE
		SET @n_year = p_year + 1, @n_month = 1;
	END IF;

	DELETE FROM fin_receivable_sum
	 WHERE `year` = @n_year
		 AND `month` = @n_month;

	INSERT INTO fin_receivable_sum(id, `year`, `month`, customer_id, begin_debit_bal, debit_amt, credit_amt)
		SELECT MD5(UUID()), @n_year, @n_month, IFNULL(b.customer_id, c.id), b.debit_bal, 0, 0
			FROM fin_receivable_sum b
			LEFT JOIN bas_customer c
				ON b.customer_id = c.id
       AND c.is_enabled = 1
		 WHERE b.debit_bal != 0
			 AND b.`year` = p_year
			 AND b.`month` = p_month;

END
;;
DELIMITER ;

-- ----------------------------
-- Procedure structure for sp_stk_io_sum
-- ----------------------------
DROP PROCEDURE IF EXISTS `sp_stk_io_sum`;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `sp_stk_io_sum`(IN `p_year` smallint,IN `p_month` tinyint)
BEGIN
	DECLARE n_year SMALLINT;
	DECLARE n_month TINYINT;

	DROP TABLE IF EXISTS `tmp`;
	CREATE TEMPORARY TABLE tmp(
		material_id VARCHAR(36),
		batch_no VARCHAR(100),
		warehouse_id VARCHAR(36),
		unit_id VARCHAR(36),
		in_qty DECIMAL(18,6) DEFAULT 0,
		in_cost DECIMAL(18,2) DEFAULT 0,
		out_qty DECIMAL(18,6) DEFAULT 0,
		out_cost DECIMAL(18,2) DEFAULT 0
	);
	
	#初始发生数:上月汇总已生成本月的期初数
	UPDATE stk_io_sum s 
		 SET s.in_qty = 0, s.in_cost = 0, s.out_qty = 0, s.out_cost = 0
	 WHERE s.`year` = p_year
	   AND s.`month` = p_month;
	
	#发生数
	INSERT INTO tmp(material_id, batch_no, warehouse_id, unit_id, in_qty, in_cost, out_qty, out_cost)
		SELECT e.material_id, e.batch_no, e.warehouse_id, e.unit_id, 
           SUM(CASE e.stock_io_direction WHEN '1' THEN e.qty ELSE 0 END) in_qty,
           SUM(CASE e.stock_io_direction WHEN '1' THEN e.cost ELSE 0 END) in_cost,
           SUM(CASE e.stock_io_direction WHEN '2' THEN e.qty ELSE 0 END) out_qty,
           SUM(CASE e.stock_io_direction WHEN '2' THEN e.cost ELSE 0 END) out_cost
			FROM stk_io b
		 INNER JOIN stk_io_entry_std e
			  ON b.id = e.mid
		 WHERE b.is_effective = 1 
			 AND b.is_voided = 0
			 AND b.bill_date BETWEEN fn_first_day_of_ym(p_year,p_month) AND fn_last_day_of_ym(p_year,p_month)
		 GROUP BY e.material_id, e.batch_no, e.warehouse_id, e.unit_id;

	UPDATE stk_io_sum s
	 INNER JOIN tmp t
			ON s.material_id = t.material_id
		 AND s.batch_no = t.batch_no
		 AND s.warehouse_id = t.warehouse_id
		 AND s.unit_id = t.unit_id
		 SET s.in_qty = t.in_qty, s.in_cost = t.in_cost, s.out_qty = t.out_qty, s.out_cost = t.out_cost
	 WHERE s.`year` = p_year
		 AND s.`month` = p_month;

	#本月新增
	INSERT INTO stk_io_sum(id, `year`, `month`, material_id, batch_no, warehouse_id, unit_id, begin_qty, begin_cost, in_qty, in_cost, out_qty, out_cost)
		SELECT MD5(UUID()), p_year, p_month, t.material_id, t.batch_no, t.warehouse_id, t.unit_id, 0, 0, t.in_qty, t.in_cost, t.out_qty, t.out_cost
			FROM tmp t
			LEFT JOIN stk_io_sum s
				ON t.material_id = s.material_id
		   AND t.batch_no = s.batch_no
		   AND t.warehouse_id = s.warehouse_id
		   AND t.unit_id = s.unit_id
			 AND s.`year` = p_year
			 AND s.`month` = p_month
		 WHERE s.id IS NULL;

  #期末结存
	UPDATE stk_io_sum s
		 SET s.bal_qty = IFNULL(s.begin_qty, 0) + IFNULL(s.in_qty, 0) - IFNULL(s.out_qty, 0),
		     s.bal_cost = IFNULL(s.begin_cost, 0) + IFNULL(s.in_cost, 0) - IFNULL(s.out_cost, 0)
	 WHERE s.`year` = p_year
		 AND s.`month` = p_month;

	#结转下月
	IF p_month < 12 THEN
		SET @n_year = p_year, @n_month = p_month + 1;
	ELSE
		SET @n_year = p_year + 1, @n_month = 1;
	END IF;

	DELETE FROM stk_io_sum
	 WHERE `year` = @n_year
		 AND `month` = @n_month;

	INSERT INTO stk_io_sum(id, `year`, `month`, material_id, batch_no, warehouse_id, unit_id, begin_qty, begin_cost, in_qty, in_cost, out_qty, out_cost, bal_qty, bal_cost)
		SELECT MD5(UUID()), @n_year, @n_month, s.material_id, s.batch_no, s.warehouse_id, s.unit_id, s.bal_qty, s.bal_cost, 0, 0, 0, 0, 0, 0
			FROM stk_io_sum s
		 WHERE s.bal_qty != 0
       AND s.bal_cost != 0
			 AND s.`year` = p_year
			 AND s.`month` = p_month;
END
;;
DELIMITER ;

