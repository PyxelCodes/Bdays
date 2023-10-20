# CMakeList.txt : CMake project for Birthdays, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Birthdays")

find_package(jsoncpp REQUIRED)

# Add source to this project's executable.
add_executable (Birthdays "src/Birthdays.cpp" "src/Birthdays.h" "src/getConfigPath.cpp" "src/getConfigPath.h" "src/readConfig.cpp" "src/readConfig.h" "src/printTable.cpp" "src/printTable.h" "src/configToBday.cpp" "src/configToBday.h")

target_link_libraries(Birthdays jsoncpp_lib)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Birthdays PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
