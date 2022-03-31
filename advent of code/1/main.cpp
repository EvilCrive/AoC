#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int numbers[2000];
    ifstream in("input_1.txt");

    if (!in) {
        cout << "Cannot open file noob";
        return 1;
    }

    for(unsigned int i=0; i<2000; i++){
        in >> numbers;
    }



} 