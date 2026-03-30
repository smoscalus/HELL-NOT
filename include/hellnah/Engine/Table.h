#pragma once

#include "../Storage/FileStorage.h"
#include "../Core/WorkFile.h"

namespace Engine
{
template <typename T>
class Table
{
    Core::WorkFile& _workFile;

public:
    Table(Core::WorkFile& workFile) : _workFile(workFile) {}

    T insert(T);
    T get(T);
    void remove(T);
};
}
