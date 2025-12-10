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
- DFS commit - tree.h, developer_log.md

## Journal Entry 2: 12/8/2025

- Forgot to set childVisited in the findNode() method. 
- Fixed createRoot() again so that we do set a newNode, instead of dereferencing nullptr.
- Implemented playGame() method to play the game.
- Noticed printing was not working, will work on later. 
- Implemented Destructor. Running at O($n^2$), so not that fastest...
- Had to search up how to check if an input is a number or not in C++...
- So far, working okay. We will have to see.

### Errors of the Day:
- A lot! Especially with all the implemented stuff. Biggest problem was 
checking if visited and child were the same node. Forgot how to check so it gave a bunch of errors.
(I named the nodes v not visited...)
- Small error, forgot to make the string into an int.

### Files Modified
- tree.h mostly. Not munch of main was modified. Did start adding nodes though... not sure how I will do that correctly yet.

### Commit History
- Initial commit of the day with broken destructor and different
fixes to createRoot and findNode. Also the implemented playGame().
- intChoice added. Not just string. Forgot to add an integer.

## Journal Entry 3: 12/9/2025

- Realized I implemented everything wrong... Will fix the playGame() and printAll()
- Fixed the printing as well to print something closer to what the README.md showed.
- Implemented printAll() into playGame() method

### Errors of the Day:
- Followed printAll() method. Recursion does not work when doing it this way, thus I removed the recursive call.
- Problem calling actual main. Something about URL rejected, port numbers, etc. Looks like the string is wrong?
  - Very annoying error. Was not exactly sure what happened with the main.cpp. 
  
### Files Modified
- tree.h - printAll() method.
- tree.h - playGame() method.
- main.cpp - Fixing the curl call.

### Commit History
- First commit included new playGame() that I think will work. 
- Second commit included fixing of the curl call... Not sure what's wrong but we will see.
- 