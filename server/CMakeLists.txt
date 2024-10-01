file(GLOB_RECURSE SERVER_SOURCE "${PROJECT_SOURCE_DIR}/server/*.cpp" "${PROJECT_SOURCE_DIR}/server/*.h")
add_executable(Server ${SERVER_SOURCE})

target_link_libraries(Server PRIVATE Shared subprocess)
target_include_directories(Server PRIVATE ${PROJECT_SOURCE_DIR}/shared)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Server PROPERTY CXX_STANDARD 20)
endif()
