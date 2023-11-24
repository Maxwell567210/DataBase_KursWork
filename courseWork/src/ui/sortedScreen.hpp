#pragma once

#include "../Singleton.hpp"
#include "pagePrint.hpp"

void sortedScreen()
{
    listView<ListNodeIndex>(singleton.getSortedList(), [](ListNodeIndex ln)
                            { return ln.pointer->data; });
}