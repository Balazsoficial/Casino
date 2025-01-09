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
    while (true)
    {
    if (filesystem::exists(GetTempFolder())) {
        ifstream storage(GetTempFolder());
    }
    else {
        ofstream storage(GetTempFolder());
        storage << 1000;
    }
    srand(time(nullptr));
    int guess;
    int bet;
    int money =Getmoney();
    int randomNumber =0+(rand()%36);
    cout <<"You have "<<Getmoney() <<"$!\n";
    cout << "Enter a number of your choice: ";
    cin >> guess;
    cout << "Make a bet: ";
    cin >> bet;
    while (bet>Getmoney()) {
        cout << "Your bet cant be bigger than your money which you have: "<<Getmoney<<"$!\n";
        cout << "Make a bet: ";
        cin >> bet;

    }
    if(guess == randomNumber)
      {
      cout << "You guessed correctly!\n";
       money = money +bet*2;
        bet =0;
        filesystem::remove(filesystem::path(GetTempFolder()));
        ofstream storage(GetTempFolder());
        storage << money;
      }
      else

        {
        cout << "your guess is wrong, the correct number is "<< randomNumber<<"!\n";
          bet =0;
          filesystem::remove(filesystem::path(GetTempFolder()));
          ofstream storage(GetTempFolder());
          storage << money;
        }


    cout << "press ctrl+c if you want to quit!\n";
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
            exit(1);
        }
    int moneyint =stoi(money);
    return moneyint;
    }
}