# DataProcessingAndStorage
## Running the Project:
This project requires C++17 or higher.
1. Open project in terminal
2. Run:   ```.\DataProcessingAndStorage.exe```
5. The compiled main.cpp will then run. The code is formatted such that each command is given a line, and it's output is given a line. If no out, then the command is assumed successful.

## Building the Project:
This project requires C++17 or higher. It was built in CLion with CMake, so CLion will be able to run the code without setup. Otherwise, CMake, minGW or building in terminal are options.
### Compile Directly
1. Open project in terminal.
2. Run: 	```g++ -std=c++17 -o DataProcessingAndStorage.exe inMemoryDB.cpp inMemoryDB.h main.cpp```
4. DataProcessingAndStorage.exe should then be built.
### CMake
1. Open project in terminal. Navigate to DataProcessingAndStorage\cmake-build-debug.
2. Run: ```cmake .```
3. DataProcessingAndStorage.exe should then be built.
### minGW
1. Open project in terminal.
2. Run: ```mingw32-make```
3. DataProcessingAndStorage.exe should then be built.

## Assignment Feedback:
I think this project needs more clear instructions. It was unclear to me if we needed to include user interaction, or if having the example code in the assignment was enough. I think the assignment could be made more challenging and rewarding with the inclusion of user interaction. For grading, specifying a language or having students submit the output of their program might be helpful. I had fun with this assignment, I think it was a good difficulty for an assignment with a one week time frame. 
