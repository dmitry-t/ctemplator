add_library(ctemplator-nodes
    IfNode.cpp
    EmptyNode.cpp
    ExprNode.cpp
    LeafNode.cpp
    ListNode.cpp
    Node.cpp
    TextNode.cpp
)

target_link_libraries(ctemplator-nodes
    ctemplator-vars
)
