#include <iostream>
#include <vector>
#include <string>
#include <tuple>

int r_x1=236;
int r_x2=262;
int r_y1=-78;
int r_y2=-58;


bool checkRegion(int x, int y){
    return ((x>=r_x1) && (x<=r_x2) && (y>=r_y1) && (y<=r_y2));
}

std::vector<std::tuple<int,int>> createPath(int x, int y){
    std::vector<std::tuple<int,int>> points;
    points.push_back(std::make_tuple(0,0));
    points.push_back(std::make_tuple(x,y));
    int x1=x;
    int y1=y;
    int last=1;
    bool check = false;
    bool loop = false;
    while(loop==false){
        points.push_back(std::make_tuple(std::get<0>(points[last])+x1,std::get<1>(points[last])+y1));
        last++;
        int pos0=std::get<0>(points[last]);
        int pos1=std::get<1>(points[last]);
        if (pos0 > r_x2 || (y1 < 0 && pos1 < r_y1)){
            check = false;break;
        }
        if (r_x1 <= pos0 && pos0 <= r_x2 && r_y1 <= pos1 && pos1 <= r_y2){
            check = true;break;
        }
        if(x1<0)    x1++;
        if(x1>0)    x1--;
        y1--;
    }
    if(!check)  points.clear();
    return points;   
}

int main(){
    int c=0;
    std::vector<std::vector<std::tuple<int,int>>> collection;
    for(unsigned int i=0; i<1000; i++){
        for(unsigned int j=0; j<1000; j++){
            std::vector<std::tuple<int,int>> tmp = createPath(i-500,j-500);
            if(!tmp.empty())    c++;//collection.push_back(tmp);
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