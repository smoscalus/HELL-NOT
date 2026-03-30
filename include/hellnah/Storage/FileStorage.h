#pragma once

#include "../Core/WorkFile.h"

namespace Storage
{
    class FileStorage
    {
    public:

        static void create_file(const char *path);
        static void read_file(const char *path);
        static int is_exists_file(const char *path);

        int add();
        int get();
        void remove();
    };
};
