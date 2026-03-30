#include <iostream>
#include "../include/hellnah/Engine/Database.h"

using namespace std;

struct student
{
    char Value[32] = "vasya";
    int age = 10;
};

int main()
{
    auto db = Database("students.hellnot");

    auto students = db.open_table<student>("students");
}
