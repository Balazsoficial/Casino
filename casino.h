//
// Created by Balazsoficial on 2025. 01. 19..
//
#include <iostream>
#include <string>
using namespace std;
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
void CheckPartitionWin(string partitions, int Randomnum, int money, int bet) {

        if  (partitions=="1st" && Randomnum<=12) {
            Victory();
            money = money-bet;
            money =money+(2*bet);
            Setmoney(money);
            cout << Randomnum;
        }
        else if (partitions=="2nd" && Randomnum<=24 && Randomnum>12) {
            Victory();
            money = money-bet;
            money =money+(2*bet);
            Setmoney(money);
        }
        else if (partitions=="3rd" && Randomnum<=36 && Randomnum>24) {
            Victory();
            money = money-bet;
            money =money+(2*bet);
            Setmoney(money);
        }
        else {
            Loss();
            money = money-bet;
            Setmoney(money);
        }


    }




