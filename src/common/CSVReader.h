#ifndef CSVREADER_H
#define CSVREADER_H

#include <vector>
#include <string>
#include "Point.h"

using namespace std;

class CSVReader {
public:
    //reads CSV file and returns vector of points
    vector<Point> readCSVPoints(string filename);

private:
};

#endif // CSVREADER_H
