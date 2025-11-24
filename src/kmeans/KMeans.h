#ifndef KMEANS_H
#define KMEANS_H

#include <vector>
#include "Point.h"
#include "Cluster.h"

using namespace std;

class KMeans {
public:
    // K-means algorithm implementation will go here

private:
    vector<Point> points;
    vector<ClusterCenter> centers;
    int k;
    double epsilon;
};

#endif // KMEANS_H
