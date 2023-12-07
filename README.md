# DataProcessingAndStorage
## Running the Project:
This project requires C++17 or higher.
1. Open project in terminal
2. Run: .\DataProcessingAndStorage.exe
3. The compiled main.cpp will then run. The code is formatted such that each command is given a line, and it's output is given a line. If no out, then the command is assumed successful.

## Building the Project:
This project requires C++17 or higher. It was built in CLion with CMake, so CLion will be able to run the code without setup. Otherwise, CMake, minGW or building in terminal are options.
### Compile Directly
1. Open project in terminal.
2. Run 	g++ -std=c++17 -o DataProcessingAndStorage.exe inMemoryDB.cpp inMemoryDB.h main.cpp
3. DataProcessingAndStorage.exe should then be built.
### CMake
1. Open project in terminal. Navigate to DataProcessingAndStorage\cmake-build-debug.
2. Run cmake .
3. DataProcessingAndStorage.exe should then be built.
### minGW
1. Open project in terminal.
2. Run mingw32-make
3. DataProcessingAndStorage.exe should then be built.

## Project Feedback:
I think this project would benefit from requiring user interaction with the database. Requireing an interface where the user inputs the commands live would both give better direction of implementation, 
and provide for a slightly more challenging/involved project. Instead of having the commands statically in main,
the program could take in the terminal command "get(A)" and the program would have to parse the command and return a value. 
