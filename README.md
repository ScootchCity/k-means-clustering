k-means-clustering
==================

A simple k-means clustering implementation in C++ for 2D point data.

## Project Structure

```
k-means-clustering/
├── data/                          # Input datasets
├── output/                        # Clustering results
└── src/
    ├── common/                    # Shared code used by both programs
    │   ├── Point.h / Point.cpp
    │   ├── Cluster.h / Cluster.cpp
    │   ├── CSVReader.h / CSVReader.cpp
    │   ├── CSVWriter.h / CSVWriter.cpp
    │   └── CMakeLists.txt
    ├── kmeans/                    # K-means clustering implementation
    │   ├── KMeans.h / KMeans.cpp
    │   ├── main.cpp
    │   └── CMakeLists.txt
    ├── generator/                 # Test data generator
    │   ├── DataGenerator.h / DataGenerator.cpp
    │   ├── generate_data.cpp
    │   └── CMakeLists.txt
    └── CMakeLists.txt
```

### src/common/ - Shared Components
- **Point.h / Point.cpp**: Point structure (id, x, y, cluster_id, distance_to_center) and operations.
- **Cluster.h / Cluster.cpp**: ClusterCenter structure (id, x, y) and operations.
- **CSVReader.h / CSVReader.cpp**: Parses CSV files containing point data.
- **CSVWriter.h / CSVWriter.cpp**: Writes points and cluster centers to CSV files.

### src/kmeans/ - K-Means Algorithm
- **KMeans.h / KMeans.cpp**: K-means clustering algorithm implementation.
- **main.cpp**: Entry point for the clustering program.

### src/generator/ - Data Generation
- **DataGenerator.h / DataGenerator.cpp**: Generates random clustered test datasets.
- **generate_data.cpp**: Entry point for the data generator program.

## Build Instructions

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

This builds two executables:
- `kmeans` (or `kmeans.exe`)
- `generate_data` (or `generate_data.exe`)

## Usage

### Generate Test Data

```bash
# Linux
./build/generate_data <num_points> <num_clusters> <output_file>
./build/generate_data 1000 3 data/test_3clusters.csv

# Windows
.\build\Debug\generate_data.exe 1000 3 data/test_3clusters.csv
```

### Run K-Means Clustering

```bash
# Linux
./build/kmeans <input_file> <k> <output_directory>
./build/kmeans data/test_3clusters.csv 3 output

# Windows
.\build\Debug\kmeans.exe data/test_3clusters.csv 3 output
```

## Output Format

The k-means program generates CSV files for each iteration in the specified output directory:
- `iteration_N_points.csv`: Contains id, x, y, cluster_id, distance_to_center for each point.
- `iteration_N_centers.csv`: Contains cluster_id, center_x, center_y for each cluster center.

This means we get a snapshot of each iteration of the algorithm to use in a gif, or however we see fit.