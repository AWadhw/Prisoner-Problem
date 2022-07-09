#include <iostream>
#include <vector>
#include <unordered_set>
#include "Prison.h"
#include "TagSearch.h"

int main(void){

//Setup Up Prisoners and Layout

    int numPrisoners {};
    numPrisoners = GetNumPrisoners(); //also 

    std::vector<PrisonBox> prisonList(numPrisoners);
    std::vector<int> prisonTags(numPrisoners);

    PrisonMethods::GeneratePrisonTags(prisonTags, numPrisoners);
    PrisonMethods::ShufflePrisonTagVector(prisonTags);
    PrisonMethods::PopulatePrisonBoxes(prisonList, prisonTags);
    
    PrisonMethods::PrintAllPrisoners(prisonList);
    //TagSearchMethods::RandomTagSearch(prisonList, prisonTags);

    //////////////////////////START RUN///////////////////////////////////
    // int numTries {50}; //HardCoded for Now
    // int randomFoundFlag {0};
    // int organizedFoundFlag {0};
    
    return 0;
}