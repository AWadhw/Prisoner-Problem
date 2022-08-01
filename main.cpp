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
    std::cout << "Generating prison map!";
    std::unordered_map<int, int> prisonLayout;
    CellMethods::PrintAllPrisoners(prisonLayout);
    CellMethods::PopulatePrisonMap(prisonLayout, prisonTags, numPrisoners);
    CellMethods::PrintAllPrisoners(prisonLayout);


    //////////////////////////START RUN///////////////////////////////////
    long double samples {10000};  
    long double sum {0};
    for(int i = 0; i < samples; i++){
        sum += TagSearchMethods::TagSearchMethodsFullOrganizedSearch(numPrisoners, NUM_TRIES, prisonLayout);
        PrisonMethods::ShufflePrisonTagVector(prisonTags); //shuffling
        CellMethods::PopulatePrisonMap(prisonLayout, prisonTags, numPrisoners);
    }

    std::cout << "\n And your average probability with organized search for success is: " << std::endl;
    std::cout << (sum/samples) << std::endl;
    sum = 0;

    for(int i = 0; i < samples; i++){
        sum += TagSearchMethods::FullRandomTagSearch(numPrisoners, NUM_TRIES, prisonLayout, prisonTags); //using prison layout to seed a seach sequence
        PrisonMethods::ShufflePrisonTagVector(prisonTags); //shuffling
        CellMethods::PopulatePrisonMap(prisonLayout, prisonTags, numPrisoners);
    }

    std::cout << "\n And your average probability with full random for success is: " << std::endl;
    std::cout << (sum/samples) << std::endl;
    
    return 0;
}