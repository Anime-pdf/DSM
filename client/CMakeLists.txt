file(GLOB_RECURSE CLIENT_SOURCE "${PROJECT_SOURCE_DIR}/client/*.cpp" "${PROJECT_SOURCE_DIR}/client/*.h")
add_executable(Client ${CLIENT_SOURCE})

target_link_libraries(Client PRIVATE Shared subprocess)
target_include_directories(Client PRIVATE ${PROJECT_SOURCE_DIR}/shared)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Client PROPERTY CXX_STANDARD 20)
endif()
