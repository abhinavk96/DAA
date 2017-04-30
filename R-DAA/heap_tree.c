sHeapUtil function is written considering following things –

    Every Node can have 2 children, 0 child (last level nodes) or 1 child (there can be at most one such node).
    If Node has No child then it’s a leaf node and return true (Base case)
    If Node has one child (it must be left child because it is a complete tree) then we need to compare this node with its single child only.
    If Node has both child then check heap property at Node at recur for both subtrees.
    Complete code.

