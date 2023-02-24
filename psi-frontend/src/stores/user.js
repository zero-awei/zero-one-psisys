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
  }
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
      text: '表单组件',
      href: '/component/form',
      icon: 'IconTickets',
      pid: 3
    },
    {
      id: 3,
      text: '表格组件',
      href: '/component/table',
      icon: 'IconTickets',
      pid: 3
    },
    {
      id: 4,
      text: '弹出框组件',
      href: '/component/dialog',
      icon: 'IconTickets',
      pid: 3
    },
    {
      id: 5,
      text: '抽屉组件',
      href: '/component/drawer',
      icon: 'IconTickets',
      pid: 3
    },
    {
      id: 6,
      text: '自定义列组件',
      href: '/component/custom',
      icon: 'IconTickets',
      pid: 3
    },
    {
      id: 6,
      text: 'center组件',
      href: '/component/center',
      icon: 'IconTickets',
      pid: 3
    }
  ]
}
// 采购管理
const purManagement = {
  id: 700,
  text: '采购管理',
  icon: 'IconTickets',
  children: [
    {
      id: 701,
      text: '采购申请',
      href: '/PurRequisition',
      icon: 'IconTickets',
      pid: 5
    },
    {
      id: 702,
      text: '采购询价',
      href: '/PurInquiry',
      icon: 'IconTickets',
      pid: 5
    },
    {
      id: 703,
      text: '供应报价',
      href: '/SupplyQuotation',
      icon: 'IconTickets',
      pid: 5
    },
    {
      id: 704,
      text: '采购比价',
      href: '/PurComparison',
      icon: 'IconTickets',
      pid: 5
    },
    {
      id: 705,
      text: '采购订单',
      href: '/PurOrder',
      icon: 'IconTickets',
      pid: 5
    },
    {
      id: 706,
      text: '采购预付申请',
      href: '/PurPrepaymentApply',
      icon: 'IconTickets',
      pid: 5
    },
    {
      id: 707,
      text: '采购申请',
      href: '/PurPaymentApply',
      icon: 'IconTickets',
      pid: 5
    },
    {
      id: 708,
      text: '采购统计',
      href: '',
      icon: 'IconTickets',
      pid: 5,
      children: [
        {
          id: 711,
          text: '采购订单执行情况',
          href: '',
          icon: '',
          pid: 51
        },
        {
          id: 712,
          text: '采购订单汇总',
          href: '',
          icon: '',
          pid: 51
        },
        {
          id: 713,
          text: '采购订单汇总-部门',
          href: '',
          icon: '',
          pid: 51
        },
        {
          id: 714,
          text: '采购订单汇总-业务员',
          href: '',
          icon: '',
          pid: 51
        },
        {
          id: 715,
          text: '采购订单汇总-供应商',
          href: '',
          icon: '',
          pid: 51
        },
        {
          id: 716,
          text: '采购订单汇总-物料',
          href: '',
          icon: '',
          pid: 51
        }
      ]
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
const kucunRouter = {}

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
    routeMenus: []
  }),
  getters: {
    // 获取token
    getToken: (state) => state.token || localStorage.getItem('token'),
    // 是否已加载
    isLoaded: (state) => state.loaded,
    // 获取当前用户
    getUser: (state) => state.user,
    // 获取菜单
    getMenus: (state) => state.menus
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
      this.menus = testMenus
      // 在后端返回菜单列表中添加组件列表路由
      this.menus.push(componentRouter)
      this.menus.push(yewuRouter)
      this.menus.push(baseDataRouter)
      this.menus.push(purManagement)
      this.menus.push(kucunRouter)
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
      // if (this.menus.length > 0) {
      //   let temp = []
      //   temp = this.digui(this.menus, temp)
      //   this.routeMenus = temp
      //   return this.routeMenus
      // }
      // for (let item in this.menus) {
      //   if (this.menus[item].children) {
      //     this.getRouteMenus(this.menus[item].children)
      //   } else {
      //     routeMenus.push(this.menus[item])
      //   }
      // }
      // return routeMenus
      for (let i in this.menus) {
        if (this.menus[i].children) {
          for (let j in this.menus[i].children) {
            let itemj = this.menus[i].children[j]
            if (itemj.children) {
              for (let k in itemj.children) {
                let itemk = itemj.children[k]
                if (itemk.children) {
                } else {
                  this.routeMenus.push(itemk)
                }
              }
            } else {
              this.routeMenus.push(itemj)
            }
          }
        } else {
          this.routeMenus.push(this.menus[i])
        }
        return this.routeMenus
        // // // console.log('this.routeMenus', this.routeMenus)
        // if (this.menus[i].children) {
        //   for (let j in this.menus[i]){
        //     if(j.chi)
        //   }

        // } else {
        //   routeMenus.push(this.menus[item])
        // }
      }
    }
  }
})
