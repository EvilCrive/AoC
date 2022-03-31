#include <iostream>
#include <vector>
#include <fstream>
using std::vector;
using std::ifstream;
using std::cout;
using std::endl;

namespace Day6{
    namespace Utils{
        vector<int> setupVector(vector<int>&);
        vector<unsigned long long int> setupVector2(vector<unsigned long long int>&);
    }
    vector<int> readInput(ifstream&);
    vector<unsigned long long int> readInput2(ifstream&);
    void partOne(vector<int>&);
    void partTwo(vector<unsigned long long int>&);
}

int main(){

    ifstream in("input");
    vector<unsigned long long int> input=Day6::readInput2(in);
    Day6::partTwo(input);
    

}

void Day6::partOne(vector<int>& input){
    unsigned int days=80;
    for(unsigned int d=0; d<days; d++){
        for(unsigned int i=0;i<input.size();i++){
            if(input[i]==0){
                input.push_back(9);
                input[i]=6;
            }else    input[i]--; 
        }
    }
    cout<<input.size();
}

void Day6::partTwo(vector<unsigned long long int>& input){
    unsigned int days=256;
    vector<unsigned long long int> fishStates=Utils::setupVector2(input);
    for(unsigned int i=0; i<days; i++){
        unsigned long long tmp = fishStates[0];
        fishStates[0]=fishStates[1];
        fishStates[1]=fishStates[2];
        fishStates[2]=fishStates[3];
        fishStates[3]=fishStates[4];
        fishStates[4]=fishStates[5];
        fishStates[5]=fishStates[6];
        fishStates[6]=fishStates[7]+tmp;
        fishStates[7]=fishStates[8];
        fishStates[8]=tmp;

    }
    unsigned long long int sum=0LL;
    for(unsigned int i=0; i<fishStates.size();i++){
        sum+=fishStates[i];
        cout<<fishStates[i]<<" ";
    }
    cout<<endl<<sum;
}

vector<int> Day6::readInput(ifstream& in){
    vector<int> input;
    for(unsigned int i=0; i<599; i++){
        char c;
        in.get(c);
        if(c!=',')  input.push_back(c-'0');
    }
    return input;
}

vector<unsigned long long int> Day6::readInput2(ifstream& in){
    vector<unsigned long long int> input;
    for(unsigned int i=0; i<599; i++){
        char c;
        in.get(c);
        if(c!=',')  input.push_back(c-'0');
    }
    return input;
}

vector<unsigned long long int> Day6::Utils::setupVector2(vector<unsigned long long int>& input){
    vector<unsigned long long int> fishStates;
    for(unsigned int i=0; i<9; i++)
        fishStates.push_back(0);
    for(unsigned int i=0; i<input.size();i++)
        fishStates[input[i]]++;
    return fishStates;
}