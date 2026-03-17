#pragma once

#include "../Core/WorkFile.h"

class FileStorage
{
    WorkFile _workFile;

private:
    FileStorage(const char *path) : _workFile(path) {};

public:
    static FileStorage OpenFile(const char *path);

    int add();

    int get();

    void remove();
};
