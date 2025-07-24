#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <vector>
#include <iostream>
#include <iterator>

template <typename T>
class BinaryTree
{
    struct TreeNode
    {
        TreeNode(T value, TreeNode *left, TreeNode *right);
        ~TreeNode();
        T GetValue();
        TreeNode *GetLeft();
        TreeNode *GetRight();
        void SetValue(T value);
        void SetLeft(TreeNode *left);
        void SetRight(TreeNode *right);

    private:
        T _value;
        TreeNode *_left;
        TreeNode *_right;
    };

    BinaryTree &operator=(const BinaryTree &other);
    BinaryTree &operator=(BinaryTree &&other);
    TreeNode *Find(const T &value);
    TreeNode *FindParent(const T &value);
    void Print(TreeNode *current, std::string padding, bool isRight);
    TreeNode *_root;

public:
    BinaryTree();
    BinaryTree(T *arr, int size);
    ~BinaryTree<T>();
    BinaryTree(const BinaryTree &other);
    BinaryTree(BinaryTree &&other);
    bool Empty() const;
    bool Insert(const T &value);
    bool Remove(const T &value);
    bool Contains(const T &value);
    std::vector<T> RoundRrootL();
    std::vector<T> RoundLrootR();
    void Output();
};

#include "./impl/BinaryTree.h"

#endif // BINARYTREE_H
