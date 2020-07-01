#include "BinaryTree.h"
#include <iostream>

using std::vector;

namespace BinaryTrees
{
    void node::SetLeft(node *given_node)
    {
        this->left = given_node;
        given_node->SetHeight(this->GetHeight() + 1);
        given_node->SetParent(this, true);
    }

    void node::SetRight(node *given_node)
    {
        this->right = given_node;
        given_node->SetHeight(this->GetHeight() + 1);
        given_node->SetParent(this, true);
    }

    void node::SetParent(node *given_node, bool self_call)
    {
        this->parent = given_node;
        if (!self_call)
            given_node->GetLeft() ? given_node->SetRight(this) : given_node->SetLeft(this);
    }

    void BinaryTree::SetRoot(node *given_root)
    {
        root = given_root;
        root->SetHeight(0);
    };

    vector<int> BinaryTree::InorderWalk(node *root)
    {
        vector<int> result{};

        if (root->GetLeft())
        {
            vector<int> left_results = InorderWalk(root->GetLeft());

            for (const int i : left_results)
                result.push_back(i);
        }

        result.push_back(root->GetData());

        if (root->GetRight())
        {
            vector<int> right_results = InorderWalk(root->GetRight());

            for (const int i : right_results)
                result.push_back(i);
        }

        return result;
    }

    vector<int> BinaryTree::PreorderWalk(node *root)
    {
        vector<int> result{};

        result.push_back(root->GetData());

        if (root->GetLeft())
        {
            vector<int> left_results = PreorderWalk(root->GetLeft());

            for (const int i : left_results)
                result.push_back(i);
        }

        if (root->GetRight())
        {
            vector<int> right_results = PreorderWalk(root->GetRight());

            for (const int i : right_results)
                result.push_back(i);
        }

        return result;
    }

} // namespace BinaryTrees