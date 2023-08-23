/**
 * @file   <function.h>
 * @author Wade Aiello
 * @brief  header file including function prototypes 
 * @date   08/22/2023
 *
 */
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

void makeVectors(ifstream &file, vector <int>& numOfWins, vector <string>& teamNames);
void sortFiles(vector <int>& numOfWins, vector <string>& teamNames);
void writeFiles(ofstream &file, vector <int>& numOfWins, vector <string>& teamNames);

#endif