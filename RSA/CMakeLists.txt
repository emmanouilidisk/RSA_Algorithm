cmake_minimum_required(VERSION 3.0.0)
project(RSA VERSION 0.1.0)

add_executable(${PROJECT_NAME}
main.cpp
RSA.h
RSA.cpp
)

target_include_directories(
  ${PROJECT_NAME} 
  PRIVATE boost_1_66_0/
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
