#include "KMeans.h"
#include <cmath>

//public
KMeans::KMeans(vector<Point> points, int k, double convergence_threshold){
    
}

void KMeans::initialize(){

}

void KMeans::step(){

}

bool KMeans::hasConverged(){
    
}

vector<Point> KMeans::getPoints(){

}

vector<Cluster> KMeans::getClusters(){

}

//private
void KMeans::assignPointsToClusters(){

    // assign cluster_id of point to nearest cluster implementation
    // for each point, calculate distance to each cluster center and assign to nearest one
    for (auto& point : points) {
        double min_distance = std::numeric_limits<double>::max();
        int closest_cluster_id = -1;

        for (const auto& cluster : clusters) {
            
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

    // recalculate cluster centers implementation
    // for each cluster, calculate the new center based on the mean of assigned points
    for (auto& cluster : clusters) {
        double sum_x = 0.0;
        double sum_y = 0.0;
        int count = 0;

        for (const auto& point : points) {
            if (point.cluster_id == cluster.id) {
                
                sum_x += point.x;
                sum_y += point.y;
                count++;
            }
        }
    }
    
}

double KMeans::calculateDistance(Point pt, Cluster cl){

    // euclidean distance implementation for calculating distance between point and cluster center
    // passing a singular point in a singual cluster
    // take x, y coordinates from the cluster and point and calculate distance from points

    for (pt; pt.x && pt.y; ){
        for (cl; cl.x && cl.y; ){

            double distance = std::sqrt(std::pow((cl.x - pt.x), 2) + std::pow((cl.y - pt.y), 2));
            
            return distance; 
        }
    }

}