#pragma once

#include "../Storage/FileStorage.h"
#include "../Core/WorkFile.h"
#include "../Core/DbHeader.h"
#include "../Core/RecordHeader.h"

#include <fstream>

namespace Engine
{
template <typename T>
class Table
{
    Core::WorkFile& _workFile;

public:
    Table(Core::WorkFile& workFile) : _workFile(workFile) {}

    int insert(T obj)
    {
        const char* path = _workFile.getValue();
        size_t size = sizeof(obj);

        std::ofstream file(path, std::ios::binary | std::ios::app);

        int id = Storage::FileStorage::add(path, size);
        file.write(reinterpret_cast<const char*>(&obj), size);

        file.close();

        return id;
    }

    T get(int id)
    {
        const char* path = _workFile.getValue();
        uint64_t offset = sizeof(Core::DbHeader) + (id - 1) * (sizeof(Core::RecordHeader) + sizeof(T));
        
        std::fstream file(_workFile.getValue(), std::ios::binary | std::ios::in);
        file.seekg(offset, std::ios::beg);

        Core::RecordHeader header;
        file.read(reinterpret_cast<char*>(&header), sizeof(header));

        if (header.isDeleted == 1)
        {
            throw std::runtime_error("Record deleted");
        }

        T value;
        file.read(reinterpret_cast<char*>(&value), sizeof(T));
        return value;
    }
    void remove(T);
};
}
