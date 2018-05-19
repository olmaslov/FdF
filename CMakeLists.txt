cmake_minimum_required(VERSION 3.9)

project(fdf_linux)



set(SOURCE_FILES main.c fdf.h reader.c )


add_executable(fdf_linux ${SOURCE_FILES})
include_directories(/usr/local/include)
target_link_libraries(fdf_linux /usr/local/lib/libmlx.a)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -framework OpenGL -framework AppKit")