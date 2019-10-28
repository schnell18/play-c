cmake_minimum_required (VERSION 2.6)
project (aes)
# The version number
set (AES_VERSION_MAJOR 1)
set (AES_VERSION_MINOR 0)

# should we use our own math functions
# option (USE_MYMATH "Use tutorial provided math implementation" ON)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
    "${PROJECT_SOURCE_DIR}/aesConfig.h.in"
    "${PROJECT_BINARY_DIR}/aesConfig.h"
)

# add the binary tree to the search path for include files
# so that we will find aesConfig.h
include_directories("${PROJECT_BINARY_DIR}")


# add tiny-AES-c to header search path
include_directories("${PROJECT_SOURCE_DIR}/libs/tiny-AES-c")
add_subdirectory(libs/tiny-AES-c)
set (EXTRA_LIBS ${EXTRA_LIBS} tiny-aes)

# add b64.c to header search path
include_directories("${PROJECT_SOURCE_DIR}/libs/b64.c")
set (EXTRA_LIBS ${EXTRA_LIBS} b64)
add_library(b64 libs/b64.c/encode.c libs/b64.c/decode.c)


# add the executable
add_executable(aes main.c)
target_link_libraries(aes ${EXTRA_LIBS})

install(TARGETS aes DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/aesConfig.h" DESTINATION include)
