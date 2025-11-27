#ifndef CSVREADER_H
#define CSVREADER_H

#include <vector>
#include <string>
#include "Point.h"

using namespace std;

class CSVReader {
public:
    // Reads CSV file and returns vector of Points
    vector<Point> readCSV(string filename);

private:
};

#endif // CSVREADER_H
