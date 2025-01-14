//
// Created by Balazsoficial on 2025. 01. 09..
//
#include <iostream>
#include <random>
#include <ctime>
#include <fstream>
#include <string>
#include <windows.h>
using namespace ::std;
string GetTempFolder();
int Getmoney();
int Setmoney(int money);
void HandleBettingNumbers(int bet,int randomNumber,int guess);
void SetColor(int textColor, int backgroundColor);
bool IsEven (int Number);
void HandleBettingEo(int bet,int randomNum,char guess);
void Victory();
void Loss();
bool IsRed(int randomNum);
void HandleBettingColors(int bet,int randomNum,string guess);
void GetColor(int RandomNum,string strguess);
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
        cout  << "What do you want to play\n> 1. Select a number between 1 and 36!\n> 2. Even or odd!\n> 3. Black/Red/Green!\n> 4. 0/00 \nEnter your choice below: ";
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
        if (type == 5) {
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
        return 0;
    }
}

string GetTempFolder() {

        /* Old path finding
            char cPath[MAX_PATH];
            if (GetTempPathA(MAX_PATH, cPath))
            strTempPath =cPath;*/

    string  Tempdir = getenv("TEMP");
    string  TempLoc = Tempdir + "/data.txt";
    return TempLoc;
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
void HandleBettingNumbers(int bet,int randomNumber,int guess) {
    int money = Getmoney();
    if (randomNumber!=guess) {
        money = money-bet;
        Setmoney(money);
    }
    else {
        money = money-bet;
        money =money+(2*bet);
        Setmoney(money);

    }


}
void SetColor(int textColor, int backgroundColor) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandle, textColor);
}
bool IsEven(int Number) {
    if (Number % 2 == 0) {
        return true;
    }
    else {
       return false;
    }
}
void HandleBettingEo(int bet,int randomNumber,char guess) {
    int money = Getmoney();
    if (randomNumber%2==0 && std::tolower(guess)=='o' ||randomNumber%2==1 && std::tolower(guess)=='e') {
        money = money-bet;
        Setmoney(money);
    }
    else {
        money = money-bet;
        money =money+(2*bet);
        Setmoney(money);
    }


}
void Victory() {
    cout <<"██╗   ██╗ ██████╗ ██╗   ██╗    ██╗    ██╗ ██████╗ ███╗   ██╗██╗"<<endl;
    cout <<"╚██╗ ██╔╝██╔═══██╗██║   ██║    ██║    ██║██╔═══██╗████╗  ██║██║"<<endl;
    cout <<" ╚████╔╝ ██║   ██║██║   ██║    ██║ █╗ ██║██║   ██║██╔██╗ ██║██║"<<endl;
    cout <<"  ╚██╔╝  ██║   ██║██║   ██║    ██║███╗██║██║   ██║██║╚██╗██║╚═╝"<<endl;
    cout <<"   ██║   ╚██████╔╝╚██████╔╝    ╚███╔███╔╝╚██████╔╝██║ ╚████║██╗"<<endl;
    cout <<"   ╚═╝    ╚═════╝  ╚═════╝      ╚══╝╚══╝  ╚═════╝ ╚═╝  ╚═══╝╚═╝"<<endl;


}
void Loss() {
     cout <<"██╗   ██╗ ██████╗ ██╗   ██╗    ██╗      ██████╗ ███████╗████████╗██╗"<<endl;
     cout <<"╚██╗ ██╔╝██╔═══██╗██║   ██║    ██║     ██╔═══██╗██╔════╝╚══██╔══╝██║"<<endl;
     cout <<" ╚████╔╝ ██║   ██║██║   ██║    ██║     ██║   ██║███████╗   ██║   ██║"<<endl;
     cout <<"  ╚██╔╝  ██║   ██║██║   ██║    ██║     ██║   ██║╚════██║   ██║   ╚═╝"<<endl;
     cout <<"   ██║   ╚██████╔╝╚██████╔╝    ███████╗╚██████╔╝███████║   ██║   ██╗"<<endl;
     cout <<"   ╚═╝    ╚═════╝  ╚═════╝     ╚══════╝ ╚═════╝ ╚══════╝   ╚═╝   ╚═╝"<<endl;
}
bool IsRed(int randomNum) {
    switch (randomNum) {
        case 1: return true;
        case 2: return false;
        case 3: return true;
        case 4: return false;
        case 5: return true;
        case 6: return false;
        case 7: return true;
        case 8: return false;
        case 9: return true;
        case 10: return false;
        case 11: return false;
        case 12: return true;
        case 13: return false;
        case 14: return true;
        case 15: return false;
        case 16: return true;
        case 17: return false;
        case 18: return true;
        case 19: return true;
        case 20: return false;
        case 21: return true;
        case 22: return false;
        case 23: return true;
        case 24: return false;
        case 25: return true;
        case 26: return false;
        case 27: return true;
        case 28: return false;
        case 29: return false;
        case 30: return true;
        case 31: return false;
        case 32: return true;
        case 33: return false;
        case 34: return true;
        case 35: return false;
        case 36: return true;

    }
}
void HandleBettingColors(int bet,int randomNum,string guess) {
    int money = Getmoney();
    if (IsRed(randomNum) && guess =="Red"||IsRed(randomNum)==false && guess =="Black") {
        money = money-bet;
        money =money+(2*bet);
        Setmoney(money);

    }
    else {
        money = money-bet;
        Setmoney(money);
    }

}
void GetColor(int RandomNum,string strguess) {
    if (IsRed(RandomNum)==true) {
        cout << "The correct color was red!\n";
    }
    else if (IsRed(RandomNum)==false) {
        cout << "The correct color was black!\n";
    }
    else if (RandomNum==0 && strguess=="Green"||RandomNum==37 && strguess=="Green") {
        cout << "The correct color was green!\n";
    }
}



