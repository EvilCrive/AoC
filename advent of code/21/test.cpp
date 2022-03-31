#include <iostream>
#include <fstream>
#include <tuple>

int main(){
    std::tuple<int,int> start = std::make_tuple(0,0);
    std::get<0>(start)++;
    std::cout<<std::get<0>(start);
    
}