cmake_minimum_required(VERSION 3.0.0)
project(raytracer_cpp VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(raytracer_cpp main.cpp tuple.cpp utils.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

enable_testing()

add_executable(
  tuple_test
  tuple_test.cpp
  tuple.cpp
  utils.cpp
)

target_link_libraries(
  tuple_test
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(tuple_test)