#pragma once

#include <iostream>
#include <functional>

#include "../tools/listTools.hpp"
#include "../data/Sorting.hpp"
#include "../data/Nodes.hpp"

// Функция для добавления вершины в дерево
void addToBST(TreeNode *&root, Investor *val, std::function<bool(Investor, Investor)> pred)
{
    if (!root)
        root = new TreeNode(val);
    else if (pred(*val, *root->data))
        addToBST(root->left, val, pred);
    else
        addToBST(root->right, val, pred);
}

void placeWeights(ListNodeIndex *head)
{
    ListNodeIndex *current = head;

    while (current != nullptr)
    {
        Investor dataToCount = current->pointer->data;
        int count = 0;

        ListNodeIndex *runner = head;

        // Count how many times the data value appears in the list
        while (runner != nullptr)
        {
            if (equalsFio(runner->pointer->data, dataToCount))
                count++;
            runner = runner->next;
        }

        current->weight = count;
        current = current->next;
    }
}
void deleteTree(TreeNode *root)
{
    if (root == nullptr)
        return;
    if (root->left)
        deleteTree(root->left);
    if (root->right)
        deleteTree(root->right);
    delete root;
}

TreeNode *buildA1Tree(ListNodeIndex *start, ListNodeIndex *end)
{
    TreeNode *tree = nullptr;
    ListNodeIndex *copied = copyByIndex(start, end);
    placeWeights(copied);
    mergeSort(copied, compareWeight);

    ListNodeIndex *current = copied;
    while (current != nullptr)
    {
        addToBST(tree, &current->pointer->data, compareTree);
        current = current->next;
    }
    clearList(copied);
    return tree;
}

enum class WalkType
{
    down,
    right,
    up,
};

void treeWalk(TreeNode *root, std::function<void(TreeNode)> fun, WalkType walkType)
{
    if (root == nullptr)
        return;

    switch (walkType)
    {
    case WalkType::down:
        fun(*root);
        treeWalk(root->left, fun, walkType);
        treeWalk(root->right, fun, walkType);
        break;
    case WalkType::right:
        treeWalk(root->left, fun, walkType);
        fun(*root);
        treeWalk(root->right, fun, walkType);
        break;
    case WalkType::up:
        treeWalk(root->left, fun, walkType);
        treeWalk(root->right, fun, walkType);
        fun(*root);
        break;
    }
}