add_executable(ctemplator-compiler-tests
    ParserTests.cpp
    main.cpp
)

target_link_libraries(ctemplator-compiler-tests
    ctemplator-compiler
    gtest
    pthread
)
