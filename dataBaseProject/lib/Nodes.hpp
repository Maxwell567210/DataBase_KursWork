#pragma once

#include <cstring>

struct Person
{
    char author[12] = "";
    char title[32] = "";
    char publish[16] = "";
    short int year = 0;
    short int pageQuant = 0;
};

struct ListNode
{
    ListNode *next = nullptr;
    Person data;
};

struct ListNodeIndex
{
    ListNodeIndex *next = nullptr;
    ListNode *pointer = nullptr;
    int weight = 0;
};

struct TreeNode
{
    Person *data;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    int weight = 0;

    TreeNode(Person *data) : data(data) {}
};