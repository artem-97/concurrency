cmake_minimum_required(VERSION 3.0.0)

# specify the C++ standard
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fcoroutines -pthread -Wall -Wpedantic")
set(CMAKE_CXX_COMPILER "g++-10")
set(CMAKE_CXX_STANDARD 20)


set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")


set(PROJECT_NAME concurrency)
project(${PROJECT_NAME} VERSION 0.1.0)
 
# include_directories(src)
add_subdirectory(src/atomic)
add_subdirectory(src/lock-free)
add_subdirectory(src/channel)
# add_executable(${PROJECT_NAME} ${SRC_FILES} )
