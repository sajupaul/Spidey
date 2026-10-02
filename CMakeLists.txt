cmake_minimum_required(VERSION 3.20)

project(Spidey
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(Spidey
    src/main.cpp
    src/representation/entity.cpp
)

target_include_directories(Spidey
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

enable_testing()

find_package(GTest REQUIRED)

add_executable(SpideyEntityTest
    tests/entity_test.cpp
    src/representation/entity.cpp
)

target_include_directories(SpideyEntityTest
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(SpideyEntityTest
    PRIVATE
        GTest::gtest
        GTest::gtest_main
)

add_test(
    NAME SpideyEntityTest
    COMMAND SpideyEntityTest
)