cmake_minimum_required(VERSION 3.20)
project(sky_math VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(sky_math INTERFACE)
target_include_directories(sky_math INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(sky_math INTERFACE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(sky_math INTERFACE -Wall -Wextra -Wpedantic -Werror)
endif()

add_executable(sky-math-demo src/main.cpp)
target_link_libraries(sky-math-demo PRIVATE sky_math)

include(CTest)
if(BUILD_TESTING)
    add_executable(sky-math-tests tests/test_main.cpp)
    target_link_libraries(sky-math-tests PRIVATE sky_math)
    add_test(NAME sky-math-tests COMMAND sky-math-tests)
endif()
