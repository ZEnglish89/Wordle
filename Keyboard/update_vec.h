#ifndef UPDATE_VEC_H
#define UPDATE_VEC_H
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

vector<string> update(){
    vector<string> vec={TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET};
    string element;
    ifstream file;
    int i=0;
    file.open("letters.txt",ios::in);
    if(file.is_open()){
        while(getline(file,element)){
            switch(stoi(element)){
                case 0:
                case 1:
                vec[i]=element;
                break;
                case 3:
                vec[i]=(TEXTRESET);
                break;
                case 4:
                vec[i]=(TEXTGRAY);
                break;
                case 5:
                vec[i]=(TEXTYELLOW);
                break;
                case 6:
                vec[i]=(TEXTGREEN);
                break; 
            }
            i++;
        }
        file.close();
    }
    return (vec);
}
#endif