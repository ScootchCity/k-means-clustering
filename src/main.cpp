#include <iostream>
#include "Point.h"
#include "Cluster.h"
#include "KMeans.h"
#include "CSVReader.h"
#include "CSVWriter.h"

using namespace std;

int main(int argc, char* argv[]) {
    cout << "K-Means Clustering" << endl;

    if(argc != 4) {
        cout << "Wrong number of arguments!\n";
        cout << "Usage: kmeans <input_file> <k_value> <convergence_threshold>\n";
        return 1;
    }

    string input_file = argv[1];
    int k = stoi(argv[2]);
    double convergence_threshold = stod(argv[3]);


    CSVWriter writer;
    CSVReader reader;
    vector<Point> points = reader.readCSVPoints(input_file);

    KMeans kmeans(points, k, convergence_threshold);
    kmeans.initialize();

    //write initial state to files
    writer.writePoints(kmeans.getPoints(), "output/iteration_" + to_string(i) + "_points.csv");
    writer.writeClusters(kmeans.getClusters(), "output/iteration_" + to_string(i) + "_clusters.csv");

    int i = 1; //first iteration (the beginning state) was written already so we start at one
    while(!kmeans.hasConverged()){
        kmeans.step();

        //write current stage to files
        writer.writePoints(kmeans.getPoints(), "output/iteration_" + to_string(i) + "_points.csv");
        writer.writeClusters(kmeans.getClusters(), "output/iteration_" + to_string(i) + "_clusters.csv");

        i++;
    }

    return 0;
}
