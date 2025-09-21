//COMSC 210 | Lab 13 | Anisha Rayapudi
//IDE used: VS 2022

#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

const int SIZE = 30;

int main () {
    vector<int> weather;
    ifstream fin;

    fin.open("C:\\Users\\rayap\\Documents\\Visual Studio 2022\\COMSC-210\\weather_data.txt");
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
        vector<int>::iterator it;
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

        vector<int> temp(5);
        fill(temp.begin(), temp.end(), 0);
        cout << "Weather filled with 0: ";
        for (int val : weather) cout << val << " ";
        cout << endl;

        weather.swap(temp);
        cout << "17. Swapped: ";
        for (int val : weather) cout << val << " ";
        cout << endl;


    }
    else {
        cout << "File not found";
    }
    return 0;
}