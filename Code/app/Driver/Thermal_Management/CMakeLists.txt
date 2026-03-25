cmake_minimum_required(VERSION 3.22)

enable_language(C CXX ASM)

set(mThermal_Include_Dirs
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set(mThermal_App_Dirs
    ${CMAKE_CURRENT_SOURCE_DIR}/mThermal_Management.cpp
)

target_sources(${CMAKE_PROJECT_NAME} PRIVATE ${mThermal_App_Dirs})

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${mThermal_Include_Dirs})