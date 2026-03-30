#pragma once

#include "../Storage/FileStorage.h"
#include "../Core/WorkFile.h"

template <typename T>
class Table
{
    
public: 
    Table(WorkFile WorkFile)
    {
        
    }

    T insert(T);

    T get(T);

    void remove(T);
};
