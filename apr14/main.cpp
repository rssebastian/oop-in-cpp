#include "TuringMachine.h"

int main()
{
    // Print a tape of 100 then clear it
    TuringMachine tm;
    std::cout << "Currently at Square " << tm.get_current_square() << std::endl;
    std::cout << "Square State #" << tm.get_current_square() << ": " << tm.read_square() << std::endl;
    tm.make_mark();
    std::cout << "Square State #" << tm.get_current_square() << ": " << tm.read_square() << std::endl;
    tm.move_right();
    tm.move_right();
    std::cout << tm.get_tape() << std::endl;
    tm.move_left();
    tm.remove_mark();
    tm.move_left();
    tm.remove_mark();
    std::cout << tm.get_tape();
    return 0;
}