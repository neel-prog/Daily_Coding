\# Two Sum Using Custom Hash Table in C++



\## Overview



This project implements the \*\*Two Sum\*\* problem without using STL containers such as `unordered\_map` or `map`. Instead, it uses a \*\*custom hash table\*\* implemented with \*\*linked lists (Separate Chaining)\*\* for collision handling.



The program stores each array element and its index in a hash table, allowing it to find the required pair in \*\*O(n)\*\* average time complexity.



\---



\# Problem Statement



Given an array of integers and a target value, find the \*\*indices\*\* of two numbers whose sum is equal to the target.



\### Example



\*\*Input\*\*



```

Array: 2 7 11 15 3

Target: 9

```



\*\*Output\*\*



```

Indices are: 0 1

Values are: 2 7

```



\---



\# Features



\* Custom Hash Table implementation

\* Collision handling using Separate Chaining (Linked List)

\* Handles negative numbers in the hash function

\* Stores both value and index

\* Average Time Complexity: \*\*O(n)\*\*

\* Space Complexity: \*\*O(n)\*\*



\---



\# Data Structure Used



\## Node Structure



Each node stores:



\* Integer value

\* Original index

\* Pointer to the next node



```

+-------+-------+-------+

| Value | Index | Next  |

+-------+-------+-------+

```



\---



\# Hash Function



```

Hash(key) = abs(key) % 10007

```



\* Converts negative numbers into positive.

\* Maps every value to one of the available buckets.



\---



\# Functions



\## 1. hash(int key)



Calculates the bucket index for a given key.



\*\*Parameters\*\*



\* key → Integer value



\*\*Returns\*\*



\* Bucket index



\---



\## 2. insert(Node\* hashmap\[], int value, int index)



Inserts a new node at the beginning of the linked list of the corresponding bucket.



\*\*Parameters\*\*



\* hashmap → Hash table

\* value → Array element

\* index → Original index



\---



\## 3. search(Node\* hashmap\[], int value)



Searches for a value in the corresponding bucket.



\*\*Parameters\*\*



\* hashmap → Hash table

\* value → Value to search



\*\*Returns\*\*



\* Pointer to the node if found

\* `nullptr` if not found



\---



\# Algorithm



1\. Read the input array.

2\. Read the target value.

3\. Create an empty hash table.

4\. Traverse the array.

5\. Compute the required complement:



```

need = target - nums\[i]

```



6\. Search the hash table for the complement.

7\. If found:



&#x20;  \* Return the stored index.

&#x20;  \* Return the current index.

8\. Otherwise, insert the current value and index into the hash table.

9\. Continue until a pair is found or the array ends.



\---



\# Collision Handling



This implementation uses \*\*Separate Chaining\*\*.



Example:



```

Bucket 5



Before



10 -> 20 -> NULL



Insert 30



30 -> 10 -> 20 -> NULL

```



Each bucket contains a linked list of nodes that share the same hash value.



\---



\# Time Complexity



| Operation           | Complexity |

| ------------------- | ---------- |

| Hash Calculation    | O(1)       |

| Insert              | O(1)       |

| Search (Average)    | O(1)       |

| Search (Worst Case) | O(n)       |

| Overall Two Sum     | O(n)       |



\---



\# Space Complexity



```

O(n)

```



The hash table stores one node for each element in the array.



\---



\# Project Structure



```

TwoSum.cpp

│

├── class TwoSum

│   ├── Node Structure

│   ├── hash()

│   ├── search()

│   └── insert()

│

└── main()

&#x20;   ├── Read input

&#x20;   ├── Create Hash Table

&#x20;   ├── Find complement

&#x20;   ├── Store values

&#x20;   └── Display result

```



\---



\# Sample Input



```

Enter the input array:

2 7 11 15 3



Enter the target value:

9

```



\---



\# Sample Output



```

Indices are: 0 1

Values are: 2 7

```



\---



\# Concepts Demonstrated



\* C++ Classes

\* Structures

\* Dynamic Memory Allocation (`new`)

\* Linked Lists

\* Hash Tables

\* Collision Resolution

\* Pointers

\* Time Complexity Optimization

\* Searching Algorithms



\---



\# Future Improvements



\* Accept arrays of dynamic size.

\* Free allocated memory to prevent memory leaks.

\* Implement deletion from the hash table.

\* Convert the implementation into a reusable hash table class.

\* Compare performance with `std::unordered\_map`.

\* Add support for multiple test cases.



\---



\# Author



\*\*Neel Kiran Sankpal\*\*



\*\*Language:\*\* C++



\*\*Algorithm:\*\* Hash Table with Separate Chaining



\*\*Purpose:\*\* Educational implementation of the Two Sum problem without using the C++ STL hash map.



