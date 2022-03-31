#include "day9.h"

std::vector<std::vector<int>> Day9::Utils::findLowestPoints(std::vector<std::vector<int>>& field){
    int rows = field.size();
    int columns = field[0].size();
    std::vector<std::vector<int>> lowestPoints;
    for(unsigned int i=0; i<rows; i++){
        for(unsigned int j=0; j<columns; j++){
            
            if(i==0 || j==0 || i==rows-1 || j==columns-1){
                if(i==0 && j==0){
                    //corner topleft
                    if((field[i][j]<field[i+1][j])&&(field[i][j]<field[i][j+1])){
                        std::vector<int> actualLowestPoint;
                        actualLowestPoint.push_back(i);
                        actualLowestPoint.push_back(j);
                        lowestPoints.push_back(actualLowestPoint);
                    }
                }else if(i==0 && j==columns-1){
                    //corner topright
                    if((field[i][j]<field[i+1][j])&&(field[i][j]<field[i][j-1])){
                        std::vector<int> actualLowestPoint;
                        actualLowestPoint.push_back(i);
                        actualLowestPoint.push_back(j);
                        lowestPoints.push_back(actualLowestPoint);
                        
                    }
                }else if(i==rows-1 && j==0){
                    //corner bottomleft
                    if((field[i][j]<field[i-1][j])&&(field[i][j]<field[i][j+1])){
                        std::vector<int> actualLowestPoint;
                        actualLowestPoint.push_back(i);
                        actualLowestPoint.push_back(j);
                        lowestPoints.push_back(actualLowestPoint);
                    }
                }else if(i==rows-1 && j==columns-1){
                    //corner bottomright
                    if((field[i][j]<field[i-1][j])&&(field[i][j]<field[i][j-1])){
                        std::vector<int> actualLowestPoint;
                        actualLowestPoint.push_back(i);
                        actualLowestPoint.push_back(j);
                        lowestPoints.push_back(actualLowestPoint);
                    }
                }else if(i==0){
                    if((field[i][j]<field[i+1][j])&&(field[i][j]<field[i][j-1])&&(field[i][j]<field[i][j+1])){
                        std::vector<int> actualLowestPoint;
                        actualLowestPoint.push_back(i);
                        actualLowestPoint.push_back(j);
                        lowestPoints.push_back(actualLowestPoint);
                    }
                }else if(j==0){
                    if((field[i][j]<field[i-1][j])&&(field[i][j]<field[i+1][j])&&(field[i][j]<field[i][j+1])){
                        std::vector<int> actualLowestPoint;
                        actualLowestPoint.push_back(i);
                        actualLowestPoint.push_back(j);
                        lowestPoints.push_back(actualLowestPoint);
                    }
                }else if(i==rows-1){
                    if((field[i][j]<field[i-1][j])&&(field[i][j]<field[i][j-1])&&(field[i][j]<field[i][j+1])){
                        std::vector<int> actualLowestPoint;
                        actualLowestPoint.push_back(i);
                        actualLowestPoint.push_back(j);
                        lowestPoints.push_back(actualLowestPoint);
                    }
                }else if(j==columns-1){
                    if((field[i][j]<field[i-1][j])&&(field[i][j]<field[i+1][j])&&(field[i][j]<field[i][j-1])){
                        std::vector<int> actualLowestPoint;
                        actualLowestPoint.push_back(i);
                        actualLowestPoint.push_back(j);
                        lowestPoints.push_back(actualLowestPoint);
                    }
                }
            }else if((field[i][j]<field[i-1][j])&&(field[i][j]<field[i+1][j])&&(field[i][j]<field[i][j-1])&&(field[i][j]<field[i][j+1])){
                    std::vector<int> actualLowestPoint;
                    actualLowestPoint.push_back(i);
                    actualLowestPoint.push_back(j);
                    lowestPoints.push_back(actualLowestPoint);
            }
        }
    }
    return lowestPoints;
}

bool comparePoints(std::vector<std::vector<int>>& field, int i, int j, int i2, int j2){
    if(
        (
            abs(field[i][j])<field[i2][j2]
            )
        &&(abs(field[i][j])==(field[i2][j2]-1))
        &&(field[i2][j2]<9)//&&(field[i2][j2]>0)
        )
        return true;
    else return false;
}

int Day9::Utils::basinSize(std::vector<std::vector<int>>& field, int rowL, int columnL){
    int rowMax = field.size()-1;
    int columnMax = field[rowL].size()-1;
    int neighborgsBasinSize = 0;
    //field[rowL][columnL]*=-1;


    if(rowL==0 && columnL==0){
        if(comparePoints(field, rowL, columnL, rowL+1, columnL)){
            neighborgsBasinSize+=basinSize(field, rowL+1, columnL);
        }
        if(comparePoints(field, rowL, columnL, rowL, columnL+1)){
            neighborgsBasinSize+=basinSize(field, rowL, columnL+1);
        }
    }else if(rowL==0 && columnL==columnMax){
        if(comparePoints(field, rowL, columnL, rowL+1, columnL)){
            neighborgsBasinSize+=basinSize(field, rowL+1, columnL);
        }
        if(comparePoints(field, rowL, columnL, rowL, columnL-1)){
            neighborgsBasinSize+=basinSize(field, rowL, columnL-1);
        }

    }else if(rowL==rowMax && columnL==0){
        if(comparePoints(field, rowL, columnL, rowL-1, columnL)){
            neighborgsBasinSize+=basinSize(field, rowL-1, columnL);
        }
        if(comparePoints(field, rowL, columnL, rowL, columnL+1)){
            neighborgsBasinSize+=basinSize(field, rowL, columnL+1);
        }

    }else if(rowL==rowMax && columnL==columnMax){
        if(comparePoints(field, rowL, columnL, rowL-1, columnL)){
            neighborgsBasinSize+=basinSize(field, rowL-1, columnL);
        }
        if(comparePoints(field, rowL, columnL, rowL, columnL-1)){
            neighborgsBasinSize+=basinSize(field, rowL, columnL-1);
        }
    }else if(columnL==0){
        if(comparePoints(field, rowL, columnL, rowL+1, columnL)){
            neighborgsBasinSize+=basinSize(field, rowL+1, columnL);
        }
        if(comparePoints(field, rowL, columnL, rowL, columnL+1)){
            neighborgsBasinSize+=basinSize(field, rowL, columnL+1);
        }
        if(comparePoints(field, rowL, columnL, rowL-1, columnL)){
            neighborgsBasinSize+=basinSize(field, rowL-1, columnL);
        }
    }else if(columnL==columnMax){
        if(comparePoints(field, rowL, columnL, rowL+1, columnL)){
            neighborgsBasinSize+=basinSize(field, rowL+1, columnL);
        }
        if(comparePoints(field, rowL, columnL, rowL, columnL-1)){
            neighborgsBasinSize+=basinSize(field, rowL, columnL-1);
        }
        if(comparePoints(field, rowL, columnL, rowL-1, columnL)){
            neighborgsBasinSize+=basinSize(field, rowL-1, columnL);
        }
    }else if(rowL==0){
        if(comparePoints(field, rowL, columnL, rowL+1, columnL)){
            neighborgsBasinSize+=basinSize(field, rowL+1, columnL);
        }
        if(comparePoints(field, rowL, columnL, rowL, columnL-1)){
            neighborgsBasinSize+=basinSize(field, rowL, columnL-1);
        }
        if(comparePoints(field, rowL, columnL, rowL, columnL+1)){
            neighborgsBasinSize+=basinSize(field, rowL, columnL+1);
        }  
    }else if(rowL==rowMax){
        if(comparePoints(field, rowL, columnL, rowL-1, columnL)){
            neighborgsBasinSize+=basinSize(field, rowL-1, columnL);
        }
        if(comparePoints(field, rowL, columnL, rowL, columnL-1)){
            neighborgsBasinSize+=basinSize(field, rowL, columnL-1);
        }
        if(comparePoints(field, rowL, columnL, rowL, columnL+1)){
            neighborgsBasinSize+=basinSize(field, rowL, columnL+1);
        }  
    }else{
        if(comparePoints(field, rowL, columnL, rowL-1, columnL)){
            neighborgsBasinSize+=basinSize(field, rowL-1, columnL);
        }
        if(comparePoints(field, rowL, columnL, rowL+1, columnL)){
            neighborgsBasinSize+=basinSize(field, rowL+1, columnL);
        }
        if(comparePoints(field, rowL, columnL, rowL, columnL-1)){
            neighborgsBasinSize+=basinSize(field, rowL, columnL-1);
        }
        if(comparePoints(field, rowL, columnL, rowL, columnL+1)){
            neighborgsBasinSize+=basinSize(field, rowL, columnL+1);
        }  
    }
    return 1+neighborgsBasinSize;
}


int Day9::Utils::basinSizeNew(std::vector<std::vector<int>>& field, std::vector<std::vector<bool>>& fieldBool, int rowL, int columnL){
    int rowMax = field.size()-1;
    int columnMax = field[rowL].size()-1;
    int basinS = 0;
    if(fieldBool[rowL][columnL])    return 0;
    fieldBool[rowL][columnL]=true;
    int x,y;

    if(rowL==0 && columnL==0){
        x=1;y=0;
        if(( field[rowL][columnL]<field[rowL+x][columnL+y]) &&(field[rowL+x][columnL+y]<9)){
            basinS+=basinSizeNew(field, fieldBool, rowL+x, columnL+y);
        }
        x=0;y=1;
        if(( field[rowL][columnL]<field[rowL+x][columnL+y]) &&(field[rowL+x][columnL+y]<9)){
            basinS+=basinSizeNew(field, fieldBool, rowL+x, columnL+y);
        }

    }else if(rowL==0 && columnL==columnMax){
        x=1;y=0;
        if(( field[rowL][columnL]<field[rowL+x][columnL+y]) &&(field[rowL+x][columnL+y]<9)){
            basinS+=basinSizeNew(field, fieldBool, rowL+x, columnL+y);
        }
        x=0;y=-1;
        if(( field[rowL][columnL]<field[rowL+x][columnL+y]) &&(field[rowL+x][columnL+y]<9)){
            basinS+=basinSizeNew(field, fieldBool, rowL+x, columnL+y);
        }
    }else if(rowL==rowMax && columnL==0){
        x=-1;y=0;
        if(( field[rowL][columnL]<field[rowL+x][columnL+y]) &&(field[rowL+x][columnL+y]<9)){
            basinS+=basinSizeNew(field, fieldBool, rowL+x, columnL+y);
        }
        x=0;y=1;
        if(( field[rowL][columnL]<field[rowL+x][columnL+y]) &&(field[rowL+x][columnL+y]<9)){
            basinS+=basinSizeNew(field, fieldBool, rowL+x, columnL+y);
        }
    }else if(rowL==rowMax && columnL==columnMax){
        x=-1;y=0;
        if(( field[rowL][columnL]<field[rowL+x][columnL+y]) &&(field[rowL+x][columnL+y]<9)){
            basinS+=basinSizeNew(field, fieldBool, rowL+x, columnL+y);
        }
        x=0;y=-1;
        if(( field[rowL][columnL]<field[rowL+x][columnL+y]) &&(field[rowL+x][columnL+y]<9)){
            basinS+=basinSizeNew(field, fieldBool, rowL+x, columnL+y);
        }
    }else if(columnL==0){
        x=1;y=0;
        if(( field[rowL][columnL]<field[rowL+x][columnL+y]) &&(field[rowL+x][columnL+y]<9)){
            basinS+=basinSizeNew(field, fieldBool, rowL+x, columnL+y);
        }
        x=-1;y=0;
        if(( field[rowL][columnL]<field[rowL+x][columnL+y]) &&(field[rowL+x][columnL+y]<9)){
            basinS+=basinSizeNew(field, fieldBool, rowL+x, columnL+y);
        }
        x=0;y=1;
        if(( field[rowL][columnL]<field[rowL+x][columnL+y]) &&(field[rowL+x][columnL+y]<9)){
            basinS+=basinSizeNew(field, fieldBool, rowL+x, columnL+y);
        }
    }else if(columnL==columnMax){
        x=1;y=0;
        if(( field[rowL][columnL]<field[rowL+x][columnL+y]) &&(field[rowL+x][columnL+y]<9)){
            basinS+=basinSizeNew(field, fieldBool, rowL+x, columnL+y);
        }
        x=-1;y=0;
        if(( field[rowL][columnL]<field[rowL+x][columnL+y]) &&(field[rowL+x][columnL+y]<9)){
            basinS+=basinSizeNew(field, fieldBool, rowL+x, columnL+y);
        }
        x=0;y=-1;
        if(( field[rowL][columnL]<field[rowL+x][columnL+y]) &&(field[rowL+x][columnL+y]<9)){
            basinS+=basinSizeNew(field, fieldBool, rowL+x, columnL+y);
        }
    }else if(rowL==0){
        x=1;y=0;
        if(( field[rowL][columnL]<field[rowL+x][columnL+y]) &&(field[rowL+x][columnL+y]<9)){
            basinS+=basinSizeNew(field, fieldBool, rowL+x, columnL+y);
        }
        x=0;y=1;
        if(( field[rowL][columnL]<field[rowL+x][columnL+y]) &&(field[rowL+x][columnL+y]<9)){
            basinS+=basinSizeNew(field, fieldBool, rowL+x, columnL+y);
        }
        x=0;y=-1;
        if(( field[rowL][columnL]<field[rowL+x][columnL+y]) &&(field[rowL+x][columnL+y]<9)){
            basinS+=basinSizeNew(field, fieldBool, rowL+x, columnL+y);
        }
    }else if(rowL==rowMax){
        x=-1;y=0;
        if(( field[rowL][columnL]<field[rowL+x][columnL+y]) &&(field[rowL+x][columnL+y]<9)){
            basinS+=basinSizeNew(field, fieldBool, rowL+x, columnL+y);
        }
        x=0;y=1;
        if(( field[rowL][columnL]<field[rowL+x][columnL+y]) &&(field[rowL+x][columnL+y]<9)){
            basinS+=basinSizeNew(field, fieldBool, rowL+x, columnL+y);
        }
        x=0;y=-1;
        if(( field[rowL][columnL]<field[rowL+x][columnL+y])&&(field[rowL+x][columnL+y]<9)){
            basinS+=basinSizeNew(field, fieldBool, rowL+x, columnL+y);
        }
    }else{
        x=1;y=0;
        if(( field[rowL][columnL]<field[rowL+x][columnL+y])&&(field[rowL+x][columnL+y]<9)){
            basinS+=basinSizeNew(field, fieldBool, rowL+x, columnL+y);
        }
        x=-1;y=0;
        if(( field[rowL][columnL]<field[rowL+x][columnL+y]) &&(field[rowL+x][columnL+y]<9)){
            basinS+=basinSizeNew(field, fieldBool, rowL+x, columnL+y);
        }  
        x=0;y=1;
        if(( field[rowL][columnL]<field[rowL+x][columnL+y])&&(field[rowL+x][columnL+y]<9)){
            basinS+=basinSizeNew(field, fieldBool, rowL+x, columnL+y);
        }
        x=0;y=-1;
        if(( field[rowL][columnL]<field[rowL+x][columnL+y])&&(field[rowL+x][columnL+y]<9)){
            basinS+=basinSizeNew(field, fieldBool, rowL+x, columnL+y);
        }  
    }
    return 1+basinS;
}

void Day9::exercise(bool partOne){
    if(partOne){
        std::ifstream in("input");
        std::vector<std::vector<int>> field = Day9::readInput(in);
        Day9::partOne(field,field.size(),field[0].size(), true);
        std::vector<std::vector<int>> lowPoints = Utils::findLowestPoints(field);
        //Day9::Prints::printArray(lowPoints);
        //Day9::Prints::printArray(field);
    }else{
        std::ifstream in("input");
        std::vector<std::vector<int>> field = Day9::readInput(in);
        //Day9::partTwo(field);
        //std::vector<std::vector<int>> field = Day9::readInput(in);
        Day9::partTwoNew(field);
    }
}

void Day9::partTwo(std::vector<std::vector<int>>& field){
    std::vector<int> basins_size;
    std::vector<std::vector<int>> lowest_points = Utils::findLowestPoints(field);

    /*for(unsigned int i=0; i<lowest_points.size(); i++){
        field[lowest_points[i][0]][lowest_points[i][1]]*=-1;
    }*/

    for(unsigned int i=0; i<lowest_points.size(); i++){
        //calcola la size del basin nato dal lowest point preso dall'iterazione del vector lowest_points
        basins_size.push_back(Utils::basinSize(field,lowest_points[i][0],lowest_points[i][1]));
    }
    std::cout<<"[";
    for(unsigned int i = 0; i<lowest_points.size();i++){
        std::cout<<"("<<lowest_points[i][0]<<", "<<lowest_points[i][1]<<")";
        if(i!=lowest_points.size()-1)   std::cout<<",";
    }
    std::cout<<"]"<<std::endl;
    //search the top 3 size in basins size and multiply them
    int max[3] = {0,0,0};
    int indexTmp[3] = {-1,-1,-1};
    for(unsigned int i=0; i<basins_size.size(); i++){
        if(basins_size[i]>max[0]){
            max[0]=basins_size[i];
            indexTmp[0]=i;
        }
    }
    for(unsigned int i=0; i<basins_size.size(); i++){
        if(basins_size[i]>max[1] && i!=indexTmp[0]){
            max[1]=basins_size[i];
            indexTmp[1]=i;
        }
    }
    for(unsigned int i=0; i<basins_size.size(); i++){
        if(basins_size[i]>max[2] && i!=indexTmp[0] && i!=indexTmp[1]){
            max[2]=basins_size[i];
            indexTmp[2]=i;
        }
    }
    std::cout<<std::endl<<max[0]*max[1]*max[2];

}

void Day9::partTwoNew(std::vector<std::vector<int>>& field){
    std::vector<int> basins_size;
    std::vector<std::vector<int>> lowest_points = Utils::findLowestPoints(field);
    std::vector<std::vector<bool>> fieldBool;

    for(unsigned int i=0; i<field.size();i++){
        std::vector<bool> fieldBoolrow;
        for(unsigned int j=0;j<field[i].size();j++){
            fieldBoolrow.push_back(false);
        }
        fieldBool.push_back(fieldBoolrow);
    }

 

    for(unsigned int i=0; i<lowest_points.size(); i++){
        //calcola la size del basin nato dal lowest point preso dall'iterazione del vector lowest_points
        basins_size.push_back(Utils::basinSizeNew(field,fieldBool,lowest_points[i][0],lowest_points[i][1]));
    }
    for(unsigned int i = 0; i<basins_size.size();i++){
        std::cout<<basins_size[i]<<std::endl;
    }
    //search the top 3 size in basins size and multiply them
    int max[3] = {0,0,0};
    int indexTmp[3] = {-1,-1,-1};
    for(unsigned int i=0; i<basins_size.size(); i++){
        if(basins_size[i]>max[0]){
            max[0]=basins_size[i];
            indexTmp[0]=i;
        }
    }
    for(unsigned int i=0; i<basins_size.size(); i++){
        if(basins_size[i]>max[1] && i!=indexTmp[0]){
            max[1]=basins_size[i];
            indexTmp[1]=i;
        }
    }
    for(unsigned int i=0; i<basins_size.size(); i++){
        if(basins_size[i]>max[2] && i!=indexTmp[0] && i!=indexTmp[1]){
            max[2]=basins_size[i];
            indexTmp[2]=i;
        }
    }
    std::cout<<std::endl<<max[0]*max[1]*max[2];

}
void Day9::Prints::printTest(int value, int i, int j, char test, int uno, int due, int tre, int quattro){
    std::cout<<value<<": "<<i<<","<<j<<" "<<test<<", around me there are:"<<uno<<","<<due<<","<<tre<<","<<quattro<<"."<<std::endl;
}
void Day9::partOne(std::vector<std::vector<int>>& field, int rows, int columns, bool prints){
    int sumRisk=0;
    for(unsigned int i=0; i<rows; i++){
        for(unsigned int j=0; j<columns; j++){
            if(i==0 || j==0 || i==rows-1 || j==columns-1){
                if(i==0 && j==0){
                    //corner topleft
                    if((field[i][j]<field[i+1][j])&&(field[i][j]<field[i][j+1])){
                        sumRisk+=field[i][j]+1;
                        if(prints)  Day9::Prints::printTest(field[i][j],i,j,'a', field[i+1][j], field[i][j+1],2);
                    }
                }else if(i==0 && j==columns-1){
                    //corner topright
                    if((field[i][j]<field[i+1][j])&&(field[i][j]<field[i][j-1])){
                        sumRisk+=field[i][j]+1;
                        if(prints)  Day9::Prints::printTest(field[i][j],i,j,'b', field[i+1][j], field[i][j-1],2);
                        
                    }
                }else if(i==rows-1 && j==0){
                    //corner bottomleft
                    if((field[i][j]<field[i-1][j])&&(field[i][j]<field[i][j+1])){
                        sumRisk+=field[i][j]+1;
                        if(prints)  Day9::Prints::printTest(field[i][j],i,j,'c', field[i-1][j], field[i][j+1],2);
                    }
                }else if(i==rows-1 && j==columns-1){
                    //corner bottomright
                    if((field[i][j]<field[i-1][j])&&(field[i][j]<field[i][j-1])){
                        sumRisk+=field[i][j]+1;
                        if(prints)  Day9::Prints::printTest(field[i][j],i,j,'d', field[i-1][j],field[i][j-1]);
                    }
                }else if(i==0){
                    if((field[i][j]<field[i+1][j])&&(field[i][j]<field[i][j-1])&&(field[i][j]<field[i][j+1])){
                        sumRisk+=field[i][j]+1;
                        if(prints)  Day9::Prints::printTest(field[i][j],i,j,'e', field[i+1][j], field[i][j-1], field[i][j+1]);
                    }
                }else if(j==0){
                    if((field[i][j]<field[i-1][j])&&(field[i][j]<field[i+1][j])&&(field[i][j]<field[i][j+1])){
                        sumRisk+=field[i][j]+1;
                        if(prints)  Day9::Prints::printTest(field[i][j],i,j,'f', field[i-1][j], field[i+1][j],field[i][j+1]);
                    }
                }else if(i==rows-1){
                    if((field[i][j]<field[i-1][j])&&(field[i][j]<field[i][j-1])&&(field[i][j]<field[i][j+1])){
                        sumRisk+=field[i][j]+1;
                        if(prints)  Day9::Prints::printTest(field[i][j],i,j,'g', field[i-1][j],field[i][j-1], field[i][j+1]);
                    }
                }else if(j==columns-1){
                    if((field[i][j]<field[i-1][j])&&(field[i][j]<field[i+1][j])&&(field[i][j]<field[i][j-1])){
                        sumRisk+=field[i][j]+1;
                        if(prints)  Day9::Prints::printTest(field[i][j],i,j,'h', field[i-1][j], field[i+1][j], field[i][j-1]);
                    }
                }
            }else if((field[i][j]<field[i-1][j])&&(field[i][j]<field[i+1][j])&&(field[i][j]<field[i][j-1])&&(field[i][j]<field[i][j+1])){
                    sumRisk+=field[i][j]+1;
                    if(prints)  Day9::Prints::printTest(field[i][j],i,j,'i', field[i-1][j], field[i+1][j], field[i][j-1], field[i][j+1]);
            }
        }
    }
    std::cout<<sumRisk<<std::endl;
}

std::vector<std::vector<int>> Day9::readInput(std::ifstream& in){
    std::vector<std::vector<int>> field;
    int rows=100;
    int columns=100;
    char c;
    for(unsigned int h=0; h<rows; h++){
        std::vector<int> fieldRow;
        for(unsigned int j=0; j<columns; j++){
            in>>c;
            fieldRow.push_back(c-'0');
        }
        field.push_back(fieldRow);
    }
    return field;
}

void Day9::Prints::printArray(std::vector<std::vector<int>>& field){
    for(unsigned int i=0; i<field.size(); i++){
        for(unsigned int j=0; j<field[i].size(); j++)
            std::cout<<field[i][j]<<" ";
        std::cout<<std::endl;
    }
}