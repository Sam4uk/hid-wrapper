cmake_minimum_required(VERSION 3.11)

include_directories(
    include
)


link_libraries(
    hidapi-hidraw
)

add_executable(check "test/test.cxx" "source/hidapi-wrapper.cpp")

enable_testing()

add_test(check check)

file(WRITE "${CMAKE_BINARY_DIR}/.gitignore" "*\n*.*")