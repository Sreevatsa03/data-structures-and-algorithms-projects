#include "LinkedList.h"
#include <cstdlib>

LinkedList::LinkedList() {
    head = NULL;
}
// Constructor that initializes a new linked list

LinkedList::~LinkedList() {
    while (head != NULL) {
        Node *p = head -> next;
        free(head);
        head = p;
    }
}
// Destructor that frees the memory of the linked list

void LinkedList::push(char c) {
    Node *n = new Node;
    n -> data = c;
    n -> next = head;
    head = n;
}
// Method that adds a node to the linked list, but the new node is added to the front of the linked list and pushes the previos nodes all to the next "index"

char LinkedList::pop() {
    char c = head -> data;
    Node *p  = head;
    head = head -> next;
    free(p);
    return c;
}
// Method that removes the last node of the linked list

char LinkedList::peek() {
    return head -> data;

}
// Method that returns the item in the first node in the linked list

char LinkedList::get(int index) {
    Node *p = head;
    for (int i = 0; i < index; i++) {
        p = p -> next;
    }
    return p -> data;
}
// Method that returns the item in a certain node given the parameter as the index in the linked list where that node is located

void LinkedList::printList() { 
    while (head != NULL) { 
        printf("%c -> ", head -> data); 
        head = head -> next; 
    } 
    printf("NULL\n"); 
} 
// Method that prints out the linked list: node 1 -> node 2 -> node 3 -> etc.

int LinkedList::length() {
    int length = 0;
    if(head == NULL) {
        return length;
    }
    Node *p = head;
    while(p != NULL) {
        p = p -> next;
        length++;
    }
    return length;
}
// Method that returns the number of nodes currently in the linked list

bool LinkedList::isPalindrome(int index) { 
    bool pal = false;
    int j = index;
    if(length() - j > 3) {
        if((length() - j) % 2 == 0) {
            for(int i = 0; i < ((length() - j) / 2) - 1; i++) {
                if(get(i + j) != get(length() - i - 1)) {
                    return false;
                } else {
                    pal = true;
                }
            } 
        } else {
            for(int i = 0; i <= ((length() - j - 1) / 2) - 1; i++) {
                if(get(i + j) != get(length() - i -1)) {
                    return false;
                } else {
                    pal = true;
                }
            }
        }
    } else {
        if(length() - j == 1 || length() - j == 0) {
            return true;
        }
        if(length() - j == 2) {
            return(get(length() - 1) == get(length() - 2));
        }
        if(length() - j == 3) {
            return(get(length() - 1) == get(length() - 3));
        }
    }
    return pal;
}
// Method that takes in a parameter for an index and finds if there is a pal from the last node to the node at that index

int LinkedList::lengthPalindrome() {
    int maxSize = 0;
    for(int i = length() - 1; i >= 0; i--) {
        if(isPalindrome(i)) {
            int x = length() - i;
            if(x > maxSize) {
                maxSize = x;
            }
        }
    }
    return maxSize;
}
// Method that finds the longest pal in the linked list starting from the last node to the first using isPalindrome(int index)