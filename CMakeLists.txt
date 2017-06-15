cmake_minimum_required(VERSION 3.0)

project(djc_math_tests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

find_library(SDL_FRAMEWORK SDL2)

if (NOT SDL_FRAMEWORK)
     message(FATAL_ERROR "SDL2 not found")
endif()

    add_executable(${PROJECT_NAME} ./tests.cpp)

    target_link_libraries(${PROJECT_NAME}
                          ${SDL_FRAMEWORK})
