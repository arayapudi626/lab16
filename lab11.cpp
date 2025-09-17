#include <iostream>
#include <string>
using namespace std;

const int COUNTRIES = 3;

struct Country {
    string name;
    double flightPrice;
    int duration;
    string*favSights;
    int numSights;

    ~Country(){
        if (favSights)
            delete[] favSights;
            favSights= nullptr;
        }
    };

void getCountry(Country* cptr, int num);
void displayCountry(Country* cptr);

int main (){

    Country * list = new Country[COUNTRIES];
    for (int i = 0; i < COUNTRIES; i++){
        getCountry(&list[i], i+1);
    }
     cout <<'\n'<< "------Country summary-----" << '\n';
    for (int i = 0; i < COUNTRIES; i++) {
    displayCountry(&list[i]);
    }
    return 0;

}

void getCountry(Country* cptr, int num){
    cout << "Country #" << num << '\n';
    cout << "Name: ";
    getline(cin, cptr->name);
    cout << "Flight price from US: ";
    cin >> cptr->flightPrice;
    cout << "Duration in days: ";
    cin >> cptr->duration;
    cout <<"How many favorite sights? ";
    cin >> cptr->numSights;
    cin.ignore();

    cptr -> favSights = new string[cptr->numSights];
    for (int i = 0; i < cptr->numSights; i++){
        cout <<"Favorite sight #"<<(i+1)<<": ";
        getline(cin, *(cptr->favSights+i));
    }
    cin.ignore();
    }

void displayCountry(Country* cptr){
    cout << "Country: " << cptr -> name << '\n';
    cout << "Flight price: $" << cptr->flightPrice << '\n';
    cout << "Days stayed: " << cptr->duration << '\n';
    cout << "Favorite sights (" << cptr->numSights << "): ";
    if (cptr->numSights == 0){
        cout << "no favorite sights :( ";
    }
    else {
        for (int i = 0; i < cptr->numSights; i++)
        {
          cout << *(cptr->favSights + i) << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}