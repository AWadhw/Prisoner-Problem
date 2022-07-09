#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include "Prison.h"
#include "TagSearch.h"

int main(void){

//Setup Up Prisoners and Layout

    int numPrisoners {};
    numPrisoners = GetNumPrisoners(); 

    std::vector<int> prisonTags(numPrisoners);
    PrisonMethods::GeneratePrisonTags(prisonTags, numPrisoners);
    PrisonMethods::ShufflePrisonTagVector(prisonTags);
    PrisonMethods::PrintPrisonVector(prisonTags);

    //myHashTable
    std::cout << "Map Stuff!!!";
    std::unordered_map<int, int> prisonLayout;
    CellMethods::PrintAllPrisoners(prisonLayout);
    CellMethods::PopulatePrisonMap(prisonLayout, prisonTags, numPrisoners);
    CellMethods::PrintAllPrisoners(prisonLayout);
    
    //TagSearchMethods::RandomTagSearch(prisonList, prisonTags);

    //////////////////////////START RUN///////////////////////////////////
    // int numTries {50}; //HardCoded for Now
    // int randomFoundFlag {0};
    // int organizedFoundFlag {0};
    
    return 0;
}