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

 Date: 21/02/2023 14:58:09
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for sys_menu
-- ----------------------------
DROP TABLE IF EXISTS `sys_menu`;
CREATE TABLE `sys_menu`  (
  `id` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `parent_id` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `name` varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '名称',
  `url` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '路径',
  `icon` varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '图标',
  `sort_no` double(8, 2) NULL DEFAULT NULL COMMENT '排序',
  `create_time` timestamp(0) NOT NULL DEFAULT CURRENT_TIMESTAMP(0) COMMENT '创建时间',
  `update_time` timestamp(0) NULL DEFAULT NULL COMMENT '修改时间',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of sys_menu
-- ----------------------------
INSERT INTO `sys_menu` VALUES ('00a2a0ae65cdca5e93209cdbde97cbe6', NULL, '主菜单', '/main', NULL, 1.00, '2023-02-14 19:58:54', NULL);
INSERT INTO `sys_menu` VALUES ('020b06793e4de2eee0007f603000c769', '00a2a0ae65cdca5e93209cdbde97cbe6', '菜单1', '/main/1', NULL, 1.10, '2023-02-14 19:57:33', NULL);
INSERT INTO `sys_menu` VALUES ('024f1fd1283dc632458976463d8984e1', '00a2a0ae65cdca5e93209cdbde97cbe6', '菜单2', '/main/2', NULL, 1.20, '2023-02-14 19:58:11', NULL);
INSERT INTO `sys_menu` VALUES ('043780fa095ff1b2bec4dc406d76f023', '00a2a0ae65cdca5e93209cdbde97cbe6', '菜单3', '/main/3', NULL, 1.30, '2023-02-14 19:59:23', NULL);
INSERT INTO `sys_menu` VALUES ('05b3c82ddb2536a4a5ee1a4c46b5abef', '020b06793e4de2eee0007f603000c769', '子菜单1', '/main/1/1', NULL, 1.11, '2023-02-14 20:00:02', NULL);
INSERT INTO `sys_menu` VALUES ('0620e402857b8c5b605e1ad9f4b89350', '020b06793e4de2eee0007f603000c769', '子菜单2', '/main/1/2', NULL, 1.12, '2023-02-14 20:00:39', NULL);
INSERT INTO `sys_menu` VALUES ('078f9558cdeab239aecb2bda1a8ed0d1', '024f1fd1283dc632458976463d8984e1', '子菜单3', '/main/2/1', NULL, 1.21, '2023-02-14 20:01:12', NULL);
INSERT INTO `sys_menu` VALUES ('08e6b9dc3c04489c8e1ff2ce6f105aa4', '024f1fd1283dc632458976463d8984e1', '子菜单4', '/main/2/2', NULL, 1.22, '2023-02-14 20:01:42', NULL);
INSERT INTO `sys_menu` VALUES ('0ac2ad938963b6c6d1af25477d5b8b51', '043780fa095ff1b2bec4dc406d76f023', '子菜单5', '/main/3/1', NULL, 1.31, '2023-02-14 20:03:47', NULL);
INSERT INTO `sys_menu` VALUES ('1627131817436422145', '00a2a0ae65cdca5e93209cdbde97cbe6', '菜单1', '/main/1', '', NULL, '2023-02-19 10:23:49', NULL);

SET FOREIGN_KEY_CHECKS = 1;
