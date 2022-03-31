#include <iostream>
#include <fstream>
#include <vector>
#include <string>

namespace day13{
    void readInput(std::vector<std::vector<char>>&, std::vector<std::string>&);
    void fillZeros(std::vector<std::vector<char>>&);
    void foldVertical(std::vector<std::vector<char>>&,int);
    void foldHorizontal(std::vector<std::vector<char>>&,int);
    void printMatrix(std::vector<std::vector<char>>&);
    void countHashtags(std::vector<std::vector<char>>&);
}

int main(){
    std::vector<std::vector<char>> input_V;
    std::vector<std::string> folds;
    day13::readInput(input_V, folds);
    day13::foldVertical(input_V,655);
    day13::foldHorizontal(input_V,447);
    day13::foldVertical(input_V,327);
    day13::foldHorizontal(input_V,223);
    day13::foldVertical(input_V,163);
    day13::foldHorizontal(input_V,111);
    day13::foldVertical(input_V,81);
    day13::foldHorizontal(input_V,55);
    day13::foldVertical(input_V,40);
    day13::foldHorizontal(input_V,27);
    day13::foldHorizontal(input_V,13);
    day13::foldHorizontal(input_V,6);

    day13::printMatrix(input_V);
    day13::countHashtags(input_V);

}

//! Implementation methods

//? read and parse input
void day13::readInput(std::vector<std::vector<char>>& input_V, std::vector<std::string>& folds){
    std::ifstream in("input");
    fillZeros(input_V);
    for(std::string s;std::getline(in,s);){
        if(s.find(',')!=std::string::npos){
            std::string tmp="";
            std::string::size_type sz;
            int integer=0;
            for(unsigned int i=0; i<s.size(); i++){
                if(s[i]==','){
                    integer=std::stoi(tmp,&sz);
                    tmp="";
                }else   tmp+=s[i];
            }
            
            input_V[std::stoi(tmp,&sz)][integer]='#';
        }else if(s.find('=')!=std::string::npos){
            folds.push_back(s);
        }    
    } 

}

void day13::fillZeros(std::vector<std::vector<char>>& matrix){
    for(unsigned int i=0; i<2000; i++){
        std::vector<char> rows;
        for(unsigned int j=0; j<2000; j++){
            rows.push_back('.');
        }
        matrix.push_back(rows);
    }

}

void day13::foldVertical(std::vector<std::vector<char>>& matrix, int coord){
    for(unsigned int i=0; i<matrix.size(); i++){
        for(unsigned int j=0; j<matrix[i].size(); j++){
            if(j==coord)    matrix[i][j]='|';
            if(j>coord){
                if((j-coord-1)<(coord-1)){
                    //folda oltre all metà
                    if(matrix[i][j]=='#'){
                        int toFoldIndex = j-coord-1;
                        int notToFoldLastIndex = coord -1;
                        int index = coord - 1 - toFoldIndex;
                        matrix[i][j]='.';
                        matrix[i][index]='#';
                    }
                }
            }
        }
    //erase j>coord
    }
}


void day13::foldHorizontal(std::vector<std::vector<char>>& matrix, int coord){
    for(unsigned int i=0; i<matrix.size(); i++){
        for(unsigned int j=0; j<matrix[i].size(); j++){
            if(i==coord)    matrix[i][j]='-';
            if(i>coord){
                if((i-coord-1)<(coord-1)){
                    //folda oltre all metà
                    if(matrix[i][j]=='#'){
                        int toFoldIndex = i-coord-1;
                        int notToFoldLastIndex = coord -1;
                        int index = coord - 1 - toFoldIndex;
                        matrix[i][j]='.';
                        matrix[index][j]='#';
                    }
                }
            }
        }
    //erase j>coord
    }
}

void day13::printMatrix(std::vector<std::vector<char>>& matrix){
    for(unsigned int i=0; i<50; i++){
        for(unsigned int j=0; j<50; j++){
            std::cout<<matrix[i][j];
        }
        std::cout<<std::endl;
    }
}

void day13::countHashtags(std::vector<std::vector<char>>& matrix){
    int counter = 0;
    for(unsigned int i=0; i<matrix.size(); i++){
        for(unsigned int j=0; j<matrix[i].size(); j++){
            if(matrix[i][j]=='#')   counter++;
        }
    }
    std::cout<<counter;
}