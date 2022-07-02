#include <cstdlib>

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
        static void PrintAllPrisoners(std::vector<PrisonBox>);
        static void PopulateVectorAscending(std::vector<PrisonBox> &prisonList);
};

void PrisonMethods::PrintAllPrisoners(std::vector<PrisonBox> prisonList){
    std::cout << std::endl;
    for(auto i : prisonList){
        std::cout << i.Box << " and " << i.Tag << std::endl;
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
