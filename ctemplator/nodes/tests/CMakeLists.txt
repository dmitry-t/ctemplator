add_executable(ctemplator-nodes-tests
    ForNodeTests.cpp
    main.cpp
)

target_link_libraries(ctemplator-nodes-tests
    ctemplator-expr
    ctemplator-nodes
    gtest
    pthread
)
