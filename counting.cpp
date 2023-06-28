//
// Created by kaitl on 4/25/2022.
//

#include <istream>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "counting.h"

// counts how many times the words show up
std::map<std::string, int> countingWords (std::vector<std::string> words) {
    std::map<std::string, int> wordCountMap;
    for (int i = 0; i < words.size(); ++i) {
        if(wordCountMap.find(words[i]) == wordCountMap.end()) { // if the word is not found in the map
            wordCountMap.insert(std::pair<std::string, int> (words[i], 1)); // increment the count by 1
        } else {
            wordCountMap.find(words[i]) -> second = wordCountMap.at(words[i]) + 1; // else add 1 to the count
        }
    }
    return wordCountMap;
}

// creates a new map to store the words into a vector to be able to have multiple words under one frequency
std::map<int, std::vector<std::string>, std::greater<>> newMap (std::map<std::string, int>& wordCountMap) {
    std::map<int, std::vector<std::string>, std::greater<>> countMap;
    for (auto& i : wordCountMap) {
        countMap[i.second].push_back(i.first);
    }
    return countMap;
}

// compares which frequency is larger for sorting
bool compare(std::pair<std::string, int>& first, std::pair<std::string, int>& second) {
    return first.second < second.second;
}

// sorts the frequencies by placing into a vector
void sortingFrequencies(std::map<std::string, int>& map, int count) {
    std::vector<std::pair<std::string, int>> frequencies;
    for (auto& i : map) {
        frequencies.push_back(i);
    }
    sort(frequencies.begin(), frequencies.end(), compare);
    frequencies.resize(count);
}