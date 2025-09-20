//COMSC 210 | Lab 12 | Anisha Rayapudi
//IDE used: VS 2022

#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <array>
using namespace std;

const int SIZE = 30;

int main () {
    array<int, SIZE> weather{};
    ifstream fin;
    fin.open("weather_data.txt");
    if (fin.good()){
        for (int i = 0; i < SIZE; i++){
            fin >> weather[i];
        }
        fin.close();

        cout << "1. Size: " << weather.size() <<endl;
        cout << "2. Values: ";
        for (int val:weather) cout << val << " ";
        cout << endl;
        cout << "3. Element 2: " << weather.at(2) << endl;
        cout << "4. Element 2: " << weather[2] << endl;
        cout << "5. Front: " << weather.front() << endl;
        cout << "6. Back: " << weather.back() << endl;
        cout << "Empty? " << (weather.empty()? "True" : "False") << endl;
        cout << "8. Address: " << weather.data() << endl;

        sort(weather.begin(), weather.end());
        cout <<"9. Sorted: ";
        for (int val : weather) cout << val << " ";
        cout << endl;
        sort(weather.rbegin(), weather.rend());
        cout << "10. Reverse sorted: ";
        for (int val : weather) cout << val << " ";
        cout << endl;

        int target = 59;
        array<int, SIZE>::iterator it;
        it = find(weather.begin(), weather.end(), target);
        cout << "11. Value " << target;
        if (it != weather.end()){
            cout << " found in position " << it - weather.begin() << endl;
        }
        else {
            cout <<" was not found " << endl;
        }

        cout << "12.Max: " << *max_element(weather.begin(), weather.end()) << endl;
        cout << "13.Min: " << *min_element(weather.begin(), weather.end()) << endl;
        cout << "14. Sum: " << accumulate(weather.begin(), weather.end(), 0) << endl;


    }
}