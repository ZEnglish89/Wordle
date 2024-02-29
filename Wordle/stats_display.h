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
    system("CLS"); //Clear screen
    ifstream file;
    vector<vector<string>> data; //The total data found within the file.
    vector<string> eachline; //This will contain one line of data at a time, being overwritten for the next line.
    string line; //This will receive each line of data before it is written to eachline.
    string element; //This will be each individual element of data, overwritten each time for the next one.
    file.open("stats.txt",ios::in);
    if(file.is_open()){
        while(getline(file,line)){ //Read each line to line.
            stringstream ss(line); //Convert line to a stringstream so getline may be used on it.
            while(getline(ss,element,',')){
                if(element!="")
                    eachline.push_back(element);
                element="";
            } //Read each element from the stringstream to eachline.
            data.push_back(eachline);
            eachline.clear();
            line=""; //add eachline to the total data, clear the necessary variables, and move on to the next line.
        }
        file.close();
    }
    int played=data.size(); //One line per game played, so data.size() represents the number of games played.
    int averageattempts=0;
    float percentage=0;
    int currstreak=0;
    int longeststreak=0;
    for(int i=0;i<data.size();i++){
        averageattempts+=stoi(data[i][1]); //data[i][1] represents the number of attempts taken on game i.
        percentage+=stoi(data[i][2]); //data[i][2] represents whether game i was a win or less.
        if(data[i][2]=="1")
            currstreak++;
        else
            currstreak=0;
        if(currstreak>longeststreak)
            longeststreak=currstreak; //add to the streak and update the maximum if it was a win, reset the streak otherwise.
    }
    if(played!=0){
        averageattempts=averageattempts/played;
        percentage=(percentage/played)*100; //calculate averages.
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