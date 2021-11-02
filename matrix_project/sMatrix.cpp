#include "sMatrix.h"
#include "sNode.h"
#include <cstdlib>
#include <iostream>
#include "dMatrix.h"

using namespace std;

smatrix::smatrix(int r, int c) {
    nrows = r;
    ncols = c;
    rows = new snode*[nrows];
    for (int i = 0; i < nrows; i++) {
        rows[i] = nullptr;
    }
}

smatrix::smatrix(const dmatrix &matrix) {
    float **ptr = matrix.getArr();
    nrows = matrix.getRows();
    ncols = matrix.getCols();
    rows = new snode *[nrows];
    for (int x = 0; x < nrows; x++)
    {
        rows[x] = nullptr;
    }
    for (int i = 0; i < nrows; i++)
    {
        for (int j = 0; j < ncols; j++)
        {
            float nVal = ptr[i][j];
            if (nVal != 0)
            {
                snode *n = new snode();
                n->col = j;
                n->val = nVal;
                n->next = nullptr;
                if (rows[i] == nullptr)
                {
                    rows[i] = n;
                }
                else
                {
                    snode *temp = rows[i];
                    while (temp->next != nullptr)
                    {
                        temp = temp->next;
                    }
                    temp->next = n;
                }
            }
        }
    }
}


float smatrix::get(int r, int c) const{
    snode *p = rows[r];
    while (p != nullptr && p -> col < c) {
        p = p-> next;
    }
    if (p != nullptr && p -> col == c) {
        return p -> val;
    } else {
        return 0.0;
    }
}

int smatrix::getCols() const{
	return ncols;
}

int smatrix::getRows() const{
	return nrows;
}

void smatrix::set(int r, int c, float val) {
	snode *cur = rows[r];
	snode *prev = nullptr;
	while(cur != nullptr && cur->col < c) {
		prev = cur;
		cur = cur->next;
	}
	if(cur != nullptr && cur->col == c) {
		cur->val = val;
	}
	else if(prev==nullptr) {
		snode *n = new snode;
		n->val = val;
		n->col = c;
		n->next = cur;
		rows[r] = n;
	}
	else {
		snode *n = new snode;
		n->val = val;
		n->col = c;
		prev->next = n;
		n->next = cur;
	}

}

smatrix smatrix::add(const smatrix &right) {
	smatrix result = smatrix(nrows,ncols);
	for(unsigned int i=0; i<nrows; i++) {
		snode *lp = rows[i];
		snode *rp = right.rows[i];
		snode *pSum = nullptr;
		while(lp != nullptr || rp != nullptr) {
			float rv = 0;
			unsigned int rc=0;
			if(lp==nullptr) {
				rv = rp->val;
				rc = rp->col;
				rp = rp->next;
			}
			else if(rp==nullptr || lp->col < rp->col) {
				rv = lp->val;
				rc = lp->col;
				lp = lp->next;
			}
			else if(rp->col < lp->col) {
				rv = rp->val;
				rc = rp->col;
				rp = rp->next;
			}
			else {
				rv = lp->val + rp->val;
				rc = lp->col;
				rp = rp->next;
				lp = lp->next;
			}

			if (rv != 0) {
				snode *sum = new snode();
				sum->col = rc;
				sum->val = rv;
				sum->next = nullptr;
				if(pSum == nullptr) {
					result.rows[i] = sum;
					pSum = sum;
				}
				else {
					pSum->next = sum;
					pSum = sum;
				}
			}
		}
	}
	return result;
}

void smatrix::dump() const{
	for(int i = 0; i < nrows; i++) {
		snode *p = rows[i];
		for(int j = 0; j < ncols; j++) {
			if(p == nullptr) {
				cout << " - ";
			}
			else if(p -> col > j) {
				cout << " - ";
			}
			else if(p -> col==j) {
				cout << " " << p -> val << " ";
				p = p -> next;
			}
			else {
				cout << " BAD ";
			}
		}
		cout << endl;
	}
}

smatrix smatrix::transpose() const{
	smatrix *result = new smatrix(ncols, nrows);
	for (int i = 0; i < nrows; i++) {
		snode *temp = rows[i];
		while (temp != nullptr) {
			snode *n = new snode;
			n -> col = i;
			n -> val = temp -> val;
			if (result-> getRowPtr()[temp -> col] == nullptr) {
				n -> next = nullptr;
				result -> getRowPtr()[temp -> col] = n;
			} else{
				snode *tempPtr = result -> getRowPtr()[temp -> col];
				while (tempPtr -> next != nullptr) {
					tempPtr = tempPtr -> next;
				}
				n -> next = nullptr;
				tempPtr -> next = n;
			}
			temp = temp -> next;
		}
	}
	return *result;
}

smatrix smatrix::multiply(const smatrix &right) const{
smatrix *result = new smatrix(nrows, right.getCols());

smatrix b_trans = right.transpose();
for (int i = 0; i < nrows; i++)
{
	snode *multPtr = nullptr;
	for (int j = 0; j < right.getCols(); j++)
	{
		snode *lp = rows[i];
		snode *rp = b_trans.getRowPtr()[j];
		float newVal = 0;
		unsigned int retCol = j;
		while (lp != nullptr && rp != nullptr)
		{
			if (lp -> col < rp -> col)
			{
				lp = lp -> next;
			}
			else
			{
				if (rp -> col < lp -> col)
				{
					rp = rp -> next;
				}
				else
				{
					newVal += lp -> val * rp -> val;
					lp = lp -> next;
					rp = rp -> next;
				}
			}
		}
		if (newVal != 0)
		{
			snode *mult = new snode();
			mult -> col = retCol;
			mult -> val = newVal;
			mult -> next = nullptr;
			if (multPtr == nullptr)
			{
				result -> getRowPtr()[i] = mult;
				multPtr = mult;
			}
			else
			{
				multPtr -> next = mult;
				multPtr = mult;
			}
		}
	}
}
return *result;
}

snode **smatrix::getRowPtr() {
	return rows;
}

smatrix::~smatrix() {
    delete rows;
}

