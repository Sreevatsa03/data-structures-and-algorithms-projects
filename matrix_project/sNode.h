#ifndef SNODE_H
#define SNODE_H

using namespace std;

struct snode {
    snode *next;
    float val;
    unsigned int col;
};

#endif