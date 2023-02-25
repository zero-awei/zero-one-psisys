import {addMenu} from '@/views/sysmanage/apip/menu.js'

// -----------------定义测试数据---------------

let params = {

}


// -----------------定义测试方法---------------

export const handleAddMenu=()=>{

    //2. 调用views/sysmanage/api/menujs的addMenu方法
  addMenu(
    {
      params
    },
    // 3.调用成功返回参数成功执行这个方法
    (data) => {
      // TODO 需要前后端字段匹配
      console.log('请求成功data',data)
    },
    // 4.执行失败给出提示信息
    () => {
      console.log('请求失败data', data)
      ElMessage.error('新增菜单出现错误')
    }
  )
}