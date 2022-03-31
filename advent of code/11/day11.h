#ifndef DAY11_H
#define DAY11_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
namespace day11{
    void exercise(bool);
    namespace partOne{
        void exercise();
        std::vector<std::vector<int>> readInput();
        int oneStep(std::vector<std::vector<int>>&);
        void explode(int,int,std::vector<std::vector<int>>&);
    }
}

#endif


