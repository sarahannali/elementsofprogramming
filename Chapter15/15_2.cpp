#include <iostream>
#include <limits>
#include "BinaryTree.h"

using BinaryTrees::BinaryTree;
using BinaryTrees::node;
using namespace std;

int ClosestGreateValue(node *root, int value)
{
    int closest = numeric_limits<int>::min();
    node *curr_node = root;

    while (curr_node->GetData() > value || curr_node->GetRight())
    {
        if (curr_node->GetData() <= value)
        {
            curr_node = curr_node->GetRight();
        }
        else
        {
            closest = curr_node->GetData();
            if (curr_node->GetLeft())
                curr_node = curr_node->GetLeft();
            else
                break;
        }
    }

    return closest;
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

    int ans = ClosestGreateValue(binary_tree.GetRoot(), 10);

    cout << ans;
}