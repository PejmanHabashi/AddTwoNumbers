cmake_minimum_required(VERSION 2.6)

Project (solution CXX)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} ${EXTRA_LIBS})
