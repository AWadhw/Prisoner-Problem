#pragma once
//#include <unordered_map>

class TagSearchMethods{
    public: 
        static int RandomTagSearchPerPrisoner(const int numTries, std::unordered_map<int, int> &myMap,std::vector<int> prisonTags, const int prisonerID);
        static int FullRandomTagSearch(int numPrisoners, const int numTries, std::unordered_map<int, int> &myMap, std::vector<int> prisonTags);
        static int OrganizedTagSearchPerPrisoner(const int numTries, std::unordered_map<int, int> &myMap, const int prisonerID);
};

//COME BACK TO THIS LOL 
int TagSearchMethods::RandomTagSearchPerPrisoner(const int numTries, std::unordered_map<int, int> &myMap, std::vector<int> prisonTags, const int prisonerID){

    PrisonMethods::ShufflePrisonTagVector(prisonTags); //shiffling a random sequence of picking every time. 

    for(int i = 0; i < numTries; i++){
        if(myMap[prisonTags.at(i)] == prisonerID){
            return 1;
        }
        // if(prisonTags.size() == numTries - 1){
        //     return 0;
        // }
    }
    return 0;
}

int TagSearchMethods::FullRandomTagSearch(int numPrisoners, const int numTries, std::unordered_map<int, int> &myMap, std::vector<int> prisonTags){
    int successfulSearch{1};
    for(int i = 0; i < numPrisoners; i++){
        successfulSearch = TagSearchMethods::RandomTagSearchPerPrisoner(numTries, myMap, prisonTags, i+1);
        if(successfulSearch != 1){
            return 0;
        }
    }
    return successfulSearch;
}

int TagSearchMethods::OrganizedTagSearchPerPrisoner(const int numTries, std::unordered_map<int, int> &myMap, const int prisonerID){

    if(myMap[prisonerID] == prisonerID){ //already using a single try here
        return 1;
    }

    int startSeed = myMap[prisonerID];
    for(int i = 1; i < numTries; i++){
        if(myMap[startSeed] == prisonerID){
            return 1;
        }
        startSeed = myMap[startSeed];
    }
    return 0;
}

int TagSearchMethodsFullOrganizedSearch(const int numPrisoners, const int numTries, std::unordered_map<int, int> &myMap){
    int successfulSearch {1};
    for(int i = 0; i < numPrisoners; i++){
        successfulSearch = TagSearchMethods::OrganizedTagSearchPerPrisoner(numTries, myMap, i+1);
        if(successfulSearch != 1){
            return 0;
        }
    }
    return successfulSearch;
}


