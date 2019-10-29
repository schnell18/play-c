cmake_minimum_required(VERSION 2.8)
project (HELLOLIB)

add_subdirectory(src lib)
install(FILES COPYRIGHT README DESTINATION share/doc/cmake-hello/t3)
install(DIRECTORY doc/ DESTINATION share/doc/cmake-hello/t3)
