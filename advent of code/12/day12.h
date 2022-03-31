#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>



namespace day12
{
    struct node{
    std::string value;
    std::vector<node*> links;
    };

    void partOne();

    std::vector<std::vector<std::string>> readInput();
    std::map<std::string, std::vector<std::string>> parseInput(std::vector<std::vector<std::string>>&, std::vector<std::string>&);
    day12::node* createTree(std::map<std::string, std::vector<std::string>>&, std::vector<std::string>&, std::string);
    void print(node*);
    day12::node* scam();
}