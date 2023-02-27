/*
 * @Author: 160405103 1348313766@qq.com
 * @Date: 2023-02-25 23:37:05
 * @LastEditors: 160405103 1348313766@qq.com
 * @LastEditTime: 2023-02-26 13:48:38
 * @FilePath: \psi-frontend\src\views\test\api\menu.js
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
import { addMenu } from '@/views/sysmanage/api/menu.js'

// -----------------定义测试数据---------------

let params = {
  icon: '1.png',
  id: '234',
  name: '菜单名',
  parentId: '1',
  url: '/menu1'
}

// -----------------定义测试方法--------------- 这些方法就是用在业务页面里的方法

export const handleAddMenu = () => {
  //2. 调用views/sysmanage/api/menujs的addMenu方法
  addMenu(
    {
      params
    },
    // 3.调用成功返回参数成功执行这个方法
    (data) => {
      // TODO 在控制台打印后端返回数据
      // 需要前后端字段匹配
      console.log('请求成功data', data)
    },
    // 4.执行失败给出提示信息
    (msg) => {
      console.log('msg', msg)
      ElMessage.error('新增菜单出现错误')
    }
  )
}
