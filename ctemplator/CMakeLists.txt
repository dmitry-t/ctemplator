add_subdirectory(compiler)

add_library(ctemplator
    Engine.cpp
    FileStorage.cpp
    Path.cpp
)

target_link_libraries(ctemplator
    ctemplator-compiler
    PocoFoundation
)
