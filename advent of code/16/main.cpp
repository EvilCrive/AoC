#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(){
    std::ifstream in("input");
    std::vector<char> numInput;
    std::vector<bool> numInputB;
    for(std::string s; std::getline(in,s);){
        for(int i=0; i<s.size(); i++){
            numInput.push_back(s[i]);
        }
    }
    for(unsigned int i=0; i<numInput.size();i++){
        int n=0;
        if(numInput[i]=='A' || numInput[i]=='B' || numInput[i]=='C' || numInput[i]=='D' || numInput[i]=='E' || numInput[i]=='F')    n=numInput[i]-'A'+10;
        else    n= numInput[i]-'0';
        std::string r="";
        while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
        if(r.size()==0) r="0000";
        else if(r.size()==1)    r="000"+r;
        else if (r.size()==2)   r="00"+r;
        else if(r.size()==3)    r="0"+r;
        numInputB.push_back(r[0]-'0');
        numInputB.push_back(r[1]-'0');
        numInputB.push_back(r[2]-'0');
        numInputB.push_back(r[3]-'0');
    }
    
    for(unsigned int i=0; i<numInputB.size();){
        if(numInputB[i+3])
    }

}