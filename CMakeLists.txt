cmake_minimum_required(VERSION 3.20)


project(horribleML
    VERSION 0.1.2.3
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



include_directories(include)


# GoogleTest

include(CTest)
if(BUILD_TESTING)
    message(STATUS "Testing enabled")
    add_subdirectory(test)
endif()

