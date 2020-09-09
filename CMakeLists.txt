cmake_minimum_required(VERSION 3.16)
project(fdf C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(includes)
include_directories(libft)
include_directories(minilibx)
include_directories(srcs)

add_executable(fdf
        includes/color.h
        includes/fdf.h
        includes/keysmac.h
        includes/quaterni.h
        srcs/bresenham.c
        srcs/checks.c
        srcs/clean.c
        srcs/cntrl.c
        srcs/draw.c
        srcs/fdf_init.c
        srcs/keymlx.c
        srcs/keys.c
        srcs/main.c
        srcs/menu.c
        srcs/quaterni.c
        srcs/read.c)
target_link_libraries(fdf
        /Users/blavonne/fdf/minilibx/libmlx.a
        "-framework OpenGL"
        "-framework AppKit"
        /Users/blavonne/fdf/libft/libft.a)