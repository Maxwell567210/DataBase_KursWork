#pragma once

#include <iostream>
#include <functional>

#include "../data/Nodes.hpp"

void printWalkMenu()
{
    std::cout << "<1> : Exit"
              << "\t"
              << "<2> : Previos"
              << "\t"
              << "<3> : Next"
              << std::endl;
}

void printSearchMenu()
{
    std::cout << "<1> : Exit"
              << "\t"
              << "<2> : Previos"
              << "\t"
              << "<3> : Next"
              << "\t"
              << "<4> : Tree"
              << std::endl;
}

void printStartLine()
{
    std::cout << "Fio"
              << "\t\t\t\t"
              << "Sum"
              << "\t"
              << "Data"
              << "\t\t\t\t"
              << "Adv Fio" << std::endl;
}

Investor listConverter(ListNode node)
{
    return node.data;
}

Investor indexConverter(ListNodeIndex node)
{
    return node.pointer->data;
}

template <typename T>
void printPage(T *head, std::function<Investor(T)> converter, T *end = nullptr)
{
    for (int i = 0; i < 20; i++)
    {
        Investor data = converter(*head);
        std::cout
            << data.fio
            << "\t"
            << data.sum
            << "\t" << data.data
            << "\t\t\t"
            << data.adcFio << std::endl;
        if (head != nullptr && head != end)
            head = head->next;
    }
    std::cout << std::endl;
}

template <typename T>
void listView(T *head, std::function<Investor(T)> converter)
{
    T **packArr = new T *[200];
    for (int i = 0; i < 200; i++)
    {
        packArr[i] = head;
        for (int j = 0; j < 20; j++)
            if (head != nullptr)
                head = head->next;
    }

    int page = 0;

    bool quitLoop = false;
    while (!quitLoop)
    {
        system("cls");
        std::cout << "page: " << page + 1 << std::endl;
        printPage(packArr[page], converter);
        printWalkMenu();
        switch (getch())
        {
        case '1':
            quitLoop = true;
            break;
        case '2':
            page = (page > 0) ? page - 1 : 0;
            break;
        case '3':
            page = (page < 199) ? page + 1 : 199;
            break;
        }
    }

    delete packArr;
}