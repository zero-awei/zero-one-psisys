# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

# 指定工程名
project ("zero-one-psi")

# 设置安装目录前缀
set (CMAKE_INSTALL_PREFIX "../install/${PROJECT_NAME}" CACHE PATH "install path prefix" FORCE )

# C++标准
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加宏定义
add_definitions(-DLINUX)
add_definitions(-D_CRT_SECURE_NO_WARNINGS -D_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS )
add_definitions(-DASIO_STANDALONE )
add_definitions(-DCHECK_TOKEN)
add_definitions(-DSTOP_PWD="01star")
add_definitions(-DBSONCXX_STATIC -DMONGOCXX_STATIC -DENABLE_AUTOMATIC_INIT_AND_CLEANUP=OFF)

# 在camke .. 的时候会输出提示目录路径
message (STATUS "Prefix dir is ${CMAKE_INSTALL_PREFIX}")
message (STATUS "Binary dir is ${PROJECT_BINARY_DIR}")
message (STATUS "Source dir is ${PROJECT_SOURCE_DIR}")

# 检查OpenSSL库是否存在
find_package (OpenSSL REQUIRED)
if(OPENSSL_FOUND)
  include_directories (${OPENSSL_INCLUDE_DIRS})
  message (STATUS "OpenSSL Found!")
endif()

# 设置宏定义开关
option (USE_XLNT "use xlnt" ON)
option (USE_DFS "use fastdfs" ON)
option (USE_YML "use yaml" ON)
option (USE_NACOS "use nacos, need open yaml" ON)
option (USE_REDIS "use redis" ON)
option (USE_KAFKA "use kafka" OFF)
option (USE_ROCKETMQ "use rocketmq" ON)
option (USE_MONGO "use mongodb" ON)

# 选项宏定义
# 为了保证排除后编译通过，在单独使用这些库的地方加上对应的宏定义
if (USE_XLNT)
	add_definitions(-DUSE_XLNT)
endif()
if (USE_DFS)
	add_definitions(-DUSE_DFS)
endif()
if (USE_YML)
	add_definitions(-DUSE_YML)
endif()
if (USE_NACOS)
	add_definitions(-DUSE_NACOS)
endif()
if (USE_REDIS)
	add_definitions(-DUSE_REDIS)
endif()
if (USE_KAFKA)
	add_definitions(-DUSE_KAFKA)
endif()
if (USE_ROCKETMQ)
	add_definitions(-DUSE_ROCKETMQ)
endif()
if (USE_MONGO)
	add_definitions(-DUSE_MONGO)
endif()

# 包含子项目
add_subdirectory ("lib-http")
add_subdirectory ("lib-mysql")
add_subdirectory ("lib-common")
add_subdirectory("psi-c1")