#ifndef DISTRIBUTOR_H
#define DISTRIBUTOR_H

#include <vector>
#include <string>

void distribute_data(const std::vector<std::vector<std::string>> &data, int world_size, int world_rank);
std::vector<std::vector<std::string>> receive_data(int world_rank);

#endif // DISTRIBUTOR_H
