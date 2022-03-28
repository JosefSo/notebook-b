/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 *
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Josef Sokolov>
 *
 * Date: 2021-03
 */


#include <string>
#include <stdexcept>
#include <iostream>

#include "doctest.h"
#include "Direction.hpp"
#include "Notebook.hpp"

using namespace ariel;
using namespace std;

TEST_CASE("Good input")
{
	Notebook note;

	CHECK_NOTHROW(note.write(0, 0, 0, Direction::Vertical, "some_text"));
	CHECK_NOTHROW(note.write(0, 0, 0, Direction::Vertical, "some_text"));

	CHECK((note.read(0, 0, 0, Direction::Horizontal, 9)) == ("some_text"));
	CHECK((note.read(20, 0, 0, Direction::Horizontal, 9)) == ("some_text"));
	CHECK((note.read(60, 0, 0, Direction::Vertical, 9)) == ("some_text"));
	CHECK(note.read(0, 5, 0, Direction::Horizontal, 9) == "some_text");

	CHECK((note.read(0, 0, 0, Direction::Horizontal, 9)) == ("some_text"));
	CHECK((note.read(21, 0, 0, Direction::Horizontal, 9)) == ("some_text"));
	CHECK((note.read(61, 0, 0, Direction::Vertical, 9)) == ("some_text"));
	CHECK(note.read(50, 5, 0, Direction::Horizontal, 9) == "some_text");

	CHECK((note.read(10, 0, 0, Direction::Horizontal, 9)) == ("some_text"));
	CHECK((note.read(22, 0, 0, Direction::Horizontal, 9)) == ("some_text"));
	CHECK((note.read(62, 0, 0, Direction::Vertical, 9)) == ("some_text"));
	CHECK(note.read(11, 5, 0, Direction::Horizontal, 9) == "some_text");

	CHECK_NOTHROW(note.erase(0, 6, 0, Direction::Horizontal, 8));
	CHECK_NOTHROW(note.erase(6, 8, 0, Direction::Horizontal, 8));
}

TEST_CASE("bad input")
{
	Notebook note;

	CHECK_THROWS(note.read(0, 0, 10, Direction::Horizontal, 97));
	CHECK_THROWS(note.read(0, 0, 40, Direction::Horizontal, 90));
	CHECK_THROWS(note.read(0, 0, 1, Direction::Horizontal, 100));
	CHECK_THROWS(note.read(0, 0, 1, Direction::Horizontal, 110));

	CHECK_THROWS(note.erase(0, 0, 93, Direction::Horizontal, 10));
	CHECK_THROWS(note.erase(0, 0, 94, Direction::Horizontal, 10));
	CHECK_THROWS(note.erase(0, 0, 95, Direction::Horizontal, 10));
	CHECK_THROWS(note.erase(0, 0, 96, Direction::Horizontal, 10));
	CHECK_THROWS(note.erase(0, 0, 97, Direction::Horizontal, 10));
	CHECK_THROWS(note.erase(0, 0, 0, Direction::Horizontal, 110)); 

}