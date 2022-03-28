#include <iostream>
#include <string>
#include "Direction.hpp"
#include <stdexcept>
#include <unordered_map>

using namespace std;

namespace ariel
{
    class Notebook
    {
        private:
            //unordered_map <int, unordered_map <int, char[100]>> notebook;
        public:
            unordered_map <int, unordered_map <int, char[100]>> notebook;
            // constructor
            Notebook(){}
            // destructor
            ~Notebook(){}

            void write(int num_page,  int row,  int column, Direction direction, string text);
            string read( int num_page,  int row,  int column, Direction dir,  int text2read);
            void erase( int num_page,  int row,  int column, Direction dir,  int text2read);
            void show( int num_page);

    };

}