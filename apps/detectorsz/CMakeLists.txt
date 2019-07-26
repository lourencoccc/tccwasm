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
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 --std=c++11")
    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s WASM=1 -s DEMANGLE_SUPPORT=1")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s TOTAL_MEMORY=268435456")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s ALLOW_MEMORY_GROWTH=1")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s FORCE_FILESYSTEM=1 --no-heap-copy")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --bind --preload-file assets/")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --post-js ../../src/webapp_helper.js")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}../../../webapp)
    set(OpenCV_DIR "/home/vagrant/opencv/build_wasm2")
    include_directories("/home/vagrant/emsdk/emscripten/1.38.31/system/include/")
elseif(UNIX)
    message(STATUS ">>> Linux/OSx")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(WIN32)
    message(STATUS ">>> Windows")
    include_directories("D:/Apps/emsdk/fastcomp/emscripten/system/include")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /O2 /MT")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
    add_compile_options("/std:c++17")
endif()

set(BUILD_SHARED_LIBS OFF)
include_directories("include/")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIB_DIR})

set(SOURCE_CORE src/image_process.cpp
    src/face_detect.cpp
    src/mat_adapter.cpp
    src/utils.cpp
)

set(SOURCE_CORE_WASM src/webapp_facade.cpp
    src/image_process.cpp
    src/face_detect.cpp
    src/mat_adapter.cpp
    src/utils.cpp
)

if(NOT WASM)
    add_library(detectorsz_core ${SOURCE_CORE})

    add_executable(detectorsz_app src/main.cpp)
    target_link_libraries(detectorsz_app detectorsz_core)
    target_link_libraries(detectorsz_app ${OpenCV_LIBS})
else()
    add_executable(detectorsz_core.html ${SOURCE_CORE_WASM})
    target_link_libraries(detectorsz_core.html ${OpenCV_LIBS})
endif()
