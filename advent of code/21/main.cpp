#include <iostream>
#include <tuple>

void partOne();
void partTwo();

int main(){
    partTwo();
}

int p1_wins=0;
int p2_wins=0;

void recursiveF(int start_p1, int start_p2, int score_p1, int score_p2, int sum1, int sum2){

    if(sum1!=0 && sum2!=0){
        start_p1+=sum1;
        start_p2+=sum2;
        while(start_p1>10)  start_p1-=10;
        while(start_p2>10)  start_p2-=10;
        score_p1+=start_p1;
        score_p2+=start_p2;
    }
    if(score_p1>20){
        p1_wins++;
        return;
    }
    if(score_p2>20){
        p2_wins++;
        return;
    }
    for(unsigned int i=3; i<=9; i++){
        for(unsigned int k=3; k<=9; k++){
            recursiveF(start_p1, start_p2, score_p1, score_p2, i, k);
        }
    }
    
    /*roll111
    roll112
    roll113

    roll121
    roll122
    roll123

    roll131
    roll132
    roll133

    roll211
    roll212
    roll213

    roll221
    roll222
    roll223

    roll231
    roll232
    roll233

    roll311
    roll312
    roll313

    roll321
    roll322
    roll323

    roll331
    roll332
    roll333*/

}

void partTwo(){
    int starting_point_p1=7;
    int starting_point_p2=6;
    int score_p1=0;
    int score_p2=0;
    recursiveF(7,6,0,0,0,0);
    std::cout<<p1_wins<<" "<<p2_wins;
}
void partOne(){
    
    int starting_point_p1=7;
    int starting_point_p2=6;
    int score_p1=0;
    int score_p2=0;
    int dice_counter=1;
    int counter_dice=0;
    while(score_p1<1000 && score_p2<1000){
        int sum1=0;
        int sum2=0;

        if(dice_counter==101)   dice_counter=1;
        sum1+=dice_counter;
        dice_counter++;
        counter_dice++;
        if(dice_counter==101)   dice_counter=1;
        sum1+=dice_counter;
        dice_counter++;
        counter_dice++;
        if(dice_counter==101)   dice_counter=1;
        sum1+=dice_counter;
        dice_counter++;
        counter_dice++;

        if(dice_counter==101)   dice_counter=1;

        starting_point_p1+=sum1;
        while(starting_point_p1>10){
            starting_point_p1-=10;
        }
        score_p1+=starting_point_p1;
        if(score_p1>999)    break;

        if(dice_counter==101)   dice_counter=1;
        sum2+=dice_counter;
        dice_counter++;
        counter_dice++;
        if(dice_counter==101)   dice_counter=1;
        sum2+=dice_counter;
        dice_counter++;
        counter_dice++;
        if(dice_counter==101)   dice_counter=1;
        sum2+=dice_counter;
        dice_counter++;
        counter_dice++;

        starting_point_p2+=sum2;
        while(starting_point_p2>10){
            starting_point_p2-=10;
        }
        score_p2+=starting_point_p2;

    }
    if(score_p1>999)    std::cout<<score_p2*counter_dice;
    else if(score_p2>999)   std::cout<<score_p1*counter_dice;
}