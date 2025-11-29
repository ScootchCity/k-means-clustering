k-means-clustering
==================

A simple k-means clustering implementation in C++ for 2D point data.

## Project Structure

```
k-means-clustering/
├── python_dataset_maker/
│   └── generate_test_data.py     # Python script to generate test datasets
├── src/
│   ├── Point.h                   # Point struct definition
│   ├── Cluster.h                 # Cluster struct definition
│   ├── CSVReader.h / CSVReader.cpp
│   ├── CSVWriter.h / CSVWriter.cpp
│   ├── KMeans.h / KMeans.cpp
│   ├── main.cpp
│   └── CMakeLists.txt
└── CMakeLists.txt
```

### Source Files
- **Point.h**: Point structure (id, x, y, cluster_id, distance_to_cluster).
- **Cluster.h**: Cluster structure (id, x, y).
- **CSVReader.h / CSVReader.cpp**: Reads CSV files containing x,y point data.
- **CSVWriter.h / CSVWriter.cpp**: Writes points and cluster centers to CSV files.
- **KMeans.h / KMeans.cpp**: K-means clustering algorithm implementation.
- **main.cpp**: Entry point that orchestrates the clustering process.

## Build Instructions

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

This builds the `kmeans` executable (or `kmeans.exe` on Windows).

## Usage

### Prepare Input Data

Input CSV files should contain x,y coordinates with a header row:
```csv
x,y
1.5,2.3
4.2,5.1
...
```

Test datasets can be generated using the `generate_test_data.py` script in the `python_dataset_maker/` directory. Edit the variables at the top of the script to customize dataset parameters, then run it to generate a CSV file.

### Run K-Means Clustering

```bash
kmeans <input_file> <k_value> <convergence_threshold>
```

Arguments:
- `input_file`: Path to CSV file containing x,y point data
- `k_value`: Number of clusters to create
- `convergence_threshold`: Algorithm stops when cluster centers move less than this distance

Example:
```bash
# Linux/Mac
./build/kmeans data.csv 3 0.01

# Windows
.\build\Debug\kmeans.exe data.csv 3 0.01
```

## Output Format

The program writes CSV files for each iteration to the current directory:
- `iteration_N_points.csv`: Contains id, x, y, cluster_id, distance_to_cluster for each point
- `iteration_N_clusters.csv`: Contains id, x, y for each cluster center

Each iteration is saved, from initial random assignment (iteration 0) through convergence, allowing visualization of the algorithm's progression.