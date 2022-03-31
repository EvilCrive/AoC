#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <string>
#include <map>
#include <algorithm>
int main(){
    std::ifstream in("input");
    std::string str="";
    std::getline(in,str);

    std::map<std::string, char> rules; 
    std::map<std::string, long long> count;
    std::map<std::string, long long> next;
    std::map<char,long long> countLetters;

    std::string s;
    std::getline(in,s);

    for(; std::getline(in,s);){
        std::string pair;
        pair+=s[0];
        pair+=s[1];
        char insert=s[s.size()-1];
        rules.insert(std::pair<std::string, char>(pair,insert));
    }

    for(unsigned int i=0; i<(str.size()-1);i=i+2){
        std::string pair;
        pair+=str[i];pair+=str[i+1];
        count[pair]++;
    }

    for(int k=0; k<1; k++){
        for(std::map<std::string,long long>::iterator it=count.begin(); it!=count.end();it++){
            char insert = rules[it->first];
            std::string npair1, npair2;

            npair1+=it->first[0];npair1+=insert;
            next[npair1]+=it->second;

            npair2+=insert;npair2+=it->first[1];
            next[npair2]+=it->second;
        }
        count=next;
        next.clear();
    }

    for(auto it=count.begin(); it!=count.end(); it++){
        countLetters[it->first[0]]+=it->second;
        countLetters[it->first[1]]+=it->second;
    }

    //auto [min1,max1] = std::minmax_element(countLetters.begin(), countLetters.end(), [&](auto l, auto r){return l.second < r.second;});
    
    long long max=0;
    long long min=countLetters.begin()->second;
    for(auto it=countLetters.begin(); it!=countLetters.end(); it++){
        std::cout<<it->first<<" "<<it->second<<std::endl;
        if(max<it->second)  max=it->second;
        if(min>it->second)  min=it->second;
    }
    std::cout<<max-min;
}