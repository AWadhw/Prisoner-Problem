#pragma once

class TagSearchMethods{
    public: 
        static int RandomTagSearchPerPrisoner(const int numTries, std::unordered_map<int, int> &myMap,std::vector<int> searchSequence, const int prisonerID);
        static int FullRandomTagSearch(const int numPrisoners, const int numTries, std::unordered_map<int, int> &myMap, std::vector<int> searchSequence);
        static int OrganizedTagSearchPerPrisoner(const int numTries, std::unordered_map<int, int> &myMap, const int prisonerID);
        static int TagSearchMethodsFullOrganizedSearch(const int numPrisoners, const int numTries, std::unordered_map<int, int> &myMap);
};

//COME BACK TO THIS LOL 
int TagSearchMethods::RandomTagSearchPerPrisoner(const int numTries, std::unordered_map<int, int> &myMap, std::vector<int> searchSequence, const int prisonerID){

    PrisonMethods::ShufflePrisonTagVector(searchSequence); //shuffling a random sequence of picking every time. 

    for(int i = 0; i < numTries; i++){
        if(myMap[searchSequence.at(i)] == prisonerID){
            return 1;
        }
    }
    return 0;
}

int TagSearchMethods::FullRandomTagSearch(const int numPrisoners, const int numTries, std::unordered_map<int, int> &myMap, std::vector<int> searchSequence){
    int successfulSearch{1};
    for(int i = 0; i < numPrisoners; i++){
        successfulSearch = TagSearchMethods::RandomTagSearchPerPrisoner(numTries, myMap, searchSequence, i+1);
        if(successfulSearch != 1){
            return 0;
        }
    }
    return successfulSearch;
}

int TagSearchMethods::OrganizedTagSearchPerPrisoner(const int numTries, std::unordered_map<int, int> &myMap, const int prisonerID){

    std::vector<int> mySanity {};
    if(myMap[prisonerID] == prisonerID){ //already using a single try here
        return 1;
    }

    int startSeed = myMap[prisonerID];
    for(int i = 1; i < numTries; i++){
        if(myMap[startSeed] == prisonerID){
            return 1;
        }
        startSeed = myMap[startSeed];
        mySanity.push_back(startSeed);
    }
    
    return 0;
}

int TagSearchMethods::TagSearchMethodsFullOrganizedSearch(const int numPrisoners, const int numTries, std::unordered_map<int, int> &myMap){
    int successfulSearch {1};
    for(int i = 0; i < numPrisoners; i++){
        successfulSearch = TagSearchMethods::OrganizedTagSearchPerPrisoner(numTries, myMap, i+1);
        if(successfulSearch != 1){
            return 0;
        }
    }
    return successfulSearch;
}



