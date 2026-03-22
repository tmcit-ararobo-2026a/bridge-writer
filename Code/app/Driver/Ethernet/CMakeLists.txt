cmake_minimum_required(VERSION 3.22)

enable_language(C CXX ASM)

set(mEthernet_Include_Dirs
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set(mEthernet_App_Dirs
    ${CMAKE_CURRENT_SOURCE_DIR}/mEthernet.cpp
)

target_sources(${CMAKE_PROJECT_NAME} PRIVATE ${mEthernet_Include_Dirs})

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${mEthernet_App_Dirs})