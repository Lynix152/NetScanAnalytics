cmake_minimum_required(VERSION 3.10)
project(DataAnalysisSystem)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB SOURCES "src/*.cpp" "src/loader/*.cpp" "src/utils/*.cpp")

add_executable(DataAnalysisSystem ${SOURCES})

find_package(MPI REQUIRED)
include_directories(SYSTEM ${MPI_INCLUDE_PATH})
target_link_libraries(DataAnalysisSystem ${MPI_LIBRARIES})

if(MPI_COMPILE_FLAGS)
    set_target_properties(DataAnalysisSystem PROPERTIES
            COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
endif()

if(MPI_LINK_FLAGS)
    set_target_properties(DataAnalysisSystem PROPERTIES
            LINK_FLAGS "${MPI_LINK_FLAGS}")
endif()
