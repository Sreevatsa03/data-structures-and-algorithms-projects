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

class node {
public:
    char val;
    /* & - and, | - or, ! - not, ^ - xor, > - implies(!A|B)*/
    /*Precedence: ! -> &,|,^ -> > */
	node *left;
    node *right;
    node(char value) {
    	val = value;
       	left = nullptr;
       	right = nullptr;
    }
    node(char value, node* el, node* er) {
    	val = value;
       	left = el;
       	right = er;
    }
    node(char value, node* el) {
        val = value;
       	left = el;
      	right = nullptr;
    }
    virtual ~node() {
    }
};

#endif
