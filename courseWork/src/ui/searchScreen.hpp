#pragma once

#include "../Singleton.hpp"

#include "pagePrint.hpp"
#include "treeScreen.hpp"

using namespace std;

void searchListView(ListNodeIndex *start, ListNodeIndex *end, int itemCount, string key)
{
    int pageCount = itemCount / 20;
    if (itemCount % 20 != 0)
        pageCount++;
    ListNodeIndex **packArr = new ListNodeIndex *[pageCount];
    ListNodeIndex *current = start;
    for (int i = 0; i < pageCount; i++)
    {
        packArr[i] = current;
        for (int j = 0; j < 20; j++)
            if (current != nullptr)
                current = current->next;
    }

    int page = 0;
    bool quitLoop = false;
    while (!quitLoop)
    {
        system("cls");
        cout << "page: " << page << endl;
        printPage<ListNodeIndex>(packArr[page], indexConverter, end);
        printSearchMenu();
        switch (getch())
        {
        case '1':
            quitLoop = true;
            break;
        case '2':
            page = (page > 0) ? page - 1 : 0;
            break;
        case '3':
            page = (page < pageCount - 1) ? page + 1 : pageCount - 1;
            break;
        case '4':
            treeScreen(start, end);
            break;
        }
    }
    delete packArr;
}

void searchView(ListNodeIndex *head)
{
    cout << "Enter Key: ";
    string key;
    cin >> key;

    int itemCount = 0;
    ListNodeIndex *start = nullptr;
    ListNodeIndex *end = nullptr;
    ListNodeIndex *current = head;
    while (current != nullptr)
    {
        bool apply = (current->pointer->data.fio[0] == key[0]) &&
                     (current->pointer->data.fio[1] == key[1]) &&
                     (current->pointer->data.fio[2] == key[2]);

        if (apply)
            itemCount++;
        if (apply && start == nullptr)
        {
            start = current;
            end = current;
        }
        if (apply)
            end = current;

        if (!apply && start != nullptr)
            break;
        current = current->next;
    }

    if (start == nullptr)
    {
        cout << "Not Found!" << endl;
        getch();
        return;
    }
    searchListView(start, end, itemCount, key);
}

void searchScreen()
{
    searchView(singleton.getSortedList());
}