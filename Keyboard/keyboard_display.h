#ifndef KEYBOARD_DISPLAY_H
#define KEYBOARD_DISPLAY_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#define TEXTRESET "\033[0m"
#define TEXTGREEN "\033[32m"
#define TEXTYELLOW "\033[33m"
#define TEXTGRAY "\033[90m"
using namespace std;
void DisplayKeyboard(vector<string> lettercolors,vector<int> indexes){
    for(int i=0;i<indexes.size();i++){
        lettercolors[indexes[i]]=TEXTGREEN;
    }
    cout<<lettercolors[int('Q')-65]<<" --- "<<TEXTRESET<<lettercolors[int('W')-65]<<" --- "<<TEXTRESET<<lettercolors[int('E')-65]<<" --- "<<TEXTRESET<<lettercolors[int('R')-65]<<" --- "<<TEXTRESET<<lettercolors[int('T')-65]<<" --- "<<TEXTRESET<<lettercolors[int('Y')-65]<<" --- "<<TEXTRESET
    <<lettercolors[int('U')-65]<<" --- "<<TEXTRESET<<lettercolors[int('I')-65]<<" --- "<<TEXTRESET<<lettercolors[int('O')-65]<<" --- "<<TEXTRESET<<lettercolors[int('P')-65]<<" ---"<<TEXTRESET<<endl;

    cout<<lettercolors[int('Q')-65]<<"| Q |"<<TEXTRESET<<lettercolors[int('W')-65]<<"| W |"<<TEXTRESET<<lettercolors[int('E')-65]<<"| E |"<<TEXTRESET<<lettercolors[int('R')-65]<<"| R |"<<TEXTRESET<<lettercolors[int('T')-65]<<"| T |"<<TEXTRESET<<lettercolors[int('Y')-65]<<"| Y |"<<TEXTRESET
    <<lettercolors[int('U')-65]<<"| U |"<<TEXTRESET<<lettercolors[int('I')-65]<<"| I |"<<TEXTRESET<<lettercolors[int('O')-65]<<"| O |"<<TEXTRESET<<lettercolors[int('P')-65]<<"| P |"<<TEXTRESET<<endl;

    cout<<lettercolors[int('Q')-65]<<" --- "<<TEXTRESET<<lettercolors[int('W')-65]<<" --- "<<TEXTRESET<<lettercolors[int('E')-65]<<" --- "<<TEXTRESET<<lettercolors[int('R')-65]<<" --- "<<TEXTRESET<<lettercolors[int('T')-65]<<" --- "<<TEXTRESET<<lettercolors[int('Y')-65]<<" --- "<<TEXTRESET
    <<lettercolors[int('U')-65]<<" --- "<<TEXTRESET<<lettercolors[int('I')-65]<<" --- "<<TEXTRESET<<lettercolors[int('O')-65]<<" --- "<<TEXTRESET<<lettercolors[int('P')-65]<<" ---"<<TEXTRESET<<endl;


    cout<<lettercolors[int('A')-65]<<"   --- "<<TEXTRESET<<lettercolors[int('S')-65]<<" --- "<<TEXTRESET<<lettercolors[int('D')-65]<<" --- "<<TEXTRESET<<lettercolors[int('F')-65]<<" --- "<<TEXTRESET<<lettercolors[int('G')-65]<<" --- "<<TEXTRESET<<lettercolors[int('H')-65]<<" --- "<<TEXTRESET
    <<lettercolors[int('J')-65]<<" --- "<<TEXTRESET<<lettercolors[int('K')-65]<<" --- "<<TEXTRESET<<lettercolors[int('L')-65]<<" ---"<<TEXTRESET<<endl;

    cout<<lettercolors[int('A')-65]<<"  | A |"<<TEXTRESET<<lettercolors[int('S')-65]<<"| S |"<<TEXTRESET<<lettercolors[int('D')-65]<<"| D |"<<TEXTRESET<<lettercolors[int('F')-65]<<"| F |"<<TEXTRESET<<lettercolors[int('G')-65]<<"| G |"<<TEXTRESET<<lettercolors[int('H')-65]<<"| H |"<<TEXTRESET
    <<lettercolors[int('J')-65]<<"| J |"<<TEXTRESET<<lettercolors[int('K')-65]<<"| K |"<<TEXTRESET<<lettercolors[int('L')-65]<<"| L |"<<TEXTRESET<<endl;

    cout<<lettercolors[int('A')-65]<<"   --- "<<TEXTRESET<<lettercolors[int('S')-65]<<" --- "<<TEXTRESET<<lettercolors[int('D')-65]<<" --- "<<TEXTRESET<<lettercolors[int('F')-65]<<" --- "<<TEXTRESET<<lettercolors[int('G')-65]<<" --- "<<TEXTRESET<<lettercolors[int('H')-65]<<" --- "<<TEXTRESET
    <<lettercolors[int('J')-65]<<" --- "<<TEXTRESET<<lettercolors[int('K')-65]<<" --- "<<TEXTRESET<<lettercolors[int('L')-65]<<" ---"<<TEXTRESET<<endl;


    cout<<lettercolors[int('Z')-65]<<"        --- "<<TEXTRESET<<lettercolors[int('X')-65]<<" --- "<<TEXTRESET<<lettercolors[int('C')-65]<<" --- "<<TEXTRESET<<lettercolors[int('V')-65]<<" --- "<<TEXTRESET<<lettercolors[int('B')-65]<<" --- "<<TEXTRESET<<lettercolors[int('N')-65]<<" --- "<<TEXTRESET
    <<lettercolors[int('M')-65]<<" ---"<<TEXTRESET<<endl;

    cout<<lettercolors[int('Z')-65]<<"       | Z |"<<TEXTRESET<<lettercolors[int('X')-65]<<"| X |"<<TEXTRESET<<lettercolors[int('C')-65]<<"| C |"<<TEXTRESET<<lettercolors[int('V')-65]<<"| V |"<<TEXTRESET<<lettercolors[int('B')-65]<<"| B |"<<TEXTRESET<<lettercolors[int('N')-65]<<"| N |"<<TEXTRESET
    <<lettercolors[int('M')-65]<<"| M |"<<TEXTRESET<<endl;

    cout<<lettercolors[int('Z')-65]<<"        --- "<<TEXTRESET<<lettercolors[int('X')-65]<<" --- "<<TEXTRESET<<lettercolors[int('C')-65]<<" --- "<<TEXTRESET<<lettercolors[int('V')-65]<<" --- "<<TEXTRESET<<lettercolors[int('B')-65]<<" --- "<<TEXTRESET<<lettercolors[int('N')-65]<<" --- "<<TEXTRESET
    <<lettercolors[int('M')-65]<<" ---"<<TEXTRESET<<endl;
    return;

}
#endif