#ifndef HOW_TO_PLAY_H
#define HOW_TO_PLAY_H
#include <iostream>
#define TEXTRESET "\033[0m"
#define TEXTGREEN "\033[32m"
#define TEXTYELLOW "\033[33m"
#define TEXTGRAY "\033[90m"
using namespace std;
void HowToPlay(){
    system("CLS");
    cout<<"============================================="<<endl;
    cout<<"                 HOW TO PLAY                 "<<endl;
    cout<<"============================================="<<endl;
    cout<<"Guess the Wordle in six tries."<<endl<<endl<<endl;
    cout<<"HOW TO PLAY:"<<endl;
    cout<<"- Each guess must be a valid 5 letter word."<<endl;
    cout<<"- The color of the tiles will change to show"<<endl;
    cout<<"  you how close your guess was to the word."<<endl<<endl<<endl;
    cout<<TEXTGREEN<<" --- "<<TEXTRESET<<" ---  ---  ---  --- "<<endl;
    cout<<TEXTGREEN<<"| W |"<<TEXTRESET<<"| E || A || R || Y |"<<endl;
    cout<<TEXTGREEN<<" --- "<<TEXTRESET<<" ---  ---  ---  --- "<<endl;
    cout<<"W is in the word and in the correct spot."<<endl<<endl;
    cout<<" --- "<<TEXTYELLOW<<" --- "<<TEXTRESET<<" ---  ---  --- "<<endl;
    cout<<"| P |"<<TEXTYELLOW<<"| I |"<<TEXTRESET<<"| L || L || S |"<<endl;
    cout<<" --- "<<TEXTYELLOW<<" --- "<<TEXTRESET<<" ---  ---  --- "<<endl;
    cout<<"I is in the word but in the wrong spot."<<endl<<endl;
    cout<<" ---  ---  --- "<<TEXTGRAY<<" --- "<<TEXTRESET<<" --- "<<endl;
    cout<<"| V || A || G |"<<TEXTGRAY<<"| U |"<<TEXTRESET<<"| E |"<<endl;
    cout<<" ---  ---  --- "<<TEXTGRAY<<" --- "<<TEXTRESET<<" --- "<<endl;
    cout<<"U is not in the word in any spot."<<endl<<endl<<endl;
    cout<<"Press [enter] to continue"<<endl;
    while(true){
        cin.ignore();
        if(cin.get()=='\n')
            return;
    }
}
#endif