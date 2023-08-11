cmake_minimum_required(VERSION 3.1)
project(opencvapi VERSION 1.0.0)

include(CTest)
enable_testing()

find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(opencvapi main.cpp)

target_include_directories(opencvapi PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(opencvapi ${OpenCV_LIBS} )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${CPACK_PROJECT_VERSION})
include(CPack)

