#include <iostream>
#include <vector>
#include <string>
#include <fstream>

namespace Day8{
    void readInput(std::vector<std::vector<std::string>>&, std::vector<std::vector<std::string>>&);
    void partOne(std::vector<std::vector<std::string>>&);
    void partTwo(std::vector<std::vector<std::string>>&, std::vector<std::vector<std::string>>&);
    namespace Utils{
        void printArray(std::vector<std::string>&);
        bool compare2strings(std::string, std::string);
    }
    
}

int main(){
    std::vector<std::vector<std::string>> inputV, outputV;
    Day8::readInput(inputV, outputV);
    //Day8::Utils::printArray(inputV[1]);
    Day8::partTwo(inputV, outputV);
}

void Day8::partOne(std::vector<std::vector<std::string>>& array){
    int counter=0;
    for(unsigned int i=0; i<200; i++){
        for(unsigned int j=0; j<4; j++){
            if((array[i][j].size()==2) ||(array[i][j].size()==3) ||(array[i][j].size()==4) ||(array[i][j].size()==7)){
                counter++;
            }
        }  
    }
    std::cout<<counter;
}

void Day8::partTwo(std::vector<std::vector<std::string>>& array, std::vector<std::vector<std::string>>& outputV){
    int result=0;
    for(unsigned int k=0; k<200; k++){
        std::string num0, num1, num2, num3, num4, num5, num6, num7, num8, num9;
        for(unsigned int i=0; i<10; i++){
            if(array[k][i].size()==2){
                num1 = array[k][i];
            }else if(array[k][i].size()==3){  
                num7 = array[k][i];
            }else if(array[k][i].size()==4){
                num4 = array[k][i];
            }else if(array[k][i].size()==7){
                num8 = array[k][i];
            }
        }
        char aaaa,bb,cc,dddd,ee,ff,gggg;
        //find aaaa
        char num1a, num1b, num7a, num7b, num7c;
        num1a=num1[0];num1b=num1[1];
        num7a=num7[0];num7b=num7[1];num7c=num7[2];
        if(num1a==num7a){
            if(num1b==num7b){
                aaaa=num7c;
            }else if(num1b==num7c){
                aaaa=num7b;
            }
        }else if(num1a==num7b){
            if(num1b==num7a){
                aaaa=num7c;
            }else if(num1b==num7c){
                aaaa=num7a;
            }
        }else if(num1a==num7c){
            if(num1b==num7a){
                aaaa=num7b;
            }else if(num1b==num7b){
                aaaa=num7a;
            }
        }
        //find dddd and bb
        char extra1, extra2;
        char num4a, num4b, num4c, num4d;
        num4a=num4[0];num4b=num4[1];num4c=num4[2];num4d=num4[3];
        if(num1a==num4a){
            if(num1b==num4b){
                extra1=num4c;
                extra2=num4d;
            }else if(num1b==num4c){
                extra1=num4b;
                extra2=num4d;
            }else if(num1b==num4d){
                extra1=num4b;
                extra2=num4c;
            }
        }else if(num1a==num4b){
            if(num1b==num4a){
                extra1=num4c;
                extra2=num4d;
            }else if(num1b==num4c){
                extra1=num4a;
                extra2=num4d;
            }else if(num1b==num4d){
                extra1=num4a;
                extra2=num4c;
            }
        }else if(num1a==num4c){
            if(num1b==num4a){
                extra1=num4b;
                extra2=num4d;
            }else if(num1b==num4b){
                extra1=num4a;
                extra2=num4d;
            }else if(num1b==num4d){
                extra1=num4a;
                extra2=num4b;
            }
        }else if(num1a==num4d){
            if(num1b==num4a){
                extra1=num4b;
                extra2=num4c;
            }else if(num1b==num4b){
                extra1=num4a;
                extra2=num4c;
            }else if(num1b==num4c){
                extra1=num4a;
                extra2=num4b;
            }
        }
        std::string sixdigits1, sixdigits2, sixdigits3;
        int counter=0;
        for(unsigned int i=0; i<10; i++){
            if(array[k][i].size()==6){
                if(counter==0){
                    sixdigits1=array[k][i];
                    counter++;
                }else if(counter==1){
                    sixdigits2=array[k][i];
                    counter++;
                }else if(counter==2){
                    sixdigits3=array[k][i];
                    counter++;
                }
            }
        }

        std::string sixnine1, sixnine2;
        if((sixdigits1.find(extra1)==std::string::npos) || (sixdigits1.find(extra2)==std::string::npos)){
            num0=sixdigits1;
            sixnine1=sixdigits2;
            sixnine2=sixdigits3;
        }else if((sixdigits2.find(extra1)==std::string::npos) || (sixdigits2.find(extra2)==std::string::npos)){
            num0=sixdigits2;
            sixnine1=sixdigits1;
            sixnine2=sixdigits3;
        }else if((sixdigits3.find(extra1)==std::string::npos) || (sixdigits3.find(extra2)==std::string::npos)){
            num0=sixdigits3;
            sixnine1=sixdigits1;
            sixnine2=sixdigits2;
        }

        if(num0.find(extra1)==std::string::npos){
            dddd=extra1;
            bb=extra2;
        }else if(num0.find(extra2)==std::string::npos){
            dddd=extra2;
            bb=extra1;
        }

        //find cc and ff
        if((sixnine1.find(num1a)!=std::string::npos) && (sixnine1.find(num1b)!=std::string::npos)){
            num9=sixnine1;
            num6=sixnine2;
        }else if((sixnine2.find(num1a)!=std::string::npos) && (sixnine2.find(num1b)!=std::string::npos)){
            num9=sixnine2;
            num6=sixnine1;
        }
        if((num6.find(num1a)==std::string::npos)){
            cc=num1a;
            ff=num1b;
        }else if(num6.find(num1b)==std::string::npos){
            cc=num1b;
            ff=num1a;
        }
        //find gggg
        std::string fivedigits1, fivedigits2, fivedigits3;
        std::string twofive1, twofive2;
        counter=0;
        for(unsigned int i=0; i<10; i++){
            if(array[k][i].size()==5){
                if(counter==0){
                    fivedigits1=array[k][i];
                    counter++;
                }else if(counter==1){
                    fivedigits2=array[k][i];
                    counter++;
                }else if(counter==2){
                    fivedigits3=array[k][i];
                    counter++;
                }
            }
        }

        if((fivedigits1.find(cc)!=std::string::npos)&&(fivedigits1.find(ff)!=std::string::npos)){
            num3=fivedigits1;
            twofive1=fivedigits2;
            twofive2=fivedigits3;
        }else if((fivedigits2.find(cc)!=std::string::npos)&&(fivedigits2.find(ff)!=std::string::npos)){
            num3=fivedigits2;
            twofive1=fivedigits1;
            twofive2=fivedigits3;
        }else if((fivedigits3.find(cc)!=std::string::npos)&&(fivedigits3.find(ff)!=std::string::npos)){
            num3=fivedigits3;
            twofive1=fivedigits1;
            twofive2=fivedigits2;
        }

        if(twofive1.find(cc)==std::string::npos){
            num5=twofive1;
            num2=twofive2;
        }else if(twofive2.find(cc)==std::string::npos){
            num5=twofive2;
            num2=twofive1;
        }
        std::string findGggg=num3;
        for(unsigned int k=0; k<6;k++){
            for(unsigned int i=0;i<5;i++){
                if(findGggg[i]==cc || findGggg[i]==aaaa || findGggg[i]==ff || findGggg[i]==dddd) findGggg.erase(i,1);i=5;
            }
        }
        gggg=findGggg[0];
        //find ee
        std::string findEe=num8;
        for(unsigned int k=0; k<8;k++){
            for(unsigned int i=0;i<5;i++){
                if(findEe[i]==aaaa || findEe[i]==bb || findEe[i]==cc || findEe[i]==ff || findEe[i]==dddd || findEe[i]==gggg) findEe.erase(i,1);i=5;
            }
        }
        ee=findEe[0];
        //std::cout<<k<<": "<<"aaaa: "<<aaaa<<", bb: "<<bb<<", cc: "<<cc<<", dddd:"<<dddd<<", ee: "<<ee<<", ff: "<<ff<<"."<<", gggg: "<<gggg<<std::endl;
        //std::cout<<num1<<" "<<num2<<" "<<num3<<" "<<num4<<" "<<num5<<" "<<num6<<" "<<num7<<" "<<num8<<" "<<num9<<std::endl;
        //output
        std::string output="";
        for(unsigned int j=0; j<4; j++){
            if(Utils::compare2strings(outputV[k][j],num0)){
                output+="0";
            }else if(Utils::compare2strings(outputV[k][j],num1)){
                output+="1";
            }else if(Utils::compare2strings(outputV[k][j],num2)){
                output+="2";
            }else if(Utils::compare2strings(outputV[k][j],num3)){
                output+="3";
            }else if(Utils::compare2strings(outputV[k][j],num4)){
                output+="4";
            }else if(Utils::compare2strings(outputV[k][j],num5)){
                output+="5";
            }else if(Utils::compare2strings(outputV[k][j],num6)){
                output+="6";
            }else if(Utils::compare2strings(outputV[k][j],num7)){
                output+="7";
            }else if(Utils::compare2strings(outputV[k][j],num8)){
                output+="8";
            }else if(Utils::compare2strings(outputV[k][j],num9)){
                output+="9";
            }

        }
        
        std::string::size_type sz;
        int outputN = std::stoi(output, &sz);
        result+=outputN;
    }
    std::cout<<result;

}

bool Day8::Utils::compare2strings(std::string s1, std::string s2){
    if(s1.size()!=s2.size())    return false;
    for(unsigned int i=0; i<s1.size();i++){
        bool check=false;
        for(unsigned int j=0; j<s1.size();j++){
            if(s1[i]==s2[j])    check=true;
        }
        if (check==false)  return false;
    }
    return true;
}

void Day8::readInput(std::vector<std::vector<std::string>>& inputV, std::vector<std::vector<std::string>>& outputV){
    std::ifstream in("input");
    std::string s;
    bool sbarra = false;
    for(unsigned int j=0; j<200; j++){
        std::vector<std::string> inputMV, outputMV;
        for(unsigned int i=0; i<15; i++){
            in>>s;
            if(s=="|")  sbarra=true;
            else{
                if(!sbarra)  inputMV.push_back(s);
                else    outputMV.push_back(s);
            }
        }
        inputV.push_back(inputMV);
        outputV.push_back(outputMV);
        sbarra=false;
    }
}
void Day8::Utils::printArray(std::vector<std::string>& tmp){
    for(unsigned int i=0; i<tmp.size(); i++){
        std::cout<<tmp[i]<<" ";
    }
    std::cout<<std::endl;
}