cmake_minimum_required (VERSION 3.8)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("DSM")

# TODO: Add tests

set(INCLUDE_DIRS 
		external/cpp-httplib
		external/subprocess
		${PROJECT_SOURCE_DIR}/shared
)

add_subdirectory(shared)
add_subdirectory(coordinator)
add_subdirectory(server)

target_include_directories(Coordinator PRIVATE ${INCLUDE_DIRS})
target_include_directories(Server PRIVATE ${INCLUDE_DIRS})