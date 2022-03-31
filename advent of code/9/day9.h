#ifndef DAY9_H
#define DAY9_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

namespace Day9{
    namespace Prints{
        void printTest(int, int, int, char, int, int, int=-1, int=-1);
        void printArray(std::vector<std::vector<int>>&);
    }
    namespace Utils{
        std::vector<std::vector<int>> findLowestPoints(std::vector<std::vector<int>>&);
        int basinSize(std::vector<std::vector<int>>&, int, int);
        int basinSizeNew(std::vector<std::vector<int>>&, std::vector<std::vector<bool>>&, int, int);
    }
    void exercise(bool);
    void partOne(std::vector<std::vector<int>>&, int, int, bool);
    void partTwo(std::vector<std::vector<int>>&);
    void partTwoNew(std::vector<std::vector<int>>&);
    std::vector<std::vector<int>> readInput(std::ifstream&);
}

#endif