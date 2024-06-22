cmake_minimum_required(VERSION 3.10)
project(DataAnalysisSystem)

set(CMAKE_CXX_STANDARD 17)

# Debugging flags
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_BUILD_TYPE Debug)

# Include directories
include_directories(include)

# Source files
file(GLOB SOURCES "src/*.cpp" "src/loader/*.cpp" "src/utils/*.cpp")

# Add executable with sources
add_executable(DataAnalysisSystem ${SOURCES})

# Find and link MPI library
find_package(MPI REQUIRED)
include_directories(${MPI_CXX_INCLUDE_DIRS})
target_link_libraries(DataAnalysisSystem ${MPI_CXX_LIBRARIES})

# Find and link tinyxml2 library
find_package(tinyxml2 REQUIRED)
include_directories(${tinyxml2_INCLUDE_DIR})
target_link_libraries(DataAnalysisSystem tinyxml2::tinyxml2)

# Find and link nlohmann_json library
find_package(nlohmann_json REQUIRED)
target_link_libraries(DataAnalysisSystem nlohmann_json::nlohmann_json)

# Set output directory based on platform
if(WIN32)
    set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
else()
    set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
endif()

# Optional: Copy DLLs for Windows
if(WIN32)
    add_custom_command(TARGET DataAnalysisSystem POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:nlohmann_json::nlohmann_json>
            ${EXECUTABLE_OUTPUT_PATH}/$<TARGET_FILE_NAME:nlohmann_json::nlohmann_json>)

    add_custom_command(TARGET DataAnalysisSystem POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:tinyxml2::tinyxml2>
            ${EXECUTABLE_OUTPUT_PATH}/$<TARGET_FILE_NAME:tinyxml2::tinyxml2>)
endif()
