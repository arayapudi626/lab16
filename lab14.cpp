//COMSC 210 | Lab 14 | Anisha Rayapudi
//IDE used: VS 2022

#include <iostream>
#include <iomanip>
#include <vector>
#include <array>
#include <fstream>
using namespace std;

const int SIZE = 5;

class Color {
    private:
    int red;
    int green;
    int blue;

    public:
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
    array<Color,SIZE> colors;
    ifstream fin("colors.txt");
    int r, g, b;
    int i = 0;

    if (fin.good()) {
        while(fin >> r >> g >> b && i < SIZE) {
            colors[i].setRed(r);
            colors[i].setGreen(g);
            colors[i].setBlue(b);
            i++;
        }
        fin.close();
    }
    else{
        cout << "File not found" << endl;
    }
    for (auto val : colors) {
        val.print();
    }
    return 0;
}