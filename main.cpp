#include <iostream>
#include <vector>
#include <unordered_set>
#include "Prison.h"

int main(void){

    int numPrisoners {};
    numPrisoners = GetNumPrisoners(); //also 

    std::vector<PrisonBox> prisonCell(numPrisoners);

    PrisonMethods::PrintAllPrisoners(prisonCell);
    PrisonMethods::PopulateVectorAscending(prisonCell);
    PrisonMethods::PrintAllPrisoners(prisonCell);
    
    std::unordered_set<int> mySet;

    
    return 0;
}