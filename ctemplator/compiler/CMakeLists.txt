add_library(ctemplator-compiler
    Parser.cpp
    Tokenizer.cpp
)

target_link_libraries(ctemplator-compiler
    PocoFoundation
)
