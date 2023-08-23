#include "functions.h"


void makeVectors(ifstream &file, vector <int>& numOfWins, vector <string>& teamNames){
    file.open("WorldSeriesWinners.txt");
    if(file.fail()){
        cout << "Error opening file\n";
        exit(0);
    }

    for(int i = 0; file.peek() != EOF||i < 64; i++){
        bool isTeam = false;
        string newTeam;
        getline(file, newTeam);
        for(int team = 0; team < teamNames.size(); team++){
            if(newTeam == teamNames[team]){
                isTeam = true;
                numOfWins[team]++;
            }
    }
        if(isTeam == false){
            teamNames.push_back(newTeam);
            numOfWins.push_back(1);
        }
    }
    file.close();
}
void sortFiles(vector <int>& numOfWins, vector <string>& teamNames){
    int minIndex, minVal;
    string minTeam;
    for(int i = 0; i < teamNames.size()-1; i++){
        minIndex = i;
        minVal = numOfWins[i];
        minTeam = teamNames[i];
        for(int index = i + 1; index < teamNames.size(); ++index){
            if(numOfWins[index]<minVal){
                minVal = numOfWins[index];
                minIndex = index;
                minTeam = teamNames[index];
            }
        }
        numOfWins[minIndex] = numOfWins[i];
        numOfWins[i] = minVal;
        teamNames[minIndex] = teamNames[i];
        teamNames[i] = minTeam;

    }
}
