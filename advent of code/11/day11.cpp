#include "day11.h"
void day11::exercise(bool part){
    if(part==false){
        day11::partOne::exercise();
    }else{
 
    }
}

void day11::partOne::exercise(){
    std::vector<std::vector<int>> input_V = readInput();
    int count = 0;
    for(unsigned int i=0; i<100; i++)   
        count+= oneStep(input_V);
    /*for(unsigned int i=0; i<10; i++){
        for(unsigned int j=0; j<10; j++)
            std::cout<<input_V[i][j]<<" ";
        std::cout<<"\n";
    }*/
    std::cout<<count;
    
}

std::vector<std::vector<int>> day11::partOne::readInput(){
    std::ifstream in("input");
    std::vector<std::vector<int>> result;
    std::string s;
    for(;std::getline(in,s);){
        std::vector<int> row_Actual;
        for(int i=0;i<s.size();i++)
            row_Actual.push_back(s[i]-'0');
        result.push_back(row_Actual);
    }
    return result;
}

int day11::partOne::oneStep(std::vector<std::vector<int>>& input_V){
    int counter = 0;
    for(unsigned int i=0; i<10; i++){
       for(unsigned int j=0; j<10; j++){
           input_V[i][j]++;
           //if(input_V[i][j]>9)  explode(i,j,input_V);
        }
    }
    for(unsigned int i=0; i<10; i++)
       for(unsigned int j=0; j<10; j++)
           if(input_V[i][j]<0)  input_V[i][j]=0;counter++;  
    return counter;
}
    
void day11::partOne::explode(int i, int j, std::vector<std::vector<int>>& input_V){
    input_V[i][j]=-100;
    int counter = 1;
    if(i!=0){
        input_V[i-1][j]++;
        if(input_V[i-1][j]>9)   counter += explode(i-1,j, input_V);
        if(j!=0){
            input_V[i-1][j-1]++;
            if(input_V[i-1][j-1]>9)   counter += explode(i-1,j-1, input_V);
        }
    }
    if(i!=9){
        input_V[i+1][j]++;
        if(input_V[i+1][j]>9)   counter += explode(i+1,j, input_V);
        if(j<9){
            input_V[i+1][j+1]++;
            if(input_V[i+1][j+1]>9)   counter += explode(i+1,j+1, input_V);
        }
    }
    if(j!=0){
        input_V[i][j-1]++;
        if(input_V[i][j-1]>9)   counter += explode(i,j-1, input_V);
        if(i!=9){
            input_V[i+1][j-1]++;
            if(input_V[i+1][j-1]>9) counter+= explode(i+1,j-1, input_V);
        }
    }
    if(j!=9){
        input_V[i][j+1]++;
        if(input_V[i][j+1]>9)   counter += explode(i,j+1, input_V);
        if(i!=9){
            input_V[i-1][j+1]++;
            if(input_V[i-1][j+1]>9) counter+= explode(i-1,j+1, input_V);
        }
    }
    return counter;

}