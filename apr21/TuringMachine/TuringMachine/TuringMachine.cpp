#include "TuringMachine.h"

TuringMachine::TuringMachine(std::string tape_file, std::string state_file) {
    tape_f = tape_file;
    state_f = state_file;

    std::fstream tape_fs;
    std::fstream state_fs;
    tape_fs.open(tape_f, std::ios::in);
    if (tape_fs) {
        std::string currentLine;
        getline(tape_fs, currentLine);
        std::size_t squareReader = currentLine.find(":");
        initialState = stoi(currentLine.substr(0, squareReader));
        std::string squaresToMark = currentLine.substr(++squareReader);

        std::size_t nextComma = currentLine.find(",");
        while (nextComma != std::string::npos) {
            tape.push_back(stoi(currentLine.substr(squareReader, nextComma)));
            squareReader = nextComma + 1;
            squaresToMark = currentLine.substr(squareReader);
            if (squaresToMark.find(",") != std::string::npos) {
                nextComma += squaresToMark.find(",") + 1;
            }
            else {
                nextComma = squaresToMark.find(",");
            }
        }
        tape.push_back(stoi(currentLine.substr(squareReader)));

        std::cout << "Initial State = " << initialState << std::endl;
    }
    else {
        std::cout << "Error opening tape";
    }
    tape_fs.close();

    state_fs.open(state_f, std::ios::in);
    if (state_fs) {
        std::string currentLine;
        while (getline(state_fs, currentLine)) {
            std::size_t colon = currentLine.find(":");
            std::string ifZero = currentLine.substr(0, colon);
            std::string ifOne = currentLine.substr(colon + 1);
            std::vector<std::string> state;
            state.push_back(ifZero);
            state.push_back(ifOne);
            states.push_back(state);
        }
        std::cout << "State List: " << std::endl;
        for (int row = 0; row < states.size(); row++) {
            std::cout << states.at(row).at(0) << "|" << states.at(row).at(1) << std::endl;
        }
    }
    else {
        std::cout << "Error opening state";
    }
    state_fs.close();
};
void TuringMachine::move_left()
{
    current_square--;
    // std::cout << "Moved left, now at Square " << current_square << std::endl;
}

void TuringMachine::move_right()
{
    current_square++;
    // std::cout << "Moved right, now at Square " << current_square << std::endl;
}

bool TuringMachine::read_square()
{
    if (getIndex(tape, current_square) != -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void TuringMachine::make_mark()
{
    if (getIndex(tape, current_square) == -1)
    {
        tape.push_back(current_square);
        // std::cout << "Mark made at square " << current_square << std::endl;
    }
}

void TuringMachine::remove_mark()
{
    if (getIndex(tape, current_square) != -1)
    {
        tape.erase(tape.begin() + getIndex(tape, current_square));
        // std::cout << "Mark removed at square " << current_square << std::endl;
    }
}
std::string TuringMachine::get_tape()
{
    std::string output;
    if (tape.size() == 0)
        return "Blank Tape\n";
    long maxValue = (findMaxValue() > current_square) ? findMaxValue() : current_square;
    for (int i = findMinValue(); i <= maxValue; i++)
    {

        if (getIndex(tape, i) != -1)
        {
            output += "1";
        }
        else
        {
            output += "0";
        }
    }
    return output;
}

long TuringMachine::get_current_square()
{
    return current_square;
}