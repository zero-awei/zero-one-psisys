/*
 * @Author: 160405103 1348313766@qq.com
 * @Date: 2023-02-24 22:06:10
 * @LastEditors: 160405103 1348313766@qq.com
 * @LastEditTime: 2023-02-26 11:35:02
 * @FilePath: \psi-frontend\src\stores\user.js
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
import { defineStore } from 'pinia'
import Request from '@/apis/request'
// 测试菜单数据
let testMenus = [
  {
    id: 1,
    text: '系统管理',
    icon: 'IconSetting',
    children: [
      {
        id: 2,
        text: '角色管理',
        href: '/sysmanagement/rolemanagement',
        icon: 'IconSetting',
        pid: 1
      },
      {
        id: 3,
        text: '菜单管理',
        href: '/sysmanagement/menumanagement',
        icon: 'IconSetting',
        pid: 1
      },
      {
        id: 4,
        text: '用户管理',
        href: '/sysmanagement/usermanagement',
        icon: 'IconSetting',
        pid: 1
      },
      {
        id: 5,
        text: '部门管理',
        href: '/sysmanagement/sysposition',
        icon: 'IconSetting',
        pid: 1
      },
      {
        id: 6,
        text: '组织结构管理',
        href: '/sysmanagement/orimanage',
        icon: 'IconSetting',
        pid: 1
      },
      {
        id: 7,
        text: '分类字典',
        icon: 'IconTickets',
        pid: 997,
        href: '/sysmanagement/Category'
      },
      {
        id: 8,
        text: '通讯录',
        icon: 'IconTickets',
        pid: 997,
        href: '/sysmanagement/addressbook'
      }
    ]
  },

  /* {
    id: 2,
    text: '库存管理',
    icon: 'IconUser',
    children:[
      {
        id:2,
        text:'入库管理',
        icon:'IconUser',
        children:[
          {
            id: 2,
            text: '采购入库',
            href: '/inventory/purchase',
            icon: 'IconSetting',
            pid: 1
          },
          {
            id: 3,
            text: '采购入库退货出库（红入）',
            href: '/inventory/salesreturn',
            icon: 'IconSetting',
            pid: 1
          },
          {
            id: 4,
            text: '盘盈入库',
            href: '/inventory/inventoryprofit',
            icon: 'IconSetting',
            pid: 1
          },
          {
            id: 2,
            text: '涨吨入库',
            href: 'inventory/rise',
            icon: 'IconSetting',
            pid: 1
          },
          {
            id: 2,
            text: '其他入库',
            href: 'inventory/other',
            icon: 'IconSetting',
            pid: 1
          },
        ]
      }
    ]
  } */
]
// {
//     id: 2,
//     text: '用户管理',
//     icon: 'IconUser',
//     children: [
//       {
//         id: 2,
//         text: '用户管理1',
//         href: '/un-11',
//         icon: 'IconUser',
//         pid: 2
//       },
//       {
//         id: 3,
//         text: '用户管理2',
//         href: '/un-12',
//         icon: 'IconUser',
//         pid: 2
//       },
//       {
//         id: 4,
//         text: '用户管理3',
//         href: '/un-13',
//         icon: 'IconUser',
//         pid: 2
//       },
//       {
//         id: 5,
//         text: '用户管理4',
//         href: '/un-14',
//         icon: 'IconUser',
//         pid: 2
//       },
//       {
//         id: 6,
//         text: '用户管理5',
//         href: '/un-15',
//         icon: 'IconUser',
//         pid: 2
//       }
//     ]
//   },
//   {
//     id: 3,
//     text: '订单管理',
//     icon: 'IconTickets',
//     children: [
//       {
//         id: 2,
//         text: '订单管理1',
//         href: '/un-21',
//         icon: 'IconTickets',
//         pid: 3
//       },
//       {
//         id: 3,
//         text: '订单管理2',
//         href: '/un-22',
//         icon: 'IconTickets',
//         pid: 3
//       },
//       {
//         id: 4,
//         text: '订单管理3',
//         href: '/un-23',
//         icon: 'IconTickets',
//         pid: 3
//       },
//       {
//         id: 5,
//         text: '订单管理4',
//         href: '/un-24',
//         icon: 'IconTickets',
//         pid: 3
//       },
//       {
//         id: 6,
//         text: '订单管理5',
//         href: '/un-25',
//         icon: 'IconTickets',
//         pid: 3
//       }
//     ]
//   }
// 业务路由配置
const yewuRouter = {
  id: 998,
  text: '应付与付款',
  icon: 'IconTickets',
  children: [
    {
      id: 3,
      text: '应付管理',
      icon: 'IconTickets',
      pid: 998,
      children: [
        {
          id: 3,
          text: '采购应付',
          href: '/pay/payable/purchase',
          icon: 'IconTickets',
          pid: 2
        },
        {
          id: 3,
          text: '其他应付',
          href: '/pay/payable/other',
          icon: 'IconTickets',
          pid: 2
        },
        {
          id: 3,
          text: '应付核销',
          href: '/pay/payable/check',
          icon: 'IconTickets',
          pid: 2
        }
      ]
    }
  ]
}
// 组件测试
const componentRouter = {
  id: 999,
  text: '组件封装',
  icon: 'IconTickets',
  children: [
    {
      id: 2,
      text: '角色管理',
      href: '/sysmanagement/rolemanagement',
      icon: 'IconSetting',
      pid: 1
    },
    {
      id: 3,
      text: '菜单管理',
      href: '/sysmanagement/menumanagement',
      icon: 'IconSetting',
      pid: 1
    },
    {
      id: 4,
      text: '用户管理',
      href: '/sysmanagement/usermanagement',
      icon: 'IconSetting',
      pid: 1
    },
    {
      id: 5,
      text: '部门管理',
      href: '/sysmanagement/sysposition',
      icon: 'IconSetting',
      pid: 1
    },
    {
      id: 6,
      text: '组织结构管理',
      href: '/sysmanagement/orimanage',
      icon: 'IconSetting',
      pid: 1
    },
    {
      id: 7,
      text: '分类字典',
      icon: 'IconTickets',
      pid: 1,
      href: '/sysmanagement/Category'
    },
    {
      id: 8,
      text: '通讯录',
      icon: 'IconTickets',
      pid: 1,
      href: '/sysmanagement/addressbook'
    }
  ]
}

// 基础资料
const baseDataRouter = {
  id: 800,
  text: '基础资料',
  icon: 'IconTickets',
  children: [
    {
      id: 801,
      text: '客户',
      href: '/Client',
      icon: 'IconTickets',
      pid: 4
    },
    {
      id: 802,
      text: '供应商',
      href: '/Provider',
      icon: 'IconTickets',
      pid: 4
    },
    {
      id: 803,
      text: '仓库',
      href: '/Store',
      icon: 'IconTickets',
      pid: 4
    },
    {
      id: 804,
      text: '物料分类',
      href: '/MaterialSort',
      icon: 'IconTickets',
      pid: 4
    },
    {
      id: 805,
      text: '物料',
      href: '/Material',
      icon: 'IconTickets',
      pid: 4
    },
    {
      id: 806,
      text: '计量单位',
      href: '/Measurement',
      icon: 'IconTickets',
      pid: 4
    },
    {
      id: 807,
      text: '币种',
      href: '/Currency',
      icon: 'IconTickets',
      pid: 4
    },
    {
      id: 808,
      text: '银行账户',
      href: '/Account',
      icon: 'IconTickets',
      pid: 4
    }
  ]
}
//库存管理
const kucunRouter = {
    id: 2,
    text: '库存管理',
    icon: 'IconUser',
    children:[
      {
        id:2,
        text:'入库管理',
        icon:'IconUser',
        children:[
          {
            id: 2,
            text: '采购入库',
            href: '/inventory/Ipurchase',
            icon: 'IconSetting',
            pid: 1
          },
          {
            id: 3,
            text: '采购入库退货出库（红入）',
            href: '/inventory/salesreturn',
            icon: 'IconSetting',
            pid: 1
          },
          {
            id: 4,
            text: '盘盈入库',
            href: '/inventory/inventoryprofit',
            icon: 'IconSetting',
            pid: 1
          },
          {
            id: 2,
            text: '涨吨入库',
            href: 'inventory/rise',
            icon: 'IconSetting',
            pid: 1
          },
          {
            id: 2,
            text: '其他入库',
            href: 'inventory/other',
            icon: 'IconSetting',
            pid: 1
          },
        ]
      }
    ]
  }

export const userStore = defineStore('user', {
  state: () => ({
    // 记录token
    token: null,
    // 记录refreshToken
    refreshToken: null,
    // 保存一个标识信息，指示登陆后需要加载的初始化数据是否完成
    loaded: false,
    // 保存当前用户
    user: null,
    // 菜单数据
    menus: [],
    routeMenus: [],
    parentMenus: []
  }),
  getters: {
    // 获取token
    getToken: (state) => state.token || localStorage.getItem('token'),
    // 是否已加载
    isLoaded: (state) => state.loaded,
    // 获取当前用户
    getUser: (state) => state.user,
    // 获取菜单
    getMenus: (state) => state.menus,
    // 获取父级菜单
    getParentMenus: (state) => state.parentMenus
    // 获取子级菜单
    // getRouteMenus: (state) => state.routeMenus
  },
  actions: {
    // 加载用户
    async loadUser() {
      // 发送获取当前用户信息请求
      let data = await Request.requestForm(
        Request.GET,
        '/login/current-user',
        null
      )
      this.user = data.data
    },
    // 加载菜单
    async loadMenus() {
      //TODO[TEST_CODE]:此处写测试数据设定
      //this.menus = testMenus

      // 发送获取菜单请求
      let data = await Request.requestForm(
        Request.GET,
        '/login/get-menus',
        null
      )
      // this.menus = data.data
      this.menus.push(sysmanageRouter)
      // 在后端返回菜单列表中添加组件列表路由
      this.menus.push(baseDataRouter)
      this.menus.push(purManagement)
      this.menus.push(kucunguanli)
      this.menus.push(yingfuyufukuan)
      this.menus.push(componentRouter)
    },
    // 加载刷新凭证
    loadRefreshToken() {
      if (!this.refreshToken)
        this.refreshToken = localStorage.getItem('refreshToken')
    },
    // 刷新token
    async reloadToken() {
      // 先加载刷新凭证
      this.loadRefreshToken()
      // 发送刷新凭证请求
      let data = await Request.requestForm(
        Request.POST,
        '/login/refresh-token',
        {
          refreshToken: this.refreshToken,
          clientId: import.meta.env.VITE_API_URL
        }
      )
      //设置Token相关属性
      this.setToken(data.data)
    },
    // 设置是否加载完成
    setLoaded(loaded) {
      this.loaded = loaded
    },
    // 设置token
    setToken(data) {
      this.token = data.token
      this.refreshToken = data.refreshToken
      localStorage.setItem('token', this.token)
      localStorage.setItem('refreshToken', this.refreshToken)
    },
    // 重置数据
    resetSaveData() {
      this.loaded = false
      this.user = null
      this.token = null
      this.refreshToken = null
      localStorage.removeItem('token')
      localStorage.removeItem('refreshToken')
    },
    // 递归遍历
    // digui(tree, temp) {
    //   for (let item in this.menus) {
    //     if (this.menus[item].children) {
    //       this.digui(this.menus[item].children, temp)
    //     } else {
    //       temp.push(this.menus[item])
    //     }
    //   }
    //   return temp
    // },
    // 获取可跳转路由的菜单
    // 非递归遍历
    getRouteMenus() {
      // console.log('-------------this.menus', this.menus)
      for (let i = 0; i < this.menus.length; i++) {
        let itemi = this.menus[i] // 一级菜单
        // console.log('-----------一级菜单', itemi)
        if (itemi.children) {
          console.log('-----------一级菜单', itemi)
          this.parentMenus.push(itemi)
          // 如果有二级菜单
          for (let j in itemi.children) {
            // 遍历二级菜单

            let itemj = itemi.children[j]
            if (itemj.children) {
              console.log('-----------二级菜单', itemj)
              this.parentMenus.push(itemj)
              // 如果有三级菜单
              for (let k in itemj.children) {
                // 遍历三级菜单
                let itemk = itemj.children[k]
                if (itemk.children) {
                  console.log('-----------三级菜单', itemk)
                  this.parentMenus.push(itemk)
                } else {
                  this.routeMenus.push(itemk)
                }
              }
            } else {
              this.routeMenus.push(itemj)
            }
          }
        } else {
          this.routeMenus.push(itemi)
        }
      }
      // console.log('-------------处理后this.menus', this.menus)
      return this.routeMenus
    }
  }
})
