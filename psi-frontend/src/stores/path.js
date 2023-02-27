/*
 * @Author: 160405103 1348313766@qq.com
 * @Date: 2023-02-23 17:13:14
 * @LastEditors: 160405103 1348313766@qq.com
 * @LastEditTime: 2023-02-25 16:23:31
 * @FilePath: \psi-frontend\src\stores\path.js
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
import { defineStore } from 'pinia'
import { userStore } from './user'
export const pathStore = defineStore('path', {
  state: () => ({
    // 记录路由 id,path,text
    pathList: [],
    pathIdSet: new Set().add(1)
  }),
  getters: {
    // 获得路由列表
    // TODO   getPathList: ()  出现bug
    /**
     * Uncaught (in promise) TypeError: Cannot read properties of null (reading 'shapeFlag')
    at setVarsOnVNode (runtime-dom.esm-bundler.js:728:15)
    at setVars (runtime-dom.esm-bundler.js:717:9)
    at callWithErrorHandling (runtime-core.esm-bundler.js:173:22)
    at callWithAsyncErrorHandling (runtime-core.esm-bundler.js:182:21)
    at ReactiveEffect.getter [as fn] (runtime-core.esm-bundler.js:1750:24)
    at ReactiveEffect.run (reactivity.esm-bundler.js:190:25)
    at flushPostFlushCbs (runtime-core.esm-bundler.js:359:32)
    at flushJobs (runtime-core.esm-bundler.js:413:9)
     */
    getPathList: (state) => state.pathList,
    getLastPath: (state) => state.pathList[state.pathList.length - 1],
    getPathIdSet: (state) => state.pathIdSet
  },
  actions: {
    // 添加路由
    addPath(router) {
      let path = {}
      // // // console.log('111111111111111router', router)
      // router只有name,href这两个有效信息,没有id
      path.name = router.name
      path.href = router.href
      let userstore = userStore()
      const menus = userstore.getRouteMenus()
      // console.log('---------menus', menus)
      // console.log('---------path', path)
      if (router.href === '/home' || router.href === '/dashboard') {
        path.id = 0
        path.text = '首页'
      } else {
        // console.log('111111111111111else', router)
        for (let i = 0; i < menus.length; i++) {
          if (menus[i].href === path.href) {
            path.id = menus[i].id
            path.text = menus[i].text
            // console.log('-------------menus[i]', menus[i])
            break
          }
        }
      }
      // console.log('---------path', path)
      this.pathList.push(path)
      this.pathIdSet.add(path.id)
    },
    removePathIdSet(id) {
      this.pathIdSet.delete(id)
    }
  }
})
