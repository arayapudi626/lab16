//COMSC 210 | Lab 11 | Anisha Rayapudi
//IDE used: VS 2022

#include <iostream>
#include <string>
using namespace std;

const int COUNTRIES = 3;

// struct definition for Country and each stores name, flight price,
//duration, dynamic array of favorite sights, number of favorite sights
struct Country {
    string name;
    double flightPrice;
    int duration;
    string*favSights;
    int numSights;
// destructor
    ~Country(){
        if (favSights)
            delete[] favSights;
            favSights= nullptr;
        }
    };
//function prototypes
void getCountry(Country* cptr, int num);
void displayCountry(Country* cptr);

int main (){
//array of Country structs
    Country * list = new Country[COUNTRIES];
    //get input of Country information and goes through loop of const number of countries
    for (int i = 0; i < COUNTRIES; i++){
        //passing pointer to each struct
        getCountry(&list[i], i+1);
    }
    //displaying country information
     cout <<'\n'<< "------Country summary-----" << '\n';
    for (int i = 0; i < COUNTRIES; i++) {
    displayCountry(&list[i]);
    }
    return 0;

}
//gets input of Country struct from user
//argument: pointer to Country struct and index for number of countries
//returns: none
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

    //dynamic array of favorite sights from user input
    cptr -> favSights = new string[cptr->numSights];
    for (int i = 0; i < cptr->numSights; i++){
        cout <<"Favorite sight #"<<(i+1)<<": ";
        getline(cin, *(cptr->favSights+i));
    }
    }
//displays the country struct information
//argument: pointer to Country struct
//returns: none
void displayCountry(Country* cptr){
    cout << "Country: " << cptr -> name << '\n';
    cout << "Flight price: $" << cptr->flightPrice << '\n';
    cout << "Days stayed: " << cptr->duration << '\n';
    cout << "Favorite sights (" << cptr->numSights << "): ";
    //conditional output if there were no favorite sights
    if (cptr->numSights == 0){
        cout << "no favorite sights :( ";
    }
    // outputs the favorite sights with pointer notation
    else {
        for (int i = 0; i < cptr->numSights; i++)
        {
          cout << *(cptr->favSights + i) << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}