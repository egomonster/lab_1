cmake_minimum_required(VERSION 3.5)

project(lab_1 LANGUAGES C)

add_executable(lab_1 main.c)

install(TARGETS lab_1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
