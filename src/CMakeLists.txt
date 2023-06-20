add_library(http_parser STATIC IMPORTED)
set_target_properties(http_parser PROPERTIES IMPORTED_LOCATION /usr/lib/x86_64-linux-gnu/libhttp_parser.a)

add_library(logger logger.cpp)

add_library(relay-core relay.cpp env.cpp)
target_link_libraries(relay-core logger http_parser fmt::fmt)

add_executable(relay relay.cpp)
target_link_libraries(relay relay-core)

install(TARGETS relay DESTINATION bin)
