#ifndef BINARYTREE_H
#define BINARYTREE_H

namespace BinaryTrees
{
    struct node
    {
    public:
        node(){};
        node(int given_data) { data = given_data; };
        int data;
        node *left = nullptr;
        node *right = nullptr;
    };

    class BinaryTree
    {
    public:
        BinaryTree(){};
        void SetRoot(node *given_root) { root = given_root; };
        node *GetRoot() const { return root; }

    private:
        node *root;
    };
} // namespace BinaryTrees

#endif