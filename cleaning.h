//
// Created by kaitl on 4/27/2022.
//

#ifndef TOPCOMMONWORDS_CLEANING_H
#define TOPCOMMONWORDS_CLEANING_H

#include <map>

void cleaning(std::vector<std::string> &words, int count);
std::vector<std::string> readFile(const std::string& inFile);
void removespecialCharacters(std::string &words);
void printing(std::map<std::string, int> wordCountMap, std::map<int, std::vector<std::string>, std::greater<>> countMap, int count, int current);
void printString(std::vector<std::string> words, int count);


#endif //TOPCOMMONWORDS_CLEANING_H
