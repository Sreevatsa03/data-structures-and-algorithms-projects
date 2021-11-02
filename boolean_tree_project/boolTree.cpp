#include "boolTree.h"

using namespace std;

boolTree::boolTree(string str) {
    str = upper(str);
    str = removeSpaces(str);
    root = convert(str);
}

string boolTree::upper(string str) {
    for (int i  = 0; i < str.length(); i++) {
        if (islower(str[i])) 
            str[i] = toupper(str[i]);
    }

    return str;
}

string boolTree::removeSpaces(string str) {
    str.erase(remove(str.begin(), str.end(), ' '), str.end()); 
    return str; 
}

bool boolTree::logicEval(){
    return eval(root);
}

node* boolTree::convert(string str){
    if (str.compare("T") == 0)
        return new node('T');
    if (str.compare("F") == 0)
        return new node('F');

    char op;
    int para = 0;
    int index = 0;
    bool canRem = true;
    
    for (int i = str.size()-1; i >= 0; i--) {
        if (str[i] == ')')
            para++;
        if (str[i] == '(')
            para--;
        if (para != 0)
            continue;
        if (para == 0 && i != 0)
            canRem = false;
        if (str[i] == '>') {
             op = str[i];
             index = i;
             break;
        } if ((str[i] == '&' || str[i] == '|' || str[i] == '^') && (op != '&' && op != '|' && op != '^')) {
             op = str[i];
             index = i;
        } 
        else if (((str[i] == '!' && op != '!' && op != '|' && op != '^' && op != '&'))) {
            op = str[i];
            index = i;
        }
    }

    if (canRem) 
        return convert(str.substr(1,str.size()-2));

    if (op == '!')
        return new node('!', convert(str.substr(1, str.size() - 1)));

    return new node(op, convert(str.substr(0, index)), convert(str.substr(index + 1, str.size() - index - 1)));
}

void boolTree::print2DUtil(const string& prefix, const node* root, bool isLeft) {  
    // int count = 10;

    // if (root == nullptr)  
    //     return;  
   
    // space += count;  
   
    // print2DUtil(root->right, space);  
  
    // cout << endl;  
    // for (int i = count; i < space; i++)  
    //     cout << " ";  
    // cout << root -> val << "\n";  
  
    // print2DUtil(root -> left, space); 

    if(root != nullptr )
    {
        cout << prefix;

        cout << (isLeft ? "├──" : "└──" );

        cout << root -> val << endl;

        // enter the next tree level - left and right branch
        print2DUtil(prefix + (isLeft ? "│   " : "    "), root -> left, true);
        print2DUtil(prefix + (isLeft ? "│   " : "    "), root -> right, false);
    } 
}  
  
void boolTree::print2D2(const node *root) {   
    // print2DUtil(root, 0);  

    print2DUtil("", root, false); 
}

void boolTree::print2D() {
    print2D2(root);
}

bool boolTree::eval(node *root) {
    if (root -> left == nullptr) {
        if (root -> val == 'T') {
            return true;
        }
        if (root -> val == 'F') {
            return false;
        }
    }

    switch(root -> val) {
        case '&':
            return eval(root -> left) & eval(root -> right);
        case '|':
            return eval(root -> left) | eval(root -> right);
        case '^':
            return eval(root -> left) ^ eval(root -> right);
        case '>':
            return (!eval(root -> right)) | eval(root -> right);
        case '!':
            return !eval(root -> left);
    }
}

void boolTree::print2(node *root) const{
    // In order traversal
    if (root == nullptr) 
            return; 
    
    print2(root -> left); 

    cout << root -> val << " ";

    print2(root -> right); 
}

void boolTree::print() const {
    print2(root);
}

void boolTree::printLevelOrder2(node *root) const{   
    if (root == nullptr)
        return;  
   
    queue <node *> q;  
  
    q.push(root);  
  
    while (!(q.empty())) {  
        int nodeCount = q.size();  
  
        while (nodeCount > 0) {  
            node *node = q.front();  
            cout << node -> val << " ";  
            q.pop();  
            if (node -> left != nullptr)  
                q.push(node -> left);  
            if (node -> right != nullptr)  
                q.push(node -> right);  
            nodeCount--;  
        }  
        cout << endl;  
    }  
}

void boolTree::printLevelOrder() const{
    printLevelOrder2(root);
}

int boolTree::count(node *root) const{
    if (root != nullptr) {
        return count(root -> left) + count(root -> right) + 1;
    } else {
        return 0;
    }
}

int boolTree::maxDepth(node *root) const{
    if (root != nullptr) {
        return max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
    } else {
        return 0;
    }
}

bool boolTree::isSymmetric(node *root) const{
    return symHelp(root -> left, root -> right);
}

bool boolTree::symHelp(node *left, node *right) const{
    if (left != nullptr && right != nullptr) {
        if (left -> val == right -> val) {
            return symHelp(left -> left, right -> right) && symHelp(left -> right, right -> left);
        } else {
            return false;
        }
    } else if (left == nullptr && right == nullptr) {
        return true;
    }
}