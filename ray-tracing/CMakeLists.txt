cmake_minimum_required(VERSION 3.5)
project(ray_tracing)

SET(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Weverything -Reverything -Wno-shadow \
                         -Wno-global-constructors -Wno-c++98-compat -Wno-c++98-compat-pedantic \
                         -Wno-dollar-in-identifier-extension -Wno-missing-prototypes -g")
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
#set(CMAKE_VERBOSE_MAKEFILE ON)

set(SOURCE_FILES main.cpp monitor.cpp monitor.h object.cpp object.h point.cpp point.h ray.cpp ray.h scene.cpp scene.h widget.cpp widget.h)

add_definitions(${Qt5Widgets_DEFINITIONS})
add_executable(ray_tracing ${SOURCE_FILES} ${UI_HEADERS} ${UI_RESOURCES})

find_package(Qt5Widgets)
find_package(Qt5Declarative)

target_link_libraries(ray_tracing ${Qt5Core_QTMAIN_LIBRARIES})

qt5_use_modules(ray_tracing Widgets OpenGL)
