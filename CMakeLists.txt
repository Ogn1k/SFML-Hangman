cmake_minimum_required(VERSION 3.28)
project(Project2)

set (SOURCE_FILES main.cpp)

#add_executable(Project2)
#target_sources(Project2 PRIVATE main.cpp)
#target_compile_features(Project2 PRIVATE cxx_std_17)
#install(TARGET Project2)

set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/SFML/cmake-modules/")
find_package (SFML REQUIRED system window graphics audio REQUIRED)

add_executable (Project2 ${SOURCE_FILES})
target_link_libraries(Project2 PUBLIC sfml-system sfml-window sfml-graphics sfml-network sfml-audio)