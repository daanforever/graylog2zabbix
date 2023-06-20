cmake_minimum_required(VERSION 3.18)

project(graylog2zabbix
  VERSION 0.0.1
  DESCRIPTION "Graylog to Zabbix notifications"
  LANGUAGES CXX)

if(POLICY CMP0042)
  cmake_policy(SET CMP0042 NEW)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_LIBS   ON)

option(BUILD_TYPE "" dev)
option(BUILD_TEST "" OFF)
option(DBUILD_SSL "" NO)

set(BUILD_SHARED_LIBS OFF)
set(BUILD_STATIC_LIBS ON)
set(BUILD_EXAMPLE     OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# find_package(ZLIB CONFIG REQUIRED)
find_package(Boost REQUIRED COMPONENTS system filesystem REQUIRED)
find_package(Boost REQUIRED COMPONENTS log log_setup REQUIRED)
find_package(fmt REQUIRED CONFIG)
find_package(restinio REQUIRED)

#add_definitions("-DBOOST_ALLOW_DEPRECATED_HEADERS")
#add_definitions("-DBOOST_BIND_GLOBAL_PLACEHOLDERS")
# add_definitions("-DBOOST_LOG_DYN_LINK")

# add_subdirectory(thirdparty/web-server)

#include_directories(${INCLUDE_DIRECTORIES} ${Boost_INCLUDE_DIRS} include /usr/local/include /usr/include/boost)
include_directories(${INCLUDE_DIRECTORIES} ${Boost_INCLUDE_DIRS} include /usr/local/include)
# include_directories(${INCLUDE_DIRECTORIES} thirdparty/inotify-cpp/src/include)
# include_directories(${INCLUDE_DIRECTORIES} ${OPENSSL_INCLUDE_DIR} ${Boost_INCLUDE_DIR})

link_libraries(${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES})
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Werror -Wfatal-errors -fcoroutines")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow -pedantic -Werror -Wfatal-errors")

#set(CMAKE_CXX_CPPCHECK "cppcheck")
#include (cmake/cppcheck.cmake)

add_subdirectory(src)

# set(BUILD_TEST ON)
# if (BUILD_TEST)
  # include(CTest)
  # add_subdirectory(test) 
# endif()

message(STATUS "")
message(STATUS "")
message(STATUS "${PROJECT_NAME} configuration summary:")
include(cmake/status.cmake)

