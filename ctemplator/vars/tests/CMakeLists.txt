add_executable(ctemplator-vars-tests
    VarTests.cpp
    main.cpp
)

target_link_libraries(ctemplator-vars-tests
    ctemplator-vars
    gtest
    pthread
)
