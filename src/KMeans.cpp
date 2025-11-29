#include "KMeans.h"
#include <random>
#include <cmath>
#include <limits>

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

    assignPointsToClusters(); //assign points to their starting clusters

    //initialize prev_clusters with very different values to ensure first iteration runs
    prev_clusters = clusters;
    for(Cluster &cl : prev_clusters) {
        cl.x += 1000000.0;  //make them very far away
        cl.y += 1000000.0;
    }
}

void KMeans::step(){
    //1 step of the algo
    prev_clusters = clusters;
    assignPointsToClusters();
    updateClusterCenters();
}

bool KMeans::hasConverged(){
    //returns whether the convergence is under the convergence_threshhold
    for(int i = 0; i < clusters.size(); i++) {
        Cluster &cl = clusters[i];
        Cluster &prev_cl = prev_clusters[i];

        //used inline distance because i didnt want to turn the function into a template
        double distance = sqrt(pow((cl.x - prev_cl.x), 2) + pow((cl.y - prev_cl.y), 2));
        if(distance > convergence_threshold) {
            return false;
        }
    }
    return true;
}

vector<Point> KMeans::getPoints(){return points;}

vector<Cluster> KMeans::getClusters(){return clusters;}

//private
void KMeans::assignPointsToClusters(){
    //assign cluster_id of point to nearest cluster implementation
    //for each point, calculate distance to each cluster center and assign to nearest one
    for (Point &point : points) {
        double min_distance = numeric_limits<double>::max();
        int closest_cluster_id = -1;

        for (const Cluster &cluster : clusters) {
            
            double distance = calculateDistance(point, cluster);
            
            if (distance < min_distance) {
                min_distance = distance;
                closest_cluster_id = cluster.id;
            }
        }

        point.cluster_id = closest_cluster_id;
        point.distance_to_cluster = min_distance;
    }

}

void KMeans::updateClusterCenters(){
    //recalculate cluster centers implementation
    //for each cluster, calculate the new center based on the mean of assigned points
    for (Cluster &cluster : clusters) {
        double sum_x = 0.0;
        double sum_y = 0.0;
        int count = 0;

        //sum all points for a cluster
        for (const Point &point : points) {
            if (point.cluster_id == cluster.id) {
                sum_x += point.x;
                sum_y += point.y;
                count++;
            }
        }
        //update the cluster (provided it has points)
        if(count > 0) {
            cluster.x = sum_x/count;
            cluster.y = sum_y/count;
        }
    }
}

double KMeans::calculateDistance(Point pt, Cluster cl){
    //euclidean distance implementation for calculating distance between point and cluster center
    //passing a singular point in a single cluster
    //take x, y coordinates from the cluster and point and calculate distance from points
    return sqrt(pow((cl.x - pt.x), 2) + pow((cl.y - pt.y), 2));
}