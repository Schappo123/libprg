cmake_minimum_required(VERSION 3.21)

set(HEADERS
        "${CMAKE_CURRENT_LIST_DIR}/src/include/libprg/estruturas.h"
)

set(SOURCES
        "${CMAKE_CURRENT_LIST_DIR}/src/libprg/estruturas.c"
)

add_library(libprg ${SOURCES} ${HEADERS})

target_include_directories(libprg PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/src/include
)

target_compile_features(libprg PUBLIC c_std_17)

install(TARGETS libprg DESTINATION lib)
install(FILES ${HEADERS} DESTINATION include/libprg)