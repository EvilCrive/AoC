#ifndef DAY10_H
#define DAY10_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;

namespace day10
{
    vector<string> readInput();

    vector<char> partOne(vector<string>&);
    int calculateSyntaxError(vector<char>&);

    void discardCorrupted(vector<string>&);
    vector<string> completeIncompletes(vector<string>&);
    vector<long long> calculateCompletionScore(vector<string>&);
    long long findMiddle(vector<long long>&);
} 

#endif