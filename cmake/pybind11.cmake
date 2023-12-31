include(FetchContent)

set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
  pybind11
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
  URL https://github.com/pybind/pybind11/archive/v2.10.0.tar.gz)

FetchContent_MakeAvailable(pybind11)

include_directories(${pybind11_SOURCE_DIR})
