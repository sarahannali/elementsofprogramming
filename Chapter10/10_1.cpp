#include <iostream>
#include <vector>
#include <queue>
#include "BinaryTree.h"

using BinaryTrees::BinaryTree;
using BinaryTrees::node;
using namespace std;

int Height(node *root)
{
    int left_height = 0;
    int right_height = 0;

    if (root->GetLeft())
    {
        left_height += 1;
        left_height += Height(root->GetLeft());
    }
    if (root->GetRight())
    {
        right_height += 1;
        right_height += Height(root->GetRight());
    }

    return max(left_height, right_height);
}

bool HeightBalanced(BinaryTree binary_tree)
{
    node *root = binary_tree.GetRoot();

    int left_height = Height(root->GetLeft());
    int right_height = Height(root->GetRight());

    if (abs(left_height - right_height <= 1))
    {
        return true;
    }

    else
        return false;
}

int main()
{
    BinaryTree binary_tree;

    node *node1 = new node(13);
    node *node2 = new node(10);
    node *node3 = new node(7);
    node *node4 = new node(6);
    node *node5 = new node(5);
    node *node6 = new node(4);
    node *node7 = new node(2);
    node *node8 = new node(1);
    node *node9 = new node(3);

    binary_tree.SetRoot(node1);

    node1->SetLeft(node2);
    node1->SetRight(node3);
    node2->SetLeft(node4);
    node2->SetRight(node5);
    node3->SetLeft(node6);
    node3->SetRight(node7);
    node4->SetLeft(node8);
    node4->SetRight(node9);

    bool ans = HeightBalanced(binary_tree);

    ans ? cout << "true" : cout << "false";
}
