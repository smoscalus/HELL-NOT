#pragma once

#include "../Storage/FileStorage.h"

template <typename T>
class Table
{
    FileStorage _fileStorage;

    Table(const char *path)
    {
        _fileStorage.OpenFile(path);
    }

    T insert(T);

    T get(T);

    void remove(T);
};
