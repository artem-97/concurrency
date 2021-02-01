cmake_minimum_required(VERSION 3.0.0)

set(TEST_NAME concurrency_queue)
project(${PROJECT_NAME} VERSION 0.1.0)
 
# include_directories(src)
file(GLOB_RECURSE SRC_FILES *)
add_executable(${TEST_NAME}_test ${SRC_FILES} )
