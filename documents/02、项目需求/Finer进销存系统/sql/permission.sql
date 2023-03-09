/*
 Navicat Premium Data Transfer

 Source Server         : zopsi_sys
 Source Server Type    : MySQL
 Source Server Version : 80020
 Source Host           : 43.138.223.223:3306
 Source Schema         : zopsi_sys

 Target Server Type    : MySQL
 Target Server Version : 80020
 File Encoding         : 65001

 Date: 21/02/2023 14:58:18
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for permission
-- ----------------------------
DROP TABLE IF EXISTS `permission`;
CREATE TABLE `permission`  (
  `permission_id` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '权限编号',
  `permission_name` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '权限名称',
  `url` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT '权限对应的url',
  `father_permission_id` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT '父权限id',
  `permission_type` tinyint(0) NOT NULL COMMENT '权限类型；0表示系统权限，有且只有一个。1一级权限，2二级权限，3三级权限',
  `instruction` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT '对该权限的介绍',
  PRIMARY KEY (`permission_id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of permission
-- ----------------------------
INSERT INTO `permission` VALUES ('00a2a0ae65cdca5e93209cdbde97cbe6', '系统权限', '/', NULL, 0, NULL);
INSERT INTO `permission` VALUES ('024f1fd1283dc632458976463d8984e1', '销售管理', '/erp/sale', '00a2a0ae65cdca5e93209cdbde97cbe6', 1, NULL);
INSERT INTO `permission` VALUES ('043780fa095ff1b2bec4dc406d76f023', '销售报价', '/erp/sale/quot', '024f1fd1283dc632458976463d8984e1', 2, NULL);
INSERT INTO `permission` VALUES ('05b3c82ddb2536a4a5ee1a4c46b5abef', '销售订单', '/erp/sale/order', '024f1fd1283dc632458976463d8984e1', 2, NULL);
INSERT INTO `permission` VALUES ('0620e402857b8c5b605e1ad9f4b89350', '销售统计', '/erp/sale/statistics/order', '024f1fd1283dc632458976463d8984e1', 2, NULL);
INSERT INTO `permission` VALUES ('078f9558cdeab239aecb2bda1a8ed0d1', '销售订单执行情况', '/erp/sale/statistics/order/progress', '0620e402857b8c5b605e1ad9f4b89350', 3, NULL);
INSERT INTO `permission` VALUES ('08e6b9dc3c04489c8e1ff2ce6f105aa4', '销售订单毛利润', '/erp/sale/statistics/order/profit', '0620e402857b8c5b605e1ad9f4b89350', 3, NULL);

SET FOREIGN_KEY_CHECKS = 1;
