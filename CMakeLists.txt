# CMakeLists.txt
# Build script for SEIR epidemic simulation project

cmake_minimum_required(VERSION 3.10)
project(SEIRModel LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/model/include)

# Source files
file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/model/src/*.cpp)
file(GLOB HEADERS ${CMAKE_SOURCE_DIR}/model/include/*.h)

add_executable(seir_simulation ${SOURCES} ${HEADERS})

# If you need to link external libraries, add them here
# target_link_libraries(seir_simulation ...) 