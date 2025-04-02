













cmake_minimum_required(VERSION 3.10)
project(BitcoinRpcMultiprocess)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable pthread support
find_package(Threads REQUIRED)

# Find UniValue
find_library(UNIVALUE_LIBRARY NAMES univalue HINTS /usr/local/lib /usr/lib/x86_64-linux-gnu)
find_path(UNIVALUE_INCLUDE_DIR NAMES univalue.h HINTS /usr/local/include /usr/include)
if (UNIVALUE_LIBRARY AND UNIVALUE_INCLUDE_DIR)
    message(STATUS "Found UniValue: ${UNIVALUE_LIBRARY}")
    include_directories(${UNIVALUE_INCLUDE_DIR})
else()
    message(FATAL_ERROR "UniValue library not found. Please install libunivalue-dev or build it manually.")
endif()


# Find Libmultiprocess (which includes Cap’n Proto)
find_package(Libmultiprocess REQUIRED)

# Find LibUV
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBUV REQUIRED libuv)
if (LIBUV_FOUND)
    include_directories(${LIBUV_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "LibUV not found. Install it using: sudo apt install libuv1-dev")
endif()

# Find libevent
pkg_check_modules(LIBEVENT REQUIRED libevent)
find_library(LIBEVENT_CORE NAMES event_core)
find_library(LIBEVENT_EXTRA NAMES event_extra)
if(NOT LIBEVENT_CORE OR NOT LIBEVENT_EXTRA)
    message(FATAL_ERROR "Could not find libevent_core or libevent_extra. Install it using: sudo apt install libevent-dev")
endif()

# Find Cap’n Proto
# find_package(CapnProto REQUIRED)
if(CapnProto_FOUND)
    include_directories(${CapnProto_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "Cap’n Proto not found. Install it using: sudo apt install capnproto libcapnp-dev")
endif()

# List pre-generated Cap’n Proto files
file(GLOB CAPNP_GENERATED_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/ipc/*.capnp.c++")

# Include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ipc
    ${CMAKE_CURRENT_SOURCE_DIR}/interfaces
    ${LIBUV_INCLUDE_DIRS}
    ${LIBEVENT_INCLUDE_DIRS}
    ${UNIVALUE_INCLUDE_DIRS}
    ${CapnProto_INCLUDE_DIRS}
)

# Add executable
add_executable(rpc-server
    src/server/http_server.cpp  
    src/server/rpc_interface.cpp  
    src/server/utils.cpp  
    src/server/main.cpp   
    ${CAPNP_GENERATED_FILES}
)

# Link libraries
target_link_libraries(rpc-server PRIVATE
    CapnProto::capnp
    CapnProto::capnp-rpc
    Libmultiprocess::multiprocess
    ${LIBUV_LIBRARIES}
    Threads::Threads
    kj
    univalue
    ${LIBEVENT_LIBRARIES}
    ${LIBEVENT_CORE}
    ${LIBEVENT_EXTRA}
    ${UNIVALUE_LIBRARIES}
)

message(STATUS "BitcoinRpcMultiprocess setup complete. Run 'make' to build.")














