#ifndef CSVWRITER_H
#define CSVWRITER_H

#include <vector>
#include <string>
#include "Point.h"
#include "Cluster.h"

using namespace std;

class CSVWriter {
public:
    //writes points to CSV file
    void writePoints(vector<Point> points, string filename);
    //writes clusters to CSV file
    void writeClusters(vector<Cluster> clusters, string filename);
    //writes just the x,y (for data generator)
    void writePointsSimple(vector<Point> points, string filename);

private:
};

#endif // CSVWRITER_H
