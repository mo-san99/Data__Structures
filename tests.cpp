#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "vector.hpp"
#include "vector.cpp"
#include <string>

TEST_CASE("Testing Vector Class") {

    Vector<int> numbers(3);
    SECTION("Testing Insertions using insert method and operator[]"){
        numbers.insert(1);
        numbers.insert(2);
        numbers.insert(3);

        REQUIRE(numbers[0] == 1);
        REQUIRE(numbers[2] == 3);

        numbers.insert(20);
        numbers.insert(30);
        REQUIRE(numbers[3] == 20);
        REQUIRE(numbers[4] == 30);

        numbers[0] = 100;
        REQUIRE(numbers[0] == 100);
        REQUIRE_THROWS(numbers[10]);
    }

    SECTION("Testing removeAt() / size() / isEmpty() methods "){
        numbers.insert(10);
        numbers.insert(20);
        numbers.insert(30);

        numbers.removeAt(0);
        REQUIRE(numbers[0] == 20);
        numbers.removeAt(1);
        REQUIRE(numbers.size() == 1);

        numbers.removeAt(0);
        REQUIRE(numbers.isEmpty());
    }

    SECTION("Testing some edge cases"){
        Vector<std::string> words;
        words.insert("no");
        words.insert("dreamer");
        words.insert("is");
        words.insert("too");
        words.insert("small");

        REQUIRE_THROWS(words.removeAt(100));
        REQUIRE_THROWS_AS(words[-1], std::runtime_error);
        REQUIRE(numbers.indexOf(-10) == -1);
        REQUIRE(numbers.indexOf(10) == -1);

    }

    SECTION("Testing set_intersection() and ==operator") {
        Vector<char> characters1 { 'x', 'b', 'c', 's'};
        Vector<char> characters2 { 'c', 'a', 'd', 'b'};

        auto other = characters1.set_intersection(characters2);
        REQUIRE(other == Vector<char> { 'c' , 'b' });
    }

    SECTION("Testing reverse() and ==operator"){
        Vector<int> EvenVector { 1, 2, 3, 4 };
        Vector<int> OddVector { 1, 2, 3, 4, 5 };

        OddVector.reverse();
        EvenVector.reverse();

        REQUIRE(EvenVector == Vector<int> { 4, 3, 2, 1 });
        REQUIRE(OddVector == Vector<int> { 5, 4, 3, 2, 1 });
    }

    SECTION("Testing insertAt()"){
        Vector<int> vector { 1, 2, 3, 4 };

        vector.insertAt(5, 1);
        REQUIRE(vector[1] == 5);
        REQUIRE(vector.size() == 5);

        vector.insertAt(6, 5);
        REQUIRE(vector[5] == 6);
        REQUIRE(vector == Vector<int> { 1, 5, 2, 3, 4, 6 });
    }
}

