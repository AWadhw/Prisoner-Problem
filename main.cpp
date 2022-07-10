#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include "Prison.h"
#include "TagSearch.h"

#define NUM_TRIES 50

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
    double samples {6000000}; //remember to convert this to an int later 
    //int run = TagSearchMethods::TagSearchMethodsFullOrganizedSearch(numPrisoners, NUM_TRIES, prisonLayout);
    double sum {0};
    for(int i = 0; i < samples; i++){
        sum += TagSearchMethods::TagSearchMethodsFullOrganizedSearch(numPrisoners, NUM_TRIES, prisonLayout);
        PrisonMethods::ShufflePrisonTagVector(prisonTags); //shuffling
        CellMethods::PopulatePrisonMap(prisonLayout, prisonTags, numPrisoners);
    }
    // for(int i = 0; i < samples; i++){
    //     sum += TagSearchMethods::FullRandomTagSearch(numPrisoners, NUM_TRIES, prisonLayout, prisonTags); //being lazy here by seeding with the random tag sequence. (it doesn't matter as it will shuffle again)
    //     PrisonMethods::ShufflePrisonTagVector(prisonTags); //shuffling
    //     CellMethods::PopulatePrisonMap(prisonLayout, prisonTags, numPrisoners);
    // }

    std::cout << "\n ANDDDDD YOUR AVERAGE ISSSSSSS!!!!!!!!!!!!!" << std::endl;
    std::cout << (sum/samples) << std::endl;
    
    return 0;
}