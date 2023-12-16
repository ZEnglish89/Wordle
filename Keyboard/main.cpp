#include "keyboard_display.h"
#include "update_vec.h"
#include <iostream>
#include <vector>
#include <string>
#define TEXTGREEN "\033[32m"

using namespace std;

int main(int argc, char* argv[]) {
    vector<int> indexes;
    vector<string> keys;
    vector<string> recent;  
    while(true){
        bool escape=true;
        while(escape){
            recent=update();
            if(recent!=keys){
                escape=false;
                keys=recent;
            }
        }
        for (int i=0;i<keys.size();i++){
            if(keys[i]==TEXTGREEN)
                indexes.push_back(i);
        }
        system("CLS");
        if(keys[0]=="0"){
            indexes.clear();
            cout<<"Please launch the Wordle Game"<<endl;
        }
        else if(keys[0]=="1"){
            indexes.clear();
            cout<<"Waiting for Wordle Game round to start"<<endl;
        }
        else 
            DisplayKeyboard(keys,indexes);
    }
    return 0;
}