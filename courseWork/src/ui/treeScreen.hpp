#pragma once

#include <iostream>
#include "../Singleton.hpp"

#include "../tools/treeTools.hpp"

void treeScreen(ListNodeIndex *start, ListNodeIndex *end)
{
    bool quiteLoop = false;
    TreeNode *root = buildA1Tree(start, end);
    while (!quiteLoop)
    {
        system("cls");

        treeWalk(
            root, [](TreeNode current)
            { std::cout
                  << current.data->fio
                  << "\t"
                  << current.data->sum
                  << "\t" << current.data->data
                  << "\t\t\t"
                  << current.data->adcFio << std::endl; },
            WalkType::right);
        std::cout << "<1> : Exit"
                  << "\t"
                  << "<2> : Search"
                  << std::endl;

        switch (getch())
        {
        case '1':
            quiteLoop = true;
            break;
        case '2':
            system("cls");
            std::cout << "Enter key: ";
            string key;
            std::cin >> key;
            treeWalk(
                root, [&](TreeNode current)
                { 
                if (strncmp(key.c_str(), current.data->adcFio, 3) == 0) {
                std::cout
                  << current.data->fio
                  << "\t"
                  << current.data->sum
                  << "\t" << current.data->data
                  << "\t\t\t"
                  << current.data->adcFio << std::endl;} },
                WalkType::right);
            getch();
            break;
        }
    }
    deleteTree(root);
}