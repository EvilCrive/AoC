#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <string>
#include <map>

int main(){
    std::ifstream in("input");
    std::string str="";
    std::getline(in,str);
    std::vector<std::tuple<char,char,char>> pairs_insert;

    for(std::string s; std::getline(in,s);){
        std::tuple<char,char,char> t = std::make_tuple(s[0],s[1],s[s.size()-1]);
        pairs_insert.push_back(t);
    }
    for(unsigned int k=0; k<1; k++){
        for(unsigned int i=0; i<str.size(); i++){
            std::string s1="";
            std::string s2="";
            for(unsigned int j=0; j<i+1; j++){
                s1+=str[j];
            }
            for(unsigned int j=i+1; j<str.size(); j++){
                s2+=str[j];
            }
            char c_s1=s1[s1.size()-1];
            char c_s2=s2[0];
            std::string s3=s1+s2;
            for(unsigned int j=0; j<pairs_insert.size(); j++){
                char t1=std::get<0>(pairs_insert[j]);
                char t2=std::get<1>(pairs_insert[j]);
                if(c_s1==t1 && c_s2==t2){
                    str=s1+(std::get<2>(pairs_insert[j]))+s2;
                    i++;
                }
            }
        }
         std::cout<<str.size()<<std::endl;
    }
    std::map<char,int> count_char;
    std::vector<char> count;
    for(unsigned int i=0; i<str.size(); i++){
        bool check=false;
        for(unsigned int j=0; j<count.size();j++){
            if(str[i]==count[j]) check=true;
        }
        if(!check)  count.push_back(str[i]);
    }

    count_char.insert(std::pair<char,int>('V',0));
    count_char.insert(std::pair<char,int>('F',0));
    count_char.insert(std::pair<char,int>('K',0));
    count_char.insert(std::pair<char,int>('H',0));
    count_char.insert(std::pair<char,int>('S',0));
    count_char.insert(std::pair<char,int>('B',0));
    count_char.insert(std::pair<char,int>('P',0));
    count_char.insert(std::pair<char,int>('N',0));
    count_char.insert(std::pair<char,int>('C',0));
    count_char.insert(std::pair<char,int>('O',0));
   
    for(unsigned int i=0; i<str.size();i++){
        switch(str[i]) {
            case 'V': count_char['V']++;
            break;
            case 'F': count_char['F']++;
            break;
            case 'K': count_char['K']++;
            break;
            case 'H': count_char['H']++;
            break;
            case 'S': count_char['S']++;
            break;
            case 'B': count_char['B']++;
            break;
            case 'P': count_char['P']++;
            break;
            case 'N': count_char['N']++;
            break;
            case 'C': count_char['C']++;
            break;
            case 'O': count_char['O']++;
            break;
            //default: 
        }
    }

    std::cout<<"MAP:"<<std::endl;
    for(auto it=count_char.begin(); it!=count_char.end(); it++) std::cout<<it->second<<std::endl;
}