#include <iostream>
#include <vector>
#include <queue>
#include "BinaryTree.h"

using BinaryTrees::BinaryTree;
using BinaryTrees::node;
using namespace std;

bool SymmetricTree(node *root1, node *root2 = nullptr)
{
    bool match = true;

    if (!root2)
    {
        if (root1->GetLeft()->GetData() != root1->GetRight()->GetData())
            return false;

        match = match ? SymmetricTree(root1->GetLeft(), root1->GetRight()) : match;
    }

    else if ((root1->GetLeft() && !root2->GetRight()) || (root1->GetRight() && !root2->GetLeft()))
    {
        return false;
    }

    else
    {
        if (root1->GetLeft() && root2->GetRight())
        {
            if (root1->GetLeft()->GetData() != root2->GetRight()->GetData())
                return false;

            match = match ? SymmetricTree(root1->GetLeft(), root2->GetRight()) : match;
        }

        if (root1->GetRight() && root2->GetLeft())
        {
            if (root1->GetRight()->GetData() != root2->GetLeft()->GetData())
                return false;

            match = match ? SymmetricTree(root1->GetRight(), root2->GetLeft()) : match;
        }
    }

    return match;
}

int main()
{
    BinaryTree binary_tree;

    node *node1 = new node(314);
    node *node2 = new node(6);
    node *node3 = new node(6);
    node *node4 = new node(2);
    node *node5 = new node(2);
    node *node6 = new node(3);
    node *node7 = new node(3);

    binary_tree.SetRoot(node1);

    node1->SetLeft(node2);
    node1->SetRight(node3);
    node2->SetRight(node4);
    node3->SetLeft(node5);
    node4->SetRight(node6);
    node5->SetLeft(node7);

    bool ans = SymmetricTree(binary_tree.GetRoot());

    ans ? cout << "true" : cout << "false";
}
