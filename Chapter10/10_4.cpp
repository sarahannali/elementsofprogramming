#include <iostream>
#include <vector>
#include <queue>
#include "BinaryTree.h"

using BinaryTrees::BinaryTree;
using BinaryTrees::node;
using namespace std;

node *LCA(node *node1, node *node2)
{
    while (node1->GetHeight() != node2->GetHeight())
    {
        if (node1->GetHeight() > node2->GetHeight())
            node1 = node1->GetParent();

        else
            node2 = node2->GetParent();
    }

    while (node1 != node2)
    {
        node1 = node1->GetParent();
        node2 = node2->GetParent();
    }

    return node1;
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

    node *ans = LCA(node8, node4);

    cout << ans->GetData();
}
