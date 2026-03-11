#pragma once

#include "../Core/WorkFile.h";
#include "FileManager.h";

class IFileManager
{
public:
    ~IFileManager();

    int Write();
    int Read();
    void Delete();
};
