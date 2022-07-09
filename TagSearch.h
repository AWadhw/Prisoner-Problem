
class TagSearchMethods{
    public: 
        static int RandomTagSearch(const int numTries, const std::vector<PrisonBox> &prisonList,std::vector<int> prisonTags);
        static void OrganizedTagSearch(const std::vector<PrisonBox> &prisonList);
};

//COME BACK TO THIS LOL 
int TagSearchMethods::RandomTagSearch(const int numTries, const std::vector<PrisonBox> &prisonList, std::vector<int> prisonTags){
    srand(time(NULL));
    std::cout << rand();

    PrisonMethods::ShufflePrisonTagVector(prisonTags); //shiffling a random sequence of picking evertime. 

    for(auto i : prisonList){
        for(int j = 0; j < numTries; j++){
            if(i.Tag == prisonTags.at(j)){
                break; //prison at this moment found their tag
            }
            else if(j == (numTries - 1)){
                return 0;
            }
        }
    }

}