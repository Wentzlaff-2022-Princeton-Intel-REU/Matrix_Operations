# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 2.8.11)
project (Matrix_Operations)
add_executable (matrix_operations main.c add.c multiply.c print.c reading.c vec_add.c vec_multiply.c)
