#include <iostream>
#include <fstream>

int main(){
    int horizontalC = 0;
    int depthC = 0;
    int aim = 0;
    std::string commands[1000];
    int number[1000];
    
    std::ifstream in("input.txt");
    
    if(!in){
        std::cout<<"Cannot open file";
        return 1;
    }

    for(unsigned int i = 0; i<1000; i++){
        in>>commands[i];
        in>>number[i];
    }

    /*for(unsigned int i=0; i<11; i++){
        std::cout<<commands[i]<<" "<<number[i]<<std::endl;
    }*/
/*
    for(unsigned int i=0; i<1000; i++){
        if(commands[i]=="forward"){
            horizontalC+=number[i];
        }else if(commands[i]=="up"){
            depthC-=number[i];
        }else if(commands[i]=="down"){
            depthC+=number[i];
        }
    }
*/

    for(unsigned int i=0; i<1000; i++){
        if(commands[i]=="forward"){
            horizontalC+=number[i];
            depthC+=aim*number[i];
        }else if(commands[i]=="up"){
            aim-=number[i];
        }else if(commands[i]=="down"){
            aim+=number[i];
        }
    }
    std::cout<<horizontalC*depthC;


}