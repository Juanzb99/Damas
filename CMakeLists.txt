cmake_minimum_required (VERSION 3.0)

PROJECT(GAME_GL)

SET(lib_dir	${CMAKE_CURRENT_SOURCE_DIR}/lib)
SET(bin_dir     ${CMAKE_CURRENT_SOURCE_DIR}/bin)
SET(headers_dir ${CMAKE_CURRENT_SOURCE_DIR}/headers)
SET(src_dir     ${CMAKE_CURRENT_SOURCE_DIR}/src)


#local includes
INCLUDE_DIRECTORIES(${lib_dir})

#glutLibraries (must be in include folder)
LINK_DIRECTORIES(${lib_dir})


#bin output
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${bin_dir})

ADD_EXECUTABLE(boardgame 
${src_dir}/Damas.cpp
${src_dir}/Coordinador.cpp
${src_dir}/Ficha.cpp
${src_dir}/Maquina.cpp
${src_dir}/Motor.cpp
${src_dir}/Mundo.cpp
${src_dir}/Tablero.cpp
${src_dir}/Tabuleiro.cpp
)

TARGET_LINK_LIBRARIES(boardgame glut32)
