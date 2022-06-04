cmake_minimum_required(VERSION 3.22)

include(cmake/HunterGate.cmake)
cmake_host_system_information(RESULT HUNTER_JOBS_NUMBER QUERY NUMBER_OF_LOGICAL_CORES)
HunterGate(
    URL "https://github.com/cpp-pm/hunter/archive/v0.24.0.tar.gz"
    SHA1 "a3d7f4372b1dcd52faa6ff4a3bd5358e1d0e5efd"
    LOCAL
)

project(codenames)

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    set(HUNTER_KEEP_PACKAGE_SOURCES ON)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-Wall)
add_compile_options(-Werror)
add_compile_options(-Wfatal-errors)
add_compile_options(-Wno-deprecated)
add_compile_options(-pipe)
add_compile_options(-fPIC)
add_compile_options(-fPIE)

# settings
set(ROOT_DIR "${CMAKE_CURRENT_LIST_DIR}")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${ROOT_DIR}/cmake/")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DNDEBUG -flto")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -DNDEBUG -flto")

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_definitions(-Wno-mismatched-tags)
    add_definitions(-Wno-inconsistent-missing-override)
    add_definitions(-Wno-delete-non-abstract-non-virtual-dtor)
endif()


set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_DEBUG_LIBS        OFF)  # ignore debug libs and
set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
set(BOOST_COMPONENTS)
list(APPEND BOOST_COMPONENTS system program_options)
hunter_add_package(Boost COMPONENTS ${BOOST_COMPONENTS})
### Download dependencies ###
hunter_add_package(GTest)
### Find dependencies ###
find_package(GTest CONFIG REQUIRED) # GTest::main
find_package(Boost CONFIG COMPONENTS ${BOOST_COMPONENTS})

include_directories(${Boost_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC ${Boost_LIBRARIES} ${GTest_LIBRARIES})

### Testing ###
enable_testing()
