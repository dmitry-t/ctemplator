add_library(ctemplator-compiler
    Tokenizer.cpp
    Token.cpp
)

target_link_libraries(ctemplator-compiler
    PocoFoundation
)
