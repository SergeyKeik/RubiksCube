#ifndef LAB4_CUBE_H
#define LAB4_CUBE_H

#include <vector>
#include <iostream>
#include <string>
#include <cassert>
#include <sstream>
#include <random>
#include <algorithm>

class CubeSolver;

enum Color {
    WHITE,
    BLUE,
    RED,
    YELLOW,
    GREEN,
    ORANGE
};

class Piece {
public:
    Color pieceColor_;
};

class Side {
public:
    Side() {
        sideVec_.resize(3);
        for (int i = 0; i < 3; ++i) {
            sideVec_[i].resize(3);
        }
    }

    std::vector<std::vector<Piece>> sideVec_;

};

/*
 CUBE SIDES:
      3
      2
    1 0 4
      5
 */

class Cube {
public:
    Cube() : numOfMisplacedStickers_{-1} {
        sides_.resize(6);
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    sides_[i].sideVec_[j][k].pieceColor_ = static_cast<Color>(i);
                }
            }
        }
    }

    void turnLeft(int indexFirst, int indexSecond);

    void U();

    void U1();

    void U2();

    void D1();

    void D();

    void D2();

    void turnUp(int column);

    void R();

    void R1();

    void R2();

    void L1();

    void L();

    void L2();

    void turn90(int indexFirst, int indexSecond);

    void F();

    void F1();

    void F2();

    void B1();

    void B();

    void B2();

    void M1();

    void M();

    void M2();

    void E1();

    void E();

    void E2();

    void S();

    void S1();

    void S2();

    void turnX();

    void turnX1();

    void turnX2();

    void turnY();

    void turnY1();

    void turnY2();

    void turnZ();

    void turnZ1();

    void turnZ2();

    void applyCombination(std::string &combinationStr, bool saveCombination);

    int countMisplacedStickers();

    void makeRandomMove(int randomNumber);

    void randomize(int numberOfMoves);

    bool isValid();


    friend std::ostream &operator<<(std::ostream &out, const Cube &cube);

    friend std::istream &operator>>(std::istream &in, Cube &cube);

    friend bool operator==(const Cube &firstCube, const Cube &secondCube);

    friend bool operator!=(const Cube &firstCube, const Cube &secondCube);

    friend bool operator<(const Cube &firstCube, const Cube &secondCube);

    friend bool operator<=(const Cube &firstCube, const Cube &secondCube);

    friend bool operator>=(const Cube &firstCube, const Cube &secondCube);

    friend CubeSolver;

private:
    std::vector<Side> sides_;
    std::vector<std::string> solution_;
    int numOfMisplacedStickers_;
};

class CubeSolver {
public:
    CubeSolver(Cube cubeToSolve, int populationSize, int maxGenerations, int maxResets, int elitismNum) :
            startingPosition_{cubeToSolve}, populationSize_{populationSize}, maxGenerations_{maxGenerations},
            maxResets_{maxResets}, elitismNum_{elitismNum} {

    }

    std::vector<std::string> solve();

private:
    Cube startingPosition_;
    std::vector<Cube> population_;
    int populationSize_;
    int maxGenerations_;
    int maxResets_;
    int elitismNum_;

};


#endif