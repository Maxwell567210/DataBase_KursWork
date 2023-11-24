#pragma once

#include <cstring>

struct Investor
{
    char fio[30] = "";
    unsigned short int sum = 0;
    char data[10] = "";
    char adcFio[22] = "";
};

struct ListNode
{
    ListNode *next = nullptr;
    Investor data;
};

struct ListNodeIndex
{
    ListNodeIndex *next = nullptr;
    ListNode *pointer = nullptr;
    int weight = 0;
};

struct TreeNode
{
    Investor *data;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    int weight = 0;

    TreeNode(Investor *data) : data(data) {}
};