#include <iostream>
#include "DataGenerator.h"

using namespace std;

int main(int argc, char* argv[]) {
    cout << "K-Means Data Generator" << endl;

    // Expected usage: generate_data <num_points> <num_clusters> <output_file>
    // Example: generate_data 1000 3 data/test_3clusters.csv

    if (argc != 4) {
        cout << "Usage: generate_data <num_points> <num_clusters> <output_file>" << endl;
        cout << "Example: generate_data 1000 3 data/test_3clusters.csv" << endl;
        return 1;
    }

    // Data generation logic will go here

    return 0;
}
