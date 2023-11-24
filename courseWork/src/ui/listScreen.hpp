#pragma once

#include "../Singleton.hpp"
#include "pagePrint.hpp"

void listScreen()
{
    listView<ListNode>(singleton.getList(), [](ListNode ln)
                       { return ln.data; });
}