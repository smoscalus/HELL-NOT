#pragma once

#include "Table.h";

class Database
{
    Database(const char* path);

    template<typename T>
    Table<T> open_table(const char* path)
    {
        return T{};
    }

};
