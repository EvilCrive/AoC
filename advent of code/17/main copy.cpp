#include <iostream>
#include <vector>
#include <string>
#include <tuple>

int r_x1=236;
int r_x2=262;
int r_y1=-78;
int r_y2=-58;

bool createPath(int x, int y){
    int x1=x;
    int y1=y;
    int last=1;
    bool check = false;
    bool loop = false;
    int pos[2];
    pos[0]=0;pos[1]=0;
    while(true){
        pos[0]+=x1;pos[1]+=y1;
        if (pos[0] > r_x2 || (y1 < 0 && pos[1] < r_y1)){
            check = false;break;
        }
        if (r_x1 <= pos[0] && pos[0] <= r_x2 && r_y1 <= pos[1] && pos[1] <= r_y2){
            check = true;break;
        }
        if(x1<0)    x1++;
        if(x1>0)    x1--;
        y1--;
    }
    return check;
}

int main(){
    int c=0;
    for(unsigned int i=0; i<1000; i++){
        for(unsigned int j=0; j<1000; j++){
            if(createPath(i-500,j-500)) c++;
        }
    }
    /*int max_y=0;
    for(unsigned int i=0; i<collection.size(); i++){
        for(unsigned int j=0; j<collection[i].size(); j++){
            if(std::get<1>(collection[i][j])>max_y) max_y=std::get<1>(collection[i][j]);
        }
    }*/
    std::cout<<c;//ollection.size();
}