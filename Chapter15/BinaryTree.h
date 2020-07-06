#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <vector>

namespace BinaryTrees
{
    struct node
    {
    public:
        node(){};
        node(int given_data) { data = given_data; };
        int GetData() const { return data; };
        int GetHeight() const { return height; };
        node *GetLeft() const { return left; };
        node *GetRight() const { return right; };
        node *GetParent() const { return parent; };
        void SetHeight(int given_height) { height = given_height; };
        void SetLeft(node *);
        void SetRight(node *);
        void SetParent(node *, bool = false);

    private:
        int data;
        int height = 0;
        node *left = nullptr;
        node *right = nullptr;
        node *parent = nullptr;
    };

    class BinaryTree
    {
    public:
        BinaryTree(){};
        node *GetRoot() const { return root; }
        void SetRoot(node *);
        std::vector<int> InorderWalk(node *);
        std::vector<int> PreorderWalk(node *);

    private:
        node *root = nullptr;
    };
} // namespace BinaryTrees

#endif