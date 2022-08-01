# Prisoner-Problem
After watching a [Veritasium](https://www.youtube.com/watch?v=iSNsgj1OCLA) video, I was interested to see if this problem could be visualised and wanted to try to see the chance of success using C++.
In this riddle, a number of prisoners are assigned a tag ranging from 0 to n. To hold, a chance of success, every prisoner has to find their tags once they enter the tag room and can only check in half of the boxes. Every prisoner has to find their tag to succeed in this situation, however if one or more prisoner can not find their tag, the attempt is counted as a fail. However, there is a higher chance of success if the members choose a chaining strategy where they just follow a box with a previous tag they have found in another box. This code will prove that the chance of success using an organized approach will be around 30% each time.  
To run the code using the GNU C++ compiler, download the code and then run ```g++ -o main.exe main.cpp```
One run, there are 2 search methods, one is the organized search as discussed in the video and one is a full random search. 

Approach:
Initially, I started by setting up methods for seeding a search sequence and creating objects for the layout and members. I then used hashmaps to as a form of layout and sequence order. The number of samples can be manually set within the code as well as how many prisoners to queue for the game. 
