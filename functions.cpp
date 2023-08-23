/**
 * @file functions.cpp
 * @author Wade Aiello (waiello@nic.edu)
 * @brief Function file, including function to make vectors for teams and number of titles, as well as writing to sortFiles
 * @version 0.1
 * @date 2023-08-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "functions.h"

/**
 * @brief makes 2 vectors, one for number of wins, one for team names. Just sorted by team name appearence in txt file
 * 
 * @param file unregistered data for baseball titles. Only includes team names one by one for every year.
 * @param numOfWins vector that adds one to a team's index for every appearance of a team's name
 * @param teamNames vector that registers new team names everytime they initially appear in file
 */
void makeVectors(ifstream &file, vector <int>& numOfWins, vector <string>& teamNames)
{
    file.open("WorldSeriesWinners.txt");
    if(file.fail())                                     //terminates program if file does not exist
    {
        cout << "Error opening file\n";
        exit(0);
    }

    for(int i = 0; file.peek() != EOF||i < 64; i++)     //main for loop
    {
        bool isTeam = false;
        string newTeam;
        getline(file, newTeam);
        for(int team = 0; team < teamNames.size(); team++)
        {
            if(newTeam == teamNames[team])              //adds to number of wins vector index if team has been used before
            {
                isTeam = true;
                numOfWins[team]++;
            }

        }

        if(isTeam == false)                             //makes new vector indexes if team has not been seen
        {
            teamNames.push_back(newTeam);
            numOfWins.push_back(1);
        }

    }

    file.close();
}

/**
 * @brief Sorts files by number of titles
 * 
 * @param numOfWins vector that matches team names to number of titles based on index number
 * @param teamNames vector for team names
 */
void sortFiles(vector <int>& numOfWins, vector <string>& teamNames)
{
    int minIndex, minVal;
    string minTeam;
    for(int i = 0; i < teamNames.size()-1; i++){            //selection sorting algorithm
        minIndex = i;
        minVal = numOfWins[i];
        minTeam = teamNames[i];
        for(int index = i + 1; index < teamNames.size(); ++index)
        {
            if(numOfWins[index]<minVal)
            {
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
/**
 * @brief writes files to .csv file. creates file if it doesn't exist
 * 
 * @param file output file that includes team names and number of titles
 * @param numOfWins vector that matches team names to number of titles based on index number
 * @param teamNames vector for team names
 */
void writeFiles(ofstream &file, vector <int>& numOfWins, vector <string>& teamNames)
{
    file.open("winners.csv");
    file << "Team name, Number of wins";    // header to the csv file
    for(int i = teamNames.size()-1; i>=0; i--)      //outputs team info to file
    {
        file << endl << teamNames[i] << ", " << numOfWins[i];
    }
    file.close();

}