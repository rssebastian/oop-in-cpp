#include "TuringMachine.h"

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