#include "TuringMachine.h"

int main()
{
    // Print a tape of 100 then clear it
    //turingmachine tm;
    //std::cout << "currently at square " << tm.get_current_square() << std::endl;
    //std::cout << "square state #" << tm.get_current_square() << ": " << tm.read_square() << std::endl;
    //tm.make_mark();
    //std::cout << "square state #" << tm.get_current_square() << ": " << tm.read_square() << std::endl;
    //tm.move_right();
    //tm.move_right();
    //std::cout << tm.get_tape() << std::endl;
    //tm.move_left();
    //tm.remove_mark();
    //tm.move_left();
    //tm.remove_mark();
    //std::cout << tm.get_tape();
    //std::cout << std::endl << std::endl << std::endl;

    TuringMachine("tape.txt", "state_list.txt");

    return 0;
}