cmake_minimum_required(VERSION 3.22)

enable_language(C CXX ASM)

set(mMicroSD_Include_Dirs
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set(mMicroSD_App_Dirs
    ${CMAKE_CURRENT_SOURCE_DIR}/mMSDC.cpp
)

target_sources(${CMAKE_PROJECT_NAME} PRIVATE ${mMicroSD_App_Dirs})

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${mMicroSD_Include_Dirs})