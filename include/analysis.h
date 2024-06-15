#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <vector>
#include <string>
#include <unordered_map>

void analysis(const std::vector<std::vector<std::string>> &data, int world_size, int world_rank);
void count_lines(const std::vector<std::vector<std::string>> &data);
std::unordered_map<std::string, int> string_occurrences(const std::vector<std::vector<std::string>> &data);
std::string calculate_string_mode(const std::unordered_map<std::string, int> &occurrences);

#endif // ANALYSIS_H
