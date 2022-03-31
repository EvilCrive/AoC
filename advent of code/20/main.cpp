#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(){
    std::vector<char> imageA;
    std::vector<std::vector<char>> matrix_input;
    std::ifstream in("input");
    std::string alg;
    in>>alg;

    for(unsigned int i=0; i<alg.size(); i++){
        imageA.push_back(alg[i]);
    }
    
    for(std::string s; std::getline(in,s);){
        std::vector<char> row;
        for(unsigned int i=0; i<s.size(); i++){
            row.push_back(s[i]);
        }
        matrix_input.push_back(row);
    }

}