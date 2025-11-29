#include "CSVWriter.h"
#include <fstream>
#include <iostream>

void CSVWriter::writePoints(vector<Point> points, string filename) {
    ofstream fout(filename);

    if(!fout.is_open()) {
        cout << "Could not open points out file!\n";
        return;
    }

    //write header line
    fout << "id,x,y,cluster_id\n";

    //loop over each point and write them to file
    for(const Point &pt : points) {
        fout << pt.id << ","
             << pt.x << ","
             << pt.y << ","
             << pt.cluster_id << endl;
    }

    fout.close();
}

void CSVWriter::writeClusters(vector<Cluster> clusters, string filename) {
    ofstream fout(filename);

    if(!fout.is_open()) {
        cout << "Could not open clusters out file!\n";
        return;
    }

    //write header line
    fout << "id,x,y\n";

    //loop over each cluster and write to file
    for(const Cluster &cl : clusters) {
        fout << cl.id << ","
             << cl.x << ","
             << cl.y << endl;
    }

    fout.close();
}