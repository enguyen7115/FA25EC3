- A dated entry every time you work on the assignment
- A description of what you worked on
- Any bugs, issues, or problems you encountered
- How you attempted to solve each issue
- A brief explanation of every commit you make
- A list of all files modified during each commit

# Developer Log

## Journal Entry 1: 12/4/2025

- Didn't notice that a Developer Log is needed until now so I will summarize everything I have done so far and some errors that I remember.
- Created a createRoot() method. Had a small error where it gave me an error for creating a newNode. Realized I didn't need to make a new node and just had to set the root's id and data, thus did that instead of creating a new node
- Created an addNode() method. Like the TODO said, I found parent. If no parent, give error. Then I checked if there was already a child with the ID, if there wasn't we created a child and then we added it to the parents children.
- Created findNode(). Did this just yesterday, 12/3/2025. Implemented BFS for finding a node using a queue and a visited vector. Not sure if it will work or not yet, will have to see.
- Worked on a printAll() method today. Implemented it similar to how PA3 was created with the DFS. Trying to use recursion and a visited check so we don't have to double check.
### Commit History
- Commit Started tree.h - Started working on tree.h. Created addNode() and createRoot(), supposedly. A few errors with addRoot() but I fixed that in future commit.
- Commit BFS Traversal - Implemented BFS search into method findNode() in tree.h.
- Commit Started DFS for printAll() + Dev Log - Started DFS search in order to print entire structure.

### Files Modified

- Tree.h Commit - tree.h
- BFS Traversal Commit - tree.h
- DFS commit - tree.h

## Journal Entry 2: 