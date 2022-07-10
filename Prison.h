#pragma once

#include <cstdlib>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <ctime>
#include <unordered_map>

int FetchRandomNumber(void){
    return (static_cast<float>(rand())/RAND_MAX) * 10;
}
int GetNumPrisoners(void){
    int numPrisoners;
    std::cout << "Welcome to the prisoner problem..." << std::endl;
    std::cout << "Please enter how many prisons you would like" << std::endl;
    std::cin >> numPrisoners;
    std::cout << "\n" << numPrisoners << " Selected";
    return numPrisoners;
}

class PrisonBox{
    public: 
        int Box;
        int Tag;
        bool Opened;
};

class CellMethods{
    public:
        static void PrintAllPrisoners(std::unordered_map<int, int> &myMap);
        static void PopulatePrisonMap(std::unordered_map<int, int> &myMap, const std::vector<int> &prisonVector, const int numPrisoners);
};

void CellMethods::PrintAllPrisoners(std::unordered_map<int, int> &prisonLayout){
       for(auto i : prisonLayout){
        std::cout << i.first << " and " << i.second << std::endl;
    }
}

void CellMethods::PopulatePrisonMap(std::unordered_map<int, int> &myMap, const std::vector<int> &prisonVector, const int numPrisoners){
    for(int i = 1; i <= numPrisoners; i++){
        myMap[i] = prisonVector.at(i-1);
    }
}

class PrisonMethods{
    public: 
        static void PrintAllPrisoners(std::vector<PrisonBox> &prisonList);
        static void PrintPrisonVector(std::vector<int> &prisonVector);
        static void GeneratePrisonTags(std::vector<int> &prisonTags, const int numPrisoners);
        static void PopulatePrisonBoxes(std::vector<PrisonBox> &prisonList, std::vector<int> &prisonTags);
        static void PopulateVectorAscending(std::vector<PrisonBox> &prisonList);
        static void RandomizePrisonTags(std::vector<PrisonBox> &prisonCell);
        static void PopulatePrisonSet(std::unordered_set<int> &prisonSet, const int &numPrisoners);
        static void PrintPrisonSet(std::unordered_set<int> &prisonSet);
        static void ShufflePrisonTagVector(std::vector<int> &prisonTags);
};

void PrisonMethods::PrintAllPrisoners(std::vector<PrisonBox> &prisonList){
    std::cout << std::endl;
    for(auto i : prisonList){
        std::cout << i.Box << " and " << i.Tag << " and " << i.Opened << std::endl;
    }
}

void PrisonMethods::PrintPrisonVector(std::vector<int> &prisonVector){
    for(int i : prisonVector){
        std::cout << i << std::endl;
    }
}

void PrisonMethods::GeneratePrisonTags(std::vector<int> &prisonTags, const int numPrisoners){ 
    for(int i = 0; i < numPrisoners; i++){
        prisonTags.at(i) = i+1;
    }
}

void PrisonMethods::PopulatePrisonBoxes(std::vector<PrisonBox> &prisonList, std::vector<int> &prisonTags){ 
    int j = 1;
    for(auto& i : prisonList){
        i.Box = j;
        i.Tag = prisonTags.at(j-1);
        j++;
    }
}

void PrisonMethods::ShufflePrisonTagVector(std::vector<int> &prisonTags){
    srand(time(0)); //for creating a seed for the shuffle algorithm
    unsigned int seed = rand(); //for creating a seed for the shuffle algorithm
    auto rng = std::default_random_engine(seed);
    std::shuffle(std::begin(prisonTags), std::end(prisonTags), rng);
}

