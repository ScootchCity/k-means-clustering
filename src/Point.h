#ifndef POINT_H
#define POINT_H

struct Point {
    int id;
    double x;
    double y;
    int cluster_id;
    double distance_to_cluster;
};

#endif // POINT_H
