#include "cube.h"

std::ostream &operator<<(std::ostream &out, const Cube &cube) {
    for (int i = 0; i < 3; ++i) {
        out << '\t';
        for (int j = 0; j < 3; ++j) {
            switch (cube.sides_[3].sideVec_[i][j].pieceColor_) {
                case WHITE:
                    out << "W";
                    break;
                case GREEN:
                    out << "G";
                    break;
                case YELLOW:
                    out << "Y";
                    break;
                case BLUE:
                    out << "B";
                    break;
                case RED:
                    out << "R";
                    break;
                case ORANGE:
                    out << "O";
                    break;
            }
        }
        out << '\n';
    }
    for (int i = 0; i < 3; ++i) {
        out << '\t';
        for (int j = 0; j < 3; ++j) {
            switch (cube.sides_[2].sideVec_[i][j].pieceColor_) {
                case WHITE:
                    out << "W";
                    break;
                case GREEN:
                    out << "G";
                    break;
                case YELLOW:
                    out << "Y";
                    break;
                case BLUE:
                    out << "B";
                    break;
                case RED:
                    out << "R";
                    break;
                case ORANGE:
                    out << "O";
                    break;
            }
        }
        out << '\n';
    }


    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            switch (cube.sides_[1].sideVec_[i][j].pieceColor_) {
                case WHITE:
                    out << "W";
                    break;
                case GREEN:
                    out << "G";
                    break;
                case YELLOW:
                    out << "Y";
                    break;
                case BLUE:
                    out << "B";
                    break;
                case RED:
                    out << "R";
                    break;
                case ORANGE:
                    out << "O";
                    break;
            }
        }
        out << " ";
        for (int j = 0; j < 3; ++j) {
            switch (cube.sides_[0].sideVec_[i][j].pieceColor_) {
                case WHITE:
                    out << "W";
                    break;
                case GREEN:
                    out << "G";
                    break;
                case YELLOW:
                    out << "Y";
                    break;
                case BLUE:
                    out << "B";
                    break;
                case RED:
                    out << "R";
                    break;
                case ORANGE:
                    out << "O";
                    break;
            }
        }
        out << " ";
        for (int j = 0; j < 3; ++j) {
            switch (cube.sides_[4].sideVec_[i][j].pieceColor_) {
                case WHITE:
                    out << "W";
                    break;
                case GREEN:
                    out << "G";
                    break;
                case YELLOW:
                    out << "Y";
                    break;
                case BLUE:
                    out << "B";
                    break;
                case RED:
                    out << "R";
                    break;
                case ORANGE:
                    out << "O";
                    break;
            }
        }
        out << '\n';
    }


    for (int i = 0; i < 3; ++i) {
        out << '\t';
        for (int j = 0; j < 3; ++j) {
            switch (cube.sides_[5].sideVec_[i][j].pieceColor_) {
                case WHITE:
                    out << "W";
                    break;
                case GREEN:
                    out << "G";
                    break;
                case YELLOW:
                    out << "Y";
                    break;
                case BLUE:
                    out << "B";
                    break;
                case RED:
                    out << "R";
                    break;
                case ORANGE:
                    out << "O";
                    break;
            }
        }
        out << '\n';
    }

    return out;
}

Color getColor(char colorChar) {
    switch (colorChar) {
        case 'W':
            return WHITE;
        case 'B':
            return BLUE;
        case 'R':
            return RED;
        case 'Y':
            return YELLOW;
        case 'G':
            return GREEN;
        case 'O':
            return ORANGE;
        default:
            return WHITE;
    }
}

std::istream &operator>>(std::istream &in, Cube &cube) {
    std::string input;

    for (int i = 0; i < 3; ++i) {
        in >> input;
        for (int j = 0; j < 3; ++j) {
            cube.sides_[3].sideVec_[i][j].pieceColor_ = getColor(input[j]);
        }
    }

    for (int i = 0; i < 3; ++i) {
        in >> input;
        for (int j = 0; j < 3; ++j) {
            cube.sides_[2].sideVec_[i][j].pieceColor_ = getColor(input[j]);
        }
    }

    for (int i = 0; i < 3; ++i) {
        in >> input;
        for (int j = 0; j < 3; ++j) {
            cube.sides_[1].sideVec_[i][j].pieceColor_ = getColor(input[j]);
        }
        in >> input;
        for (int j = 0; j < 3; ++j) {
            cube.sides_[0].sideVec_[i][j].pieceColor_ = getColor(input[j]);
        }
        in >> input;
        for (int j = 0; j < 3; ++j) {
            cube.sides_[4].sideVec_[i][j].pieceColor_ = getColor(input[j]);
        }
    }

    for (int i = 0; i < 3; ++i) {
        in >> input;
        for (int j = 0; j < 3; ++j) {
            cube.sides_[5].sideVec_[i][j].pieceColor_ = getColor(input[j]);
        }
    }

    return in;
}

void Cube::turnLeft(int indexFirst, int indexSecond) {
    std::vector<Piece> tempFirst{this->sides_[5].sideVec_[indexFirst]};

    for (int i = 0, j = 2; i < 3; ++i, --j) {
        sides_[5].sideVec_[indexFirst][i] = sides_[4].sideVec_[j][indexFirst];
    }

    std::vector<Piece> tempSecond{sides_[1].sideVec_[0][indexSecond], sides_[1].sideVec_[1][indexSecond],
                                  sides_[1].sideVec_[2][indexSecond]};

    for (int i = 0; i < 3; ++i) {
        sides_[1].sideVec_[i][indexSecond] = tempFirst[i];
    }

    tempFirst = sides_[2].sideVec_[indexSecond];

    for (int i = 0, j = 2; i < 3; ++i, --j) {
        sides_[2].sideVec_[indexSecond][i] = tempSecond[j];
    }

    for (int i = 0; i < 3; ++i) {
        sides_[4].sideVec_[i][indexFirst] = tempFirst[i];
    }

}

void Cube::U() {
    turnLeft(0, 2);
    Side temp = this->sides_[0];
    for (int i = 0, l = 2; i < 3; ++i, --l) {
        for (int k = 0; k < 3; ++k) {
            sides_[0].sideVec_[k][l] = temp.sideVec_[i][k];
        }
    }
}

void Cube::U1() {
    for (int i = 0; i < 3; ++i) {
        U();
    }
}

void Cube::U2() {
    U();
    U();
}

void Cube::D1() {
    turnLeft(2, 0);
    Side temp = this->sides_[3];
    for (int i = 0; i < 3; ++i) {
        for (int k = 0, j = 2; k < 3; ++k, --j) {
            sides_[3].sideVec_[k][i] = temp.sideVec_[i][j];
        }
    }
}

void Cube::D() {
    for (int i = 0; i < 3; ++i) {
        D1();
    }
}

void Cube::D2() {
    D();
    D();
}

void Cube::turnUp(int column) {
    std::vector<Piece> tempLast{sides_[0].sideVec_[0][column],
                                sides_[0].sideVec_[1][column], sides_[0].sideVec_[2][column]};

    for (int i = 0; i < 3; ++i) {
        sides_[0].sideVec_[i][column] = sides_[5].sideVec_[i][column];
    }

    std::vector<Piece> tempLastSecond{sides_[2].sideVec_[0][column],
                                      sides_[2].sideVec_[1][column], sides_[2].sideVec_[2][column]};
    for (int i = 0; i < 3; ++i) {
        sides_[2].sideVec_[i][column] = tempLast[i];
    }

    tempLast = {sides_[3].sideVec_[0][column], sides_[3].sideVec_[1][column], sides_[3].sideVec_[2][column]};

    for (int i = 0; i < 3; ++i) {
        sides_[3].sideVec_[i][column] = tempLastSecond[i];
    }

    for (int i = 0; i < 3; ++i) {
        sides_[5].sideVec_[i][column] = tempLast[i];
    }
}

void Cube::R() {
    turnUp(2);
    Side temp = this->sides_[4];
    for (int i = 0, l = 2; i < 3; ++i, --l) {
        for (int k = 0; k < 3; ++k) {
            sides_[4].sideVec_[k][l] = temp.sideVec_[i][k];
        }
    }
}

void Cube::R1() {
    for (int i = 0; i < 3; ++i) {
        R();
    }
}

void Cube::R2() {
    R();
    R();
}

void Cube::L1() {
    turnUp(0);
    Side temp = this->sides_[1];
    for (int i = 0; i < 3; ++i) {
        for (int k = 0, j = 2; k < 3; ++k, --j) {
            sides_[1].sideVec_[k][i] = temp.sideVec_[i][j];
        }
    }
}

void Cube::L() {
    for (int i = 0; i < 3; ++i) {
        L1();
    }
}

void Cube::L2() {
    L();
    L();
}

void Cube::turn90(int indexFirst, int indexSecond) {
    std::vector<Piece> tempFirst = sides_[4].sideVec_[indexFirst];

    sides_[4].sideVec_[indexFirst] = sides_[0].sideVec_[indexFirst];

    std::vector<Piece> tempSecond = sides_[3].sideVec_[indexSecond];

    for (int i = 0, j = 2; i < 3; ++i, --j) {
        sides_[3].sideVec_[indexSecond][j] = tempFirst[i];
    }

    tempFirst = sides_[1].sideVec_[indexFirst];

    for (int i = 0, j = 2; i < 3; ++i, --j) {
        sides_[1].sideVec_[indexFirst][j] = tempSecond[i];
    }

    sides_[0].sideVec_[indexFirst] = tempFirst;
}

void Cube::F() {
    turn90(2, 0);
    Side temp = sides_[5];
    for (int i = 0, l = 2; i < 3; ++i, --l) {
        for (int k = 0; k < 3; ++k) {
            sides_[5].sideVec_[k][l] = temp.sideVec_[i][k];
        }
    }
}

void Cube::F1() {
    for (int i = 0; i < 3; ++i) {
        F();
    }
}

void Cube::F2() {
    F();
    F();
}

void Cube::B1() {
    turn90(0, 2);

    Side temp = sides_[2];
    for (int i = 0; i < 3; ++i) {
        for (int k = 0, j = 2; k < 3; ++k, --j) {
            sides_[2].sideVec_[k][i] = temp.sideVec_[i][j];
        }
    }
}

void Cube::B() {
    for (int i = 0; i < 3; ++i) {
        B1();
    }
}

void Cube::B2() {
    B();
    B();
}

void Cube::M1() {
    turnUp(1);
}

void Cube::M() {
    for (int i = 0; i < 3; ++i) {
        M1();
    }
}

void Cube::M2() {
    M();
    M();
}

void Cube::E1() {
    turnLeft(1, 1);
}

void Cube::E() {
    for (int i = 0; i < 3; ++i) {
        E1();
    }
}

void Cube::E2() {
    E();
    E();
}

void Cube::S() {
    turn90(1, 1);
}

void Cube::S1() {
    for (int i = 0; i < 3; ++i) {
        S();
    }
}

void Cube::S2() {
    S();
    S();
}

void Cube::turnX() {
    Side tempFirst{sides_[0]};
    this->sides_[0] = sides_[5];
    Side tempSecond{sides_[2]};
    this->sides_[2] = tempFirst;
    tempFirst = sides_[3];
    this->sides_[3] = tempSecond;
    this->sides_[5] = tempFirst;

    Side tempLeft = sides_[1];
    Side tempRight = sides_[4];
    for (int i = 0, l = 2; i < 3; ++i, --l) {
        for (int k = 0, j = 2; k < 3; ++k, --j) {
            sides_[1].sideVec_[k][i] = tempLeft.sideVec_[i][j];
            sides_[4].sideVec_[k][l] = tempRight.sideVec_[i][k];
        }
    }

}

void Cube::turnX1() {
    for (int i = 0; i < 3; ++i) {
        turnX();
    }
}

void Cube::turnX2() {
    turnX();
    turnX();
}

void Cube::turnY() {
    Side tempFirst = sides_[5];

    for (int i = 0, k = 2; i < 3; ++i, --k) {
        for (int j = 0; j < 3; ++j) {
            sides_[5].sideVec_[j][i] = sides_[4].sideVec_[k][j];
        }
    }
    Side tempSecond = sides_[1];

    for (int i = 0; i < 3; ++i) {
        for (int j = 0, k = 2; j < 3; ++j, --k) {
            sides_[1].sideVec_[i][j] = tempFirst.sideVec_[k][i];
        }
    }

    tempFirst = sides_[2];
    for (int k = 2; k >= 0; --k) {
        for (int j = 0, l = 2; j < 3; ++j, --l) {
            sides_[2].sideVec_[k][j] = tempSecond.sideVec_[l][k];
        }
    }
    for (int i = 0, k = 2; i < 3; ++i, --k) {
        for (int j = 0; j < 3; ++j) {
            sides_[4].sideVec_[j][i] = tempFirst.sideVec_[k][j];
        }
    }

    Side tempUp = sides_[0];
    Side tempBottom = sides_[3];
    for (int i = 0, l = 2; i < 3; ++i, --l) {
        for (int k = 0, j = 2; k < 3; ++k, --j) {
            sides_[0].sideVec_[k][l] = tempUp.sideVec_[i][k];
            sides_[3].sideVec_[k][i] = tempBottom.sideVec_[i][j];
        }
    }
}

void Cube::turnY1() {
    for (int i = 0; i < 3; ++i) {
        turnY();
    }
}

void Cube::turnY2() {
    turnY();
    turnY();
}

void Cube::turnZ() {
    Side tempFirst = sides_[4];
    sides_[4] = sides_[0];
    Side tempSecond = sides_[3];

    for (int i = 0, k = 2; i < 3; ++i, --k) {
        for (int j = 0, l = 2; j < 3; ++j, --l) {
            sides_[3].sideVec_[k][l] = tempFirst.sideVec_[i][j];
        }
    }
    tempFirst = sides_[1];

    for (int i = 0, k = 2; i < 3; ++i, --k) {
        for (int j = 0, l = 2; j < 3; ++j, --l) {
            sides_[1].sideVec_[i][j] = tempSecond.sideVec_[k][l];
        }
    }

    sides_[0] = tempFirst;

    Side tempBack = sides_[2];
    Side tempFront = sides_[5];
    for (int i = 0, l = 2; i < 3; ++i, --l) {
        for (int k = 0, j = 2; k < 3; ++k, --j) {
            sides_[5].sideVec_[k][l] = tempFront.sideVec_[i][k];
            sides_[2].sideVec_[k][i] = tempBack.sideVec_[i][j];
        }
    }
}

void Cube::turnZ1() {
    for (int i = 0; i < 3; ++i) {
        turnZ();
    }
}

void Cube::turnZ2() {
    turnZ();
    turnZ();
}

void Cube::applyCombination(std::string &combinationStr, bool saveCombination) {
    std::istringstream stream(combinationStr);
    std::string move;
    std::vector<std::string> combVec;
    while (std::getline(stream, move, ' ')) {
        combVec.push_back(move);
    }

    for (auto const &element: combVec) {
        if (element == "U") {
            U();
        } else if (element == "U'") {
            U1();
        } else if (element == "U2") {
            U2();
        } else if (element == "D") {
            D();
        } else if (element == "D'") {
            D1();
        } else if (element == "D2") {
            D2();
        } else if (element == "R") {
            R();
        } else if (element == "R'") {
            R1();
        } else if (element == "R2") {
            R2();
        } else if (element == "L") {
            L();
        } else if (element == "L'") {
            L1();
        } else if (element == "L2") {
            L2();
        } else if (element == "F") {
            F();
        } else if (element == "F'") {
            F1();
        } else if (element == "F2") {
            F2();
        } else if (element == "B") {
            B();
        } else if (element == "B'") {
            B1();
        } else if (element == "B2") {
            B2();
        } else if (element == "M") {
            M();
        } else if (element == "M'") {
            M1();
        } else if (element == "M2") {
            M2();
        } else if (element == "E") {
            E();
        } else if (element == "E'") {
            E1();
        } else if (element == "E2") {
            E2();
        } else if (element == "S") {
            S();
        } else if (element == "S'") {
            S1();
        } else if (element == "S2") {
            S2();
        } else if (element == "x") {
            turnX();
        } else if (element == "x'") {
            turnX1();
        } else if (element == "x2") {
            turnX2();
        } else if (element == "y") {
            turnY();
        } else if (element == "y'") {
            turnY1();
        } else if (element == "y2") {
            turnY2();
        } else if (element == "z") {
            turnZ();
        } else if (element == "z'") {
            turnZ1();
        } else if (element == "z2") {
            turnZ2();
        }
    }

    if (saveCombination) {
        solution_.push_back(combinationStr);
    }
}

int Cube::countMisplacedStickers() {
    int count = 0;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (sides_[i].sideVec_[j][k].pieceColor_ != sides_[i].sideVec_[1][1].pieceColor_) {
                    ++count;
                }
            }
        }
    }

    return count;
}

void Cube::makeRandomMove(int randomNumber) {
    randomNumber %= 26;

    if (randomNumber == 0) {
        U();
    } else if (randomNumber == 1) {
        U1();
    } else if (randomNumber == 2) {
        U2();
    } else if (randomNumber == 3) {
        D();
    } else if (randomNumber == 4) {
        D1();
    } else if (randomNumber == 5) {
        D2();
    } else if (randomNumber == 6) {
        R();
    } else if (randomNumber == 7) {
        R1();
    } else if (randomNumber == 8) {
        R2();
    } else if (randomNumber == 9) {
        L();
    } else if (randomNumber == 10) {
        L1();
    } else if (randomNumber == 11) {
        L2();
    } else if (randomNumber == 12) {
        F();
    } else if (randomNumber == 13) {
        F1();
    } else if (randomNumber == 14) {
        F2();
    } else if (randomNumber == 15) {
        B();
    } else if (randomNumber == 16) {
        B1();
    } else if (randomNumber == 17) {
        B2();
    } else if (randomNumber == 18) {
        M();
    } else if (randomNumber == 19) {
        M1();
    } else if (randomNumber == 20) {
        M2();
    } else if (randomNumber == 21) {
        E();
    } else if (randomNumber == 22) {
        E1();
    } else if (randomNumber == 23) {
        E2();
    } else if (randomNumber == 24) {
        S();
    } else if (randomNumber == 25) {
        S1();
    } else if (randomNumber == 26) {
        S2();
    }

}

bool Cube::isValid() {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (i != j) {
                if (sides_[i].sideVec_[1][1].pieceColor_ == sides_[j].sideVec_[1][1].pieceColor_) {
                    return false;
                }
            }
        }
    }

    std::vector<int> stickersCount(6);

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                ++stickersCount[static_cast<int>(sides_[i].sideVec_[j][k].pieceColor_)];
            }
        }
    }

    if (std::any_of(stickersCount.cbegin(), stickersCount.cend(), [](int value) { return value != 9; })) {
        return false;
    }

// opposite color is located in a second element of a pair
    std::vector<std::pair<Color, Color>> colorVec(6);

    for (int i = 0; i < 6; ++i) {
        colorVec[i].first = static_cast<Color>(i);
        if (i < 3) {
            colorVec[static_cast<int>(sides_[i].sideVec_[1][1].pieceColor_)].second =
                    sides_[i + 3].sideVec_[1][1].pieceColor_;
        } else {
            colorVec[static_cast<int>(sides_[i].sideVec_[1][1].pieceColor_)].second =
                    sides_[i - 3].sideVec_[1][1].pieceColor_;
        }
    }


// indexing is different for different sides_, so we have to do 5 distinct validations (last side is validated in the
// process)

// side 0
    Color opColor = colorVec[static_cast<int>(sides_[0].sideVec_[0][0].pieceColor_)].second;
    if (sides_[1].sideVec_[0][2].pieceColor_ == opColor || sides_[2].sideVec_[2][0].pieceColor_ == opColor) {
        return false;
    }
    opColor = colorVec[static_cast<int>(sides_[0].sideVec_[0][1].pieceColor_)].second;
    if (sides_[2].sideVec_[2][1].pieceColor_ == opColor) {
        return false;
    }
    opColor = colorVec[static_cast<int>(sides_[0].sideVec_[0][2].pieceColor_)].second;
    if (sides_[2].sideVec_[2][2].pieceColor_ == opColor || sides_[4].sideVec_[0][0].pieceColor_ == opColor) {
        return false;
    }
    opColor = colorVec[static_cast<int>(sides_[0].sideVec_[1][0].pieceColor_)].second;
    if (sides_[1].sideVec_[1][2].pieceColor_ == opColor) {
        return false;
    }
    opColor = colorVec[static_cast<int>(sides_[0].sideVec_[1][2].pieceColor_)].second;
    if (sides_[4].sideVec_[1][0].pieceColor_ == opColor) {
        return false;
    }
    opColor = colorVec[static_cast<int>(sides_[0].sideVec_[2][0].pieceColor_)].second;
    if (sides_[1].sideVec_[2][2].pieceColor_ == opColor || sides_[5].sideVec_[0][0].pieceColor_ == opColor) {
        return false;
    }
    opColor = colorVec[static_cast<int>(sides_[0].sideVec_[2][1].pieceColor_)].second;
    if (sides_[5].sideVec_[0][1].pieceColor_ == opColor) {
        return false;
    }
    opColor = colorVec[static_cast<int>(sides_[0].sideVec_[2][2].pieceColor_)].second;
    if (sides_[4].sideVec_[2][0].pieceColor_ == opColor || sides_[5].sideVec_[0][2].pieceColor_ == opColor) {
        return false;
    }
// side 1
    opColor = colorVec[static_cast<int>(sides_[1].sideVec_[0][0].pieceColor_)].second;
    if (sides_[3].sideVec_[2][0].pieceColor_ == opColor || sides_[2].sideVec_[0][0].pieceColor_ == opColor) {
        return false;
    }
    opColor = colorVec[static_cast<int>(sides_[1].sideVec_[0][1].pieceColor_)].second;
    if (sides_[2].sideVec_[1][0].pieceColor_ == opColor) {
        return false;
    }
    opColor = colorVec[static_cast<int>(sides_[1].sideVec_[0][2].pieceColor_)].second;
    if (sides_[2].sideVec_[2][0].pieceColor_ == opColor) {
        return false;
    }
    opColor = colorVec[static_cast<int>(sides_[1].sideVec_[1][0].pieceColor_)].second;
    if (sides_[3].sideVec_[1][0].pieceColor_ == opColor) {
        return false;
    }
    opColor = colorVec[static_cast<int>(sides_[1].sideVec_[2][0].pieceColor_)].second;
    if (sides_[3].sideVec_[0][0].pieceColor_ == opColor || sides_[5].sideVec_[2][0].pieceColor_ == opColor) {
        return false;
    }
    opColor = colorVec[static_cast<int>(sides_[1].sideVec_[2][1].pieceColor_)].second;
    if (sides_[5].sideVec_[1][0].pieceColor_ == opColor) {
        return false;
    }
    opColor = colorVec[static_cast<int>(sides_[1].sideVec_[2][2].pieceColor_)].second;
    if (sides_[5].sideVec_[0][0].pieceColor_ == opColor) {
        return false;
    }

// side 2
    opColor = colorVec[static_cast<int>(sides_[2].sideVec_[0][0].pieceColor_)].second;
    if (sides_[3].sideVec_[2][0].pieceColor_ == opColor) {
        return false;
    }
    opColor = colorVec[static_cast<int>(sides_[2].sideVec_[0][1].pieceColor_)].second;
    if (sides_[3].sideVec_[2][1].pieceColor_ == opColor) {
        return false;
    }
    opColor = colorVec[static_cast<int>(sides_[2].sideVec_[0][2].pieceColor_)].second;
    if (sides_[3].sideVec_[2][2].pieceColor_ == opColor || sides_[4].sideVec_[0][2].pieceColor_ == opColor) {
        return false;
    }
    opColor = colorVec[static_cast<int>(sides_[2].sideVec_[1][2].pieceColor_)].second;
    if (sides_[4].sideVec_[0][1].pieceColor_ == opColor) {
        return false;
    }
    opColor = colorVec[static_cast<int>(sides_[2].sideVec_[2][2].pieceColor_)].second;
    if (sides_[4].sideVec_[0][0].pieceColor_ == opColor) {
        return false;
    }
// side 3
    opColor = colorVec[static_cast<int>(sides_[3].sideVec_[0][0].pieceColor_)].second;
    if (sides_[5].sideVec_[2][0].pieceColor_ == opColor) {
        return false;
    }
    opColor = colorVec[static_cast<int>(sides_[3].sideVec_[0][1].pieceColor_)].second;
    if (sides_[5].sideVec_[2][1].pieceColor_ == opColor) {
        return false;
    }
    opColor = colorVec[static_cast<int>(sides_[3].sideVec_[0][2].pieceColor_)].second;
    if (sides_[5].sideVec_[2][2].pieceColor_ == opColor || sides_[4].sideVec_[2][2].pieceColor_ == opColor) {
        return false;
    }
    opColor = colorVec[static_cast<int>(sides_[3].sideVec_[1][2].pieceColor_)].second;
    if (sides_[4].sideVec_[1][2].pieceColor_ == opColor) {
        return false;
    }
    opColor = colorVec[static_cast<int>(sides_[3].sideVec_[2][2].pieceColor_)].second;
    if (sides_[4].sideVec_[0][2].pieceColor_ == opColor) {
        return false;
    }
    // side 4
    opColor = colorVec[static_cast<int>(sides_[4].sideVec_[2][0].pieceColor_)].second;
    if (sides_[5].sideVec_[0][2].pieceColor_ == opColor) {
        return false;
    }
    opColor = colorVec[static_cast<int>(sides_[4].sideVec_[2][1].pieceColor_)].second;
    if (sides_[5].sideVec_[1][2].pieceColor_ == opColor) {
        return false;
    }
    opColor = colorVec[static_cast<int>(sides_[4].sideVec_[2][2].pieceColor_)].second;
    if (sides_[5].sideVec_[2][2].pieceColor_ == opColor) {
        return false;
    }


    return true;
}

bool operator==(const Cube &firstCube, const Cube &secondCube) {
    return firstCube.numOfMisplacedStickers_ == secondCube.numOfMisplacedStickers_;
}

bool operator!=(const Cube &firstCube, const Cube &secondCube) {
    return !(operator==(firstCube, secondCube));
}

bool operator<(const Cube &firstCube, const Cube &secondCube) {
    return firstCube.numOfMisplacedStickers_ < secondCube.numOfMisplacedStickers_;
}

bool operator>(const Cube &firstCube, const Cube &secondCube) {
    return operator<(secondCube, firstCube);
}

bool operator<=(const Cube &firstCube, const Cube &secondCube) {
    return !(operator>(firstCube, secondCube));
}

bool operator>=(const Cube &firstCube, const Cube &secondCube) {
    return !(operator<(firstCube, secondCube));
}

void Cube::randomize(int numberOfMoves) {
    std::random_device random;
    std::mt19937 mersenne(random());
    std::uniform_int_distribution<std::mt19937::result_type> getNumber(0, 26);
    int randomNumber = 0;

    for (int i = 0; i < numberOfMoves; ++i) {
        randomNumber = getNumber(mersenne);
        makeRandomMove(randomNumber);
    }
}

std::vector<std::string> CubeSolver::solve() {
    std::random_device random;
    std::mt19937 mersenne(random());
    std::vector<std::string> combList{"F' L' B' R' U' R U' B L F R U R' U",
                                      "F R B L U L' U B' R' F' L' U' L U'",
                                      "U2 B U2 B' R2 F R' F' U2 F' U2 F R'",
                                      "U2 R U2 R' F2 L F' L' U2 L' U2 L F'",
                                      "U' B2 D2 L' F2 D2 B2 R' U'",
                                      "U B2 D2 R F2 D2 B2 L U",
                                      "D' R' D R2 U' R B2 L U' L' B2 U R2",
                                      "D L D' L2 U L' B2 R' U R B2 U' L2",
                                      "R' U L' U2 R U' L R' U L' U2 R U' L U'",
                                      "L U' R U2 L' U R' L U' R U2 L' U R' U",
                                      "F' U B U' F U B' U'",
                                      "F U' B' U F' U' B U",
                                      "L' U2 L R' F2 R",
                                      "R' U2 R L' B2 L",
                                      "M2 U M2 U2 M2 U M2"};
    std::vector<std::string> orientationsList{"z", "z'", "z2"};
    std::vector<std::string> rotationsList{"x", "x'", "x2", "y", "y'", "y2"};
    std::vector<std::string> movesList{"U", "U'", "U2", "D", "D'", "D2",
                                       "R", "R'", "R2", "L", "L'", "L2",
                                       "F", "F'", "F2", "B", "B'", "B2"};
    std::uniform_int_distribution<std::mt19937::result_type> getType(0, 5);
    std::uniform_int_distribution<std::mt19937::result_type> getComb(0, 14);
    std::uniform_int_distribution<std::mt19937::result_type> getRotation(0, 5);
    std::uniform_int_distribution<std::mt19937::result_type> getOrientation(0, 2);
    std::uniform_int_distribution<std::mt19937::result_type> getMove(0, 17);

    for (int i = 0; i < maxResets_; ++i) {
        population_.clear();
        for (int j = 0; j < populationSize_; ++j) {
            Cube newCube{startingPosition_};
            newCube.applyCombination(movesList[getMove(mersenne)], true);
            newCube.applyCombination(movesList[getMove(mersenne)], true);
            newCube.numOfMisplacedStickers_ = newCube.countMisplacedStickers();
            population_.push_back(newCube);
        }

        for (int j = 0; j < maxGenerations_; ++j) {
            std::sort(population_.begin(), population_.end());
            for (int k = 0; k < populationSize_; ++k) {
                if (population_[k].numOfMisplacedStickers_ == 0) {
                    return population_[k].solution_;
                }


                if (k > elitismNum_) {
                    std::uniform_int_distribution<std::mt19937::result_type> getNumber(0, elitismNum_);
                    int randCube = getNumber(mersenne);
                    population_[k] = population_[randCube];


                    int type = getType(mersenne);

                    switch (type) {
                        case 0:
                            population_[k].applyCombination
                                    (combList[getComb(mersenne)], true);
                            break;
                        case 1:
                            population_[k].applyCombination
                                    (combList[getComb(mersenne)], true);
                            population_[k].applyCombination(combList[getComb(mersenne)], true);
                            break;
                        case 2:
                            population_[k].applyCombination
                                    (rotationsList[getRotation(mersenne)], true);
                            population_[k].applyCombination
                                    (combList[getComb(mersenne)], true);
                            break;
                        case 3:
                            population_[k].applyCombination
                                    (orientationsList[getOrientation(mersenne)], true);
                            population_[k].applyCombination
                                    (combList[getComb(mersenne)], true);
                            break;
                        case 4:
                            population_[k].applyCombination
                                    (rotationsList[getRotation(mersenne)], true);
                            population_[k].applyCombination
                                    (orientationsList[getOrientation(mersenne)], true);
                            population_[k].applyCombination
                                    (combList[getComb(mersenne)], true);
                            break;
                        case 5:
                            population_[k].applyCombination
                                    (orientationsList[getOrientation(mersenne)], true);
                            population_[k].applyCombination
                                    (rotationsList[getRotation(mersenne)], true);
                            population_[k].applyCombination
                                    (combList[getComb(mersenne)], true);
                            break;
                    }
                }
                population_[k].numOfMisplacedStickers_ = population_[k].countMisplacedStickers();
            }
        }
    }
    std::vector<std::string> notFound;
    return notFound;


}