cmake_minimum_required(VERSION 3.7)

project(SDLGame)

include_directories(${MY_SOURCE_DIR}/src)
include_directories(${MY_SOURCE_DIR}/inc)

#Put the source here
set(SRCS
	
src/main
)

set(SDL2_DIR
SDL2)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable (SDLGame ${SRCS})
target_link_libraries(SDLGame ${SDL2_LIBRARIES})

add_custom_command(TARGET SDLGame 
		   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy
                       ${CMAKE_SOURCE_DIR}/SDL2/lib/x86/SDL2.dll $<TARGET_FILE_DIR:SDLGame>)


