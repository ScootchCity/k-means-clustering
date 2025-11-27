#include "CSVReader.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

vector<Point> readCSV(string filename) {
    vector<Point> points;
    ifstream fin;
    fin.open(filename);

    if(!fin.is_open()) {
        cout << "Couldnt open CSV input file!\n";
        return points;
    }

    int id = 0;
    string line;

    //skip csv header
    getline(fin, line);

    while(getline(fin, line)) {
        stringstream ss(line);
        string x_str, y_str;

        //split line into comma separated values
        getline(ss, x_str, ',');
        getline(ss, y_str, ',');
        
        //turn strings into doubles
        double x_db = stod(x_str);
        double y_db = stod(y_str);
        
        //bundle it all into a point
        Point pt;
        pt.id = id;
        pt.x = x_db;
        pt.y = y_db;
        pt.cluster_id = -1;
        pt.distance_to_center = -1.0;
        
        //push it to the vector
        points.push_back(pt);

        id++;
    }

    return points;
}