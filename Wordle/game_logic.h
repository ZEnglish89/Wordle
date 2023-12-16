#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H
#include "how_to_play.h"
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
void PrintGuess(string guess, vector<string> lettercolor);
void RunGame(){
    vector<string> validguesses;
    string element;
    int numguesses=0;
    int correctletters=0;
    string answer;
    bool victory=false;
    string guess;
    ifstream file;
    ifstream allowed;
    vector<string> keyboard={TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET};
    vector<string> lettercolor={"","","","",""};
    ofstream key;
    key.open("../keyboard/letters.txt",ios::out);
    if(key.is_open()){
        for(int i=0;i<keyboard.size();i++){
            key<<3<<endl;
//           string code=keyboard[i];
//            key<<code<<endl;
        }
        key.close();
    }
    srand(time(0));
    int randomnumber= rand()%2314;
    file.open("words.txt",ios::in);
    if(file.is_open()){
        int increments=0;
        while(getline(file,element)){
            validguesses.push_back(element);
            increments++;
            if(increments==randomnumber)
                answer=element;
        }
        file.close();
    }
    allowed.open("allowed.txt",ios::in);
    if(allowed.is_open()){
        while(getline(allowed,element)){
            validguesses.push_back(element);
        }
        allowed.close();
    }
    system("CLS");
    while(numguesses<6){
        cout<<"Enter Guess: ";
        cin>>guess;
        cout<<"\033[1A"<<"\033[2K"<<"\033[0G";
        if(find(validguesses.begin(),validguesses.end(),guess)!=validguesses.end()){
            numguesses++;
            for(int i=0;i<5;i++){
                guess[i]=toupper(guess[i]);
                answer[i]=toupper(answer[i]);
            }
            for(int i=0;i<5;i++){
                for(int j=0;j<5;j++){
                    if(lettercolor[i]==""){
                        lettercolor[i]=TEXTGRAY;
                    }
                    if(guess[i]==answer[j]){
                        if(i==j){
                            lettercolor[i]=TEXTGREEN;
                            correctletters++;
                            break;
                        }
                        else{
                            lettercolor[i]=TEXTYELLOW;
                        }
                    }
                }
                if(keyboard[int(guess[i])-65]!=TEXTGREEN)
                    keyboard[int(guess[i])-65]=lettercolor[i];
            }
            key.open("../keyboard/letters.txt",ios::out);
            if(key.is_open()){
                for(int i=0;i<keyboard.size();i++){
                if(keyboard[i]==TEXTRESET)
                    key<<3<<endl;
                else if(keyboard[i]==TEXTGRAY)
                    key<<4<<endl;
                else if(keyboard[i]==TEXTYELLOW)
                    key<<5<<endl;
                else if(keyboard[i]==TEXTGREEN)
                    key<<6<<endl;
                }
                key.close();
            }
            PrintGuess(guess,lettercolor);
            if(correctletters==5){
                victory=true;
                break;
            }
            else
                correctletters=0;
            lettercolor={"","","","",""};
        }
    }
    if(victory){
        cout<<"Congratulations!"<<endl;
    }
    else{
        cout<<"The word was: "<<answer<<endl<<endl;
        cout<<"Better luck next time!"<<endl;
    }
    ofstream stats;
    stats.open("stats.txt",ios::app);
    if(stats.is_open()){
        stats<<answer<<","<<numguesses<<","<<victory<<endl;
        stats.close();
    }
    cout<<endl<<"Press [enter] to continue"<<endl;
    while(true){
        cin.ignore();
        if(cin.get()=='\n'){
            key.open("../keyboard/letters.txt",ios::out);
            if(key.is_open()){
                key<<"0"<<endl;
            key.close();
            }
            return;
        }
    }
}
void PrintGuess(string guess,vector<string>lettercolor){
    for(int i=0;i<5;i++){
        cout<<TEXTRESET<<lettercolor[i]<<" --- "<<TEXTRESET;
    }
    cout<<endl;
    for(int i=0;i<5;i++){
        cout<<TEXTRESET<<lettercolor[i]<<"| "<<guess[i]<<" |"<<TEXTRESET;
    }
    cout<<endl;
    for(int i=0;i<5;i++){
        cout<<TEXTRESET<<lettercolor[i]<<" --- "<<TEXTRESET;
    }
    cout<<endl;
}
#endif