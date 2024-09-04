
cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_definitions(-DIS_ANDROID)

set(PROJ_NAME log-wrapper)
set(PROJ_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/src/log.cpp
)
set(LOG_WRAPPER_INCLUDE_DIR
    ${CMAKE_CURRENT_LIST_DIR}/includes
)

add_library(${PROJ_NAME} STATIC ${PROJ_SOURCES})

target_include_directories(${PROJ_NAME} PUBLIC
    ${LOG_WRAPPER_INCLUDE_DIR}
)
