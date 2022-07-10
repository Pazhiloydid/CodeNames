cmake_minimum_required(VERSION 3.20)

project(codenames CXX)

#execute_process(COMMAND conan install --update --build=missing ${CMAKE_SOURCE_DIR})

# settings
set(ROOT_DIR "${CMAKE_CURRENT_LIST_DIR}")
message(${CMAKE_BINARY_DIR})
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${ROOT_DIR}/cmake/")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_BINARY_DIR}")

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_definitions(-Wno-mismatched-tags)
    add_definitions(-Wno-inconsistent-missing-override)
    add_definitions(-Wno-delete-non-abstract-non-virtual-dtor)
endif()

# Turn on automatic invocation of the MOC, UIC & RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#Boost

find_package(Boost)

# Create executable

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} Boost::boost)
target_link_libraries(${PROJECT_NAME} Boost::headers)

message(NOTICE "test message")

### QML

find_package(Qt5 COMPONENTS Widgets QWindowsIntegrationPlugin REQUIRED)

target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::QWindowsIntegrationPlugin)

### Testing ###
find_package(GTest REQUIRED)

add_executable(tests tests.cpp)

target_link_libraries(tests GTest::gtest GTest::gtest_main)

enable_testing()
