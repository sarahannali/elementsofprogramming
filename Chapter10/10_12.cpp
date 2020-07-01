#include <iostream>
#include <vector>
#include <unordered_map>
#include "BinaryTree.h"

using BinaryTrees::BinaryTree;
using BinaryTrees::node;
using namespace std;

BinaryTree ReconstructBinaryHelper(const vector<int> &preorder, int preorder_start, int preorder_end, int inorder_start, int inorder_end, const unordered_map<int, int> &node_to_inorder_idx)
{
    BinaryTree final;
    node *root;

    if (preorder_end <= preorder_start || inorder_end <= inorder_start)
    {
        root = nullptr;
    }

    else
    {
        root = new node(preorder[preorder_start]);

        int root_inorder_idx = node_to_inorder_idx.at(preorder[preorder_start]);
        int left_subtree_size = root_inorder_idx - inorder_start;

        BinaryTree left_subtree = ReconstructBinaryHelper(preorder, preorder_start + 1, preorder_start + 1 + left_subtree_size, inorder_start, root_inorder_idx, node_to_inorder_idx);
        BinaryTree right_subtree = ReconstructBinaryHelper(preorder, preorder_start + 1 + left_subtree_size, preorder_end, root_inorder_idx + 1, inorder_end, node_to_inorder_idx);

        root->SetLeft(left_subtree.GetRoot());
        root->SetRight(right_subtree.GetRoot());
    }

    final.SetRoot(root);

    return final;
}

BinaryTree ReconstructBinary(const vector<int> &inorder, const vector<int> &preorder)
{
    unordered_map<int, int> node_to_inorder_idx;

    for (unsigned int i = 0; i < inorder.size(); i++)
    {
        node_to_inorder_idx.emplace(inorder[i], i);
    }

    return ReconstructBinaryHelper(preorder, 0, preorder.size(), 0, inorder.size(), node_to_inorder_idx);
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

    vector<int> preorder_walk = binary_tree.PreorderWalk(binary_tree.GetRoot());
    vector<int> inorder_walk = binary_tree.InorderWalk(binary_tree.GetRoot());

    BinaryTree ans = ReconstructBinary(inorder_walk, preorder_walk);
    vector<int> ans_inorder_walk = ans.InorderWalk(ans.GetRoot());

    cout << "ans inorder walk: \n";

    for (const int i : ans_inorder_walk)
        cout
            << i << '\n';

    ans_inorder_walk == inorder_walk ? cout << "true" : cout << "false";
}
