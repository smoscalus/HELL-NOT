#pragma once

#include "../Core/WorkFile.h";
#include "IFileManager.h";

class FileManager : public IFileManager
{
    WorkFile _workFile;

private:
    FileManager(const char *path) : _workFile(path) {};

public:
    static FileManager InitFile(const char *path)
    {
        // validation
        return FileManager(path);
    };

};
