#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

class MarkovChain
{
private:
    std::map<std::string, std::vector<std::string>> chain;
    std::vector<std::string> wordQueue;
    void fillQueue(std::string line);

public:
    MarkovChain(std::string textFile);
    ~MarkovChain()
    {
        chain.clear();
        wordQueue.clear();
    }
};
