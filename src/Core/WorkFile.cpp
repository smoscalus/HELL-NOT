#include "../../include/hellnah/Core/WorkFile.h"
#include "../../include/hellnah/Core/DbHeader.h"
#include "../../include/hellnah/Storage/FileStorage.h"

#include <cstring>

using namespace Storage::FileStorage;

WorkFile::WorkFile(const char *path)
{
    if (!is_exists_file(path))
    {
        create_file(path);
    }
    else
    {
        read_file(path);
    }

    strcpy(Value, path);
}
