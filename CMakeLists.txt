cmake_minimum_required(VERSION 3.28)
project(Hangman LANGUAGES CXX)

set(CMAKE_CXX_STANDART 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_EXE_LINKER_FLAGS -fuse-ld=lld)

#set (SOURCE_FILES main.cpp)

if(DOCS)
    add_subdirectory(docs)
endif()

find_package(sfml-graphics)
find_package(sfml-window)
find_package(sfml-system)

file(GLOB SOURCE_FILE src/*.cpp)
add_executable(Hangman ${SOURCE_FILE} src/main.cpp)

target_link_libraries(Hangman PRIVATE sfml-system)
target_link_libraries(Hangman PRIVATE sfml-window)
target_link_libraries(Hangman PRIVATE sfml-graphics)

# add_executable(HangmanTest test/test.cpp ${SOURCE_FILE})
# target_link_libraries(HangmanTest PRIVATE gtest sfml-graphics sfml-window sfml-system)
# add_test(NAME HangmanTest COMMAND HangmanTest)
# enable_testing()