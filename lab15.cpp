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
    array<Movie, SIZE> movie;
    ifstream fin ("input.txt");
    string w;
    int y;
    string t;
    int i = 0;
    
    if (fin.good()) {
        while (getline(fin,t)){
            fin >> y;
            fin.ignore();
            getline(fin,w);
            Movie tmp;
            tmp.setTitle(t);
            tmp.setYear(y);
            tmp.setWriter(w);
            movie[i] = tmp;
            i++;
        }
        fin.close();
    }
    else{
        cout << "File not found" << endl;
    }
    for (auto val : movie){
        val.print();
    }
    return 0;
 }