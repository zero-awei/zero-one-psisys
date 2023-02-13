## search查询组件

本质上是嵌套表单的组件

### 第一版提供功能

1.search-component 提供属性 | 作用

formData    |   表单的响应式数据

items       |  展开域的标签及组件配置

toggleItems |  折叠域的标签及组建配置

2.search-component 提供方法 | 作用 | 参数

search(formData) |  进行查询  | 表单的响应式数据

3.search-component 提供标签

input         | 输入框

select        | 选择框

daterange     | 日期选择(开始日期，结束日期)  
              | Array[1](Array[0], Array[1])

### 第二版需要提供功能

1.表单项的配置
2.表单的总体配置
