#include "day10.h"

vector<string> day10::readInput(){
    vector<string> inputV;
    std::ifstream in("input");
    
    for(string s;std::getline(in,s);){
        inputV.push_back(s);
    }

    return inputV;
}

vector<char> day10::partOne(vector<string>& inputV){
    vector<char> corrupted;
    for(int i=0; i<inputV.size();i++){
        vector<char> tmpV;
        for(int j=0; j<inputV[i].size();j++){
            char found = inputV[i][j];
            if(found=='<' || found=='{' || found=='[' || found=='('){
                tmpV.push_back(found);
            }else if(found=='>'){
                if(tmpV[tmpV.size()-1]=='<'){
                    tmpV.pop_back();
                }else{
                    corrupted.push_back(found);
                    j=inputV[i].size();
                }
            }else if(found=='}'){
                if(tmpV[tmpV.size()-1]=='{'){
                    tmpV.pop_back();
                }else{
                    corrupted.push_back(found);
                    j=inputV[i].size();
                }
            }else if(found==']'){
                if(tmpV[tmpV.size()-1]=='['){
                    tmpV.pop_back();
                }else{
                    corrupted.push_back(found);
                    j=inputV[i].size();
                }
            }else if(found==')'){
                if(tmpV[tmpV.size()-1]=='('){
                    tmpV.pop_back();
                }else{
                    corrupted.push_back(found);
                    j=inputV[i].size();
                }
            }
        }
        
        tmpV.clear();
    }
    return corrupted;
}

int day10::calculateSyntaxError(vector<char>& corruptedV){
    int result=0;
    for(int i=0; i<corruptedV.size();i++){
        if(corruptedV[i]==')'){ 
            result+=3;
        }else if(corruptedV[i]==']'){
            result+=57;
        }else if(corruptedV[i]=='}'){
            result+=1197;
        }else if(corruptedV[i]=='>'){
            result+=25137;
        }
    }
    return result;
}

void day10::discardCorrupted(vector<string>& inputV){
    for(vector<string>::iterator i=inputV.begin(); i!=inputV.end();i++){
        vector<char> tmpV;
        bool discard=false;
        for(int j=0; j<(*i).size();j++){
            char found = (*i)[j];
            if(found=='<' || found=='{' || found=='[' || found=='('){
                tmpV.push_back(found);
            }else if(found=='>'){
                if(tmpV[tmpV.size()-1]!='<')
                    discard=true;
                else    tmpV.pop_back();
            }else if(found=='}'){
                if(tmpV[tmpV.size()-1]!='{')
                    discard=true;
                else    tmpV.pop_back();
            }else if(found==']'){
                if(tmpV[tmpV.size()-1]!='[')
                    discard=true;
                else    tmpV.pop_back();
            }else if(found==')'){
                if(tmpV[tmpV.size()-1]!='(')
                    discard=true;
                else    tmpV.pop_back();
            }
        }
        
        if(discard){
            inputV.erase(i);
            i--;
            discard=false;
        }
    }
}



vector<string> day10::completeIncompletes(vector<string>& inputV){
    vector<string> result;
    for(int i=0; i<inputV.size();i++){
        vector<char> tmpV;
        for(int j=0; j<inputV[i].size();j++){
            char found = inputV[i][j];
            if(found=='<' || found=='{' || found=='[' || found=='('){
                tmpV.push_back(found);
            }else if(found=='>'){
                if(tmpV[tmpV.size()-1]=='<')
                    tmpV.pop_back();
            }else if(found=='}'){
                if(tmpV[tmpV.size()-1]=='{')
                    tmpV.pop_back();
            }else if(found==']'){
                if(tmpV[tmpV.size()-1]=='[')
                    tmpV.pop_back();
            }else if(found==')'){
                if(tmpV[tmpV.size()-1]=='(')
                    tmpV.pop_back();
            }
        }
        int j=tmpV.size()-1;
        string tmpS="";
        while(j>-1){
            j=tmpV.size()-1;
            if(tmpV[j]=='<'){
                tmpV.pop_back();
                tmpS+=">";
            }else if(tmpV[j]=='['){
                tmpV.pop_back();
                tmpS+="]";
            }else if(tmpV[j]=='('){
                tmpV.pop_back();
                tmpS+=")";
            }else if(tmpV[j]=='{'){
                tmpV.pop_back();
                tmpS+="}";
            }
        }
        result.push_back(tmpS);
        tmpV.clear();
    }
    return result;

}

vector<long long> day10::calculateCompletionScore(vector<string>& completesV){
    vector<long long> result;
    for(unsigned int i=0; i<completesV.size(); i++){
        long long calcRow=0;
        for(unsigned int j=0; j<completesV[i].size(); j++){
            char actualC = completesV[i][j];
            calcRow*=5;
            if(actualC==')')    calcRow+=1;
            else if(actualC==']')   calcRow+=2;
            else if(actualC=='}')   calcRow+=3;
            else if(actualC=='>')   calcRow+=4;
        }
        result.push_back(calcRow);
    }
    return result; 
}

long long day10::findMiddle(vector<long long>& complcalcV){
    std::sort(complcalcV.begin(),complcalcV.end());
    //sort array
    int index=complcalcV.size()/2;
    //pick array[size/2]
    return complcalcV[index];
   // return complcalcV[index];
}

