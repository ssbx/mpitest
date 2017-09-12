cmake_minimum_required(VERSION 3.0)
project(mpitest)

set(MPITEST_LIBS "")


#
# MPI library config
#
find_package(MPI REQUIRED)
include_directories(${MPI_C_INCLUDE_PATH})
set(CMAKE_EXE_LINKER_FLAGS 
    ${CMAKE_EXE_LINKER_FLAGS} 
    ${MPI_CXX_LINK_FLAGS})
set(CMAKE_CXX_FLAGS 
    ${CMAKE_CXX_FLAGS} 
    ${MPI_CXX_COMPILE_FLAGS})
set(MPITEST_LIBS ${MPITEST_LIBS} ${MPI_CXX_LIBRARIES})


#
# BLAS/LAPACK library config
#
find_package(LAPACK REQUIRED)
set(CMAKE_EXE_LINKER_FLAGS 
    ${CMAKE_EXE_LINKER_FLAGS} 
    ${LAPACK_LINKER_FLAGS})
set(BLA_STATIC TRUE)
set(MPITEST_LIBS ${MPITEST_LIBS} ${LAPACK_LIBRARIES})


#
# OpenMP library config
#
find_package(OpenMP REQUIRED)
set(CMAKE_CXX_FLAGS 
    ${CMAKE_CXX_FLAGS}
    ${OpenMP_CXX_FLAGS})


#
# Our executable test
#
add_executable(mpitest code/mpitest.cpp)
target_link_libraries(mpitest ${MPITEST_LIBS})
add_executable(mptest code/mptest.cpp)
target_link_libraries(mptest ${MPITEST_LIBS})

