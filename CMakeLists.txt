cmake_minimum_required(VERSION 3.16)
project(sky_math_core LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(sky_math STATIC src/sky_math.cpp)
target_include_directories(sky_math PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_options(sky_math PRIVATE -Wall -Wextra -Wpedantic -Werror)

add_executable(app src/main.cpp)
target_link_libraries(app PRIVATE sky_math)
target_compile_options(app PRIVATE -Wall -Wextra -Wpedantic -Werror)

add_executable(test_app tests/test_main.cpp)
target_link_libraries(test_app PRIVATE sky_math)
target_compile_options(test_app PRIVATE -Wall -Wextra -Wpedantic -Werror)

enable_testing()
add_test(NAME sky_math_contract COMMAND test_app)
