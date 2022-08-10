#include <iostream>
#include <fstream>
#include <sstream>
#include "cube.h"

int main() {
    std::string command;
    Cube newCube;

    std::string listOfCommands = "Welcome to Rubik's Cube simulator! Available commands:\n"
                                 "new: creates a new solved cube cube;\n"
                                 "solve: prints a combination to solve the current cube;\n"
                                 "randomize X: performs X random rotations on the current cube\n"
                                 "print: prints current cube to console\n"
                                 "apply X: applies a move with a name X to the current cube\n"
                                 "load X: loads a cube from a file with a name X\n"
                                 "help: prints a list of available commands\n"
                                 "moves: prints a list of available moves\n"
                                 "quit: close a program\n";

    std::cout << listOfCommands;
    while (command != "quit") {
        std::cout <<"This program is yours to command. What would you prefer?\n";
        std::getline(std::cin, command);
        std::istringstream sstream(command);
        std::string parsedCommand;
        sstream >> parsedCommand;
        if (parsedCommand == "new") {
            Cube replacement;
            newCube = replacement;
        } else if (parsedCommand == "solve") {
            CubeSolver solver{newCube, 500, 300, 10, 50};
            std::vector<std::string> solution = solver.solve();

            std::cout << "\nThe solution is:\n";

            for (int i = 0; i < solution.size(); ++i) {
                std::cout << solution[i] << ' ';
                if ((i + 1) % 5 == 0) {
                    std::cout << '\n';
                }
            }
            std::cout << "\n Total number of moves required is: " << solution.size() << '\n';
        } else if (parsedCommand == "randomize") {
            int numOfMoves = 0;
            sstream >> numOfMoves;
            newCube.randomize(numOfMoves);
        } else if (parsedCommand == "print") {
            std::cout << newCube;
        } else if (parsedCommand == "apply") {
            std::string move;
            sstream >> move;
            newCube.applyCombination(move, false);
        } else if (parsedCommand == "load") {
            std::string fileName;
            sstream >> fileName;
            std::ifstream fileInput(fileName);
            fileInput >> newCube;
        } else if (parsedCommand == "help") {
            std::cout << listOfCommands;
        } else if (parsedCommand == "moves") {
            std::cout << "U U' U2 D D' D2 R R' R2 L L' L2 F F' F2 B B' B2\n"
                         "M M' M2 E E' E2 S S' S2 x y z\n";
        } else if (parsedCommand != "quit") {
            std::cout << "Sorry, but I have no idea what you are trying to do...\n";
        }
    }

//    std::ifstream fin("testinput.txt");
//    std::ofstream fout("testoutput.txt");
//    Cube testCube;
//    fin >> testCube;
//    std::cout << testCube.isValid() << '\n';
//    std::string test{"B' R' B' U2 B2 L U' B' U2 L' B' D' L2 R' U' L' U2 F2 L' D' L' B' U B' U2"};
//    testCube.applyCombination(test, false);
//    std::cout << testCube.isValid();
//
//
//
//    CubeSolver solver{testCube, 500, 300, 10, 50};
//    std::vector<std::string> solution_ = solver.solve();
//
//    std::cout << "\nThe solution is:\n";
//
//    for (const auto &element: solution_) {
//        std::cout << element << ' ';
//    }

    return 0;
}
