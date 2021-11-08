cmake_minimum_required(VERSION 3.10)
##


project(appwind)
##

SET(appwind_src "main.cpp")
ADD_EXECUTABLE(appwind ${appwind_src})
##
SET(lib_src "libs")
ADD_LIBRARY (Lib STATIC ${lib_src})

##
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED True)
##
TARGET_LINK_LIBRARIES(appwind ${libs})

