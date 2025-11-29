#include "KMeans.h"
#include <random>

//public
KMeans::KMeans(vector<Point> points, int k, double convergence_threshold){
    this->points = points;
    this->k = k;
    this->convergence_threshold = convergence_threshold;
}

void KMeans::initialize(){
    //initializes k clusters by picking k random points from the points array
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, points.size()-1);
    int point_index;

    //for making sure no duplicates
    vector<int> already_chosen;

    for(int i = 0; i < k; i++) {
        //for making sure no duplicates
        //its a bit sloppy. maybe there is a cleaner way?
        bool duplicate = true;
        while(duplicate) {
            duplicate = false;
            point_index = distrib(gen);
            for(int index : already_chosen) {
                if (index == point_index) {
                    duplicate = true;
                    break;
                }
            }
        }
        already_chosen.push_back(point_index); //add valid index to already_chosen

        //make the new cluster and push it
        Cluster cl;
        cl.id = i;
        cl.x = points[point_index].x;
        cl.y = points[point_index].y;

        clusters.push_back(cl);
    }

    prev_clusters = clusters; //init the prev_clusters as well
}

void KMeans::step(){
    //1 step of the algo
    assignPointsToClusters();
    updateClusterCenters();
}

bool KMeans::hasConverged(){
    //returns whether the convergence is under the convergence_threshhold
}

vector<Point> KMeans::getPoints(){return points;}

vector<Cluster> KMeans::getClusters(){return clusters;}

//private
void KMeans::assignPointsToClusters(){
    //for each point calculate the distance to each cluster
    //assign each points cluster_id to the closest cluster
}

void KMeans::updateClusterCenters(){
    //update clusters to be the new mean of all points in their cluster
}

double KMeans::calculateDistance(Point pt, Cluster cl){
    //get the distance of a point to a cluster
}