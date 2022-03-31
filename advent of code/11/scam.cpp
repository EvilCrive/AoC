#include <algorithm>
#include <cstddef>
#include <iostream>
#include <fstream>
#include <list>
#include <utility>
#include <vector>
#include <string>
#include <bitset>
#include <stdio.h>
#include <math.h>     
using namespace std;
template<class L>
void printVector(list<L> lista){
    cout<<"-- start element --"<<endl;
    for(auto x: lista){
        cout<<x<<" ";
    }
    cout<<endl<<"-- finish element --"<<endl;
}
template<class T>
vector<T> createArr(string tmp, string sep){
    vector<T> tmpList;
    size_t pos=0;
    string token;
    while((pos = tmp.find(sep))!=string::npos){
        token = tmp.substr(0,pos);
        tmpList.push_back(token);
        tmp.erase(0,pos+sep.length());
    }
    tmpList.push_back(tmp);
    return tmpList;
}
void print_matrix(int tmp[10][10]){
    for(unsigned int i=0; i<10;i++){
        for(unsigned int j=0; j<10; j++)
            cout<<tmp[i][j];
        cout<<endl;
    }
}
 
struct point{
    unsigned int x;
    unsigned int y;
};
long long int counter=0;
void explode(point lower, int (&matrix)[10][10]){
    counter++;
    unsigned int i=lower.x;
    unsigned int j=lower.y;
    matrix[i][j]=-100;
 
    
    if (i!=0){
        matrix[i-1][j]++;
        if (matrix[i-1][j]>9) {
            explode({i-1,j}, matrix);
        }
        if (j!=0){
            matrix[i-1][j-1]++;
            if (matrix[i-1][j-1]>9) {
                explode({i-1,j-1}, matrix);
            }
        }
    }
    if (i!=9){ 
        matrix[i+1][j]++;
        if (matrix[i+1][j]>9) {
            explode({i+1,j}, matrix);
        }
        if (j!=9){
            matrix[i+1][j+1]++;
            if (matrix[i+1][j+1]>9) {
                explode({i+1,j+1}, matrix);
            }
        }
    }
    if (j!=0){
        matrix[i][j-1]++;
        if (matrix[i][j-1]>9) {
            explode({i,j-1}, matrix);
        }
        if (i!=9){
            matrix[i+1][j-1]++;
            if (matrix[i+1][j-1]>9) {
                explode({i+1,j-1}, matrix);
            }
        }
    }
    if (j!=9){
        matrix[i][j+1]++;
        if (matrix[i][j+1]>9) {
            explode({i,j+1}, matrix);
        }
        if (i!=0){
            matrix[i-1][j+1]++;
            if (matrix[i-1][j+1]>9) {
                explode({i-1,j+1}, matrix);
            }
        }
    }
 
}
 
unsigned int exploded=0;
int main(){
    ifstream myfile;
    myfile.open("input");
    //myfile.open("./input");
    string line;
    int matrix[10][10];
    unsigned int lineIter=0;
 
    while(getline(myfile, line)){
    for(unsigned int i=0; i<10; i++){
            matrix[lineIter][i]=line[i]-48;
        }
        lineIter++;
    }
    for(unsigned int iterations=0; iterations<1000;iterations++){
        //cout<<"-- step "<<iterations+1<<" --"<<endl;
        // exploding
        for(unsigned int i=0; i<10;i++){
            for(unsigned int j=0; j<10; j++){
                matrix[i][j]++;
                if(matrix[i][j]>9){
                    explode({i,j}, matrix);
                }
            }
        }
        // fixing exploded nodes
        for(unsigned int i=0; i<10;i++){
            for(unsigned int j=0; j<10; j++){
                if(matrix[i][j]<0){
                    matrix[i][j]=0;
                    exploded++;
                }
            }
        }
        if(exploded==100) cout<<"exploded iteration: "<<iterations+1<<endl;
        exploded=0;
        //print_matrix(matrix);
    }
    cout<<"Counter: "<<counter<<endl;
}