cmake_minimum_required(VERSION 3.28)
project(Media_Library_ManagementV1_0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER "-static")
include_directories("D:\\SoftwareInstall\\MySQL\\MySQL Server 8.0\\include")
link_directories("D:\\SoftwareInstall\\MySQL\\MySQL Server 8.0\\lib")
link_libraries(libmysql)

add_executable(Media_Library_ManagementV1_0 main.cpp
        MysqlServer.cpp
        MysqlServer.h
        Help.cpp
        Help.h
        Book.cpp
        Book.h
        Video.cpp
        Video.h
        Picture.cpp
        Picture.h)
target_link_libraries(Media_Library_ManagementV1_0 libmysql)
