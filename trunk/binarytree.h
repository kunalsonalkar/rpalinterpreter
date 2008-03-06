
#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

struct TreeNode {

    string data;
    TreeNode *left;
    TreeNode *right;

};

class BTreeNode {

protected:

    string data;
    BTreeNode *left;
    BTreeNode *right;

    void preOrderPrint(BTreeNode *root);
    void deleteAllNodes(BTreeNode *root);

public:

    BTreeNode();
    BTreeNode(string data, BTreeNode *left, BTreeNode *rightt);
    ~BTreeNode();

    void setLeft(BTreeNode* left);
    void setRight(BTreeNode* right);

    BTreeNode* getLeft();
    BTreeNode* getRight();

    void preorder();

};

#endif // BINARYTREE_H_INCLUDED
