file(GLOB_RECURSE COORDINATOR_SOURCE "${PROJECT_SOURCE_DIR}/coordinator/*.cpp" "${PROJECT_SOURCE_DIR}/coordinator/*.h")
add_executable(Coordinator ${COORDINATOR_SOURCE})

target_link_libraries(Coordinator PRIVATE Shared subprocess)
target_include_directories(Coordinator PRIVATE ${PROJECT_SOURCE_DIR}/shared)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Coordinator PROPERTY CXX_STANDARD 20)
endif()
