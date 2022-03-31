#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(){
    std::ifstream in("input.txt");
    std::vector<std::string> input;
    for(std::string s; std::getline(in,s);){
        input.push_back(s);
    }
    std::string first = input[0];
    int counter=0;
    for(unsigned int i=0; i<first.size(); i++){
        if(first[i]=='[')   counter++;
        else if(first[i]==']')   counter--;
        else if(first[i]!=',' && first[i]>9){
            int number1 = (first[i]-'0')/2;
            int number2 = (first[i]-'0')/2;
            std::string to_add="";
            first[i]='[';
            if(((first[i]-'0')%2)!=0){
                number2++;
            }
            to_add+=number1+'0';
            to_add+=',';
            to_add+=number2+'0';
            to_add+=']';
            first.insert(i,to_add);
        }
        if(counter>=5){
           int number1 = first[i+1];
           if(first[i]==']')   counter--;
           std::cout<<counter;
        }

    }
}