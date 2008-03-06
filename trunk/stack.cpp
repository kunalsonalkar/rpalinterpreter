#include "stack.h"
#include "binarytree.h"

Stack::Stack()
{
    top = new Node;
    top -> data = NULL;
    top -> next = NULL;

}

Stack::~Stack()
{
    Node *tempNode;
    while (top -> next != NULL)
    {
        tempNode = top;
        top = top -> next;
        delete tempNode;
    }
    delete top;
}


bool Stack::push(BTreeNode* item)
{
    Node *tmpNode;

    tmpNode = new Node;

    tmpNode -> data = item;
    tmpNode -> next = top;

    top = tmpNode;

    return true;
}

BTreeNode* Stack::pop()
{
    BTreeNode* topItem;

    Node *topNode;
    topNode = top;

    if (top -> next == NULL)
    {
        return NULL;
    }
    else
    {
        topItem = top -> data;
        top = top -> next;
    }

    delete topNode;
    return topItem;
}

bool Stack::clearAll()
{
    while(top -> next != NULL)
        pop();
    return true;
}

bool Stack::buildTree(string dat, int childCount)
{
    BTreeNode *tmpRoot = new BTreeNode(dat, pop(), NULL);
    //tmpRoot-> data = dat;
    //tmpRoot-> right = NULL;
    //tmpRoot->left = st->pop();

    BTreeNode *currNode = tmpRoot->getLeft();

    while  ((--childCount) > 0 )
    {
        currNode->setRight(pop());
        currNode->setLeft(NULL);

        currNode = currNode->getRight();
    }

    push(tmpRoot);
}
