#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;

namespace Day3{
    vector<vector<bool>> readInput(); 
    namespace Utils{
        void printInput(vector<vector<bool>>&);
        void printNumber(vector<bool>&);
        int bin2dec(vector<bool>&);
    }
    vector<bool> gammaRate(vector<vector<bool>>&);
    vector<bool> epsilonRate(vector<bool>&);
    
    void partOne(vector<vector<bool>>&);
    void partTwo(vector<vector<bool>>&);
    vector<bool> oxygenRate(vector<vector<bool>>&);
    vector<bool> co2Rate(vector<vector<bool>>&);
}

int main(){
    vector<vector<bool>> inputV = Day3::readInput();
    Day3::partTwo(inputV);
}

void Day3::partOne(vector<vector<bool>>& inputV){
    vector<bool> gamma = Day3::gammaRate(inputV);
    vector<bool> epsilon = Day3::epsilonRate(gamma);
    Day3::Utils::printInput(inputV);
    cout<<"gamma: ";
    Day3::Utils::printNumber(gamma);
    cout<<"epsilon: ";
    Day3::Utils::printNumber(epsilon);
    cout<<"prodotto in decimale: "<<Day3::Utils::bin2dec(gamma)*Day3::Utils::bin2dec(epsilon);
}

void Day3::partTwo(vector<vector<bool>>& inputV){
    vector<bool> oxygen = Day3::oxygenRate(inputV);
    vector<bool> co2 = Day3::co2Rate(inputV);
    //Day3::Utils::printInput(inputV);
    cout<<"oxygen: ";
    Day3::Utils::printNumber(oxygen);
    cout<<" "<<Day3::Utils::bin2dec(oxygen)<<endl;
    cout<<"co2: ";
    Day3::Utils::printNumber(co2);
    cout<<" "<<Day3::Utils::bin2dec(co2)<<endl;
    cout<<"prodotto in decimale: "<<Day3::Utils::bin2dec(oxygen)*Day3::Utils::bin2dec(co2);
}


vector<bool> Day3::oxygenRate(vector<vector<bool>>& inputV){
    vector<vector<bool>> newArray=inputV;
    int rows = 1000;
    for(unsigned int i=0; i<12;i++){
        int counterOnes=0;
        int counterZeros=0;
        bool ones=true;
        for(unsigned int j=0; j<rows;j++){
            if(newArray[j][i]==true)  counterOnes++;
            else    counterZeros++;
        }
        if(counterOnes<counterZeros)    ones=false;
        if(newArray.size()>1){  
        
            for(unsigned int j=0; j<rows; j++){
               
                if(ones && newArray[j][i]==false){
                    newArray.erase(newArray.begin()+j);
                    rows--;
                    j--;
                }else if(!ones && newArray[j][i]==true){
                    newArray.erase(newArray.begin()+j);
                    rows--;
                    j--;
                }   
            } 
        }    
    }
    return newArray[0];
}
vector<bool> Day3::co2Rate(vector<vector<bool>>& inputV){

    vector<vector<bool>> newArray=inputV;
    int rows =1000;
    for(unsigned int i=0; i<12;i++){
        int counterOnes=0;
        int counterZeros=0;
        bool ones=false;
        for(unsigned int j=0; j<rows;j++){
            if(newArray[j][i]==true)  counterOnes++;
            else    counterZeros++;
        }
        if(counterOnes<counterZeros)
            ones=true;
        if(newArray.size()>1){
            for(unsigned int j=0; j<rows; j++){
                if(ones && newArray[j][i]==false){
                    newArray.erase(newArray.begin()+j);
                    rows--;
                    j--;
                }else if(!ones && newArray[j][i]==true){
                    newArray.erase(newArray.begin()+j);
                    rows--;
                    j--;
                }
            }
        }
    }
    return newArray[0];
}

vector<vector<bool>> Day3::readInput(){
    vector<vector<bool>> result;
    std::ifstream in("input");
    for(std::string s;getline(in,s);){
        vector<bool> oneNumber;
        for(unsigned int i=0; i<s.size(); i++){
            if(s[i]=='1')   oneNumber.push_back(true);
            else if(s[i]=='0')  oneNumber.push_back(false);
        }
        result.push_back(oneNumber);
    }
    return result;
}


vector<bool> Day3::gammaRate(vector<vector<bool>>& inputV){
    vector<bool> gamma;

    for(unsigned int i=0; i<12;i++){
        int counterOnes=0;
        int counterZeros=0;
        for(unsigned int j=0; j<1000;j++){
            if(inputV[j][i]==true)  counterOnes++;
            else    counterZeros++;
        }
        if(counterOnes>counterZeros)    gamma.push_back(true);
        else    gamma.push_back(false);
    }
    return gamma;
}

vector<bool> Day3::epsilonRate(vector<bool>& gamma){
    vector<bool> epsilon;
    for(unsigned int i=0;i<gamma.size();i++){
        if(gamma[i])    epsilon.push_back(false);
        else    epsilon.push_back(true);
    }
    return epsilon;
}

void Day3::Utils::printInput(vector<vector<bool>>& inputV){
    cout<<"Stampa input:"<<endl;
    for(unsigned int i=0;i<inputV.size();i++){
        for(unsigned int j=0;j<inputV[i].size();j++){
            cout<<inputV[i][j];
        }
        cout<<endl;
    }
}

void Day3::Utils::printNumber(vector<bool>& number){
    for(unsigned int i=0;i<number.size();i++){
        cout<<number[i];
    }
    cout<<endl;
}

int Day3::Utils::bin2dec(vector<bool>& binary){
    int result=0;
    for(unsigned int i=0; i<12; i++){
        if(binary[i]){
            int tmp=2048;
            for(unsigned int j=0;j<i;j++)
                tmp/=2; 
            result+=tmp;
            }
        }
    return result;
}

