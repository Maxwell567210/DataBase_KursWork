#pragma once

#include "listTools.hpp"
// #include "tools/treeTools.hpp"
#include "Nodes.hpp"
#include "getListFromDB.hpp"
// #include "data/Sorting.hpp"

class Singleton
{
private:
    ListNode *list = nullptr;
    ListNodeIndex *sortedList = nullptr;

public:
    ListNode *getList()
    {
        if (list == nullptr)
            list = getListFromDataBase();
        return list;
    }

    // ListNodeIndex *getSortedList()
    // {
    //     if (sortedList == nullptr)
    //     {
    //         sortedList = copyByIndex(getList());
    //         mergeSort(sortedList, compareList);
    //     }
    //     return sortedList;
    // }

    void clear()
    {
        clearList(list);
        clearList(sortedList);
    }

} singleton;