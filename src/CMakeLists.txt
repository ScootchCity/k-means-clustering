cmake_minimum_required( VERSION 3.10 )
project(k-means-clustering)

## C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## C++ compiler options
if(MSVC)
    set( CMAKE_CXX_FLAGS "/W4" )
    set( CMAKE_CXX_FLAGS_DEBUG "/Od /Zi" )
    set( CMAKE_CXX_FLAGS_RELEASE "/O2" )
else()
    set( CMAKE_CXX_FLAGS "-Wall -Wextra" )
    set( CMAKE_CXX_FLAGS_DEBUG "-g -O0" )
    set( CMAKE_CXX_FLAGS_RELEASE "-O3" )
endif()

## Add subdirectories
add_subdirectory( common )
add_subdirectory( kmeans )
add_subdirectory( generator )

## Install both executables
install( TARGETS kmeans generate_data
         RUNTIME DESTINATION bin )