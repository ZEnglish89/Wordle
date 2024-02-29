#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H
#include "how_to_play.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <time.h>
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
    vector<string> keyboard={TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET,TEXTRESET};//the macros for the colors of the keyboard. This is lengthy, but it's just 26 for the 26 letters.
    vector<string> lettercolor={"","","","",""}; //the colors for the five letters in the word, starting blank.

    ofstream key;
    key.open("../keyboard/letters.txt",ios::out);
    if(key.is_open()){
        for(int i=0;i<keyboard.size();i++){
            key<<3<<endl;
//           string code=keyboard[i];
//            key<<code<<endl;
        }
        key.close();
    } //start each game by making all of the keys on the keyboard white, because no letters have been guessed yet.
    srand(time(0)); //seeding random based on the current time, so it doesn't give consistent values playthrough to playthrough.
    int randomnumber= rand()%2314; //picking which word will be the solution.
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
    } //finding the word, as well as adding all of the words to the pool of valid guesses.
    allowed.open("allowed.txt",ios::in);
    if(allowed.is_open()){
        while(getline(allowed,element)){
            validguesses.push_back(element);
        }
        allowed.close();
    }//adding the items which are not words, but still valid guesses, to the pool of valid guesses.
    system("CLS");
    while(numguesses<6){
        cout<<"Enter Guess: ";
        cin>>guess;
        cout<<"\033[1A"<<"\033[2K"<<"\033[0G"; //the code to clear one line, so the "enter guess" prompt doesn't stay.
        if(find(validguesses.begin(),validguesses.end(),guess)!=validguesses.end()){ // if the guess can be found within the pool of valid guesses, continue with the game. Otherwise, the gamelogic is skipped and the while loop iterates, allowing you to reguess with no penalty.
            numguesses++;
            for(int i=0;i<5;i++){
                guess[i]=toupper(guess[i]);
                answer[i]=toupper(answer[i]);
            } //case insensitive.
            for(int i=0;i<5;i++){
                lettercolor[i]=TEXTGRAY;//Assume the letter does not appear, then change it if it does.
                for(int j=0;j<5;j++){
                    if(guess[i]==answer[j]){ //if the letter matches one of the letters within the word.
                        if(i==j){//if the letter is exactly where it should be.
                            lettercolor[i]=TEXTGREEN;
                            correctletters++;
                            break;//add to the number of letters that are in the right spot, and move on to the next letter.
                        }
                        else{//if the letter is in the wrong spot.
                            lettercolor[i]=TEXTYELLOW;
                        }
                    }
                }
                if(keyboard[int(guess[i])-65]!=TEXTGREEN)
                    keyboard[int(guess[i])-65]=lettercolor[i]; //Update the keyboard macros to match the colors of the letters you just guessed. However, if you've already turned a letter green, it will remain green even if you put it somewhere else in a later guess.
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
            } //Write the updated keyboard colors out to the keyboard file. Because of some fuckery on my part, 3 corresponds to white, 4 to gray, etc.
            PrintGuess(guess,lettercolor); //print the guess the player just made, properly formatted and matching the colors.
            if(correctletters==5){
                victory=true;
                break;
            }//If all five letters are correct, the player wins, and you stop the game.
            else
                correctletters=0;
            lettercolor={"","","","",""};//otherwise, reset the letters and colors for the next guess and loop.
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
    }//update the stats file with the results of the current game.
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
    }//When you hit enter, notify the keyboard that the game has ended and then return to the menu.
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