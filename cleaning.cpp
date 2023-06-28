//
// Created by kaitl on 4/27/2022.
//

#include <vector>
#include <string>
#include <fstream>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <ostream>
#include <cctype>
#include "cleaning.h"
#include "counting.h"

// cleans up words
// lowers the letters and removes the special characters
void cleaning(std::vector<std::string> &words, int count) {
    for (int i = 0; i < words.size(); ++i) {
        std::transform(words[i].begin(), words[i].end(), words[i].begin(), ::tolower);
        for (int j = 0; j < words.size(); ++j) {
            removespecialCharacters(words[i]);
        }
    }
    std::map<std::string, int> wordCountMap = countingWords(words);
    sortingFrequencies(wordCountMap, count);
}

// reads the file from the command line
std::vector<std::string> readFile(const std::string& inFile) {
    std::vector<std::string> copiedFile;
    std::ifstream file(inFile);
    std::copy(std::istream_iterator<std::string>(file), std::istream_iterator<std::string>(), std::back_inserter(copiedFile));
    file.close();
    return copiedFile;
}

// removes the special characters
void removespecialCharacters(std::string &words) {
    for (int i = 0; i < words.size() - 1; ++i) {
        if ((words.at(i) < 'a' || words.at(i) > 'z') && (words.at(i) < '0' || words.at(i) > '9')) { // erases the special characters in front of words
            words.erase(words.begin() + i); // do this to keep track of important characters like apostrophes
        } else if (words.at(i) >= 'a' && words.at(i) <= 'z') {
            break; // breaks if there is a letter
        }
    }
    for (int i = words.size() - 1; i > 0; --i) {
        if ((words.at(i) < 'a' || words.at(i) > 'z') && (words.at(i) > '0' || words.at(i) < '9')) { // erases the special characters behind words
            words.erase(words.begin() + i); // do this to keep track of important characters like apostrophes
        } else if (words.at(i) >= 'a' && words.at(i) <= 'z') {
            break; // breaks if there is a letter
        }
    }
}

void printing(std::map<std::string, int> wordCountMap, std::map<int, std::vector<std::string>, std::greater<>> countMap, int count, int current) {
    // erases all the stop words
    wordCountMap.erase("a");
    wordCountMap.erase("an");
    wordCountMap.erase("and");
    wordCountMap.erase("in");
    wordCountMap.erase("is");
    wordCountMap.erase("it");
    wordCountMap.erase("the");
    // creates a new map to store string of words into vectors
    countMap = newMap(wordCountMap);
    for (auto const &i: countMap) {
        if (current < count + 1) {
            std::cout << current << ".)" << " These words appeared " << i.first << " times: "; // prints out number in front and number of times it appears
            printString(i.second, count);
            ++current;
        }
    }
}

void printString(std::vector<std::string> words, int count) {
    // uses vector of strings to print out all the words
    std::cout << "{";
    for (int i = 0; i < words.size() - 1; ++i) {
        std::cout << words[i] << ", ";
    }
    std::cout << words.at(words.size() - 1) << "}" << std::endl;
    ++count;
}