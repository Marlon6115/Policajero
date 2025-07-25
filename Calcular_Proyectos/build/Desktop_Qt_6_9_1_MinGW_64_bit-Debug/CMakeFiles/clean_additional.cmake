# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Calcular_Proyectos_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Calcular_Proyectos_autogen.dir\\ParseCache.txt"
  "Calcular_Proyectos_autogen"
  )
endif()
