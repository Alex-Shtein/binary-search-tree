#ifndef BINARY_SEACH_TREE_H
#define BINARY_SEACH_TREE_H

#include <vector>
#include <iostream>
#include <iterator>

template <typename T>
class BinarySearchTree
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

    BinarySearchTree &operator=(const BinarySearchTree &other);
    BinarySearchTree &operator=(BinarySearchTree &&other);
    TreeNode *Find(const T &value);
    TreeNode *FindParent(const T &value);
    void Print(TreeNode *current, std::string padding, bool isRight);
    TreeNode *_root;

public:
    BinarySearchTree();
    BinarySearchTree(T *arr, int size);
    ~BinarySearchTree<T>();
    BinarySearchTree(const BinarySearchTree &other);
    BinarySearchTree(BinarySearchTree &&other);
    bool Empty() const;
    bool Insert(const T &value);
    bool Remove(const T &value);
    bool Contains(const T &value);
    std::vector<T> RoundRrootL();
    std::vector<T> RoundLrootR();
    void Output();
};

#include "./impl/BinarySearchTree.h"

#endif // BINARY_SEACH_TREE_H
