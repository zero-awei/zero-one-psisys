/*
 * @Author: 160405103 1348313766@qq.com
 * @Date: 2023-02-18 16:39:10
 * @LastEditors: 160405103 1348313766@qq.com
 * @LastEditTime: 2023-03-02 17:57:01
 * @FilePath: \psi-frontend\src\plugins\el-icon.js
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
// 这里导入你要使用的图标
// 写成多行避免解决冲突麻烦
import { Menu } from '@element-plus/icons-vue'
import { Setting } from '@element-plus/icons-vue'
import { User } from '@element-plus/icons-vue'
import { Tickets } from '@element-plus/icons-vue'
import { RefreshRight } from '@element-plus/icons-vue'
import { ArrowUp } from '@element-plus/icons-vue'
import { ArrowDown } from '@element-plus/icons-vue'
import { FullScreen } from '@element-plus/icons-vue'
import { Close } from '@element-plus/icons-vue'
import { Search } from '@element-plus/icons-vue'
import { Edit } from '@element-plus/icons-vue'
import { House } from '@element-plus/icons-vue'
import { ShoppingCart } from '@element-plus/icons-vue'
import { MessageBox } from '@element-plus/icons-vue'
import { Money } from '@element-plus/icons-vue'
import { SuitcaseLine } from '@element-plus/icons-vue'
export default (app) => {
  app.component('IconMenu', Menu)
  app.component('IconSetting', Setting)
  app.component('IconUser', User)
  app.component('IconTickets', Tickets)
  app.component('RefreshRight', RefreshRight)
  app.component('ArrowUp', ArrowUp)
  app.component('ArrowDown', ArrowDown)
  app.component('FullScreen', FullScreen)
  app.component('Close', Close)
  app.component('Search', Search)
  app.component('Edit', Edit)
  app.component('House', House)
  app.component('ShoppingCart', ShoppingCart)
  app.component('MessageBox', MessageBox)
  app.component('Money', Money)
  app.component('SuitcaseLine', SuitcaseLine)
}
