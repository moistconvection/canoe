# ========================
# A collection of examples
# ========================

if (${HYDROSTATIC})
  add_subdirectory(1d-rad-jupiter)
  add_subdirectory(2023-jupiter-mwr-eq)
else()
  add_subdirectory(2019-Li-snap)
endif()
