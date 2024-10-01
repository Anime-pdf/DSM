add_executable(Server "Server.cpp" "Server.h")

target_link_libraries(Server PRIVATE Shared subprocess)
target_include_directories(Server PRIVATE ${CMAKE_SOURCE_DIR}/shared)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Server PROPERTY CXX_STANDARD 20)
endif()
