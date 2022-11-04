cmake_minimum_required(VERSION 3.16.0)

if(UNIX)
    message ("We are running on linux system ...")
elseif(MSVC)
    message("We are running on windows system (MSVC) ...")
endif()

set (CMAKE_BUILD_TYPE "Release")
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_STANDARD 17)


set (CMAKE_CXX_FLAGS "-fmodules-ts -Ofast -flto -march=native -fno-exceptions -fno-rtti -fno-ident -fno-unwind-tables -fno-omit-frame-pointer")

project(latexFigureCodeGenerator LANGUAGES CXX)

set (inc include/latexfigurehelper.h)

set (src src/main.cpp)
set (src ${src} src/latexfigurehelper.cpp)

ADD_EXECUTABLE(latexFigureCodeGenerator ${inc} ${src})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)