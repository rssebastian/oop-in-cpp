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
    long initialState = 0;
    std::vector<int> tape;
    std::string tape_f;
    std::string state_f;
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
    TuringMachine() {};
    TuringMachine(std::string tape_file, std::string state_file) {
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
            std::cout << squaresToMark << std::endl;

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
                std::cout << currentLine << std::endl;
            }
        }
        else {
            std::cout << "Error opening state";
        }
        state_fs.close();
    };
    void move_left();          // moves the read head 1 square left
    void move_right();         // moves the read head 1 square right
    bool read_square();        // returns true if there is a mark
                               // on the current square, false otherwise
    void make_mark();          // marks the current square, if it
                               // is not already marked
    void remove_mark();        // if there is a mark on the current
                               // square, remove it
    std::string get_tape();    // returns a string
                               // representation of the tape
    long get_current_square(); // returns the location of
                               // the read head
};