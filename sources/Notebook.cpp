#include "Notebook.hpp"

using namespace std; 
using ariel::Direction;

const int onehundred = 100, zero = 0, ninetynine = 99, thirtytwo = 32, onetwentysix = 126, onetwentyseven = 127;


namespace ariel
{
    void check_input(int num_page, int row, int num_col, Direction direction, int text_length)
    {
        if(direction == Direction::Horizontal && num_col + text_length > onehundred)
        {
            throw runtime_error("limit is 100 letters for row");
        }
        if(num_page < zero || row < zero || num_col < zero || text_length < zero)
        {
            throw runtime_error("only positive numbers to: page, row, col, text_length");
        }

        if(num_col > ninetynine)
        {
            throw runtime_error("max of col is 99");
        }
    }
    void check_correctness_text(string text){
        for(int i = 0; i < text.length(); i++){
            if(text[(unsigned int)i] < thirtytwo || text[(unsigned int)i] > onetwentysix){
                throw runtime_error("uncorrect symbol appears in text");
            }
        }
    }

    void Notebook::write(int num_page,  int row,  int column, Direction direction, string text)
    {
        // all checks in one function
        check_input(num_page, row, column, direction, int(text.length()));
        // checks text
        check_correctness_text(text);

        if(direction == Direction::Horizontal){
            for(int i=0; i<text.length(); i++){
                char letter = this->notebook[num_page][row][column+i];
                char letfromtxt = text[(unsigned int)i];
                if (letfromtxt == '~'){
                    throw runtime_error("You can't write '~' ");
                }
                if (letter != '_' && letter > thirtytwo && letter < onetwentyseven){
                    throw runtime_error("you can't write on the written text");
                }
                this->notebook[num_page][row][column+i] = letfromtxt;
            }
        }
        if(direction == Direction::Vertical){
            for(int i=0; i<text.length(); i++){
                char letter = this->notebook[num_page][row+i][column];
                char letfromtxt = text[(unsigned int)i];
                if (letfromtxt == '~'){
                    throw runtime_error("You can't write '~' ");
                }
                if(letter != '_' && letter > thirtytwo && letter < onetwentyseven){
                    throw runtime_error("you can't write on the written text");
                }
                this->notebook[num_page][row+i][column] = letfromtxt;
            }
        }

    }
    string Notebook::read(int num_page,  int row,  int column, Direction direction,  int text2read)
    {
        check_input(num_page, row, column, direction, text2read);
        string ans;
        if(direction == Direction::Horizontal){
            for(int i=0; i<text2read; i++){
                char letter = this->notebook[num_page][row][column+i];
                if(letter < thirtytwo || letter > onetwentysix){
                    ans+='_';
                }
                else{
                    ans += letter;
                }
            }
        }
        if(direction == Direction::Vertical){
            for(int i=0; i<text2read; i++){
                char letter = this->notebook[num_page][row+i][column];
                if(letter < thirtytwo || letter > onetwentysix){
                    ans+='_';
                }
                else{
                    ans += letter;
                }
                
            }
            // for(int i=0; i<text2read; i++){
            //     ans += this->notebook[num_page][row+i][column];
            // }
        }
        return ans;
    }
    void Notebook::erase(int num_page,  int row,  int column, Direction direction,  int text2read)
    {
        check_input(num_page, row, column, direction, text2read);
        if(direction == Direction::Horizontal){
            for(int i=0; i<text2read; i++){
                this->notebook[num_page][row][column+i] = '~';
            }
        }
        if(direction == Direction::Vertical){
            for(int i=0; i<text2read; i++){
                this->notebook[num_page][row+i][column] = '~';
            }
        }

    }
    
    void Notebook::show(int num_page){
        if(num_page < 0){
            throw runtime_error("only positive numbers");
        }
        for(int i = 0; i<onetwentysix; i++){
            cout<<i<<':'<<" ";
            for(int j = 0; j<onehundred; j++){
                char letter = this->notebook[num_page][i][j];
                if(letter < thirtytwo || letter > onetwentysix){
                    cout<<'_';
                }
                else{
                    cout<<letter;
                }
                
            }
            cout<<"\n";
        }
    }

}