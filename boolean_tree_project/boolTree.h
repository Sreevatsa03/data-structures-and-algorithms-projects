#include "node.h"

#ifndef BOOLTREE_H
#define BOOLTREE_H

using namespace std;

class boolTree {
private:
	bool symHelp(node *left, node *right) const;
    bool subHelp() const;
    node *root;
public:
    boolTree(string);
    string upper(string);
    string removeSpaces(string);
    bool logicEval();
    bool eval(node *root);
    node* convert(string);
    void print2(node *root) const;
    void print() const;
    void printLevelOrder2(node *root) const;
    void printLevelOrder() const;
    void print2DUtil(const string& prefix, const node* root, bool isLeft);
    void print2D2(const node *root);
    void print2D();
    int count(node *root) const;
    int maxDepth(node *root) const;
    bool isSymmetric(node *root) const;
    bool isSubTree(node *root1, node *root2) const;
};

#endif /* BOOLTREE_H_ */
