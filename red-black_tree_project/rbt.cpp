#include "rbt.h"

using namespace std;

rbt::rbt() {
    root = nullptr;
}

rbt::rbt(int k) {
    node* head = new node(k);
    root = head;
}

node* rbt::getRoot() {
    return root;
}

node* rbt::search(int n) {
    node *temp = root; 
    while (temp != nullptr) { 
        if (n < temp->key) { 
            if (temp->left == nullptr) 
                break; 
            else
                temp = temp->left; 
        } else if (n == temp->key) { 
            break; 
        } else { 
            if (temp->right == nullptr) 
                break; 
            else
                temp = temp->right; 
        } 
    } 
  
    return temp; 
} 

int rbt::minValue() {
    return minValue2(root) -> key;
}

node* rbt::minValue2(node* root) { 
    node* current = root; 
  
    while (current -> left) 
        current = current -> left; 
  
    return current; 
}

int rbt::maxValue() {
    return maxValue2(root) -> key;
}

node* rbt::maxValue2(node* root) { 
    node* current = root; 
  
    while (current -> right) 
        current = current -> right; 
  
    return current; 
}

void rbt::print2(node* r) { 
    if (r == nullptr) 
        return; 
  
    queue<node *> q; 
    node *curr; 
  
    q.push(r); 
  
    while (!q.empty()) { 
        curr = q.front(); 
        q.pop(); 

        cout << curr->key << " "; 

        if (curr->left != nullptr) 
            q.push(curr->left); 
        if (curr->right != nullptr) 
            q.push(curr->right); 
    } 
} 

void rbt::print() {
    cout << "Level order: " << endl; 
    if (root == nullptr) 
        cout << "Tree is empty" << endl; 
    else
        print2(root); 
    cout << endl;   
}

void rbt::inorder2(node *r) { 
    if (r == NULL) 
        return; 
    inorder2(r->left); 
    cout << r->key << " "; 
    inorder2(r->right); 
}

void rbt::printInOrder() { 
    cout << "Inorder: " << endl; 
    if (root == NULL) 
        cout << "Tree is empty" << endl; 
    else
        inorder2(root); 
    cout << endl; 
}

void rbt::print2DUtil(const string& prefix, const node* root, bool isLeft) {  
    if(root != nullptr )
    {
        cout << prefix;

        cout << (isLeft ? "├──" : "└──" );

        cout << root -> key << endl;

        print2DUtil(prefix + (isLeft ? "│   " : "    "), root -> right, true);
        print2DUtil(prefix + (isLeft ? "│   " : "    "), root -> left, false);
    } 
}  
  
void rbt::print2D() {   
    print2DUtil("", root, false); 
}

void rbt::leftRotate(node *x) { 
    node *nParent = x->right; 
  
    if (x == root) 
      root = nParent; 
  
    x->moveDown(nParent); 

    x->right = nParent->left; 
    if (nParent->left != nullptr) 
        nParent->left->parent = x; 

        nParent->left = x; 
    } 

void rbt::rightRotate(node *x) { 
    node *nParent = x->left; 

    if (x == root) 
        root = nParent; 

    x->moveDown(nParent); 

    x->left = nParent->right; 
    if (nParent->right != nullptr) 
        nParent->right->parent = x; 

    nParent->right = x; 
} 

void rbt::swapColors(node *x1, node *x2) { 
    COLOR temp; 
    temp = x1->color; 
    x1->color = x2->color; 
    x2->color = temp; 
} 

void rbt::swapValues(node *u, node *v) { 
    int temp; 
    temp = u->key; 
    u->key = v->key; 
    v->key = temp; 
} 
 
void rbt::fixRedRed(node *x) { 
    if (x == root) { 
        x->color = BLACK; 
        return; 
    } 

    node *parent = x->parent, *grandparent = parent->parent, *uncle = x->uncle(); 

    if (parent->color != BLACK) { 
        if (uncle != nullptr && uncle->color == RED) { 
            parent->color = BLACK; 
            uncle->color = BLACK; 
            grandparent->color = RED; 
            fixRedRed(grandparent); 
        } else { 
            if (parent->isOnLeft()) { 
                if (x->isOnLeft()) {  
                    swapColors(parent, grandparent); 
                } else { 
                    leftRotate(parent); 
                    swapColors(x, grandparent); 
                } 
                rightRotate(grandparent); 
            } else { 
                if (x->isOnLeft()) { 
                    rightRotate(parent); 
                    swapColors(x, grandparent); 
                } else { 
                    swapColors(parent, grandparent); 
                } 
                leftRotate(grandparent); 
            } 
        } 
    } 
} 

node* rbt::successor(node *x) { 
    node *temp = x; 

    while (temp->left != nullptr) 
        temp = temp->left; 

    return temp; 
} 

node* rbt::BSTreplace(node *x) { 
    if (x->left != nullptr && x->right != nullptr) 
        return successor(x->right); 

    if (x->left == nullptr && x->right == nullptr) 
        return nullptr; 

    if (x->left != nullptr) 
        return x->left; 
    else
        return x->right; 
} 

void rbt::deleteNode(node *v) { 
    node *u = BSTreplace(v); 

    bool uvBlack = ((u == nullptr || u->color == BLACK) && (v->color == BLACK)); 
    node *parent = v->parent; 

    if (u == nullptr) { 
        if (v == root) { 
            root = nullptr; 
        } else { 
            if (uvBlack) { 
                fixDoubleBlack(v); 
            } else { 
                if (v->sibling() != nullptr) 
                v->sibling()->color = RED; 
            } 

            if (v->isOnLeft()) { 
                parent->left = nullptr; 
            } else { 
                parent->right = nullptr; 
            } 
        } 
        delete v; 
        return; 
    } 

    if (v->left == nullptr || v->right == nullptr) { 
        if (v == root) { 
            v->key = u->key; 
            v->left = v->right = nullptr; 
            delete u; 
        } else { 
            if (v->isOnLeft()) { 
                parent->left = u; 
            } else { 
                parent->right = u; 
            } 
            delete v; 
            u->parent = parent; 
            if (uvBlack) { 
                fixDoubleBlack(u); 
            } else { 
                u->color = BLACK; 
            } 
        } 
        return; 
    } 
 
    swapValues(u, v); 
    deleteNode(u); 
} 

void rbt::fixDoubleBlack(node *x) { 
    if (x == root) 
        return; 

    node *sibling = x->sibling(), *parent = x->parent; 
    if (sibling == nullptr) { 
        fixDoubleBlack(parent); 
    } else { 
        if (sibling->color == RED) {  
            parent->color = RED; 
            sibling->color = BLACK; 
        if (sibling->isOnLeft()) { 
            rightRotate(parent); 
        } else { 
            leftRotate(parent); 
        } 
        fixDoubleBlack(x); 
        } else {  
            if (sibling->hasRedChild()) { 
                if (sibling->left != nullptr && sibling->left->color == RED) { 
                    if (sibling->isOnLeft()) {  
                        sibling->left->color = sibling->color; 
                        sibling->color = parent->color; 
                        rightRotate(parent); 
                    } else { 
                        sibling->left->color = parent->color; 
                        rightRotate(sibling); 
                        leftRotate(parent); 
                    } 
                } else { 
                    if (sibling->isOnLeft()) { 
                        sibling->right->color = parent->color; 
                        leftRotate(sibling); 
                        rightRotate(parent); 
                    } else { 
                        sibling->right->color = sibling->color; 
                        sibling->color = parent->color; 
                        leftRotate(parent); 
                    } 
                } 
                parent->color = BLACK; 
            } else { 
                sibling->color = RED; 
                if (parent->color == BLACK) 
                    fixDoubleBlack(parent); 
                else
                    parent->color = BLACK; 
            } 
        } 
    } 
}

void rbt::insert(int n) { 
    node *newNode = new node(n); 
    if (root == nullptr) { 
        newNode->color = BLACK; 
        root = newNode; 
    } else { 
        node *temp = search(n); 

        if (temp->key == n) { 
            return; 
        } 

        newNode->parent = temp; 

        if (n < temp->key) 
            temp->left = newNode; 
        else
            temp->right = newNode; 

        fixRedRed(newNode); 
    } 
}

void rbt::deleteByVal(int n) { 
    if (root == nullptr) 
        return; 

    node *v = search(n), *u; 

    if (v->key != n) { 
        cout << "No node found to delete with value:" << n << endl; 
        return; 
    } 

    deleteNode(v); 
}