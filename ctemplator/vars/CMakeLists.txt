add_library(ctemplator-vars
    Array.cpp
    DerivedObject.cpp
    Object.cpp
    Var.cpp
)

target_link_libraries(ctemplator-vars
    
)

add_subdirectory(tests)
