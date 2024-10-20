cmake_minimum_required(VERSION 3.10)

project(projet C)

set(SOURCES
    main.c
    board.c
    board.h
    cell.c
    cell.h
)

add_executable(Projet_exe ${SOURCES})
