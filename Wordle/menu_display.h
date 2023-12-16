#ifndef MENU_DISPLAY_H
#define MENU_DISPLAY_H
#include <string>
#include <vector>
#include <iostream>
using namespace std;
char DisplayMainMenu(){
    string s;
    char selection;
    system("CLS");
    cout<<"========================="<<endl;
    cout<<"    WELCOME TO WORDLE    "<<endl;
    cout<<"========================="<<endl<<endl<<endl;
    cout<<"1. Play Wordle"<<endl;
    cout<<"2. How to Play"<<endl;
    cout<<"3. Statistics Summary"<<endl;
    cout<<"4. Reset Statistics"<<endl;
    cout<<"5. Exit"<<endl<<endl<<endl;
    cout<<"Select an option:";
    cin>>s;
    if(s.length()!=1)
        s="";
    selection=s[0];
    return (selection);
}
#endif