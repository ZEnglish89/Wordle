#include "menu_display.h"
#include "game_logic.h"
#include "how_to_play.h"
#include "stats_display.h"
#include "stats_reset.h"
#include <fstream>

int main(int argc, char* argv[]) {
    bool escape=true;
    char s;
    ofstream key;    
    while(escape){
    key.open("../keyboard/letters.txt",ios::out);
    if(key.is_open()){
        key<<"1"<<endl;
        key.close();
    }
    s=DisplayMainMenu();
    switch(s){
        case '1':
        RunGame();
        break;
        case '2':
        HowToPlay();
        break;
        case '3':
        DisplayStatistics();
        break;
        case '4':
        ResetStatistics();
        DisplayStatistics();
        break;
        case '5':
        cout<<"Goodbye"<<endl;
        escape=false;
        key.open("../keyboard/letters.txt",ios::out);
        if(key.is_open()){
            key<<"0"<<endl;
            key.close();
        }
        break;
    }        
    }

    return 0;
}