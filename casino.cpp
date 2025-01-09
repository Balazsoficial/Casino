//
// Created by Balazsoficial on 2025. 01. 09..
//
#include <iostream>
#include <random>
#include <ctime>
#include <fstream>
#include <filesystem>
#include <string>
using namespace ::std;
string GetTempFolder();
int Getmoney();
int main()
{

    if (filesystem::exists(GetTempFolder())) {
        ifstream storage(GetTempFolder());
    }
    else {
        ofstream storage(GetTempFolder());
    }
    srand(time(nullptr));
    int guess;
    int money;
    int randomNumber =0+(rand()%36);
    cout <<"You have "<<Getmoney() <<"$!\n";
    cout << "Enter a number of your choice: ";
    cin >> guess;
    if(guess == randomNumber)
      {
      cout << "you guessed correctly!\n";
      }
      else
          //
        {
        cout << "your guess is wrong, the correct number is "<< randomNumber<<"!\n";
        }



    return 0;
}
string GetTempFolder() {
    filesystem::path templocation = filesystem::temp_directory_path();
    string path_string =templocation.string();
    string data ="/data.txt";
    string  temp = path_string + data;
    return temp;

}
int Getmoney() {
    string money;
    ifstream storage(GetTempFolder());
    while(getline(storage, money)) {
        if (money.empty()) {
            money =1000;
        }
    int moneyint =stoi(money);
    return moneyint;
    }
}