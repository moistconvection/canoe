# Installs harp library
#
#   library: libharp_debug.o
#   library: libharp_release.o
#
# Define the following variables
#
#   HARP_INCLUDE_DIR
#   HARP_LIBRARY_DEBUG
#   HARP_LIBRARY_RELEASE
#
# Normal usage would be:
#
#   include_directories( ${INVERSION_INCLUDE_DIR})
#   target_link_libraries( ${INVERSION_LIBRARY_DEBUG})

set(namel harp)
string(TOUPPER ${namel} nameu)

file(GLOB src_files
    *.cpp
    )

string(TOLOWER ${CMAKE_BUILD_TYPE} buildl)
string(TOUPPER ${CMAKE_BUILD_TYPE} buildu)

add_library(${namel}_${buildl}
    OBJECT
    ${src_files}
    )

set_target_properties(${namel}_${buildl}
    PROPERTIES
    COMPILE_FLAGS ${CMAKE_CXX_FLAGS_${buildu}}
    )

target_include_directories(${namel}_${buildl}
    PRIVATE
    ${NETCDF_INCLUDES}
    )
