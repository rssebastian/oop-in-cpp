#include "TuringMachine.h"

int main()
{
    TuringMachine tm = TuringMachine("tape.txt", "state_list.txt");
    std::cout << std::endl;
    std::cout << "Starting Tape: " << tm.get_tape() << std::endl;
    tm.run();
    std::cout << "Ending Tape: " << tm.get_tape() << std::endl;
    return 0;
}

/*
TEST CASE OUTPUT
Initial State = 1
State List :
1, R, 2 | 1, L, 2
1, L, 1 | 0, L, 3
1, L, 0 | 1, L, 4
1, R, 4 | 0, R, 1

Starting Tape : Blank Tape
Ending Tape : [-10, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3]
*/