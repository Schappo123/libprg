cmake_minimum_required(VERSION 3.21)

set(HEADERS
        "${CMAKE_CURRENT_LIST_DIR}/src/include/libprg/libprg.h"
        src/libprg/pilha.c
        src/libprg/fila.c
        src/libprg/lista_linear.c
        src/libprg/lista_encadeada.c
        src/libprg/lista_encadeada_dupla.c
        src/libprg/main.c
)

set(SOURCES
        src/libprg/pilha.c
        src/libprg/fila.c
        src/libprg/lista_linear.c
        src/libprg/lista_encadeada.c
        src/libprg/lista_encadeada_dupla.c
        src/libprg/main.c
)

add_library(libprg ${SOURCES} ${HEADERS}
        src/libprg/fila.c
        src/libprg/lista_linear.c
        src/libprg/lista_encadeada.c
        src/libprg/lista_encadeada_dupla.c
        src/libprg/main.c)

target_include_directories(libprg PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/src/include
)

target_compile_features(libprg PUBLIC c_std_17)

install(TARGETS libprg DESTINATION lib)
install(FILES ${HEADERS} DESTINATION include/libprg)