cmake_minimum_required (VERSION 2.6)

project (Reactive)

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set (CMAKE_CXX_COMPILER "clang++")
endif ()



set (CMAKE_MACOSX_RPATH 1)
#SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

# Add find modules to the path
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules/")

# Set some nicer output dirs.
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

# enable valgrind
set (CMAKE_MEMORYCHECK_COMMAND valgrind)
set (CMAKE_MEMORYCHECK_COMMAND_OPTIONS "--error-exitcode=1 -v --track-origins=yes --leak-check=full --show-reachable=yes --trace-children=yes --child-silent-after-fork=yes -q")

find_file (HAVE_VALGRIND "valgrind")

set (REACTIVE_VERSION_MAJOR   0)
set (REACTIVE_VERSION_MINOR   1)
set (REACTIVE_VERSION_PATCH   0)
set (REACTIVE_INCLUDE_PATH    "${CMAKE_INSTALL_PREFIX}/include/reactive")
set (REACTIVE_LIBRARY_PATH    "${CMAKE_INSTALL_PREFIX}/lib/reactive")
set (REACTIVE_MODULE_PATH     "${CMAKE_INSTALL_PREFIX}/lib/reactive")
set (SYSTEM                   "${CMAKE_SYSTEM}")
set (SYSTEM_NAME              "${CMAKE_SYSTEM_NAME}")
set (SYSTEM_PROCESSOR         "${CMAKE_SYSTEM_PROCESSOR}")
set (SIZEOF_DATA_PTR          "${CMAKE_CXX_SIZEOF_DATA_PTR}")

string (TIMESTAMP REACTIVE_CURRENT_YEAR "%Y")

message (STATUS "System name: ${CMAKE_SYSTEM_NAME}")
message (STATUS "System processor: ${CMAKE_SYSTEM_PROCESSOR}")
message (STATUS "System version: ${CMAKE_SYSTEM_VERSION}")

# Populate the configuration header.
configure_file (
    "${CMAKE_SOURCE_DIR}/include/reactive/version.hpp.in"
    "${CMAKE_SOURCE_DIR}/include/reactive/version.hpp"
)

if (NOT CMAKE_BUILD_TYPE)
    set (CMAKE_BUILD_TYPE Release CACHE STRING
         "Choose the type of build. Options are 'Debug' and 'Release'."
         FORCE)
endif ()

string (TOUPPER ${CMAKE_BUILD_TYPE} CMAKE_BUILD_TYPE)
string (COMPARE EQUAL ${CMAKE_BUILD_TYPE} "DEBUG"   IS_DEBUG)
string (COMPARE EQUAL ${CMAKE_BUILD_TYPE} "RELEASE" IS_RELEASE)

if (NOT IS_DEBUG)
    if (NOT IS_RELEASE)
        message (FATAL_ERROR "Invalid CMAKE_BUILD_TYPE specified. Must be either 'Debug' or 'Release'.")
    endif ()
endif ()

message (STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# Set compile/link flags.
set (REACTIVE_LIBDIR_FLAGS_ "$ENV{LDFLAGS}")
set (REACTIVE_LIB_FLAGS_    "-lpthread")

if (${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")
    set (REACTIVE_LINK_FLAGS_ "${REACTIVE_LIBDIR_FLAGS_} -L/usr/local/lib -L/opt/local/lib ${REACTIVE_LIB_FLAGS_}")
else ()
    set (REACTIVE_LINK_FLAGS_ "${REACTIVE_LIBDIR_FLAGS_} ${REACTIVE_LIB_FLAGS_} -ldl -L/opt/local/lib -L/usr/local/lib")
endif ()

set (CXX_FLAGS_EXTRA "-std=c++11")

set (CMAKE_CXX_FLAGS         "$ENV{CPPFLAGS} -Wall")
set (CMAKE_CXX_FLAGS_DEBUG   "-g -ggdb -O0 -fprofile-arcs -ftest-coverage -fno-inline -Wextra -Wno-unused-parameter -DDEBUG ${CXX_FLAGS_EXTRA}")
set (CMAKE_CXX_FLAGS_RELEASE "-O3 -fomit-frame-pointer ${CXX_FLAGS_EXTRA}")

if (${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")
    include_directories ("${PROJECT_BINARY_DIR}" "/usr/local/include")
else ()
    include_directories ("${PROJECT_BINARY_DIR}")
endif ()

link_directories (/opt/local/lib)

include_directories (${CMAKE_CURRENT_SOURCE_DIR}/include)

find_package (Boost 1.54.0 REQUIRED COMPONENTS thread system iostreams regex date_time signals filesystem) #  COMPONENTS date_time filesystem system ...

include_directories (${Boost_INCLUDE_DIRS})

find_package (HttpParser REQUIRED)
include_directories (${HTTP_PARSER_INCLUDE_DIRS})

find_package(Crypto REQUIRED)
include_directories (${CRYPTO_INCLUDE_DIR})

find_package(LibUV REQUIRED)
include_directories (${LIBUV_INCLUDE_DIRS})

# find cpp files
#file (GLOB_RECURSE SRCFILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/src/ *.cpp)

file (
    GLOB_RECURSE
    INC_FILES
    include/*
)

file (
    GLOB_RECURSE
    SRC_FILES
    src/*
)

add_library (ReactiveShared SHARED ${SRC_FILES})
set_target_properties (ReactiveShared PROPERTIES XCODE_ATTRIBUTE_DEBUG_INFORMATION_FORMAT "dwarf-with-dsym" OUTPUT_NAME reactive)
target_link_libraries (ReactiveShared ${Boost_LIBRARIES} pthread ${HTTP_PARSER_LIBRARIES} ${CRYPTO_LIBRARIES} ${LIBUV_LIBRARIES})

add_library (ReactiveStatic STATIC ${SRC_FILES})
set_target_properties (ReactiveStatic PROPERTIES XCODE_ATTRIBUTE_DEBUG_INFORMATION_FORMAT "dwarf-with-dsym" OUTPUT_NAME reactive)
target_link_libraries (ReactiveStatic ${Boost_LIBRARIES} pthread ${HTTP_PARSER_LIBRARIES} ${CRYPTO_LIBRARIES} ${LIBUV_LIBRARIES})

enable_testing ()

file (
    GLOB_RECURSE
    TEST_FILES
    test/*
)

add_executable (
    reactive-test
    ${TEST_FILES}
)

target_link_libraries (reactive-test ReactiveShared pthread)

if (CMAKE_COMPILER_IS_GNUCXX)
    include (CodeCoverage)
    setup_target_for_coverage (reactive-coverage reactive-test coverage)
    target_link_libraries (reactive-test gcov)
endif ()

add_subdirectory (demo)

function (add_memcheck_test name binary)
    set (memcheck_command "${CMAKE_MEMORYCHECK_COMMAND} ${CMAKE_MEMORYCHECK_COMMAND_OPTIONS}")
    separate_arguments (memcheck_command)
    add_test (${name} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${binary})
    if (HAVE_VALGRIND)
        add_test (memcheck_${name} ${memcheck_command} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${binary})
    endif ()
endfunction (add_memcheck_test)

add_memcheck_test(Reactive reactive-test)

install(FILES ${INC_FILES} DESTINATION include)

install(TARGETS ReactiveShared ReactiveStatic
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)
