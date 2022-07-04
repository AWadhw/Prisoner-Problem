#include <cstdlib>
#include <algorithm>
#include <random>

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
};

class PrisonMethods{
    public: 
        static void PrintAllPrisoners(std::vector<PrisonBox> &prisonList);
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
        std::cout << i.Box << " and " << i.Tag << std::endl;
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

void PrisonMethods::PopulateVectorAscending(std::vector<PrisonBox> &prisonList){
    int j = 1;
    for(auto& i : prisonList){
        i.Tag = j;
        i.Box = j;
        j++;
    }
}
void PrisonMethods::PopulatePrisonSet(std::unordered_set<int> &prisonSet, const int &NumPrisoners){
    for(int i = 0; i < NumPrisoners; i++){
        prisonSet.insert(i);
    }
}
void PrisonMethods::PrintPrisonSet(std::unordered_set<int> &prisonSet){
    for(int i : prisonSet){
        std::cout << i << std::endl;
    }
}
void PrisonMethods::ShufflePrisonTagVector(std::vector<int> &prisonTags){
    auto rng = std::default_random_engine {}; //for creating a seed for the shuffle algorithm
    std::shuffle(std::begin(prisonTags), std::end(prisonTags), rng);
}

