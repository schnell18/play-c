cmake_minimum_required(VERSION 2.8)
project (CURLTEST)

add_subdirectory(src)
install(FILES COPYRIGHT README DESTINATION share/doc/cmake-hello/t4)
install(PROGRAMS runhello.sh DESTINATION bin)
install(DIRECTORY doc/ DESTINATION share/doc/cmake-hello/t4)
