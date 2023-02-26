
<!--
 * @Author: 160405103 1348313766@qq.com
 * @Date: 2023-02-25 01:45:35
 * @LastEditors: 160405103 1348313766@qq.com
 * @LastEditTime: 2023-02-26 14:21:37
 * @FilePath: \psi-frontend\src\views\README.md
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
## 目录结构说明

- `src`：根目录
  - `apis`：公共方法
    - `date`：
      -`index.js`: 日期处理方法
    - `login`：
      -`index.js`: 登陆方法
    - `publick`：
      -`index.js`: 公共接口
    - `request.js`：封装的公共请求模板
  - `components`: 封装的公共组件
  - `views`: 业务页面

## 1.src/view目录

- `views`：存放资源和源码的目录，注意`.vue`文件文件名大写字母开头
  - `caigouguanli`：采购管理
  - `dashboard`：仪表盘(不用处理)
  - `jichuziliao`：基础资料
  - `kucunguanli`库存管理
  - `status`：404页面(不用处理)
  - `sysmanage`：系统管理
  - `test`：测试后端接口在这里
  - `yingfuyufukuan`：应付与付款

## 2.测试接口 test

- `test`：测试接口目录
  - `api`：写测试接口方法（一个模块新建一个js文件）
    - `menu.js`：菜单管理的测试接口方法 （从每个模块下的api引入接口方法）
  - `test.vue`：在这个页面引入对应方法。在登陆页面测试
详细看test.vue的注释说明
## 3.组件目录及文档

- `src/components`：组件目录
  - `dialog`
    - `demo.vue`：demo示例
    - `PsiDialog.vue`：封装的组件
    - `README.md`：组件文档
  - `drawer`
    - `demo.vue`：demo示例
    - `PsiDrawer.vue`：封装的组件
    - `README.md`：组件文档
  - `form`
  - `demo.vue`：demo示例
    - `PsiForm.vue`：封装的组件
    - `README.md`：组件文档
  - `table`
  - `demo.vue`：demo示例
    - `PsiTable.vue`：封装的组件
    - `README.md`：组件文档

## 1.1系统管理 sysmanage
7个页面对应api下的7个方法（js命名小写）
- `sysmanage`：系统管理目录
  - `api`：写接口方法（一个模块新建一个js文件）
    - `menu.js`：菜单管理的接口方法
  - `AddressBook.vue`：通讯录页面
  - `Category.vue`：分类字典页面
  - `MenuManage.vue`：菜单管理页面
  - `OriManage.vue`：组织结构管理页面
  - `RoleManage.vue`：角色管理页面
  - `SysPosition.vue`：职位/部门管理页面
  - `UserManage.vue`：用户管理页面


## 1.2基础资料 jichuziliao
8个页面对应api下的8个方法（js命名小写）

- `jichuziliao`：基础资料目录
  - `api`：写接口方法（一个模块新建一个js文件）
    - `menu.js`：菜单管理的接口方法
  - `AccountCheck.vue`：银行账户页面
  - `ClientCheck.vue`：客户页面
  - `CurrencyCheck.vue`：币种页面
  - `MaterialCheck.vue`：物料页面
  - `MaterialSortCheck.vue`：物料分类页面
  - `MeasurementCheck.vue`：计量单位页面
  - `ProviderCheck.vue`：供应商页面
  - `StoreCheck.vue`：仓库页面

## 1.3库存管理 kucunguanli
5个页面对应api下的5个方法（js命名小写）

- `kucunguanli/入库管理`：库存管理(入库管理)目录
  - `api`：写接口方法（一个模块新建一个js文件）
    - `menu.js`：菜单管理的接口方法
  - `CaiGouRuKu.vue`：采购入库页面
  - `CaiGouTuiHuoChuKu.vue`：采购退货出库（红入）页面
  - `PanYingRuKu.vue`：盘盈入库页面
  - `QiTaRuKu.vue`：其他入库页面
  - `ZhangDunRuKu.vue`：涨吨入库页面


## 1.4采购管理 caigouguanli
7个页面对应api下的7个方法（js命名小写）

- `caigouguanli`：采购管理目录
  - `api`：写接口方法（一个模块新建一个js文件）
    - `menu.js`：菜单管理的接口方法
  - `PurComparsion.vue`：采购比价页面
  - `PurInquiry.vue`：采购询价页面
  - `PurOrder.vue`：采购订单页面
  - `PurPaymentApply.vue`：采购申请页面
  - `PurPrepaymentApply.vue`：采购预付申请页面
  - `PurRequisition.vue`：采购申请页面
  - `SupplyQuotation.vue`：供应报价页面

## 1.5应付与付款 yingfuyufukuan
7个页面对应api下的7个方法（js命名小写）

- `yingfuyufukuan`：应付与付款目录
  - `fukuanguanli`：付款管理目录
    - `api`：写接口方法（一个模块新建一个js文件）
      - `menu.js`：菜单管理的接口方法
    - `CaiGouFuKuan.vue`：采购付款（无申请）页面
    - `CaiGouFuKuanApply.vue`：采购付款（有申请）页面
    - `CaiGouTuiHuoTuiKuan.vue`：采购退货退款（红付）页面
  - `yingfuguanli`：应付管理目录
    - `api`：写接口方法（一个模块新建一个js文件）
      - `menu.js`：菜单管理的接口方法
    - `CaiGouYingFu.vue`：采购应付页面
    - `QiTaYingFu.vue`：其他应付页面
    - `YingFuHeXiao.vue`：应付核销页面
  - `yufuguanli`：预付管理目录
    - `api`：写接口方法（一个模块新建一个js文件）
      - `menu.js`：菜单管理的接口方法
    - `CaiGouYuFu.vue`：采购预付（无申请）页面
    - `CaiGouYuFuApply.vue`：采购预付（有申请）页面付）页面







## 操作步骤

1.找到业务页面  xxx.vue
2.在 ./api/  新建一个文件 xxx.js  内容是测试接口
3.
  3.1 只是测试
    - 1.在src/views/test/api/  新建一个文件  xxx.js 内容是测试接口的方法
    - 2.在src/view/test/test.vue 里 import 引入方法，然后
    - 3.在登陆页面点击测试，查看控制台打印数据，或者浏览器控制台->network->fetch/xhr
  3.2 在业务页面写
    -1.引入 ./api/xxx.js     import {aaa} from './api/xxx.js'
    -2.找到对应的触发事件：比如点击按钮触发的事件
    -3.写对应的测试接口的方法 function handleAAA()


公共接口在 src/apis/public/index.js 调用

公共接口说明文档 src/apis/public/README.md

业务页面在 src/views/README.md 查看
