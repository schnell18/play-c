set(SRC_LIST hello.c)
add_library(hello SHARED ${SRC_LIST})
add_library(hellostatic STATIC ${SRC_LIST})
set_target_properties(hellostatic PROPERTIES OUTPUT_NAME "hello")
set_target_properties(hellostatic PROPERTIES CLEAN_DIRECT_OUTPUT 1)
set_target_properties(hello PROPERTIES CLEAN_DIRECT_OUTPUT 1)
set_target_properties(hello PROPERTIES VERSION 1.2 SOVERSION 1)
install(
    TARGETS hello hellostatic
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)
install(FILES hello.h DESTINATION include/hello)
