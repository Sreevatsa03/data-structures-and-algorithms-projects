#include "Node.h"

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

class LinkedList {
private:
    Node *head;
public:
    LinkedList();
    ~LinkedList();
    void printList();
    void push(char);
    char pop();
    char peek();
    char get(int index);
    bool isPalindrome(int index);
    int length();
    int lengthPalindrome();
};

#endif /* LINKEDLIST_H_ */