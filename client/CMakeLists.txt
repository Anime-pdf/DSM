add_executable(Client "Client.cpp" "Client.h")

target_link_libraries(Client PRIVATE Shared subprocess)
target_include_directories(Client PRIVATE ${CMAKE_SOURCE_DIR}/shared)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Client PROPERTY CXX_STANDARD 20)
endif()
