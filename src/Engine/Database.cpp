#include "../../include/hellnah/Engine/Database.h"
#include "../../include/hellnah/Storage/FileStorage.h"

Database::Database(const char *path)
{
    FileStorage::OpenFile(path);
}