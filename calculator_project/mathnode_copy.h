/*
 * mathNode.h
 *
 *  Created on: Oct 7, 2019
 *      Author: nvm
 */

#ifndef MATHNODE_H_
#define MATHNODE_H_


#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <math.h>

#ifndef MATHNODE_H
#define MATHNODE_H

using namespace std;

class mathNode {
public:
    string op;
    float num;
    mathNode *left;
    mathNode *right;
    void bah() {
        if (op.compare("+") == 0) num =  (left->eval() + right->eval());
        if (op.compare("-") == 0) num =  (left->eval() - right->eval());
        if (op.compare("*") == 0) num =  (left->eval() * right->eval());
        if (op.compare("/") == 0) num =  (left->eval() / right->eval());
        if (op.compare("^") == 0) num =  pow(left->eval(),right->eval());
        op = "0";
    }
    float eval() {
        if (op.compare("0") == 0) {
            return num;
        }
        if (op.compare("+") == 0) return (left->eval() + right->eval());
        if (op.compare("-") == 0) return (left->eval() - right->eval());
        if (op.compare("*") == 0) return (left->eval() * right->eval());
        if (op.compare("/") == 0) return (left->eval() / right->eval());
        if (op.compare("^") == 0) return pow(left->eval(),right->eval());
        return 0;
    }
    mathNode(float n) {
        op = "0";
        num = n;
        left = nullptr;
        right = nullptr;
    }
    mathNode(string oper, mathNode el, mathNode r) {
        op = oper;
        num = 0;
        left = &el;
        right = &r;
    }

    mathNode(string oper, mathNode el) {
        op = "0";
        num = 0;
        if (oper.compare("sin") == 0) num = sin(el.eval());
        if (oper.compare("cos") == 0) num = cos(el.eval());
        if (oper.compare("tan") == 0) num = tan(el.eval());
        if (oper.compare("cot") == 0) num = 1/tan(el.eval());
        if (oper.compare("sec") == 0) num = 1/cos(el.eval());
        if (oper.compare("csc") == 0) num = 1/sin(el.eval());
        left = nullptr;
        right = nullptr;
    }
    ~mathNode() {
    }
};

#endif


#endif /* MATHNODE_H_ */
