#include <iostream>
#include <limits>
#include <algorithm>
#include "BinaryTree.h"

using BinaryTrees::BinaryTree;
using BinaryTrees::node;
using namespace std;

int MinNode(node *root)
{
    int left = numeric_limits<int>::max();
    int right = numeric_limits<int>::max();

    if (root->GetLeft())
    {
        left = MinNode(root->GetLeft());
    }

    if (root->GetRight())
    {
        right = MinNode(root->GetRight());
    }

    int minimum = min(left, right);
    minimum = min(minimum, root->GetData());

    return minimum;
}

int MaxNode(node *root)
{
    int left = numeric_limits<int>::min();
    int right = numeric_limits<int>::min();

    if (root->GetLeft())
    {
        left = MaxNode(root->GetLeft());
    }

    if (root->GetRight())
    {
        right = MaxNode(root->GetRight());
    }

    int maximum = max(left, right);
    maximum = max(maximum, root->GetData());

    return maximum;
}

bool IsBST(node *root)
{
    bool ans = true;

    if (root->GetLeft())
    {
        if (root->GetLeft()->GetData() > root->GetData() || MaxNode(root->GetLeft()) > root->GetData())
            return false;
        ans = IsBST(root->GetLeft());
    }

    if (root->GetRight())
    {
        if (root->GetRight()->GetData() < root->GetData() || MinNode(root->GetRight()) < root->GetData())
            return false;
        ans = IsBST(root->GetRight());
    }

    return ans;
}

int main()
{
    BinaryTree binary_tree;

    node *node1 = new node(8);
    node *node2 = new node(3);
    node *node3 = new node(10);
    node *node4 = new node(1);
    node *node5 = new node(6);
    node *node6 = new node(14);
    node *node7 = new node(4);
    node *node8 = new node(7);
    node *node9 = new node(13);

    binary_tree.SetRoot(node1);

    node1->SetLeft(node2);
    node1->SetRight(node3);
    node2->SetLeft(node4);
    node2->SetRight(node5);
    node3->SetRight(node6);
    node5->SetLeft(node7);
    node5->SetRight(node8);
    node6->SetLeft(node9);

    bool ans = IsBST(binary_tree.GetRoot());

    cout << ans;
}