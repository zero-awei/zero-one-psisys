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
}
