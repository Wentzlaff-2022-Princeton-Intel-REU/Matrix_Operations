# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 2.8.11)
project (Matrix_Operations)

include_directories(include)
add_library(matrix scr/print.c scr/reading.c)

add_executable (matrix_operations scr/scalar/add.c scr/scalar/main.c scr/scalar/multiply.c)
target_include_directories(matrix_operations PRIVATE include/scalar)
target_link_libraries(matrix_operations PRIVATE matrix)

add_executable (vec_matrix_operations scr/vector/add.c scr/vector/main.c scr/vector/multiply.c)
target_include_directories(vec_matrix_operations PRIVATE include/vector)
target_link_libraries(vec_matrix_operations PRIVATE matrix)