//COMSC 210 | Lab 16 | Anisha Rayapudi
//IDE used: VS 2022

#include <iostream>
#include <iomanip>
#include <vector>
#include <array>
#include <fstream>
using namespace std;


class Color {
    private:
    int red;
    int green;
    int blue;

    public:
    Color () {red = 0; green = 0; blue =0;}
    Color (int r) {red = r; green = 0; blue = 0;} 
    Color (int r, int g, int b) {red = r; green = g; blue = b;}
    int getRed() {return red;}
    void setRed(int r) {red = r;}
    int getGreen() {return green;}
    void setGreen(int g) {green = g;}
    int getBlue() {return blue;}
    void setBlue(int b) {blue = b;}

    void print() {
        cout << "Color: " << red << ", " << green << ", " << blue << endl;
    }
};

int main () {
    Color c1;
    cout << "Default constructor: ";
    c1.print();

    Color c2(120);
    cout << "Partial constructor: ";
    c2.print();

    Color c3(120,120,120);
    cout << "Parameter constructor: ";
    c3.print();

}