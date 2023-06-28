//
// Created by kaitl on 4/25/2022.
//

#ifndef TOPCOMMONWORDS_COUNTING_H
#define TOPCOMMONWORDS_COUNTING_H
#include <map>

std::map<std::string, int> countingWords (std::vector<std::string> words);
bool compare(std::pair<std::string, int>& first, std::pair<std::string, int>& second);
void sortingFrequencies(std::map<std::string, int>& map, int count);
std::map<int, std::vector<std::string>, std::greater<>> newMap (std::map<std::string, int>& wordCountMap);


#endif //TOPCOMMONWORDS_COUNTING_H
