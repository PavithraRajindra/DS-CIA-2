# Self Organising List using Move-To-Front method using Doubly Linked List

## 1. Efficiency:
   - MTF offers constant-time access, insertion, and deletion operations, ensuring efficient performance.
   - DLL provides efficient traversal and pointer manipulation, supporting MTF reorganization operations with a time complexity of O(n).

## 2. Temporal Locality:
   - MTF leverages temporal locality by prioritizing recently accessed elements, leading to improved average access time.
   - Doubly Linked List allows for easy adjustment of pointers to move elements to the front, facilitating MTF reorganization without significant overhead.

## 3. Simplicity:
   - MTF is straightforward to implement and understand, with minimal overhead compared to more complex methods like Count.
   - Doubly Linked List offers simplicity in insertion, deletion, and traversal, making it well-suited for MTF implementation without sacrificing efficiency.

## 4. Comparison with other methods:
   - Transpose and Count methods, while offering some benefits, may not provide as significant improvements in average access time as MTF.
   - Doubly Linked List outperforms other data structures like Binary Search Trees, Queues, or Stacks in supporting MTF reorganization efficiently.

## 5. Conclusion:
  - With its balance of efficiency, simplicity, and effectiveness in leveraging temporal locality, the Move-to-Front method using a Doubly Linked List emerges as the optimal choice for implementing a self-organizing list.

Therefore the Doubly Linked List with the Move-to-Front method remains the best-suited approach for efficiently maintaining access patterns and optimizing average access time in a wide range of scenarios.


## Algorithm 1: Insertion of an element into the SOL
**Input:** head, num: The integer value to be inserted into the linked list.

**Output:** true (if the insertion is successful) / false (if memory allocation fails).

    1. Create a new node initialize the new node.
    2. newnode->data <- num
    3. newnode->next <- nullptr 
    4. if head is nullptr (the list is empty)
        a. newnode->prev <- nullptr
        b. head <- newnode
        c. tail <- newnode
        d. return true
    5. otherwise (insert at the end of non-empty list):
        a. newnode->prev <- tail
        b. tail->next <- newnode
        c. tail <- newnode
        d. return true

## Algorithm 2: Deletion of an element into the SOL
**Input:** head, num: The integer value to be deleted from the linked list.

**Output:** true (if the deletion is successful) / false (if the element is not found in the list or the list is empty).

    1. Initialize a temporary node temp <- head
    2. Repeat until temp is not nullptr
        a. if temp->data is num
            i. if temp is head
                1. head <- head->next
                2. if head is not nullptr
                    a. head->prev <- nullptr
                3. otherwise
                    a. tail is nullptr
            ii.  else if temp is tail
                1. tail is tail->prev
                2. if tail is not nullptr
                    a. tail->next <- nullptr
                3. else
                    a. head <- nullptr
            iii. else
                1. temp->prev->next <- temp->next
                2. temp->next->prev <- temp->prev
            iv. free temp
            v. return true
        b. temp <- temp->next

    3. otherwise
        a. return false

## Algorithm 3: MTF (Move To Front) – move an element to the front
**Input**: head, temp: A pointer to the node that needs to be moved to the front of the linked list.

**Output:** The linked list is modified such that the node originally pointed to by temp becomes the new head node.

    1. if temp is head
        a. return 
    2. otherwise if temp is tail
        a. tail <- temp->prev
        b. tail->next <- nullptr
    3. otherwise
        a. temp->next->prev <- temp->prev
    4. temp->prev->next <- temp->next
    5. temp->prev <- nullptr
    6. head->prev <- temp
    7. temp->next <- head
    8. head <- temp
 
## Algorithm 4: Access an element in the SOL
**Input:** head, num: The integer value to be searched for in the linked list.

**Output:** true (if the element with the value num is found in the list) / false (if the element is not found in the list).
 
    1. Initialize a pointer variable target <- head
    2. Repeat until target is not nullptr
        a.  if target->data is num
            i. call function movetofront(target)
            ii. return true
        b.  target <- target->next
    3. otherwise
        a.  return false

## Algorithm 5: Display elements of the SOL
**Input:** head

**Output:** Prints the contents of the self-organizing list to the console. If the list is empty, an appropriate message is displayed.

    1. Initialize a temporary node temp <- head
    2. if head is nullptr
        a. display ‘The list is empty’
    3. otherwise
        a. display ‘Contents of the self organizing list:’
        b. repeat until temp is not nullptr
            i. display temp->data
            ii. temp <- temp->next


## FUNCTIONAL REQUIREMENTS:
    1. insertion()
    2. deletion()
    3. movetofront()
    4. access()
    5. display()


## TIME COMPLEXITY ANALYSIS FOR EACH ALGORITHM:

### 1. insertion() – O(1) (Constant Time)

f(n) = 5(newnode creation and initialization )+4 (insertion when list is empty)+4(insertion when list is non-empty)
f(n) =9 
g(n) = 1 and c = 10

n
Cost of f(n)
Cost of c.g(n)
0
9
0
1
9
10

Therefore n0 = 0 for which f(n) <= c.g(n) is true for all n0 < n .   
Therefore f(n) = O(n)

**Analysis summary:**

• Best Case: O(1) (Constant Time)
    
• Average Case: O(1) (Constant Time)
    
• Worst Case: O(1) (Constant Time)

**Explanation:**

The provided insertion method specifically inserts new nodes at the end of the linked list. This characteristic leads to constant time complexity in all cases:

• Best Case (O(1)): Even if the list is empty (head == nullptr), only a few constant time operations are needed to set the new node as both head and tail.
    
• Average Case (O(1)): Regardless of the initial list state (empty or non-empty), inserting at the end always involves a fixed number of pointer updates, making the average time complexity constant.
    
• Worst Case (O(1)): The worst case scenario, where the list might be very large, doesn't affect the time complexity. Since we're only manipulating pointers at the end of the list for insertion, the number of operations remains constant, resulting in O(1) complexity.

### 2. deletion()– O(n)

	f(n) = 1(initialization of temp pointer)+(12n+1)(traversal and deletion)+1(return value)
	f(n) = 12n+3
	g(n) = n and c = 13

n
Cost of f(n)
Cost of c.g(n)
0
3
0
1
15
13
2
27
26
3
39
39
4
51
52

Therefore n0 = 3 for which f(n) <= c.g(n) is true for all n0 < n .                    
Therefore f(n) = O(n)

**Analysis summary:**

• Best Case: O(1) (Constant Time)
    
• Average Case: O(n) (Linear Time)
    
• Worst Case: O(n) (Linear Time)

**Explanation:**

The time complexity of the deletion method depends on how long it takes to find the target element in the list.

• Best Case (O(1)): This occurs when the target element is at the head of the list. In this case, the first iteration of the loop finds the element, and the deletion process involving pointer updates and memory deallocation takes constant time.
    
• Average Case (O(n)): On average, the element might be located somewhere in the middle of the list. The loop needs to iterate potentially through all n elements in the worst case to reach the target. The average number of iterations might be less than n but still proportional to the list size.
    
• Worst Case (O(n)): The worst case scenario happens when the target element is at the end of the list or isn't present in the list at all. The loop iterates through the entire list (n elements) before exiting without finding a match.

### 3. movetofront()– O(1) (Constant Time)

	f(n) = 4(constant time checks)+5(pointer updates)
	f(n) = 9
	g(n) = 1 and c = 10

n
Cost of f(n)
Cost of c.g(n)
0
9
0
1
9
10

Therefore n0 = 0 for which f(n) <= c.g(n) is true for all n0 < n .                    Therefore f(n) = O(1)

**Analysis summary:**

◦ Best Case: O(1) (Constant Time)
	
◦ Average Case: O(1) (Constant Time)
	
◦ Worst Case: O(1) (Constant Time)
 
**Explanation:**

◦ Best Case (O(1)): This occurs when temp is already the head of the list. In this case, the first check (temp == head) leads to an immediate return, requiring only a constant time comparison.
	
◦ Average Case (O(1)): Even for a non-special case (where temp is not the head or tail), the pointer updates and assignments are all constant time operations. The average time complexity remains constant because the method performs the same set of operations irrespective of the initial position of temp within the list.
	
◦ Worst Case (O(1)): The worst case also results in constant time complexity. Regardless of the list's size or temp's position, the method involves a fixed number of pointer manipulations and assignments, leading to O(1) complexity.

### 4. access()– O(n)

	f(n) = 1(initialization of search pointer)+ (4n+1)(search loop and MTF function)+1(return value)
	f(n) = 4n+3
	g(n) = n and c = 5

n
Cost of f(n)
Cost of c.g(n)
0
3
0
1
7
5
2
11
10
3
15
15
4
19
20

Therefore n0 = 3 for which f(n) <= c.g(n) is true for all n0 < n .                    Therefore f(n) = O(n)

**Analysis summary:**

◦ Best Case: O(1) (Constant Time)
	
◦ Average Case: O(n) (Linear Time)
	
◦ Worst Case: O(n) (Linear Time)

**Explanation:**

◦ Best Case (O(1)): This occurs when the target element is at the head of the list. In this case, the first iteration of the loop finds the element, and the subsequent call to movetofront has constant time complexity (as analyzed previously). The overall time complexity becomes constant (O(1)).
	
◦ Average Case (O(n)): On average, the element might be located somewhere in the middle of the list. The loop needs to iterate potentially through all n elements in the worst case to reach the target. The average number of iterations might be less than n but still proportional to the list size, leading to an average time complexity of O(n).
	
◦ Worst Case (O(n)): The worst case scenario happens when the target element is at the end of the list or isn't present in the list at all. The loop iterates through the entire list (n elements) before exiting without finding a match. The additional call to movetofront (which is O(1)) doesn't affect the dominant factor, which is the search loop.

### 5. display()– O(n)

	f(n) = 1(initializing temp pointer)+1(list is empty)+(3n+2)(traversal and display)
	f(n) = 3n+4
	g(n) = n and c = 4


n
Cost of f(n)
Cost of c.g(n)

0
4
0

1
7
4

2
10
8

3
13
12

4
16
16
5
19
20
Therefore n0 = 4 for which f(n) <= c.g(n) is true for all n0 < n .                    
Therefore f(n) = O(n)

**Analysis summary:**

• Best Case: O(n) (Linear Time)
    
• Average Case: O(n) (Linear Time)
    
• Worst Case: O(n) (Linear Time)

**Explanation:**

◦ Best Case (O(n)): Even if the list has only one element (head), the loop needs to iterate once to print that element's data. This results in linear time complexity (O(n)).
        
◦ Average Case (O(n)): There's no scenario where the loop iterates less than the number of elements (n) in the list. On average, the loop iterates through all elements, leading to O(n) complexity.
        
◦ Worst Case (O(n)): The worst case also exhibits linear time complexity. Regardless of the data arrangement in the SOL (random, sorted, etc.), the loop needs to visit all elements once to print their data, resulting in O(n) complexity.

## APPLICATIONS:

### Some common applications of SOLs:

**1. Cache Management:**

 In computer systems, caches store frequently accessed data from main memory to improve retrieval speed. SOLs can be employed in cache management to prioritize data items that are accessed more often. By moving recently accessed data to the front of the list, subsequent retrievals become faster.
    
**2. Recently Used Items (RUIs) Lists:**

 Many applications maintain lists of recently used items (RUIs) to provide users with quick access to previously interacted-with elements. SOLs can be used for these RUI lists, ensuring that the most recently used items are at the beginning for faster retrieval. This can be seen in features like recently opened files or browsing history.

**3. Branch Prediction in Processors:**

 Modern processors employ branch prediction to speculate on which branch (true or false) of a conditional statement is more likely to be taken. SOLs can be used to store branch history information, with frequently taken branches positioned closer to the front for faster prediction decisions.

**4. Network Routing:**

 In networking scenarios, routers maintain routing tables to determine the best path for data packets. SOLs can be used in these routing tables to prioritize frequently used routes, potentially improving network performance.
    
**5. Database Query Optimization:**

 Database systems can benefit from SOLs to optimize query execution. By keeping frequently accessed data structures or query patterns at the forefront of an SOL, subsequent queries referencing that data might experience faster execution times.
    
**6. Spell Checkers and Autocomplete:**

 Spell checkers and autocomplete features rely on maintaining a dictionary of words. SOLs can be used for these dictionaries, keeping frequently misspelled words or user-typed prefixes closer to the beginning for faster suggestion retrieval.
    
**7. Intrusion Detection Systems (IDS):**

 IDS monitor network traffic for suspicious activity. SOLs can be used to store patterns of known attacks or suspicious IP addresses. By prioritizing recently encountered patterns, the IDS might be able to identify potential threats more efficiently.
    
**8. Web Server Request Logging:**

 Web servers often log access requests. SOLs can be used to maintain these logs, keeping recently accessed pages or user information closer to the front for faster retrieval during analysis or troubleshooting.


