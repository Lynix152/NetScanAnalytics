#include "../include/distributor.h"
#include "../include/Logger.h"
#include <mpi.h>

void distribute_data(const std::vector<std::vector<std::string>> &data, int world_size, int world_rank) {
    int num_rows = data.size();
    int chunk_size = num_rows / (world_size - 1);
    int offset = 0;

    for (int i = 1; i < world_size; ++i) {
        int start = offset;
        int end = (i == world_size - 1) ? num_rows : start + chunk_size;
        int count = end - start;

        MPI_Send(&count, 1, MPI_INT, i, 0, MPI_COMM_WORLD);

        for (int j = start; j < end; ++j) {
            for (const auto& value : data[j]) {
                MPI_Send(value.c_str(), value.size() + 1, MPI_CHAR, i, 0, MPI_COMM_WORLD);
            }
        }

        offset = end;
    }
}

std::vector<std::vector<std::string>> receive_data(int world_rank) {
    MPI_Status status;
    int count;
    MPI_Recv(&count, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);

    std::vector<std::vector<std::string>> local_data(count);

    for (int i = 0; i < count; ++i) {
        char buffer[256];
        MPI_Recv(buffer, 256, MPI_CHAR, 0, 0, MPI_COMM_WORLD, &status);
        local_data[i].emplace_back(buffer);
    }

    return local_data;
}
