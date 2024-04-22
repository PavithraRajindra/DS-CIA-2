## Disjoint Set ADT
The implementation of disjoint-set data structure using trees, particularly with the union by rank method, offers several advantages over other data structures like arrays

## Efficient Union and Find Operations 
  -In a tree-based implementation, the union operation is typically faster compared to array-based implementations. 
  -By linking smaller trees to larger ones based on their rank, the height of trees is kept low, resulting in faster find operations as well.

## Balanced Trees 
  -Union by rank ensures that the resulting trees remain balanced. 
  -Balanced trees prevent degenerate cases where the tree becomes essentially a linked list, ensuring that find operations remain efficient even in worst-case scenarios.

## Optimized Find Operation 
  -The find operation in a tree-based disjoint-set structure has a time complexity of O(log n) in the worst case, where n is the number of elements. 
   -This is because path compression is applied during the find operation, which flattens the tree structure, reducing the height of the tree.

## Memory Efficiency
  -Tree-based implementations typically require less memory compared to array-based implementations, especially when dealing with large sets of elements. 
  -This is because only the parent pointer, rank, and possibly some additional metadata are stored for each element, rather than allocating memory for an entire array.

## Scalability
  -Tree-based implementations scale well with the number of elements in the disjoint sets. 
  -Even for large sets of elements, the time complexity of union and find operations remains logarithmic, making tree-based implementations suitable for a wide range of applications.

## Flexibility 
  -Tree-based disjoint-set implementations offer flexibility in terms of the underlying data structure. 
  -Different variations, such as using path compression or weighted union, can be applied based on the specific requirements of the application.

    Overall, tree-based implementations with union by rank strike a balance between efficiency, memory usage, and scalability, making them a popular choice for implementing disjoint-set data structures in various algorithms and applications.

## Algorithm

## Algorithm: Create(Data)
    - Input: Data(integer).
    - Output: Newnode (pointer to a node).
    - Steps:
        - Allocate memory for a new node.
        - Initialize the new node->data = data value 
        - Setting its parent pointer to itself and rank = 0.
        - If capacity of the nodes array < new node->data, resize the array.
        - Set nodes[data] = newnode->data
        - Return a pointer to the new node.

## Algorithm: Find(Element)
    - Input: Data(integer).
    - Output: Pointer to the root node of the tree.
    - Steps:
        - Retrieve the node corresponding to the given element's data value from the nodes array.
        - If the node is not found, return nullptr.
        - Initialize temp = nodes[data].
        - While temp->parent is not equal to the node itself:
            - Update temp->parent to point to the root node of its parent.
            - Move to the parent node.
        - Return the pointer to the root node of the tree.

## Algorithm: Merge(Element1, Element2)
    - Input: Num1 and Num2 (integers).
    - Output: Success or Failure.
    - Steps:
        - Call Find method to find the root nodes of the elements.
        - If either of the elements is not found (i.e., Find operation returns nullptr), return False.
        - If the root nodes of both elements are the same, return False (Sets are not disjoint).
        - Otherwise, compare the ranks of the two root nodes:
            - If first_node->rank < second_node->rank, make the first root node the child of the second root node.
            - If first_node->rank > second_node->rank, make the second root node the child of the first root node.
            - If the ranks are equal, choose one root node to be the parent of the other and increment the rank of the chosen root node.
        - Return True.

