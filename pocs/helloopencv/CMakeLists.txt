cmake_minimum_required (VERSION 3.7)
project (helloopencv)

# The version number.
set (crosscompile_VERSION_MAJOR 1)
set (crosscompile_VERSION_MINOR 0)

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

if(UNIX)
    message(STATUS ">>> Linux/OSx")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
    #set(CMAKE_C_FLAGS "-m32")
    #set(CMAKE_EXE_LINKER_FLAGS "-m32")
    #set(LDFLAGS "-m32")
elseif(WIN32)
    message(STATUS ">>> Windows")
    #set(CMAKE_C_COMPILER "C:/Program Files (x86)/Microsoft Visual Studio/2017/Community/VC/Tools/MSVC/14.16.27023/bin/Hostx64/x86/cl.exe")
    #set(CMAKE_CXX_COMPILER "C:/Program Files (x86)/Microsoft Visual Studio/2017/Community/VC/Tools/MSVC/14.16.27023/bin/Hostx64/x86/cl.exe")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif()

set(BUILD_SHARED_LIBS OFF)

find_package( OpenCV REQUIRED )
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIB_DIR})
include_directories("include/")

add_executable(helloopencv src/main.cpp)
target_link_libraries( helloopencv ${OpenCV_LIBS} )

add_executable(readwriteimg src/rwimg.cpp)
target_link_libraries( readwriteimg ${OpenCV_LIBS} )
