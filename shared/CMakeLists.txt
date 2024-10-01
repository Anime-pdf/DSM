add_library(Shared STATIC "Cool.cpp" "Cool.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Shared PROPERTY CXX_STANDARD 20)
endif()
