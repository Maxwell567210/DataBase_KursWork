#pragma once

#include "Nodes.hpp"
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

ListNode *getListFromDataBase()
{
    std::ifstream fileDateBase("../testBase1.dat", ios::binary);
    ListNode *head = nullptr;
    ListNode *current = nullptr;
    bool endRead = false;

    while (!endRead)
    {
        ListNode *newNode = new ListNode;
        endRead = fileDateBase.read((char *)&newNode->data, sizeof(Person)).eof();

        if (endRead)
        {
            delete newNode;
            break;
        }

        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            current = newNode;
        }
        else
        {
            current->next = newNode;
            current = newNode;
        }
    }

    fileDateBase.close();
    return head;
}