cmake_minimum_required(VERSION 3.21)
project(libprg C)

set(CMAKE_C_STANDARD 17)

set(HEADERS
        "${CMAKE_CURRENT_LIST_DIR}/src/include/libprg/libprg.h"
)

set(SOURCES
        src/libprg/pilha.c
        src/libprg/fila.c
        src/libprg/lista_linear.c
        src/libprg/lista_encadeada.c
        src/libprg/lista_encadeada_dupla.c
)

# cria a biblioteca
add_library(libprg ${SOURCES}
        src/libprg/ordena.c)
target_include_directories(libprg PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src/include)
target_compile_features(libprg PUBLIC c_std_17)

# cria um executável só pra testar
add_executable(teste_libprg src/libprg/main.c)
target_link_libraries(teste_libprg PRIVATE libprg)

install(TARGETS libprg DESTINATION lib)
install(FILES ${HEADERS} DESTINATION include/libprg)