#ifndef STATS_RESET_H
#define STATS_RESET_H
#include <fstream>
using namespace std;
void ResetStatistics(){
    ofstream file;
    file.open("stats.txt",ios::out);
    if(file.is_open()){
        file<<"";
        file.close();
    }
    return;
}
#endif