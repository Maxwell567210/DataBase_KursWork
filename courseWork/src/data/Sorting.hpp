#pragma once

#include "Nodes.hpp"
#include <functional>

// Function to merge two sorted linked lists into one sorted list
void merge(
    ListNodeIndex *&left,
    ListNodeIndex *&right,
    std::function<bool(ListNodeIndex, ListNodeIndex)> pred)
{
    ListNodeIndex *result = nullptr;
    ListNodeIndex **tail = &result;

    while (true)
    {
        if (left == nullptr)
        {
            *tail = right;
            break;
        }
        else if (right == nullptr)
        {
            *tail = left;
            break;
        }

        // left->pointer->data <= right->pointer->data
        if (pred(*left, *right))
        {
            *tail = left;
            left = left->next;
        }
        else
        {
            *tail = right;
            right = right->next;
        }

        tail = &((*tail)->next);
    }

    left = result;
}

// Function to perform merge sort on a linked list
void mergeSort(
    ListNodeIndex *&head,
    std::function<bool(ListNodeIndex, ListNodeIndex)> pred)
{
    // Base case: If the list is empty or has only one element, it's already sorted
    if (head == nullptr || head->next == nullptr)
        return;

    // Split the list into two halves
    ListNodeIndex *middle = head;
    ListNodeIndex *fast = head->next;
    while (fast != nullptr)
    {
        fast = fast->next;
        if (fast != nullptr)
        {
            fast = fast->next;
            middle = middle->next;
        }
    }

    // 'middle' is now the middle node of the list
    ListNodeIndex *left = head;
    ListNodeIndex *right = middle->next;
    middle->next = nullptr;

    // Recursively sort both halves
    mergeSort(left, pred);
    mergeSort(right, pred);

    // Merge the sorted halves
    merge(left, right, pred);
    head = left; // Update the head to the merged list
}
