#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

class TuringMachine
{
private:
    long current_square = 0;
    int machineState = 0;
    std::vector<int> tape;
    std::string tape_f;
    std::string state_f;
    std::vector<std::vector<std::string>> states;
    int getIndex(std::vector<int> v, int value)
    {
        std::vector<int>::iterator it = std::find(v.begin(), v.end(), value);

        if (it != v.end())
        {
            int index = it - v.begin();
            return index;
        }
        else
        {
            return -1;
        }
    }
    int findMinValue()
    {
        int min = tape[0];
        for (int i = 0; i < tape.size(); i++)
        {
            if (tape[i] < min)
            {
                min = tape[i];
            }
        }
        return min;
    }
    int findMaxValue()
    {
        int max = tape[0];
        for (int i = 0; i < tape.size(); i++)
        {
            if (tape[i] > max)
            {
                max = tape[i];
            }
        }
        return max;
    }

public:
    TuringMachine(std::string tape_file, std::string state_file);
    void move_left();          
    void move_right();         
    bool read_square();        
    void make_mark();          
    void remove_mark();        
    std::string get_tape();    
    long get_current_square(); 
    void update();
    void run();
                               
};