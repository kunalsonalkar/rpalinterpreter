#include <iostream>
#include "stack.h"

using namespace std;

int main()
{

    Stack *s = new Stack;

    BTreeNode *node1 = new BTreeNode("5", NULL, NULL);
    BTreeNode *node2 = new BTreeNode("10", NULL, NULL);
    BTreeNode *node3 = new BTreeNode("20", NULL, NULL);

    s->push(node1);
    s->push(node2);
    s->push(node3);

    s->buildTree("where", 3);

    node1 = s->pop();

    node1->preorder();

    delete node1;
    delete node2;
    delete node3;

    delete s;

}
