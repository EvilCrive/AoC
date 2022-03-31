#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using std::cout;
using std::endl;

namespace Day7{
    std::vector<int> readInput();
    namespace longlong{
        std::vector<long long> readInput();
    }
    void partOne(std::vector<int>&);
    void partTwo(std::vector<long long>&);
    namespace Utils{
        template <class T>
        T findMaxMin(std::vector<T>&,bool);
    }
}

int main(){
    std::vector<int> inputV = Day7::readInput();
    Day7::partOne(inputV);
}

std::vector<int> Day7::readInput(){
    std::vector<int> inputV;
    std::ifstream inputF("input");

    char c;
    std::string s="";
    std::string::size_type sz;

    while(inputF.get(c)){
        if(c==','){
            inputV.push_back(std::stoi(s,&sz));
            s="";
        }else   s+=c;
    }
    inputV.push_back(std::stoi(s,&sz));
    return inputV;
}

std::vector<long long> Day7::longlong::readInput(){
    std::vector<long long> inputV;
    std::ifstream inputF("input");

    char c;
    std::string s="";
    std::string::size_type sz;

    while(inputF.get(c)){
        if(c==','){
            inputV.push_back(((long long)(std::stoi(s,&sz))));
            s="";
        }else   s+=c;
    }
    inputV.push_back(((long long)(std::stoi(s,&sz))));
    return inputV;
}

void Day7::partOne(std::vector<int>& inputV){
    std::vector<int> fuelV;
    for(unsigned int i=0; i<=Utils::findMaxMin(inputV,true);i++){
        int fuel=0;
        for(unsigned int j=0; j<inputV.size();j++){
            fuel+=abs((int)(inputV[j]-i));
        }
        fuelV.push_back(fuel);
    }
    for(unsigned int i=0;i<fuelV.size();i++)    cout<<i<<": "<<fuelV[i]<<endl;
    cout<<endl<<Utils::findMaxMin(fuelV,false);
}

void Day7::partTwo(std::vector<long long>& inputV){
    std::vector<long long> fuelV;
    for(unsigned int i=0; i<=Utils::findMaxMin(inputV,true);i++){
        long long fuel=0;
        for(unsigned int j=0; j<inputV.size();j++){
            int steps=abs((int)(inputV[j]-i));
            int fuelActual=0;
            for(unsigned int i=1; i<=steps; i++){
                fuelActual+=i;
            }
            fuel+=fuelActual;
        }
        fuelV.push_back(fuel);
    }
    cout<<Utils::findMaxMin(fuelV,false);
}

template <class T>
T Day7::Utils::findMaxMin(std::vector<T>& v, bool max){
    T result=v[0];
    if(max){
        for(unsigned int i=0; i<v.size();i++){
            if(result<v[i]) result=v[i];
        }
    }else{
        for(unsigned int i=0; i<v.size();i++){
            if(result>v[i]) result=v[i];
        }
    }
    return result;
}
