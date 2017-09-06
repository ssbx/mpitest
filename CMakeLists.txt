cmake_minimum_required(VERSION 3.0)
project(mpitest)

find_package(MPI REQUIRED)
include_directories(
    code/
    ${MPI_C_INCLUDE_PATH})

add_executable(mc_simple code/simple.c)
add_executable(mc_mpi code/mpi.c)
add_executable(test2 code/test2.c)
target_link_libraries(mc_mpi ${MPI_C_LIBRARIES})
target_link_libraries(test2 ${MPI_C_LIBRARIES})
