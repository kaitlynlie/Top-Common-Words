#include <vector>
#include <iterator>
#include <map>
#include <iostream>
#include "cleaning.h"
#include "counting.h"

int main(int argc, char **argv)
{

    // checks if there is file
    if (argc < 1)
    {
        return -1;
    }

    // creates a vector to store the words from the file
    std::vector<std::string> inFile = readFile(argv[1]);
    int count = 0;
    // gets the top words to find if any
    if (argc == 3)
    {
        for (int i = 0; i < argc; ++i)
        {
            count += atoi(argv[i]);
        }
        cleaning(inFile, count);
    }
    else
    {
        count = 10; // otherwise defaults to 10
        cleaning(inFile, count);
    }

    // makes a map to count words with strings and int
    std::map<std::string, int> wordCountMap;
    // makes a map to count ints and store strings in a vector to be able
    // to print multiple words under the same number of times it appears
    std::map<int, std::vector<std::string>, std::greater<>> countMap;
    wordCountMap = countingWords(inFile);             // counts how many times the word shows up
    int current = 1;                                  // keeps track of what number we are on for the top words
    printing(wordCountMap, countMap, count, current); // prints out the output

    return 0;
}