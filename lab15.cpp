//COMSC 210 | Lab 15 | Anisha Rayapudi
//IDE used: VS 2022

#include <iostream>
#include <iomanip>
#include <array>
#include <fstream>
using namespace std;
const int SIZE = 4;

 class Movie{
    private:
    string writer;
    int year;
    string title;

    public:
    string getWriter() {return writer;}
    void setWriter(string w) {writer = w;}
    int getYear() {return year;}
    void setYear(int y) {year = y;}
    string getTitle() {return title;}
    void setTitle(string t) {title = t;}

    void print(){
        cout << "Movie: " << title << endl;
        cout << "Year released: " << year << endl;
        cout << "Screenwriter: " << writer << endl;
    }
 };

 int main(){
    
 }