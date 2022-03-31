#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main(){
    std::ifstream in("input");
    std::vector<std::vector<std::vector<bool>>> matrix;

    for(unsigned int i=0; i<200001; i++){
        std::vector<std::vector<bool>> columns;
        for(unsigned int j=0; j<200001; j++){
            std::vector<bool> rows;
            for(unsigned int k=0; k<200001; k++){
                rows.push_back(false);
            }
            columns.push_back(rows);
        }
        matrix.push_back(columns);
    }


    std::vector<int> prova;

    prova.push_back(1);
    prova.push_back(-37+100000);


}