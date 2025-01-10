//
// Created by Balazsoficial on 2025. 01. 09..
//
#include <iostream>
#include <random>
#include <ctime>
#include <fstream>
#include <filesystem>
#include <string>
#include <windows.h>
using namespace ::std;
string GetTempFolder();
int Getmoney();
int Setmoney(int money);
void HandleBeting(int bet,int randomNumber,int guess);
void SetColor(int textColor, int backgroundColor);
int main()
{
    while (true)
    {
        cout <<  " ██████╗ █████╗ ███████╗██╗███╗   ██╗ ██████╗"<<endl;
        cout <<  "██╔════╝██╔══██╗██╔════╝██║████╗  ██║██╔═══██╗"<<endl;
        cout <<  "██║     ███████║███████╗██║██╔██╗ ██║██║   ██║"<<endl;
        cout <<  "██║     ██╔══██║╚════██║██║██║╚██╗██║██║   ██║"<<endl;
        cout <<  "╚██████╗██║  ██║███████║██║██║ ╚████║╚██████╔╝"<<endl;
        cout <<  "╚═════╝╚═╝  ╚═╝╚══════╝╚═╝╚═╝  ╚═══╝ ╚═════╝ "<<endl;


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
    cout << "Enter Your guess: ";
    cin >> guess;
        while (guess>36 or guess<0) {
            cout << "Enter Your guess (Between 0-36): ";
            cin >> guess;
        }

    cout << "Make a bet: ";
    cin >> bet;
    while (bet>Getmoney()) {
        cout << "Your bet cant be bigger than your money which you have: "<<Getmoney<<"$!\n";
        cout << "Make a bet: ";
        cin >> bet;
    }
    HandleBeting(bet,randomNumber,guess);

    if(guess == randomNumber) {
      cout << "You guessed correctly!\n";
      }
      else{
        cout << "your guess is wrong, the correct number is "<< randomNumber<<"!\n";
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
    while(getline(storage, money)){
            int moneyint =stoi(money);
        if (money.empty()) {
            moneyint = 1000;
        }

    return moneyint;
    }
}
int Setmoney(int money) {
    ofstream storage(GetTempFolder());
    storage.clear();
    storage <<money;
    storage.close();
    return 0;
}
void HandleBeting(int bet,int randomNumber,int guess) {
    int money = Getmoney();
    if (randomNumber!=guess) {
        money = money-bet;
        Setmoney(money);
    }


}
void SetColor(int textColor, int backgroundColor) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandle, textColor);
}