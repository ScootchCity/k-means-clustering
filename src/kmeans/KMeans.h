#ifndef KMEANS_H
#define KMEANS_H

#include <vector>
#include "Point.h"
#include "Cluster.h"

using namespace std;

class KMeans {
public:
    //l-means algorithm implementation will go here

private:
    vector<Point> points;
    vector<Cluster> clusters;
    int k;
    double epsilon;
};

#endif // KMEANS_H
