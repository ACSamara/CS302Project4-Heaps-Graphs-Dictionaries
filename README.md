# CS 302 Project 4: Heaps, Graphs, & Dictionaries

This project contains templated implementations of a max heap, a weighted/undirected graph, and a dictionary with string keys.
Additional classes and data files are included as example usages.

## How to Run

Run `make` from the terminal to compile the program.
Run `./project4` to run the executable.

## Data Structure Classes

### Heap

Data structure to store information from largest to smallest. Requires its passed data type to have the `<` operator.
Data can only be extracted from the top of the heap (the largest item).

In the example usage, the heap stores maintenance jobs sorted by their priority.
Every time the user extracts a job from the heap, they will get the job with the highest priority first.

### Graph

Data structure to store a set of vertices connected by edges. Each edge has a corresponding weight, but not a direction.
Uses an adjacency matrix to represent the edges of the graph. Duplicates are not permitted.

In the example usage, vertices represent campus buildings and edges represent the paths between them. 
The printShortestPath() function can be used to display the most efficient path between two buildings.

### Dictionary

Data structure to store a set of keys and values. Keys must be strings, but values can be any data type.
The data type must have an `==` operator that checks if the key associated with the value is the same as some string. 
This implementation utilizes string hashing to store values for quick retrieval and a hash table of linked lists to resolve collisions. 

The `TABLE_SIZE` of the dictionary can be changed to any prime number. Increasing the size will reduce the number of collisions in larger dictionaries.
There at least 6 entries in the example Dictionary, so `TABLE_SIZE` is set to 5 to demonstrate collision resolution.

Allows string indexing:
`exampleDictionary["exampleKey"]` returns the value associated with `"exampleKey"`.

In the example usage, the Dictionary stores Buildings by name.

## Example Usage Classes

### Building

Stores information about campus buildings. Each Building has a name, code, type, and description.
Used to demonstrate usage of the Dictionary class.

### Job

Stores information about maintenance jobs. Each Job has an ID, priority level, and description.
Used to demonstrate usage of the Heap class.

## Additional Helper Classes

The majority of these classes were reused from Project 2: Lists, Stacks, and Queues.

### ArrayList

Data structure to store lists of data as an array of dynamic size. Used to store GraphNode objects in certain Graph operations.

### ArrayQueue

Data structure to store a queue (first in, first out) as an array of dynamic size. Used for graph traversal algorithms.

### GraphNode

Contains information for easy storage in the Graph class. Its main purpose is to keep track of vertex visitation during graph traversal.

### LinkedList

Data structure to store lists of data as a series of linked nodes. Used to manage collisions in a Dictionary.

### ListNode

Contains information for easy storage in the LinkedList class. Holds the value of each item in the list and a pointer to the next item.

## Driver

### main.cpp

Contains the main function of the program. 
Loads information from files into the corresponding data structures.
Then, displays a menu that allows the user to choose which data structure to test.

1. Look up a building

    Allows the user to enter the name of a building. 
Looks the building up in the Dictionary and displays its information.

2. Add / remove a building

    Allows the user to enter the name of a building.
If the building is already in the Dictionary, allows the user to choose whether to remove it. Otherwise, allows the user to enter the rest of the information about the building and adds it to the Dictionary.

3. View campus map

    Displays the entire Graph using both breadth-first search and depth-first search traversals.

4. Find shortest path between two buildings

    Allows the user to enter the codes of two buildings.
    Then, displays the length and steps of the shortest path between them in the Graph.

5. Add a maintenance job

    Allows the user to enter information about a Job, then adds it to the Heap.

6. Process next maintenance job

    Extracts the highest-priority Job from the Heap and displays its information.

7. Exit

    Exit the program.
    
After the chosen action is completed, allows the user to choose whether to continue testing or exit the program.

### helpers.cpp

Contains helper functions to perform file I/O and terminal output in the main function.