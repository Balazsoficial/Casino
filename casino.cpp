//
// Created by Balazsoficial on 2025. 01. 09..
//
#include <iostream>
#include <random>
#include <ctime>
#include <fstream>
#include <string>
#include <windows.h>
#include <D:\Dokumentumok\Nuclear Launch Codes\cpp-console\casino\casino.h>
using namespace ::std;


int main() {
    SetConsoleOutputCP(CP_UTF8);
    while (true) {
        SetColor(2,15);
        cout <<  " ██████╗ █████╗ ███████╗██╗███╗   ██╗ ██████╗"<<endl;
        cout <<  "██╔════╝██╔══██╗██╔════╝██║████╗  ██║██╔═══██╗"<<endl;
        cout <<  "██║     ███████║███████╗██║██╔██╗ ██║██║   ██║"<<endl;
        cout <<  "██║     ██╔══██║╚════██║██║██║╚██╗██║██║   ██║"<<endl;
        cout <<  "╚██████╗██║  ██║███████║██║██║ ╚████║╚██████╔╝"<<endl;
        cout <<  "╚═════╝╚═╝  ╚═╝╚══════╝╚═╝╚═╝  ╚═══╝ ╚═════╝ "<<endl;

        ifstream test;
        test.open(GetTempFolder());
        if (test.is_open()) {
            test.close();


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
        int type;
        int randomNumber =1+(rand()%37);
        cout << "Your balance is :" <<Getmoney()<<"$!\n" << endl;
        cout  << "What do you want to play\n> 1. Select a number between 1 and 36!\n> 2. Even or odd!\n> 3. Black/Red/Green!\n> 4. 0/00\n> 5. 1st,2nd or 3d dozen! \nEnter your choice below: ";
        cin >> type;
        if (type == 1)
        {

            // cout <<"You have "<<Getmoney() <<"$!\n";
            cout << "Enter Your guess: ";
            cin >> guess;
            while (guess>36 or guess<1) {
                cout << "Enter Your guess (Between 1-36): ";
                cin >> guess;
            }

            cout << "Make a bet: ";
            cin >> bet;
            while (bet>Getmoney()) {
                cout << "Your bet cant be bigger than your money which you have: "<<Getmoney<<"$!\n";
                cout << "Make a bet: ";
                cin >> bet;
            }
            HandleBettingNumbers(bet,randomNumber,guess);

            if(guess == randomNumber) {
                Victory();
                cout << "The correct number was "<< randomNumber<<"!\n";
            }
            else{
                Loss();
                cout << "The correct number was "<< randomNumber<<"!\n";
            }
            cout << "press ctrl+c if you want to quit!\n";
            _sleep(1000);
            system("cls");

        }
        if (type == 2) {
            char eochoiche;
            //      cout <<"You have "<<Getmoney() <<"$!\n";
            cout << "Enter Your guess even(e) or odd(o):";
            cin >> eochoiche;
            while (eochoiche!='e' && eochoiche!='o') {
                cout << "Enter a valid character (e/o): ";
                cin >> eochoiche;
            }
            cout << "Make a bet: ";
            cin >> bet;
            while (bet>Getmoney()) {
                cout << "Your bet cant be bigger than your money which you have: "<<Getmoney<<"$!\n";
                cout << "Make a bet: ";
                cin >> bet;
            }
            HandleBettingEo(bet,randomNumber,eochoiche);
            if(randomNumber%2==0 && std::tolower(eochoiche)=='e' ||randomNumber%2==1 && std::tolower(eochoiche)=='o') {
                Victory();
                cout << "You guessed correctly, the number was: "<< randomNumber<<"!\n";
            }
            else{
                Loss();
                cout << "Your guess was wrong, the number was: "<< randomNumber<<"!\n";
            }
            cout << "press ctrl+c if you want to quit!\n";
            _sleep(1000);
            system("cls");


        }
        if (type == 3)
        {
            string strquess;
            //    cout <<"You have "<<Getmoney() <<"$!\n";
            cout << "Enter Your guess (Red or Black or Green): ";
            cin >> strquess;
            while (strquess!="Red" && strquess!="Black" && strquess!= "Green") {
                cout << "Enter Your guess (Red or Black or Green): ";
                cin >> strquess;
            }

            cout << "Make a bet: ";
            cin >> bet;
            while (bet>Getmoney()) {
                cout << "Your bet cant be bigger than your money which you have: "<<Getmoney<<"$!\n";
                cout << "Make a bet: ";
                cin >> bet;
            }
            HandleBettingColors(bet,randomNumber,strquess);
            if (randomNumber==0 && strquess=="Green"||randomNumber==37 && strquess=="Green") {
                Victory();
                GetColor(randomNumber,strquess);
            }
            if(IsRed(randomNumber) && strquess =="Red"||IsRed(randomNumber)==false && strquess =="Black") {
                Victory();
                GetColor(randomNumber,strquess);
            }
            else{
                Loss();
                GetColor(randomNumber, strquess);
            }
            cout << "press ctrl+c if you want to quit!\n";
            _sleep(1000);
            system("cls");

        }
        if (type == 6) {
            cout << "Reseting money file...\n";
            // filesystem::remove(GetTempFolder());
            remove(GetTempFolder().c_str());
            _sleep(500);
            cout << "Successfully reset money file!\n";
            system("cls");
        }
        if (type == 4)
        {

            string zeros;
            cout << "Enter Your guess: ";
            cin >> zeros;
            while (zeros!="0" && zeros!="00") {
                cout << "Enter Your guess zero or double zero: ";
                cin >> zeros;
            }
            if (zeros=="0") {
                guess = 0;
            }
            else if (zeros=="00") {
                guess = 37;
            }

            cout << "Make a bet: ";
            cin >> bet;
            while (bet>Getmoney()) {
                cout << "Your bet cant be bigger than your money which you have: "<<Getmoney<<"$!\n";
                cout << "Make a bet: ";
                cin >> bet;
            }
            HandleBettingNumbers(bet,randomNumber,guess);

            if(guess == randomNumber) {
                Victory();
                if (randomNumber == 37)
                {
                    cout << "The correct number was "<< "00"<<"!\n";}
            }
            else{
                Loss();
                if (randomNumber == 37){
                    cout << "The correct number was "<< randomNumber<<"!\n";}
            }
            cout << "press ctrl+c if you want to quit!\n";
            _sleep(1000);
            system("cls");

        }
        if (type == 5){

            string partitions;
            cout << "Enter Your guess: ";
            cin >> partitions;
            while (partitions!="1st" && partitions!="2nd" && partitions!="3rd") {
                cout << "Enter Your guess 1st 2nd or 3d 12 division: ";
                cin >> partitions;
            }


            cout << "Make a bet: ";
            cin >> bet;
            while (bet>Getmoney()) {
                cout << "Your bet cant be bigger than your money which you have: "<<Getmoney<<"$!\n";
                cout << "Make a bet: ";
                cin >> bet;
            }


            CheckPartitionWin(partitions, randomNumber, money,bet);

            cout << "press ctrl+c if you want to quit!\n";
            _sleep(1000);
            system("cls");
        }

    }
    return 0;
}
