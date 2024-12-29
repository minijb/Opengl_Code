cmake_minimum_required(VERSION 3.5.0)

project(
    opengl 
    VERSION 0.1.0 
    LANGUAGES C CXX
)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


#include
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

# glad
set(GLAD_DIR ${PROJECT_SOURCE_DIR}/lib/glad)
# glfw
set(GLFW_DIR ${PROJECT_SOURCE_DIR}/lib/glfw)


# source file
file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp ${GLAD_DIR}/*.c ${PROJECT_SOURCE_DIR}/src/*.h)

message(STATUS "SRC_FILES: ${SRC_FILES}")


add_executable(${PROJECT_NAME} ${SRC_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR})
target_link_directories(${PROJECT_NAME} PUBLIC ${GLFW_DIR})
target_link_libraries(${PROJECT_NAME} glfw3 openGL32)