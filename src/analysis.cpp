#include "../include/analysis.h"
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <mpi.h>

void analysis(const std::vector<std::vector<std::string>> &data, int world_size, int world_rank) {
    count_lines(data);

    auto occurrences = string_occurrences(data);
    std::string mode = calculate_string_mode(occurrences);

    if (world_rank == 0) {
        std::cout << "Most frequent string: " << mode << std::endl;
    }
}

void count_lines(const std::vector<std::vector<std::string>> &data) {
    std::cout << "Process analyzed " << data.size() << " lines." << std::endl;
}

std::unordered_map<std::string, int> string_occurrences(const std::vector<std::vector<std::string>> &data) {
    std::unordered_map<std::string, int> occurrences;
    for (const auto& row : data) {
        for (const auto& value : row) {
            occurrences[value]++;
        }
    }
    return occurrences;
}

std::string calculate_string_mode(const std::unordered_map<std::string, int> &occurrences) {
    auto mode = std::max_element(occurrences.begin(), occurrences.end(),
                                 [](const auto &a, const auto &b) {
                                     return a.second < b.second;
                                 });
    return mode->first;
}
