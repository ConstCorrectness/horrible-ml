include(FetchContent)

# GoogleTest v1.17.0
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP true         # cmake_policy(SET CMP0135 NEW)
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing()

add_executable(
  horribleutils_test
  horribleutils_test.cc
)

target_link_libraries(
  horribleutils_test
  GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(horribleutils_test)