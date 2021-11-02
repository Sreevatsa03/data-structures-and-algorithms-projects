#include "node.h"

#ifndef RBT_H
#define RBT_H

using namespace std;

class rbt {
private:
    node *root;
protected:
    void swapColors(node*, node*);
    void swapValues(node*, node*);
public:
    rbt();
    rbt(int);
    node* getRoot();
    node* search(int);
    void insert(int);
    int minValue();
    node* minValue2(node*);
    int maxValue();
    node* maxValue2(node*);
    void print2(node*);
    void print();
    void print2D();
    void inorder2(node*);
    void printInOrder();
    void print2DUtil(const string&, const node*, bool);
    void leftRotate(node*);
    void rightRotate(node*);
    void fixRedRed(node*);
    node *successor(node*);
    node *BSTreplace(node*);
    void deleteNode(node*);
    void fixDoubleBlack(node*);
    void deleteByVal(int);

};

#endif /* RBT_H_ */
