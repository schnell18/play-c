cmake_minimum_required (VERSION 2.6)

add_executable(MakeTable MakeTable.cxx)

# add cmomand to generate the source code
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
    COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
    DEPENDS MakeTable
)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

# add library
add_library(MathFunctions mysqrt.cxx ${CMAKE_CURRENT_BINARY_DIR}/Table.h)

install(TARGETS MathFunctions DESTINATION lib)
install(FILES MathFunctions.h DESTINATION include)
