#pragma once

#include "../data/Nodes.hpp"

using namespace std;

bool compareList(ListNodeIndex first, ListNodeIndex second)
{
    int fioComparison = strncmp(first.pointer->data.fio, second.pointer->data.fio, 3);
    if (fioComparison == 0)
    {
        return first.pointer->data.sum <= second.pointer->data.sum;
    }
    return fioComparison <= 0;
}

bool compareTree(Investor first, Investor second)
{
    return strncmp(first.fio, second.fio, 3) < 0;
}

bool compareWeight(ListNodeIndex first, ListNodeIndex second)
{
    return first.weight <= second.weight;
}

bool equalsFio(Investor first, Investor second)
{
    return strncmp(first.fio, second.fio, 3) == 0;
}

ListNodeIndex *copyByIndex(ListNode *head)
{
    if (head == nullptr)
    {
        return nullptr; // Return nullptr if the input list is empty
    }

    ListNodeIndex *indexHead = nullptr;    // Initialize the index list head pointer
    ListNodeIndex *currentIndex = nullptr; // Initialize the current index pointer

    ListNode *current = head; // Initialize a current pointer for traversing the original list

    while (current != nullptr)
    {
        // Create a new ListNodeIndex node for the current ListNode
        ListNodeIndex *newIndex = new ListNodeIndex;
        newIndex->pointer = current;

        if (indexHead == nullptr)
        {
            // If the index list is empty, set the new node as the head
            indexHead = newIndex;
            currentIndex = newIndex;
        }
        else
        {
            // Otherwise, link the new node to the current index list
            currentIndex->next = newIndex;
            currentIndex = newIndex;
        }

        current = current->next; // Move to the next node in the original list
    }

    return indexHead; // Return the head of the index list
}

ListNodeIndex *copyByIndex(ListNodeIndex *head)
{
    if (head == nullptr)
    {
        return nullptr; // Return nullptr if the input list is empty
    }

    ListNodeIndex *indexHead = nullptr;    // Initialize the index list head pointer
    ListNodeIndex *currentIndex = nullptr; // Initialize the current index pointer

    ListNodeIndex *current = head; // Initialize a current pointer for traversing the original list

    while (current != nullptr)
    {
        // Create a new ListNodeIndex node for the current ListNode
        ListNodeIndex *newIndex = new ListNodeIndex;
        newIndex->pointer = current->pointer;

        if (indexHead == nullptr)
        {
            // If the index list is empty, set the new node as the head
            indexHead = newIndex;
            currentIndex = newIndex;
        }
        else
        {
            // Otherwise, link the new node to the current index list
            currentIndex->next = newIndex;
            currentIndex = newIndex;
        }

        current = current->next; // Move to the next node in the original list
    }

    return indexHead; // Return the head of the index list
}

ListNodeIndex *copyByIndex(ListNodeIndex *start, ListNodeIndex *end)
{
    if (start == nullptr)
    {
        return nullptr; // Return nullptr if the input list is empty
    }

    ListNodeIndex *indexHead = nullptr;    // Initialize the index list head pointer
    ListNodeIndex *currentIndex = nullptr; // Initialize the current index pointer

    ListNodeIndex *current = start; // Initialize a current pointer for traversing the original list

    while (current != nullptr && current != end)
    {
        // Create a new ListNodeIndex node for the current ListNode
        ListNodeIndex *newIndex = new ListNodeIndex;
        newIndex->pointer = current->pointer;

        if (indexHead == nullptr)
        {
            // If the index list is empty, set the new node as the head
            indexHead = newIndex;
            currentIndex = newIndex;
        }
        else
        {
            // Otherwise, link the new node to the current index list
            currentIndex->next = newIndex;
            currentIndex = newIndex;
        }

        current = current->next; // Move to the next node in the original list
    }

    return indexHead; // Return the head of the index list
}

void clearList(ListNode *head)
{
    ListNode *temp, *current;
    temp = current = head;
    while (current != nullptr)
    {
        current = temp->next;
        delete temp;
        temp = current;
    }
    head = nullptr;
}

void clearList(ListNodeIndex *head)
{
    ListNodeIndex *temp, *current;
    temp = current = head;
    while (current != nullptr)
    {
        current = temp->next;
        delete temp;
        temp = current;
    }
}
