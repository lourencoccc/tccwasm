cmake_minimum_required (VERSION 3.7)
project (detectorsz)

set (crosscompile_VERSION_MAJOR 1)
set (crosscompile_VERSION_MINOR 0)

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

if(WASM)
    message(">>> WebAssembly - WASM=${WASM}")
    set(CMAKE_C_COMPILER "emcc")
    set(CMAKE_CXX_COMPILER "em++")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -m32 --std=c++17 -s WASM=1 -s DEMANGLE_SUPPORT=1")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s TOTAL_MEMORY=268435456")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s ALLOW_MEMORY_GROWTH=1 -s FORCE_FILESYSTEM=1")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --bind --no-heap-copy --preload-file assets/")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}../../../webapp)
    set(OpenCV_DIR "/home/vagrant/opencv/build_wasm2")
    include_directories("/home/vagrant/emsdk/emscripten/1.38.31/system/include/")
elseif(UNIX)
    message(STATUS ">>> Linux/OSx")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
elseif(WIN32)
    message(STATUS ">>> Windows")
    include_directories("D:/Apps/emsdk/fastcomp/emscripten/system/include")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
    add_compile_options("/std:c++17")
endif()

set(BUILD_SHARED_LIBS OFF)
include_directories("include/")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIB_DIR})

set(SOURCE_APP src/imageprocess.cpp
    src/facedetect.cpp
    src/imageprocessapp.cpp
    src/facedetectapp.cpp
    src/imagewrapper.cpp
)

set(SOURCE_WEBAPP src/imageprocess.cpp
    src/facedetect.cpp
    src/imageprocessweb.cpp
    src/facedetectweb.cpp
    src/imagewrapper.cpp
)

if(NOT WASM)
    add_executable(detectorsz_test src/maintest.cpp ${SOURCE_APP})
    target_link_libraries(detectorsz_test ${OpenCV_LIBS})

    add_executable(detectorsz src/mainapp.cpp ${SOURCE_APP})
    target_link_libraries(detectorsz ${OpenCV_LIBS})
else()
    add_executable(detectorsz.html ${SOURCE_WEBAPP})
    target_link_libraries(detectorsz.html ${OpenCV_LIBS})
endif()
