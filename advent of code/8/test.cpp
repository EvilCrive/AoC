#include <iostream>
#include <string>
bool compare2strings(std::string s1, std::string s2){
    if(s1.size()!=s2.size())    return false;
    for(unsigned int i=0; i<s1.size();i++){
        bool check=false;
        for(unsigned int j=0; j<s1.size();j++){
            if(s1[i]==s2[j])    check=true;
        }
        if (check=false)  return false;
    }
    return true;
}
int main(){
    std::string s ="egbdacf";
    std::string s2="abcdefg";
    std::cout<<compare2strings(s,s2);
}