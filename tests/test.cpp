#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "../include/hellnah/Engine/Database.h"

struct student
{
    char Value[32];
    int Age;
};

TEST_CASE("Insert works") {

    auto db = Engine::Database("test_students.hellnot");

    auto students = db.open_table<student>("students");

    auto id = students.insert({"Alex", 20});
    auto student = students.get(id);

    REQUIRE(students.quantity == 1);
    REQUIRE(strcmp(student.Value, "Alex") == 0);
    REQUIRE(student.Age == 20);
}
