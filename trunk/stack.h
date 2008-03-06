#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "binarytree.h"

struct Node {
   BTreeNode* data;
   Node *next;
};

class Stack
{
    protected:

        Node *top;

    public:
        Stack();
        ~Stack();

        bool push(BTreeNode* item);
        BTreeNode* pop();
        bool buildTree(string dat, int childCount);

        bool clearAll();
};


#endif // STACK_H_INCLUDED
