# CMakeList.txt: lib-http 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# 包含库目录
include_directories ("./")
include_directories ("include")

# 编译动态库
add_library (lib-http STATIC "src/HttpServer.cpp" "src/JWTUtil.cpp")

# 静态库输出名修改
set_target_properties (lib-http PROPERTIES OUTPUT_NAME http)
# 防止同名库被删除
set_target_properties (lib-http PROPERTIES CLEAN_DIRECT_OUTPUT 1)

# 安装库
install (TARGETS lib-http ARCHIVE DESTINATION libstatic)
install (DIRECTORY include/ DESTINATION include/lib-http)