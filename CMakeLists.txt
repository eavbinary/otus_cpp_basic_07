cmake_minimum_required(VERSION 3.5)

project(07.homework)

add_executable(containers main.cpp)
set_target_properties(containers PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  container_test
  serial_container_test.cc
  line_container_test.cc
)

target_link_libraries(
    container_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(container_test)
