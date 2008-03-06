#include "binarytree.h"

BTreeNode::BTreeNode()
{
    this->data = "";
    this->left = NULL;
    this->right = NULL;
}


BTreeNode::BTreeNode(string data, BTreeNode *left, BTreeNode *right)
{
    this->data = data;
    this->left = left;
    this->right = right;
}


BTreeNode::~BTreeNode()
{

    //deleteAllNodes(this);

}


void BTreeNode::preOrderPrint(BTreeNode *root)
{
    if (root != NULL)
    {
        cout<<root->data;
        cout<<"\n\t";
        preOrderPrint(root->left);
        preOrderPrint(root->right);
    }
}

void BTreeNode::deleteAllNodes(BTreeNode *root)
{
    if (root != NULL)
    {
        //To Do
        deleteAllNodes(root->left);
        deleteAllNodes(root->right);
        cout<<root->data;
        if(NULL!=root)
            delete root;
    }
}

void BTreeNode::preorder()
{
    preOrderPrint(this);
}

void BTreeNode::setLeft(BTreeNode *left)
{
    this->left = left;
}

void BTreeNode::setRight(BTreeNode *right)
{
    this->right = right;
}

BTreeNode* BTreeNode::getLeft()
{
    return this->left;
}

BTreeNode* BTreeNode::getRight()
{
    return this->right;
}
