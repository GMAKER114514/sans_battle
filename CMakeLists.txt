cmake_minimum_required(VERSION 3.10)

project(SansBattle VERSION 1.0.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE scr/main.cpp
        scr/inc/Timer.h
        scr/inc/rooms/1.h
        scr/inc/rooms/0.h
        scr/inc/things/Text.h
        scr/inc/gdata.h
        scr/inc/rooms/5.h

        scr/lib/rooms/1.cpp
        scr/lib/rooms/0.cpp
        scr/lib/things/Text.cpp
        scr/lib/rooms/3.cpp
        scr/lib/gdata.cpp
        scr/lib/rooms/5.cpp
        scr/lib/things/gaster_blaster.cpp
        scr/lib/things/move.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE})

#target_sources(${PROJECT_NAME} PRIVATE raylib.rc)
#set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "-Wl,--subsystem,windows")

set(INC raylib/include
        scr/inc
        scr/inc/rooms
        scr/inc/things
)
set(LIB raylib/lib/)
target_include_directories(${PROJECT_NAME} PRIVATE ${INC} )
target_link_directories(${PROJECT_NAME} PRIVATE ${LIB})
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

target_link_libraries(${PROJECT_NAME} PRIVATE winmm gdi32 opengl32 msimg32 kernel32 user32 shell32)