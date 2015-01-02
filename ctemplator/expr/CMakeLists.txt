add_library(ctemplator-expr
    Expression.cpp
    VariableExpr.cpp
)

target_link_libraries(ctemplator-expr
    PocoFoundation
)
