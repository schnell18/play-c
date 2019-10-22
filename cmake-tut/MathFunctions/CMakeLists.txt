cmake_minimum_required (VERSION 2.6)

# add library
add_library(MathFunctions mysqrt.cxx)

install(TARGETS MathFunctions DESTINATION lib)
install(FILES MathFunctions.h DESTINATION include)
