from sklearn.datasets import make_blobs
import pandas as pd

#===== VARIABLES =====
n_samples = 90         #number of data points
n_centers = 3          #number of cluster centers (k)
cluster_std = 1.5      #standard deviation (lower = tighter clusters)
center_box = (-10, 10) #range where cluster centers can be placed (min, max)
output_file = '../data/test_data_small.csv' #name of set file
seed = 16              #random seed for (can reproduce sets)
#=====================

X, y = make_blobs(
    n_samples=n_samples,
    centers=n_centers,
    cluster_std=cluster_std,
    center_box=center_box,
    random_state=seed
)

pd.DataFrame(X, columns=['x', 'y']).to_csv(output_file, index=False)

print(f"Generated {n_samples} points with {n_centers} clusters (std={cluster_std})")
print(f"Saved to: {output_file}")