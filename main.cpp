/**
 * @file main.cpp
 * @author Wade Aiello
 * @brief Main function, runs the program
 * @version 0.1
 * @date 2023-08-22
 * 
 * 
 */
#include "functions.h"


using namespace std;


int main(){
    
    vector <string> teamNames;
    vector <int> numOfWins;
    ifstream file;
    makeVectors(file, numOfWins, teamNames);                    //executes makeVectors function
    cout << endl << endl <<"Team Names             Titles\n";
    cout << "-------------------------------\n";

    for(int i = 0; i < teamNames.size(); i++)
    {                                                           //displays unsorted file
            cout << setw(25) << left << teamNames[i] << setw(5) << left << numOfWins[i] << endl;
    }                                                           

    sortFiles(numOfWins, teamNames);                            //sorts vector by number of titles
    cout << endl << endl << "----------Sorted Vector--------" << endl;
    cout << "Team Names             Titles\n";
    cout << "-------------------------------\n";

    for(int i = teamNames.size()-1; i>=0; i--)
    {                                                           //displays sorted file
            cout << setw(25) << left << teamNames[i] << setw(5) << left << numOfWins[i] << endl;
    }
    ofstream outputFile;
    writeFiles(outputFile, numOfWins, teamNames);              //execute writeFiles function

    return 0;
}