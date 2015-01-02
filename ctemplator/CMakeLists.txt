add_subdirectory(compiler)
add_subdirectory(nodes)

add_library(ctemplator
    Engine.cpp
    FileStorage.cpp
    Path.cpp
)

target_link_libraries(ctemplator
    ctemplator-compiler
    ctemplator-nodes
)
