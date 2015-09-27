cmake_minimum_required(VERSION 2.6)
project(geometry)

set(BIN_DIR ${geometry_SOURCE_DIR}/bin)

include_directories(include)
add_executable(geometry src/main.cpp)
install(TARGETS geometry RUNTIME DESTINATION ${BIN_DIR})
