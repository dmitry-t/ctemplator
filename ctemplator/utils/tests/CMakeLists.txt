add_executable(ctemplator-utils-tests
    LRUCacheTests.cpp
    main.cpp
)

target_link_libraries(ctemplator-utils-tests
    ctemplator
    gtest
    pthread
)
