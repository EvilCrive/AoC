#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::ifstream;
using std::cout;
using std::endl;

namespace UtilsDay4{
    vector<vector<int>> readInput(ifstream&); 
    void divideStoI(string&,int&,int&);     //divide string into two integers, string is in format iiiiiiii,iiiiiiii    where the i represent integers digits, which can be 1 to whatever, and separated by a comma
    void Exercise(vector<vector<int>>&, bool);
    void partOne(vector<vector<int>>&, vector<vector<int>>&);
    void partTwo(vector<vector<int>>&, vector<vector<int>>&);
    void fillZeros(vector<vector<int>>&);
}




int main(){
    ifstream in("input");
    vector<vector<int>> input = UtilsDay4::readInput(in);
    cout<<"PART 1:"<<endl;
    UtilsDay4::Exercise(input, false);
    cout<<"PART 2:"<<endl;
    UtilsDay4::Exercise(input, true);
}

vector<vector<int>> UtilsDay4::readInput(ifstream& in){
    vector<vector<int>> input;
    for(unsigned int counter=0; counter<500; counter++){
        vector<int> singleInput;
        int num1,num2,num3,num4;
        string s1,s2;

        in>>s1;
        in>>s2;
        in>>s2;
        divideStoI(s1,num1,num2);
        divideStoI(s2,num3,num4);

        singleInput.push_back(num1);
        singleInput.push_back(num2);
        singleInput.push_back(num3);
        singleInput.push_back(num4);
        input.push_back(singleInput);
    }
    return input;
}

void UtilsDay4::divideStoI(string& str, int& num1, int& num2){ 
    string s1,s2;
    s1="";
    int counter=0;
    for(unsigned int i=0; i<str.size(); i++){
        if(str[i]==','){
            counter=i;
            i=str.size();
        }
        else    s1+=str[i];
    }
    s2="";
    for(counter++; counter<str.size(); counter++){
        s2+=str[counter];
    }
    std::string::size_type sz;
    num1 = std::stoi(s1, &sz);
    num2 = std::stoi(s2, &sz);
}

void UtilsDay4::fillZeros(vector<vector<int>>& field){
    for(unsigned int y=0; y<1000; y++){
        vector<int> row;
        for(unsigned int x=0;x<1000;x++){
            row.push_back(0);
        }
        field.push_back(row);
    }
}

void UtilsDay4::Exercise(vector<vector<int>>& input, bool part){
    vector<vector<int>> field;
    int counter = 0;

    fillZeros(field);
    if(part)    partTwo(input, field);
    else    partOne(input, field);

    for(unsigned int i=0; i<field.size();i++){
        for(unsigned int j=0; j<field[i].size();j++){
            if(field[i][j]>1)   counter++;
        }
    }
    cout<<counter<<endl;
}

void UtilsDay4::partOne(vector<vector<int>>& input, vector<vector<int>>& field){
    for(unsigned int i=0; i<input.size();i++){
        int x0,x1,y0,y1;
        x0=input[i][0];
        y0=input[i][1];
        x1=input[i][2];
        y1=input[i][3];
        if(x0==x1){
            if(y0<y1){
                for(unsigned int k=y0;k<=y1;k++){
                    field[x0][k]++;
                }
            }else{
                for(unsigned int k=y1;k<=y0;k++){
                    field[x0][k]++;
                }
            }
        }else if(y0==y1){
            if(x0<x1){
                for(unsigned int k=x0;k<=x1;k++){
                    field[k][y0]++;
                }
            }else{
                for(unsigned int k=x1;k<=x0;k++){
                    field[k][y0]++;
                }
            }
        }
    }
}

void UtilsDay4::partTwo(vector<vector<int>>& input, vector<vector<int>>& field){
    for(unsigned int i=0; i<input.size();i++){
        int x0,x1,y0,y1;
        x0=input[i][0];
        y0=input[i][1];
        x1=input[i][2];
        y1=input[i][3];
        if(x0==x1){
            if(y0<y1){
                for(unsigned int k=y0;k<=y1;k++){
                    field[x0][k]++;
                }
            }else{
                for(unsigned int k=y1;k<=y0;k++){
                    field[x0][k]++;
                }
            }
        }else if(y0==y1){
            if(x0<x1){
                for(unsigned int k=x0;k<=x1;k++){
                    field[k][y0]++;
                }
            }else{
                for(unsigned int k=x1;k<=x0;k++){
                    field[k][y0]++;
                }
            }
        }else{
            if((abs(x1-x0))!=(abs(y1-y0)))   cout<<"diagonal isnt 45 degrees";
            else{    
                if((x0>x1)&&(y0>y1)){
                    for(unsigned int i=0; i<(x0-x1+1); i++){
                        field[x0-i][y0-i]++;
                    }
                }else if((x0>x1)&&(y0<y1)){
                    for(unsigned int i=0; i<(x0-x1+1); i++){
                        field[x0-i][y0+i]++;
                    }
                }else if((x0<x1)&&(y0>y1)){
                    for(unsigned int i=0; i<(x1-x0+1); i++){
                        field[x0+i][y0-i]++;
                    }
                }else if((x0<x1)&&(y0<y1)){
                    for(unsigned int i=0; i<(x1-x0+1); i++){
                        field[x0+i][y0+i]++;
                    }
                }
            }
        }
        
    }

}

    
