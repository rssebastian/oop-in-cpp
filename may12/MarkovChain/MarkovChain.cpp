#include "MarkovChain.h"
void MarkovChain::fillQueue(std::string line)
{
    if (line == "")
        return;
    std::size_t space = line.find(" ");
    std::string word = line.substr(0, space);
    wordQueue.push_back(word);
    if (space != std::string::npos)
        fillQueue(line.substr(space + 1));
}

MarkovChain::MarkovChain(std::string textFile)
{
    std::fstream textFileFS;
    textFileFS.open(textFile, std::ios::in);
    if (textFileFS)
    {
        std::string currentLine;
        getline(textFileFS, currentLine);
        while (currentLine == "")
            getline(textFileFS, currentLine);
        fillQueue(currentLine);

        std::string firstWord = wordQueue.at(0);
        std::string currentWord = wordQueue.at(0);
        while (wordQueue.size() != 0)
        {
            while (wordQueue.size() == 1)
            {
                getline(textFileFS, currentLine);
                fillQueue(currentLine);
                if (textFileFS.eof())
                    break;
            }
            if (wordQueue.size() == 1 && textFileFS.eof())
            {
                chain[currentWord].push_back(firstWord);
                break;
            }
            std::string nextWord = wordQueue.at(1);
            if (chain.count(currentWord) == 0)
            {
                chain.emplace(currentWord, std::vector<std::string>());
                chain[currentWord].push_back(nextWord);
            }
            else
            {
                chain[currentWord].push_back(nextWord);
            }
            currentWord = nextWord;
            wordQueue.erase(wordQueue.begin());
        }
    }
    else
    {
        std::cerr << "File not found" << std::endl;
    }
    textFileFS.close();
    std::ofstream results("results.txt");
    if (results.is_open())
    {
        for (auto &pair : chain)
        {
            std::string line;
            line += pair.first + ": ";
            for (auto &currentWord : pair.second)
            {
                line += currentWord + " ";
            }
            results << line << std::endl;
            std::cout << line << std::endl;
        }
        results.close();
    }
    else
        std::cerr << "Unable to open file";
}
