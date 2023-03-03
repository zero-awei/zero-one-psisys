# CMakeList.txt: arch-demo 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# 定义Demo项目需要使用的特定宏【仅Demo项目需要配置】
# add_definitions(-DHTTP_SERVER_DEMO)

# 设置文件名称
set (appName psi-basic_information)

# 包含库目录
include_directories ("./")
include_directories ("../lib-http/include")
include_directories ("../lib-mysql/include")
include_directories ("../lib-common/include")

# 链接库路径，程序运行的时候也在这里找
link_directories (${PROJECT_BINARY_DIR}/lib-http)
link_directories (${PROJECT_BINARY_DIR}/lib-mysql)
link_directories (${PROJECT_BINARY_DIR}/lib-common)
link_directories (${PROJECT_SOURCE_DIR}/lib-common/lib64)
link_directories (${PROJECT_SOURCE_DIR}/lib-dy/lib64)

# 将源代码添加到此项目的可执行文件
file (GLOB_RECURSE SC_FILES ./*.cpp)

# 排除xlnt案例编译【仅Demo项目需要配置】
if(USE_XLNT STREQUAL OFF)
	list (REMOVE_ITEM SC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/./uselib/excel/TestExcel.cpp")
	message (STATUS "${appName}: not compile xlnt use case.")
endif()
# 排除fastdfs案例编译【仅Demo项目需要配置】
if(USE_DFS STREQUAL OFF)
	list (REMOVE_ITEM SC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/./uselib/fastdfs/TestFastDfs.cpp")
	message (STATUS "${appName}: not compile fastdfs use case.")
endif()
# 排除redis案例编译【仅Demo项目需要配置】
if(USE_REDIS STREQUAL OFF)
	list (REMOVE_ITEM SC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/./uselib/redis/TestRedis.cpp")
	message (STATUS "${appName}: not compile redis use case.")
endif()
# 排除Kafa案例编译【仅Demo项目需要配置】
if(USE_KAFKA STREQUAL OFF)
	list (REMOVE_ITEM SC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/./uselib/kafka/TestKafka.cpp")
	message (STATUS "${appName}: not compile kafka use case.")
endif()
# 排除RocketMQ案例编译【仅Demo项目需要配置】
if(USE_ROCKETMQ STREQUAL OFF)
	list (REMOVE_ITEM SC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/./uselib/rocketmq/TestRocket.cpp")
	message (STATUS "${appName}: not compile rocketmq use case.")
endif()
# 排除MongoDB案例编译【仅Demo项目需要配置】
if(USE_MONGO STREQUAL OFF)
	list (REMOVE_ITEM SC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/./uselib/mongo/TestMongo.cpp")
	message (STATUS "${appName}: not compile mongodb use case.")
endif()

# 编译可执行文件
add_executable (${appName} ${SC_FILES})

# 链接库
target_link_libraries (${appName} "lib-common" "lib-http" "lib-mysql")

# 链接其他库依赖库，如：你要链接libuuid直接写成uuid
target_link_libraries (${appName} uuid pthread stdc++fs OpenSSL::SSL )
target_link_libraries (${appName} mysqlcppconn )
# 链接xlnt
if(USE_XLNT)
	target_link_libraries (${appName} xlnt )
	message (STATUS "${appName}: link xlnt lib")
endif()
# 链接fastdfs
if(USE_DFS)
	target_link_libraries (${appName} fdfsclient fastcommon )
	message (STATUS "${appName}: link fdfsclient lib")
endif()
# 链接ymal
if(USE_YML)
	target_link_libraries (${appName} yaml-cpp )
	message (STATUS "${appName}: link yamlcpp lib")
endif()
# 链接nacos
if(USE_NACOS)
	target_link_libraries (${appName} nacos-cli )
	message (STATUS "${appName}: link nacos lib")
endif()
# 链接redis
if(USE_REDIS)
	target_link_libraries (${appName} redis++ hiredis )
	message (STATUS "${appName}: link redis lib")
endif()
# 链接Kafka
if(USE_KAFKA)
	target_link_libraries (${appName} rdkafka++ rdkafka )
	message (STATUS "${appName}: link kakfa lib")
endif()
# 链接RocketMQ
if(USE_ROCKETMQ)
	target_link_libraries (${appName} rocketmq )
	message (STATUS "${appName}: link rocketmq lib")
endif()
# 链接MongoDB
if(USE_MONGO)
	target_link_libraries (${appName} bsoncxx bson-1.0 mongocxx mongoc-1.0 )
	message (STATUS "${appName}: link mongodb lib")
endif()

# 复制配置到调试时可执行文件所在的目录
# public目录【仅Demo项目需要配置】
file (GLOB publicDir "public/*")
file (COPY ${publicDir} DESTINATION "${PROJECT_BINARY_DIR}/${appName}/public")
# RSA公钥证书
file (COPY "public.pem" DESTINATION ${PROJECT_BINARY_DIR}/${appName})
# FastDFS配置文件
file (GLOB fdfsConf "../lib-common/include/fastdfs/conf/*")
file (COPY ${fdfsConf} DESTINATION ${PROJECT_BINARY_DIR}/${appName}/conf)

# 安装文件
# public目录【仅Demo项目需要配置】
install (DIRECTORY "public" DESTINATION ${appName})
# 可执行文件
install (TARGETS ${appName} RUNTIME DESTINATION ${appName})
# RSA公钥证书
install (FILES "public.pem" DESTINATION ${appName})
# FastDFS配置文件
install (DIRECTORY "${PROJECT_SOURCE_DIR}/lib-common/include/fastdfs/conf" DESTINATION ${appName})
# 第三方动态链接库
install (DIRECTORY "${PROJECT_SOURCE_DIR}/lib-dy/lib64/" DESTINATION lib FILES_MATCHING PATTERN "*.so*")
# 启动脚本
install (PROGRAMS ${PROJECT_SOURCE_DIR}/run-front.sh ${PROJECT_SOURCE_DIR}/run-back.sh DESTINATION ${appName})