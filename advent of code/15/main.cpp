#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int calculatePath(std::vector<std::vector<int>>& map, std::vector<int>& path, int i, int j, int path_i){
    if(i==0 && j==0){
        path_i = calculatePath(map,path,i+1,j, path_i);
        path_i = calculatePath(map,path,i,j+1, path_i);
    }else if(i==99 && j==99){
        path_i++;
        path.push_back(path_i);
    }else if(i<99 || j<99){
        path_i = calculatePath(map,path, i+1, j, path_i+map[i][j]);
        path_i = calculatePath(map, path, i, j+1, path_i+map[i][j]);
    }
    return path_i;
}

int main(){
    std::ifstream in("input");
    std::vector<std::vector<int>> mapField;
    for(std::string s; std::getline(in,s);){
        std::vector<int> row;
        for(unsigned int i=0; i<s.size(); i++)
          row.push_back(s[i]-'0');
        mapField.push_back(row);
    }
    //lowest path [0,0] -> [99,99]
    std::vector<int> path_size;
    calculatePath(mapField, path_size, 0, 0, 0);
    int min = 600;
    for(unsigned int i=0; i<path_size.size(); i++)  if(min>path_size[i])    min=path_size[i];
    std::cout<<min;
}