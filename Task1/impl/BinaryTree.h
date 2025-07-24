#ifndef IMPL_BINARYTREE_H
#define IMPL_BINARYTREE_H

#include "../BinaryTree.h"

template <typename T>
BinaryTree<T>::TreeNode::TreeNode(T value, TreeNode *left, TreeNode *right)
    : _value(value), _left(left), _right(right) {}

template <typename T>
BinaryTree<T>::TreeNode::~TreeNode()
{
    delete _left;
    delete _right;
}

template <typename T>
T BinaryTree<T>::TreeNode::GetValue()
{
    return _value;
}

template <typename T>
typename BinaryTree<T>::TreeNode *BinaryTree<T>::TreeNode::GetLeft()
{
    return _left;
}

template <typename T>
typename BinaryTree<T>::TreeNode *BinaryTree<T>::TreeNode::GetRight()
{
    return _right;
}

template <typename T>
void BinaryTree<T>::TreeNode::SetValue(T value)
{
    _value = value;
}

template <typename T>
void BinaryTree<T>::TreeNode::SetLeft(TreeNode *left)
{
    _left = left;
}

template <typename T>
void BinaryTree<T>::TreeNode::SetRight(TreeNode *right)
{
    _right = right;
}

template <typename T>
BinaryTree<T>::BinaryTree()
{
    _root = nullptr;
}

template <typename T>
BinaryTree<T>::BinaryTree(T *arr, int size) : _root(nullptr)
{
    _root = nullptr;
    for (int i = 0; i < size; i++)
    {
        Insert(arr[i]);
    }
}

template <typename T>
typename BinaryTree<T>::TreeNode *BinaryTree<T>::FindParent(const T &value)
{
    TreeNode *current = _root;
    TreeNode *parent = nullptr;

    while (current != nullptr && current->GetValue() != value)
    {
        parent = current;
        current = (value < current->GetValue()) ? current->GetLeft() : current->GetRight();
    }

    return parent;
}

template <typename T>
bool BinaryTree<T>::Insert(const T &value)
{
    if (Contains(value))
    {
        return true;
    }

    TreeNode *parent = FindParent(value);
    TreeNode *node = new TreeNode(value, nullptr, nullptr);

    if (!parent)
    {
        _root = node;
    }

    else
    {
        if (value < parent->GetValue())
        {
            parent->SetLeft(node);
        }

        else
        {
            parent->SetRight(node);
        }
    }

    return true;
}

template <typename T>
bool BinaryTree<T>::Contains(const T &value)
{
    return Find(value) != nullptr;
}

template <typename T>
typename BinaryTree<T>::TreeNode *BinaryTree<T>::Find(const T &value)
{
    TreeNode *current = _root;

    while (current != nullptr && current->GetValue() != value)
    {
        current = (value < current->GetValue()) ? current->GetLeft() : current->GetRight();
    }

    return current;
}

template <typename T>
bool BinaryTree<T>::Empty() const
{
    return !_root;
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
    while (!Empty())
    {
        Remove(_root->GetValue());
    }
}

template <typename T>
bool BinaryTree<T>::Remove(const T &value)
{
    if (!Contains(value))
    {
        return true;
    }

    TreeNode *removing = Find(value);
    if (removing->GetLeft() == nullptr && removing->GetRight() == nullptr)
    {
        if (removing->GetValue() == _root->GetValue())
        {
            _root = nullptr;
            return true;
        }
        TreeNode *parent = FindParent(removing->GetValue());

        if (removing->GetValue() < parent->GetValue())
        {
            parent->SetLeft(nullptr);
        }

        else
        {
            parent->SetRight(nullptr);
        }

        delete removing;
    }

    else
    {
        if (!removing->GetRight())
        {
            TreeNode *current = removing->GetLeft();

            while (current->GetRight())
            {
                current = current->GetRight();
            }

            T value = current->GetValue();
            Remove(value);
            removing->SetValue(value);
        }

        else
        {
            TreeNode *current = removing->GetRight();

            while (current->GetLeft())
            {
                current = current->GetLeft();
            }

            T value = current->GetValue();
            Remove(value);
            removing->SetValue(value);
        }
    }

    return true;
}

template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree<T> &other)
{
    _root = nullptr;
    std::vector<TreeNode *> nodes;
    TreeNode *current = other._root;

    while (current)
    {
        Insert(current->GetValue());

        if (current->GetRight())
        {
            nodes.push_back(current->GetRight());
        }

        if (current->GetLeft())
        {
            current = current->GetLeft();
        }

        else if (nodes.empty())
        {
            break;
        }

        else
        {
            current = nodes.back();
            nodes.pop_back();
        }
    }
}

template <typename T>
BinaryTree<T>::BinaryTree(BinaryTree<T> &&other)
{
    _root = other._root;
    other._root = nullptr;
}

template <typename T>
std::vector<T> BinaryTree<T>::RoundRrootL()
{
    std::vector<T> bypass;
    std::vector<TreeNode *> TreeNodes;
    TreeNode *current = _root;

    if (!_root)
    {
        throw std::runtime_error("Tree is empty...");
    }

    while (current || !TreeNodes.empty())
    {
        while (current)
        {
            TreeNodes.push_back(current);
            current = current->GetRight();
        }

        bypass.push_back(TreeNodes.back()->GetValue());
        current = TreeNodes.back()->GetLeft();
        TreeNodes.pop_back();
    }

    return bypass;
}

template <typename T>
std::vector<T> BinaryTree<T>::RoundLrootR()
{
    std::vector<T> bypass;
    std::vector<TreeNode *> nodes;
    TreeNode *current = _root;

    if (!_root)
    {
        throw std::runtime_error("Tree is empty...");
    }

    while (current || !nodes.empty())
    {
        while (current)
        {
            nodes.push_back(current);
            current = current->GetLeft();
        }

        bypass.push_back(nodes.back()->GetValue());
        current = nodes.back()->GetRight();
        nodes.pop_back();
    }

    return bypass;
}

template <typename T>
void BinaryTree<T>::Output()
{
    if (_root)
    {
        Print(_root, "", true);
    }
}

template <typename T>
void BinaryTree<T>::Print(TreeNode *current, std::string padding, bool isRight)
{
    if (current)
    {

        std::cout << padding;

        if (isRight)
        {
            std::cout << "├──";
            padding += "│   ";
        }

        else
        {
            std::cout << "└──"; // Если слева, то выводим соответствующий символ
            padding += "    ";  // Добавляем отступ для левого поддерева
        }

        // Выводим значение текущего узла
        std::cout << current->GetValue() << std::endl;

        // Рекурсивные вызовы для правого и левого поддеревьев
        Print(current->GetRight(), padding, true); // Рекурсивно вызываем для правого поддерева
        Print(current->GetLeft(), padding, false); // Рекурсивно вызываем для левого поддерева
    }
}

#endif