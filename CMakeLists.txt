cmake_minimum_required(VERSION 3.16)

project(tiny-shell VERSION 1.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SRC_FILES   src/main.c
                src/dalloc.c
                src/interrupt.c
                src/dinput.c
                src/process.c
            )

add_executable(tiny-shell ${SRC_FILES}) 

target_include_directories(
    tiny-shell PUBLIC
    "${PROJECT_BINARY_DIR}/include"
    "${PROJECT_SOURCE_DIR}/include"

    "${PROJECT_BINARY_DIR}/include/structure"
    "${PROJECT_SOURCE_DIR}/include/structure"

    "${PROJECT_BINARY_DIR}/include/handler"
    "${PROJECT_SOURCE_DIR}/include/handler"

    "${PROJECT_BINARY_DIR}/include/io"
    "${PROJECT_SOURCE_DIR}/include/io"
)

configure_file(
    include/config.h.in
    include/config.h
    @ONLY
)
