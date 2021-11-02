#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <locale>
#include <queue>

#ifndef NODE_H_
#define NODE_H_

using namespace std;

enum COLOR {RED, BLACK};

class node { 
public:
    int key; 
    COLOR color;
    node *left, *right, *parent; 

    node(int key) : key(key) { 
        parent = left = right = nullptr; 
    
        color = RED;
    }

    node * uncle() { 
        if (parent == nullptr || parent->parent == nullptr) 
            return nullptr; 
    
        if (parent -> isOnLeft()) 
            return parent -> parent -> right; 
        else
            return parent -> parent -> left; 
    }

    bool isOnLeft() { 
        return this == parent -> left; 
    }

    node *sibling() { 
        if (parent == nullptr) 
            return nullptr; 
    
        if (isOnLeft()) 
            return parent -> right; 
    
        return parent -> left; 
    } 
  
  
    void moveDown(node *nParent) { 
        if (parent != nullptr) { 
            if (isOnLeft()) { 
                parent -> left = nParent; 
            } else { 
                parent -> right = nParent; 
            } 
        } 
        nParent -> parent = parent; 
        parent = nParent; 
    } 
  
    bool hasRedChild() { 
        return ((left != nullptr) && (left -> color == RED)) || ((right != nullptr) && (right -> color == RED)); 
    } 
};

#endif
