#ifndef KMEANS_H
#define KMEANS_H

#include <vector>
#include <string>
#include "Point.h"
#include "Cluster.h"

using namespace std;

class KMeans {
public:
    KMeans(vector<Point> points, int k, double convergence_threshold);

    void initialize();              //initilize k centers
    void step();                    //step the algo
    bool hasConverged();            //see if convergence is below threshold
    vector<Point> getPoints();      //get the current vector of points (with assigned clusters)
    vector<Cluster> getClusters();  //get the current clusters

private:
    vector<Point> points;               //all the points
    vector<Cluster> clusters;           //all the clusters
    vector<Cluster> prev_clusters;      //previous clusters to check convergence
    int k;                              //number of clusters to make
    double convergence_threshold;       //value of convergence at which algo is done

    void assignPointsToClusters();      //assign cluster_id of point to nearest cluster
    void updateClusterCenters();        //recalculate cluster centers
    double calculateDistance(Point pt, Cluster cl); //eucledian distance between a point and a cluster
};

#endif // KMEANS_H
