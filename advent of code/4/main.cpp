#include <iostream>
#include <fstream>
#include <vector>
#include <list>

int main(){
    std::ifstream in("input");
    std::vector<int> numeriChiamati;
    std::string numeriChiamatiS;

    std::list<std::vector<std::vector<int>>> celle;

    in>>numeriChiamatiS;
    for(unsigned int k=0; k<100; k++){
        std::vector<std::vector<int>> v2;
        for(unsigned int i=0; i<5; i++){
            std::vector<int> v1;
            for(unsigned int j=0; j<5; j++){
                int tmp=0;
                in>>tmp;
                v1.push_back(tmp);
            }
            v2.push_back(v1);
        }
        celle.push_back(v2);
    }
    int tmp=-1;
    for(unsigned int i=0; i<=numeriChiamatiS.size();i++){
        if(numeriChiamatiS[i]==',' || numeriChiamatiS.size()==i){
            numeriChiamati.push_back(tmp);
            tmp=-1;
        }else{
            if(tmp!=-1){
                tmp=tmp*10+(numeriChiamatiS[i]-'0');
            }else{
                tmp=numeriChiamatiS[i]-'0';
            }
        }
        std::cout<<std::endl;
    }
    
    int numberend = -1;
    int winningMatrix[5][5];
    bool modifica = true;
    for(unsigned int k=0; k<numeriChiamati.size();k++){
        int numberCalled = numeriChiamati[k];
        std::list<std::vector<std::vector<int>>>::iterator it;
        for(it = celle.begin(); it!=celle.end(); ++it){
            for(unsigned int i=0; i<5;i++){
                for(unsigned int j=0;j<5;j++){
                    if((*it)[i][j]==numberCalled && modifica){
                        (*it)[i][j]=-1;
                        if((((*it)[i][0]==-1) && ((*it)[i][1]==-1) && ((*it)[i][2]==-1) && ((*it)[i][3]==-1) && ((*it)[i][4] ==-1)) ||(((*it)[0][j]==-1) && ((*it)[1][j]==-1) && ((*it)[2][j]==-1) && ((*it)[3][j]==-1) && ((*it)[4][j] ==-1))){
                            numberend=numberCalled;
                            modifica=false;
                            for(unsigned int a=0;a<5;a++){
                                for(unsigned int b=0;b<5;b++){
                                    winningMatrix[a][b]=(*it)[a][b];
                                }
                            }
                        }
                    
                    }
                }
            }
        }
    
    }
    int sum=0;
    for(unsigned int i=0; i<5;i++){
        for(unsigned int j=0; j<5; j++){
            if(numberend!=-1 && winningMatrix[i][j]!=-1) sum+=winningMatrix[i][j];
        }
    }
    if(numberend==-1)   std::cout<<"stupid";
    else    std::cout<<numberend*sum;
/*
        std::list<std::vector<std::vector<int>>>::iterator it;
        for(it = celle.begin(); it!=celle.end(); ++it){
            std::vector<std::vector<int>> v = *it;
            for(unsigned int i=0; i<5;i++){
                for(unsigned int j=0; j<5;j++){
                    std::cout<<v[i][j];
                }
            }
            std::cout<<std::endl;
        }*/
        std::cout<<" "<<numberend<<std::endl;

        for(unsigned int i=0;i<5;i++){
            for(unsigned int j=0;j<5;j++){
                std::cout<<winningMatrix[i][j]<< " ";
            }
        }
    
}
