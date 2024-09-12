cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build tests" OFF)

project(Stratergy)

 add_library(Stratergy STATIC ${CMAKE_CURRENT_SOURCE_DIR}/Behavioral/Stratergy/main.cpp ${CMAKE_CURRENT_SOURCE_DIR}/Behavioral/Stratergy/ConcreteStratergyA.cpp ${CMAKE_CURRENT_SOURCE_DIR}/Behavioral/Stratergy/ConcreteStratergyB.cpp ${CMAKE_CURRENT_SOURCE_DIR}/Behavioral/Stratergy/Context.cpp)
target_include_directories(Stratergy PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/Behavioral/Stratergy )

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(third-party/googletest)
  file(GLOB Stratergy_TEST_SOURCES tests/*.cpp)
  add_executable(check ${Stratergy_TEST_SOURCES})
  target_link_libraries(check Stratergy gtest_main gmock_main)
  add_test(NAME check COMMAND check)
endif()
