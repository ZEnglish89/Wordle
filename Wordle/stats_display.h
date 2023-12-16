#ifndef STATS_DISPLAY_H
#define STATS_DISPLAY_H
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;
void DisplayStatistics(){
    system("CLS");
    ifstream file;
    vector<vector<string>> data;
    vector<string> eachline;
    string line;
    string element;
    file.open("stats.txt",ios::in);
    if(file.is_open()){
        while(getline(file,line)){
            stringstream ss(line);
            while(getline(ss,element,',')){
                if(element!="")
                    eachline.push_back(element);
                element="";
            }
            data.push_back(eachline);
            eachline.clear();
            line="";
        }
        file.close();
    }
    int played=data.size();
    int averageattempts=0;
    float percentage=0;
    int currstreak=0;
    int longeststreak=0;
    for(int i=0;i<data.size();i++){
        averageattempts+=stoi(data[i][1]);
        percentage+=stoi(data[i][2]);
        if(data[i][2]=="1")
            currstreak++;
        else
            currstreak=0;
        if(currstreak>longeststreak)
            longeststreak=currstreak;
    }
    if(played!=0){
        averageattempts=averageattempts/played;
        percentage=(percentage/played)*100;
    }
    cout<<"=========================="<<endl;
    cout<<"    STATISTICS SUMMARY    "<<endl;
    cout<<"=========================="<<endl;
    cout<<"Times Played:"<<setw(13)<<right<<played<<endl;
    cout<<"Average Attempts:"<<setw(9)<<right<<averageattempts<<endl;
    cout<<"Win Percentage:"<<setw(10)<<right<<setprecision(3)<<percentage<<"%"<<endl;
    cout<<"Current Streak:"<<setw(11)<<right<<currstreak<<endl;
    cout<<"Longest Streak:"<<setw(11)<<right<<longeststreak<<endl;
    cout<<"--------------------------"<<endl;
    cout<<"WORD     ATTEMPTS      WIN"<<endl;
    cout<<"--------------------------"<<endl;
    for(int i=0;i<data.size();i++){
        cout<<data[i][0];
        cout<<"           "<<data[i][1];
        if(data[i][2]=="1"){
            cout<<"      Yes";
        }
        else{
            cout<<"       No";
        }
        cout<<endl;
    }
    cout<<"Press [enter] to continue"<<endl;
    while(true){
        cin.ignore();
        if(cin.get()=='\n')
            return;
    }
}
#endif