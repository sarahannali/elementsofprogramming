#include <iostream>
#include <vector>
#include <queue>
#include "BinaryTree.h"

using BinaryTrees::BinaryTree;
using BinaryTrees::node;
using namespace std;

vector<vector<int>> TreeLayers(BinaryTree binary_tree)
{
    queue<node *> curr_depth;
    curr_depth.push(binary_tree.GetRoot());
    vector<vector<int>> result;

    while (!curr_depth.empty())
    {
        queue<node *> next_depth;
        vector<int> this_level;

        while (!curr_depth.empty())
        {
            auto curr = curr_depth.front();
            curr_depth.pop();

            this_level.push_back(curr->data);

            if (curr->left)
                next_depth.push(curr->left);

            if (curr->right)
                next_depth.push(curr->right);
        }

        if (!this_level.empty())
        {
            result.push_back(this_level);
        }

        curr_depth = next_depth;
    }

    return result;
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

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    node4->left = node8;
    node4->right = node9;

    vector<vector<int>> ans = TreeLayers(binary_tree);

    for (unsigned int i = 0; i < ans.size(); i++)
    {
        for (unsigned int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << ',';
        }
        cout << '\n';
    }
}
