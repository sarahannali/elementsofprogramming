#include <iostream>
#include <algorithm>
#include <limits>
#include "BinaryTree.h"

using BinaryTrees::BinaryTree;
using BinaryTrees::node;
using namespace std;

void KthLargestElementsHelper(node *root, unsigned int k, vector<int>& k_elements)
{
    if (root->GetData() && k_elements.size() < k)
    {
        if (root->GetRight()) KthLargestElementsHelper(root->GetRight(), k, k_elements);

        if (k_elements.size() < k)
        {
            k_elements.push_back(root->GetData());
            if (root->GetLeft()) KthLargestElementsHelper(root->GetLeft(), k, k_elements);
        }
    }
}

vector<int> KthLargestElements(node *root, int k)
{
    vector<int> k_elements = {};
    KthLargestElementsHelper(root, k, k_elements);
    return k_elements;
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

    vector<int> ans = KthLargestElements(binary_tree.GetRoot(), 7);

    cout << "ans:\n";
    for (int i : ans)
    {
        cout << i << '\n';
    }
}