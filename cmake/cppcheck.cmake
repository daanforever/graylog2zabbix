set(CMAKE_CXX_CPPCHECK "cppcheck")

list( APPEND CMAKE_CXX_CPPCHECK
        "-i thirdparty"
        "-i CMakeFiles"
        "-I include"
        "--enable=all"
        "--inline-suppr"
        "--suppress=*:*thirdparty*"
        "--suppress=missingIncludeSystem:*"
)
