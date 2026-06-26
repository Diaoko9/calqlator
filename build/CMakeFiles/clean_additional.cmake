# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/calqlator_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/calqlator_autogen.dir/ParseCache.txt"
  "calqlator_autogen"
  )
endif()
