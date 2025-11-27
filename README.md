k-means-clustering
==================

A simple k-means clustering implementation in C++ for 2D point data.

## Project Structure

```
k-means-clustering/
├── data/                          # Input datasets (CSV files)
├── output/                        # Clustering results
├── src/
│   ├── Point.h / Point.cpp
│   ├── Cluster.h / Cluster.cpp
│   ├── CSVReader.h / CSVReader.cpp
│   ├── CSVWriter.h / CSVWriter.cpp
│   ├── KMeans.h / KMeans.cpp
│   ├── main.cpp
│   └── CMakeLists.txt
└── CMakeLists.txt
```

### Source Files
- **Point.h / Point.cpp**: Point structure (id, x, y, cluster_id, distance_to_cluster) and operations.
- **Cluster.h / Cluster.cpp**: ClusterCenter structure (id, x, y) and operations.
- **CSVReader.h / CSVReader.cpp**: Parses CSV files containing x,y point data.
- **CSVWriter.h / CSVWriter.cpp**: Writes points and cluster centers to CSV files.
- **KMeans.h / KMeans.cpp**: K-means clustering algorithm implementation.
- **main.cpp**: Entry point for the clustering program.

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

You can generate test datasets using Python's scikit-learn:
```python
from sklearn.datasets import make_blobs
import pandas as pd

X, y = make_blobs(n_samples=300, centers=3, cluster_std=1.5, random_state=42)
pd.DataFrame(X, columns=['x', 'y']).to_csv('data/test_data.csv', index=False)
```

### Run K-Means Clustering

```bash
# Linux
./build/kmeans <input_file> <k> <output_directory>
./build/kmeans data/test_data.csv 3 output

# Windows
.\build\Debug\kmeans.exe data/test_data.csv 3 output
```

## Output Format

The k-means program generates CSV files for each iteration in the specified output directory:
- `iteration_N_points.csv`: Contains id, x, y, cluster_id, distance_to_cluster for each point.
- `iteration_N_centers.csv`: Contains cluster_id, center_x, center_y for each cluster center.

This provides a snapshot of each iteration of the algorithm for visualization or creating animated gifs.