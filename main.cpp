#include <iostream>
#include <vector>
#include <unordered_set>
#include "Prison.h"

int main(void){

    int numPrisoners {};
    numPrisoners = GetNumPrisoners(); //also 

    std::vector<PrisonBox> prisonList(numPrisoners);
    std::vector<int> prisonTags(numPrisoners);

    PrisonMethods::GeneratePrisonTags(prisonTags, numPrisoners);
    PrisonMethods::ShufflePrisonTagVector(prisonTags);
    PrisonMethods::PopulatePrisonBoxes(prisonList, prisonTags);
    
 
    PrisonMethods::PrintAllPrisoners(prisonList);
    
    return 0;
}