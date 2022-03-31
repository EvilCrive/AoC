
#include "day10.h"

int main(){
    vector<string> input = day10::readInput();
    day10::discardCorrupted(input);
    
    vector<string> autoCompletes = day10::completeIncompletes(input);
    
    vector<long long> completionScore = day10::calculateCompletionScore(autoCompletes);
    std::cout<<day10::findMiddle(completionScore);
}