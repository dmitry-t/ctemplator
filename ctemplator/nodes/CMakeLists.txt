add_library(ctemplator-nodes
    Node.cpp
    ListNode.cpp
    LeafNode.cpp
    TextNode.cpp
    ExprNode.cpp
    EmptyNode.cpp
)

target_link_libraries(ctemplator-nodes
    ctemplator-vars
)
