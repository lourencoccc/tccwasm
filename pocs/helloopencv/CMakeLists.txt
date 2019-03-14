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
    # cmake -G "Unix Makefiles" ..
    # make
    # linux/osx stuff here
    #target_link_libraries(main /home/vagrant/opencv/build/opencv_core401d.lib)
    #set(CMAKE_CXX_FLAGS "-m32")
    #set(CMAKE_C_FLAGS "-m32")
    #set(CMAKE_LD_FLAGS "-m32")
    #set(LDFLAGS "-m32")
elseif(WIN32)
    message(STATUS ">>> Windows")
    # cmake -G "Visual Studio 15 2017" -A Win32 ..
    # cmake --build . --config Release
    # windows stuff here
    #target_link_libraries(helloopencv D:/Libs/opencv/build/lib/Debug/opencv_core401d.lib)
endif()


set(BUILD_SHARED_LIBS OFF)

find_package( OpenCV REQUIRED )
add_executable(helloopencv src/main.cpp)
target_link_libraries( helloopencv ${OpenCV_LIBS})


