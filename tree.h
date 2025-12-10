//
// Created by Manju Muralidharan on 11/22/25.
//

#ifndef FA25EC3_TREE_H
#define FA25EC3_TREE_H

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

/*
   TEMPLATE TREE CLASS
   Multiple parents may point to the same child.
   Students must manage storage, pointers, and dynamic allocation.

   Requirements:
   1. Templated Tree class.
   2. Nodes stored dynamically.
   3. Each node has:
      - id
      - data
      - vector of children pointers
   4. Students must prevent memory leaks.
   5. Students must create createRoot, addNode, findNode, print functions, etc.

   DO NOT IMPLEMENT ANYTHING HERE.
   Only placeholders and TODO comments.
*/


template <typename U>
class Node {
public:
    string id;
    U data;
    vector<Node<U>*> children;

    // TODO: Write constructor
    Node(const string &nodeID, const U &value) : id(nodeID), data(value) {}
};

template <typename T>
class Tree {
private:
    Node<T>* root;

public:
    Tree() : root(nullptr) {}

    // TODO: Allocate memory, assign id, assign data, set as root
    void createRoot(const string &id, const T &value) {
        if(root)
            return;

        Node<T>* newNode = new Node<T>(id, value);
        root = newNode;
    }

    // TODO: Find parent, create child, link parent to child
    // TODO: Support repeated children under multiple parents
    void addNode(const string &parentID, const string &childID, const T &value) {
        Node<T>* parent = findNode(parentID);

        if(!parent) {
            cerr << "No parent found" << endl;
            return;
        }

        Node<T>* child = findNode(childID);
        if(!child) {
            child = new Node<T>(childID, value);
        }
        parent->children.push_back(child);
    }

    // TODO: Use DFS or BFS to search tree
    Node<T>* findNode(const string &id) {
        if(!root)
            return nullptr;

        if(root->id == id)
            return root;

        queue<Node<T>*> findQueue;
        vector<Node<T>*> visited;

        findQueue.push(root);
        while(!findQueue.empty())
        {
            Node<T>* current = findQueue.front();
            findQueue.pop();

            bool alreadyVisited = false;
            for(Node<T>* v : visited)
            {
                if(v == current) {
                    alreadyVisited = true;
                    break;
                }
            }

            if(alreadyVisited)
                continue;

            visited.push_back(current);

            if(current->id == id)
                return current;

            for(Node<T>* child : current->children) {
                bool childVisited = false;

                for(Node<T>* v : visited)
                {
                    if(v == child)
                    {
                        childVisited = true;
                        break;
                    }
                }

                if(!childVisited)
                    findQueue.push(child);
            }
        }

        return nullptr;
    }

    // TODO: Print entire structure in readable form
    void printAll() {
        if(!root)
            return;

        stack<Node<T>*> stack;
        vector<Node<T>*> visited;

        stack.push(root);
        while(!stack.empty())
        {
            Node<T>* current = stack.top();
            stack.pop();

            bool alreadyVisited = false;
            for(Node<T>* v : visited)
            {
                if(v == current) {
                    alreadyVisited = true;
                    break;
                }
            }

            if(alreadyVisited)
                continue;

            visited.push_back(current);

            cout << "Node " << current->id << " : " << current->data << endl;

            for (Node<T>* child : current->children)
            {
                cout << "  Child -> " << child->id << endl;
            }

            for(Node<T>* child : current->children) {
                bool childVisited = false;

                for(Node<T>* v : visited)
                {
                    if(v == child)
                    {
                        break;
                    }
                }

                if(!childVisited)
                    stack.push(child);
            }

            cout << endl;
        }
    }

    // TODO: Students, implement a method in Tree<T> called playGame()
    // This method should:
    // 1. Start at the root node.
    // 2. Display the current node's text.
    // 3. Display numbered options for each child.
    // 4. Ask the user which path to take.
    // 5. Move to the selected child and continue until a node has no children.
    // 6. Print an ending message.
    void playGame()
    {
        if(!root)
            return;

        Node<T>* current = root;
        while(true)
        {
            printAll();

            if(current->children.empty()) {
                cout << "You have reached the end of your path! Thank you for playing" << endl;
                break;
            }

            cout << "Please choose a path you will follow!\n";
            for(int i = 0; i < current->children.size(); i++)
            {
                cout << i << ":" << current->children[i]->data << endl;
            }

            string choice;
            cin >> choice;
            int intChoice;

            try {
                intChoice = stoi(choice);
            } catch(const std::exception& e)
            {
                cout << "Input a valid number, please." << endl;
                continue;
            }

            if(intChoice >= current->children.size()) {
                cout << "Invalid choice, please enter a correct number.\n";
                continue;
            }

            current = current->children[intChoice];
        }
    }

    // TODO: Free all allocated memory
    ~Tree() {
        if(!root)
            return;

        vector<Node<T>*> visited;
        queue<Node<T>*> queue;
        queue.push(root);
        visited.push_back(root);

        while(!queue.empty())
        {
            Node<T>* current = queue.front();
            queue.pop();

            for(Node<T>* child : current->children)
            {
                for(Node<T>* v : visited)
                {
                    if(child && !(v == child))
                    {
                        visited.push_back(child);
                        queue.push(child);
                    }
                }
            }

            delete current;
        }

        root = nullptr;
    }
};

#endif //FA25EC3_TREE_H
