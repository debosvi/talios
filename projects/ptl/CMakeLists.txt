cmake_minimum_required (VERSION 3.0)
project (talios_ptl)

include(project_ver.cmake)

set(PRJ_DIR $ENV{TALIOS_PROJECT_DIR})
if("${PRJ_DIR}" STREQUAL "")
    set(PRJ_DIR ${TALIOS_PROJECT_DIR})
endif()
if("${PRJ_DIR}" STREQUAL "")
    message(FATAL_ERROR "Please source root env.sh script")
endif()

include(${PRJ_DIR}/components/tools/ext-build/cmake/boz-build.cmake)

# include(CTest)
# set (CMAKE_VERBOSE_MAKEFILE ON)

include(tools.cmake)

BOZ_COMPS_FIND_ALL("${PRJ_DIR}/components/ptl/base")
BOZ_COMPS_FIND_ALL("${PRJ_DIR}/components/ptl/design")
